/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "i2c.h"
#include "usart.h"
#include "retarget.h"
#include "lsm6dsl_reg.h"
#include "lsm303agr_reg.h"
#include "Algorithm.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef union {
	int16_t i16bit[3];
	uint8_t u8bit[6];
} axis3bit16_t;

typedef union {
	int16_t i16bit;
	uint8_t u8bit[2];
} temp16_t;

typedef struct {
	axis3bit16_t acceleration;
	axis3bit16_t gyro;
	axis3bit16_t magneto;
	uint32_t time;
} data_raw_mems_t;

typedef enum {
	LSM6DSL_id = 0,
	LSM303AGR_XL_id,
	LSM303AGR_MG_id
} sensor_t;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} quaternion_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart2;
//static data_raw_mems_t data_raw_mems;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 128 * 4
};
/* Definitions for acquisitionTask */
osThreadId_t acquisitionTaskHandle;
const osThreadAttr_t acquisitionTask_attributes = {
  .name = "acquisitionTask",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 512 * 4
};
/* Definitions for algorithmTask */
osThreadId_t algorithmTaskHandle;
const osThreadAttr_t algorithmTask_attributes = {
  .name = "algorithmTask",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 512 * 4
};
/* Definitions for logTask */
osThreadId_t logTaskHandle;
const osThreadAttr_t logTask_attributes = {
  .name = "logTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for acquisitionToAlgorithmQueue */
osMessageQueueId_t acquisitionToAlgorithmQueueHandle;
const osMessageQueueAttr_t acquisitionToAlgorithmQueue_attributes = {
  .name = "acquisitionToAlgorithmQueue"
};
/* Definitions for algorithmToLogQueue */
osMessageQueueId_t algorithmToLogQueueHandle;
const osMessageQueueAttr_t algorithmToLogQueue_attributes = {
  .name = "algorithmToLogQueue"
};
/* Definitions for acquisitionCycleTimer */
osTimerId_t acquisitionCycleTimerHandle;
const osTimerAttr_t acquisitionCycleTimer_attributes = {
  .name = "acquisitionCycleTimer"
};
/* Definitions for lsm303DrdyBinarySem */
osSemaphoreId_t lsm303DrdyBinarySemHandle;
const osSemaphoreAttr_t lsm303DrdyBinarySem_attributes = {
  .name = "lsm303DrdyBinarySem"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
static int32_t lsm6dsl_read(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len);
static int32_t lsm6dsl_write(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len);

static int32_t lsm303agr_mg_read(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len);
static int32_t lsm303agr_mg_write(void *handle, uint8_t Reg, uint8_t *Bufp,	uint16_t len);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartAcquisitionTask(void *argument);
void StartAlgorithmTask(void *argument);
void StartLogTask(void *argument);
void acquisitionCycleTimerCallback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of lsm303DrdyBinarySem */
  lsm303DrdyBinarySemHandle = osSemaphoreNew(1, 1, &lsm303DrdyBinarySem_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of acquisitionCycleTimer */
  acquisitionCycleTimerHandle = osTimerNew(acquisitionCycleTimerCallback, osTimerPeriodic, NULL, &acquisitionCycleTimer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of acquisitionToAlgorithmQueue */
  acquisitionToAlgorithmQueueHandle = osMessageQueueNew (1, sizeof(data_raw_mems_t), &acquisitionToAlgorithmQueue_attributes);

  /* creation of algorithmToLogQueue */
  algorithmToLogQueueHandle = osMessageQueueNew (1, sizeof(quaternion_t), &algorithmToLogQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of acquisitionTask */
  acquisitionTaskHandle = osThreadNew(StartAcquisitionTask, NULL, &acquisitionTask_attributes);

  /* creation of algorithmTask */
  algorithmTaskHandle = osThreadNew(StartAlgorithmTask, NULL, &algorithmTask_attributes);

  /* creation of logTask */
  logTaskHandle = osThreadNew(StartLogTask, NULL, &logTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(10);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartAcquisitionTask */
/**
* @brief Function implementing the acquisitionTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAcquisitionTask */
void StartAcquisitionTask(void *argument)
{
  /* USER CODE BEGIN StartAcquisitionTask */
	osStatus_t status = osOK;

	// Set handles for sensor communication
	stmdev_ctx_t lsm6dsl_ctx;
	lsm6dsl_ctx.write_reg = lsm6dsl_write;
	lsm6dsl_ctx.read_reg = lsm6dsl_read;
	lsm6dsl_ctx.handle = &hi2c1;

	stmdev_ctx_t lsm303agr_ctx;
	lsm303agr_ctx.write_reg = lsm303agr_mg_write;
	lsm303agr_ctx.read_reg = lsm303agr_mg_read;
	lsm303agr_ctx.handle = &hi2c1;

	uint8_t whoamI = 0, rst = 0;

	// Test communication with the sensors and reset their settings
	lsm6dsl_device_id_get(&lsm6dsl_ctx, &whoamI);
	if (whoamI != LSM6DSL_ID) {
		Error_Handler();
	} else {
		lsm6dsl_reset_set(&lsm6dsl_ctx, PROPERTY_ENABLE);
		do {
			lsm6dsl_reset_get(&lsm6dsl_ctx, &rst);
		} while (rst);
		rst = 0;
	}

	lsm303agr_mag_device_id_get(&lsm303agr_ctx, &whoamI);
	if (whoamI != LSM303AGR_ID_MG) {
		Error_Handler();
	} else {
		lsm303agr_mag_reset_set(&lsm303agr_ctx, PROPERTY_ENABLE);
		do {
			lsm303agr_mag_reset_get(&lsm303agr_ctx, &rst);
		} while (rst);
		rst = 0;
	}

	lsm6dsl_block_data_update_set(&lsm6dsl_ctx, PROPERTY_ENABLE);
	lsm6dsl_xl_data_rate_set(&lsm6dsl_ctx, LSM6DSL_XL_ODR_12Hz5);
	lsm6dsl_gy_data_rate_set(&lsm6dsl_ctx, LSM6DSL_GY_ODR_12Hz5);
	lsm6dsl_xl_full_scale_set(&lsm6dsl_ctx, LSM6DSL_2g);
	lsm6dsl_gy_full_scale_set(&lsm6dsl_ctx, LSM6DSL_125dps);

	lsm303agr_mag_block_data_update_set(&lsm303agr_ctx, PROPERTY_ENABLE);
	lsm303agr_mag_data_rate_set(&lsm303agr_ctx, LSM303AGR_MG_ODR_10Hz);
	lsm303agr_mag_set_rst_mode_set(&lsm303agr_ctx, LSM303AGR_SENS_OFF_CANC_EVERY_ODR);
	lsm303agr_mag_operating_mode_set(&lsm303agr_ctx, LSM303AGR_CONTINUOUS_MODE);

	data_raw_mems_t data_raw_mems;
	temp16_t data_raw_temp;

	memset(data_raw_mems.acceleration.u8bit, 0x00, 3 * sizeof(int16_t));
	memset(data_raw_mems.gyro.u8bit, 0x00, 3 * sizeof(int16_t));
	memset(data_raw_mems.magneto.u8bit, 0x00, 3 * sizeof(int16_t));
	memset(&data_raw_mems.time, 0x00, sizeof(uint32_t));
	memset(data_raw_temp.u8bit, 0x00, sizeof(int16_t));

	osTimerStart(acquisitionCycleTimerHandle, 100U);

	/* Infinite loop */
  for(;;)
  {
  	status = osSemaphoreAcquire(lsm303DrdyBinarySemHandle, osWaitForever);

  	if (status == osOK) {
  	  lsm6dsl_acceleration_raw_get(&lsm6dsl_ctx, data_raw_mems.acceleration.u8bit);
  	  lsm6dsl_angular_rate_raw_get(&lsm6dsl_ctx, data_raw_mems.gyro.u8bit);
  	  lsm303agr_magnetic_raw_get(&lsm303agr_ctx, data_raw_mems.magneto.u8bit);
  		lsm6dsl_temperature_raw_get(&lsm6dsl_ctx, data_raw_temp.u8bit);

  		osMessageQueuePut(acquisitionToAlgorithmQueueHandle, &data_raw_mems, 0U, 0U);
  	}

//		osThreadYield();
    osDelay(90);
  }
  /* USER CODE END StartAcquisitionTask */
}

/* USER CODE BEGIN Header_StartAlgorithmTask */
/**
* @brief Function implementing the algorithmTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAlgorithmTask */
void StartAlgorithmTask(void *argument)
{
  /* USER CODE BEGIN StartAlgorithmTask */
	osStatus_t status;
	data_raw_mems_t data_raw_mems;
	temp16_t data_raw_temp;
	quaternion_t quaternion;
	float_t temp;

	Algorithm_initialize();
  /* Infinite loop */
  for(;;)
  {
  	status = osMessageQueueGet(acquisitionToAlgorithmQueueHandle, &data_raw_mems, NULL, 0U);   // wait for message

  	if (status == osOK) {
  			temp = lsm6dsl_from_lsb_to_celsius(data_raw_temp.i16bit) - 20.1605;
			Algorithm_U.AccX = lsm6dsl_from_fs2g_to_mg(data_raw_mems.acceleration.i16bit[0])*0.00981 - 0.2906;
			Algorithm_U.AccY = lsm6dsl_from_fs2g_to_mg(data_raw_mems.acceleration.i16bit[1])*0.00981 + 0.6679;
			Algorithm_U.AccZ = lsm6dsl_from_fs2g_to_mg(data_raw_mems.acceleration.i16bit[2])*0.00981 - 0.5317;
//			Algorithm_U.GyroX = (lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[0])*0.001 - 0.7890 + 0.0486*temp) * 0.0174532925;
//			Algorithm_U.GyroY = (lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[1])*0.001 - 0.0266 - 0.1064*temp) * 0.0174532925;
//			Algorithm_U.GyroZ = (lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[2])*0.001 - 0.9607 - 0.0150*temp) * 0.0174532925;

			Algorithm_U.GyroX = lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[0])*0.001 - 0.7890 + 0.0486*temp;
			Algorithm_U.GyroY = lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[1])*0.001 - 0.0266 - 0.1064*temp;
			Algorithm_U.GyroZ = lsm6dsl_from_fs125dps_to_mdps(data_raw_mems.gyro.i16bit[2])*0.001 - 0.9607 - 0.0150*temp;

			Algorithm_step();

			quaternion.x = Algorithm_Y.EulXYZ[0];
			quaternion.y = Algorithm_Y.EulXYZ[1];
			quaternion.z = Algorithm_Y.EulXYZ[2];

			status = osMessageQueuePut(algorithmToLogQueueHandle, &quaternion, 0U, 0U);//osWaitForever);
//			temp_celsius = lsm6dsl_from_lsb_to_celsius(data_raw_temp.i16bit);
  	}
    osDelay(90);
  }
  /* USER CODE END StartAlgorithmTask */
}

/* USER CODE BEGIN Header_StartLogTask */
/**
* @brief Function implementing the logTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLogTask */
void StartLogTask(void *argument)
{
  /* USER CODE BEGIN StartLogTask */
	osStatus_t status = osOK;
	quaternion_t quaternion;

	uint8_t log_payload[100];
	uint8_t log_size = 0;
  /* Infinite loop */
  for(;;)
  {
  	status = osMessageQueueGet(algorithmToLogQueueHandle, &quaternion, NULL, 0U);

  	if (status == osOK) {
  		log_size = sprintf(log_payload, "EulXYZ: %f %f %f\r\n", Algorithm_Y.EulXYZ[0], Algorithm_Y.EulXYZ[1], Algorithm_Y.EulXYZ[2]);
  		HAL_UART_Transmit_DMA(&huart2, log_payload, log_size);
//  					printf("Accl: %f %f %f Gyro: %f %f %f \r\n", Algorithm_U.AccX, Algorithm_U.AccY, Algorithm_U.AccZ, Algorithm_U.GyroX, Algorithm_U.GyroY, Algorithm_U.GyroZ);
//  					printf("EulXYZ: %f %f %f\r\n", Algorithm_Y.EulXYZ[0], Algorithm_Y.EulXYZ[1], Algorithm_Y.EulXYZ[2]);
  		//print log
  	}

    osDelay(90);
  }
  /* USER CODE END StartLogTask */
}

/* acquisitionCycleTimerCallback function */
void acquisitionCycleTimerCallback(void *argument)
{
  /* USER CODE BEGIN acquisitionCycleTimerCallback */
	osSemaphoreRelease(lsm303DrdyBinarySemHandle);
  /* USER CODE END acquisitionCycleTimerCallback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
static int32_t lsm6dsl_write(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len) {
	if (handle == &hi2c1) {
		HAL_I2C_Mem_Write(handle, LSM6DSL_I2C_ADD_H, Reg,
		I2C_MEMADD_SIZE_8BIT, Bufp, len, HAL_MAX_DELAY);
	}
	return 0;
}

static int32_t lsm6dsl_read(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len) {
	uint16_t ret = 0;
	if (handle == &hi2c1) {
		ret = HAL_I2C_Mem_Read(handle, LSM6DSL_I2C_ADD_H, Reg,
		I2C_MEMADD_SIZE_8BIT, Bufp, len, HAL_MAX_DELAY);
	}
	return ret;
}

static int32_t lsm303agr_mg_write(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len) {
	if (handle == &hi2c1) {
		HAL_I2C_Mem_Write(handle, LSM303AGR_I2C_ADD_MG, Reg,
		I2C_MEMADD_SIZE_8BIT, Bufp, len, HAL_MAX_DELAY);
	}
	return 0;
}

static int32_t lsm303agr_mg_read(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len) {
	uint16_t ret = 0;
	if (handle == &hi2c1) {
		ret = HAL_I2C_Mem_Read(handle, LSM303AGR_I2C_ADD_MG, Reg,
		I2C_MEMADD_SIZE_8BIT, Bufp, len, HAL_MAX_DELAY);
	}
	return ret;
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
