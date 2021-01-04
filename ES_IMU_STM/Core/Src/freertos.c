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
#ifdef MADGWICK_C_CODED
#include "ahrs_madgwick.h"
#endif
#ifdef MADGWICK_MATLAB_CODED
#include "Algorithm.h"
#endif
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef union {
	int16_t i16bit[3];
	uint8_t u8bit[6];
} axis3bit16_t;

typedef struct {
	float ax[3];
} axis3_t;

typedef union {
	int16_t i16bit;
	uint8_t u8bit[2];
} temp16_t;

typedef struct {
//#ifdef MADGWICK_C_CODED
	axis3_t acc;
	axis3_t gyro;
//	axis3_t mag;
	float temp;
//#endif

//#ifdef MADGWICK_MATLAB_CODED
//	axis3bit16_t raw_acc;
//	axis3bit16_t raw_gyro;
//	axis3bit16_t raw_mag;
//	temp16_t temp;
//#endif
} data_mems_t;

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

/* Definitions for algorithmToLogQueue */
osMessageQueueId_t algorithmToLogQueueHandle;
const osMessageQueueAttr_t algorithmToLogQueue_attributes = {
  .name = "algorithmToLogQueue"
};
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
  acquisitionToAlgorithmQueueHandle = osMessageQueueNew (1, sizeof(data_mems_t), &acquisitionToAlgorithmQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
#ifdef MADGWICK_C_CODED
  algorithmToLogQueueHandle = osMessageQueueNew (1, sizeof(euler_ang_t), &algorithmToLogQueue_attributes);
#endif

#ifdef MADGWICK_MATLAB_CODED
  algorithmToLogQueueHandle = osMessageQueueNew (1, sizeof(quaternion_t), &algorithmToLogQueue_attributes);
#endif
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

	axis3bit16_t acc_raw;
	axis3bit16_t gyro_raw;
	axis3bit16_t magneto_raw;
	temp16_t temp_raw;

	data_mems_t data_mems;

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
	lsm6dsl_xl_data_rate_set(&lsm6dsl_ctx, LSM6DSL_XL_ODR_104Hz);
	lsm6dsl_gy_data_rate_set(&lsm6dsl_ctx, LSM6DSL_GY_ODR_104Hz);
	lsm6dsl_xl_full_scale_set(&lsm6dsl_ctx, LSM6DSL_4g);
	lsm6dsl_gy_full_scale_set(&lsm6dsl_ctx, LSM6DSL_2000dps);

	lsm303agr_mag_block_data_update_set(&lsm303agr_ctx, PROPERTY_ENABLE);
	lsm303agr_mag_data_rate_set(&lsm303agr_ctx, LSM303AGR_MG_ODR_10Hz);
	lsm303agr_mag_set_rst_mode_set(&lsm303agr_ctx, LSM303AGR_SENS_OFF_CANC_EVERY_ODR);
	lsm303agr_mag_operating_mode_set(&lsm303agr_ctx, LSM303AGR_CONTINUOUS_MODE);

	osTimerStart(acquisitionCycleTimerHandle, 10U);

	/* Infinite loop */
  for(;;)
  {
  	status = osSemaphoreAcquire(lsm303DrdyBinarySemHandle, osWaitForever);

  	if (status == osOK) {
  	  lsm6dsl_acceleration_raw_get(&lsm6dsl_ctx, acc_raw.u8bit);
  	  lsm6dsl_angular_rate_raw_get(&lsm6dsl_ctx, gyro_raw.u8bit);
  	  lsm303agr_magnetic_raw_get(&lsm303agr_ctx, magneto_raw.u8bit);
  		lsm6dsl_temperature_raw_get(&lsm6dsl_ctx, temp_raw.u8bit);

//			data_mems.acc.ax[0] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[0])/1000;//*0.00981 - 0.2906;
//			data_mems.acc.ax[1] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[1])/1000;//*0.00981 + 0.6679;
//			data_mems.acc.ax[2] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[2])/1000;//*0.00981 - 0.5317;
			data_mems.acc.ax[0] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[0])*0.00981;// - 0.2906;
			data_mems.acc.ax[1] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[1])*0.00981;// + 0.6679;
			data_mems.acc.ax[2] = lsm6dsl_from_fs4g_to_mg(acc_raw.i16bit[2])*0.00981;// - 0.5317;

//			data_mems.gyro.ax[0] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[0])/100000;//*0.001 - 0.7890 + 0.0486*temp;
//			data_mems.gyro.ax[1] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[1])/100000;//*0.001 - 0.0266 - 0.1064*temp;
//			data_mems.gyro.ax[2] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[2])/100000;

			data_mems.gyro.ax[0] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[0])*0.001;// - 0.7890 + 0.0486*temp;
			data_mems.gyro.ax[1] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[1])*0.001;// - 0.0266 - 0.1064*temp;
			data_mems.gyro.ax[2] = lsm6dsl_from_fs2000dps_to_mdps(gyro_raw.i16bit[2])*0.001;// - 0.4822 - 0.4785 - 0.0150*temp;

			for (size_t axes_it = 0; axes_it < 3; axes_it++)
			{
				data_mems.gyro.ax[axes_it] = ((data_mems.gyro.ax[axes_it] < 0.1) && (data_mems.gyro.ax[axes_it] > 0.1)) ? data_mems.gyro.ax[axes_it] : 0;
			}

			data_mems.temp = lsm6dsl_from_lsb_to_celsius(temp_raw.i16bit);// - 20.1605;

  		osMessageQueuePut(acquisitionToAlgorithmQueueHandle, &data_mems, 0U, 0U);
  	}

    osDelay(8);
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
#ifdef MADGWICK_C_CODED
	osStatus_t status;

	data_mems_t data_mems;
	euler_ang_t euler_ang;

//	Algorithm_initialize();
  /* Infinite loop */
  for(;;)
  {
  	status = osMessageQueueGet(acquisitionToAlgorithmQueueHandle, &data_mems, NULL, 0U);   // wait for message

  	if (status == osOK)
  	{
  		MadgwickAHRSupdateIMU(data_mems.gyro.ax[0], data_mems.gyro.ax[1], data_mems.gyro.ax[2], data_mems.acc.ax[0], data_mems.acc.ax[1], data_mems.acc.ax[2]);
  		ToEulerAngles(&euler_ang);

			status = osMessageQueuePut(algorithmToLogQueueHandle, &euler_ang, 0U, 0U);
  	}
    osDelay(8);
  }
#endif

#ifdef MADGWICK_MATLAB_CODED
    osStatus_t status;

    data_mems_t data_mems;
  	quaternion_t quaternion;

  	Algorithm_initialize();
    /* Infinite loop */
    for(;;)
    {
    	status = osMessageQueueGet(acquisitionToAlgorithmQueueHandle, &data_mems, NULL, 0U);   // wait for message

    	if (status == osOK)
    	{
				Algorithm_U.AccX = data_mems.acc.ax[0];//lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[0])*0.00981 - 0.1476 - 0.1430;
				Algorithm_U.AccY = data_mems.acc.ax[1];//lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[1])*0.00981 + 0.3055 + 0.3624;
				Algorithm_U.AccZ = data_mems.acc.ax[2];//lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[2])*0.00981 - 0.2684 - 0.2633;
				Algorithm_U.GyroX = data_mems.gyro.ax[0];//lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[0])*0.001 - 0.3981 - 0.3909 + 0.0486*temp;
				Algorithm_U.GyroY = data_mems.gyro.ax[1];//lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[1])*0.001 - 2.4888 + 2.4622 - 0.1064*temp;
				Algorithm_U.GyroZ = data_mems.gyro.ax[2];//lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[2])*0.001 - 0.4822 - 0.4785 - 0.0150*temp;

  			Algorithm_step();
  			quaternion.w = Algorithm_Y.Quat[0];
  			quaternion.x = Algorithm_Y.Quat[1];
  			quaternion.y = Algorithm_Y.Quat[2];
  			quaternion.z = Algorithm_Y.Quat[3];

  			status = osMessageQueuePut(algorithmToLogQueueHandle, &quaternion, 0U, 0U);
    	}

      osDelay(8);
    }
#endif
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
#ifdef MADGWICK_C_CODED
	osStatus_t status = osOK;
//	quaternion_t quaternion;
	euler_ang_t euler_ang;
	uint8_t log_payload[100];
	uint8_t log_size = 0;
  /* Infinite loop */
  for(;;)
  {
  	status = osMessageQueueGet(algorithmToLogQueueHandle, &euler_ang, NULL, 0U);

  	if (status == osOK) {
  		euler_ang.roll = euler_ang.roll*180.0/PI;
  		euler_ang.pitch = euler_ang.pitch*180.0/PI;
  		euler_ang.yaw = euler_ang.yaw*180.0/PI;

  		log_size = sprintf((char*)log_payload, "Roll: %.3f\t Pitch: %.3f\t Yaw: %.3f\r\n", euler_ang.roll, euler_ang.pitch, euler_ang.yaw);
  		HAL_UART_Transmit_DMA(&huart2, log_payload, log_size);

//  		log_size = sprintf((char*)log_payload, "EulXYZ: %f %f %f\r\n", Algorithm_Y.EulXYZ[0], Algorithm_Y.EulXYZ[1], Algorithm_Y.EulXYZ[2]);
//  		HAL_UART_Transmit_DMA(&huart2, log_payload, log_size);
//  					printf("Accl: %f %f %f Gyro: %f %f %f \r\n", Algorithm_U.AccX, Algorithm_U.AccY, Algorithm_U.AccZ, Algorithm_U.GyroX, Algorithm_U.GyroY, Algorithm_U.GyroZ);
//  					printf("EulXYZ: %f %f %f\r\n", Algorithm_Y.EulXYZ[0], Algorithm_Y.EulXYZ[1], Algorithm_Y.EulXYZ[2]);
  	}

    osDelay(8);
  }
#endif

#ifdef MADGWICK_MATLAB_CODED
	osStatus_t status = osOK;
	quaternion_t quaternion;
	uint8_t log_payload[100];
	uint8_t log_size = 0;

	/* Infinite loop */
  for(;;)
  {
  	status = osMessageQueueGet(algorithmToLogQueueHandle, &quaternion, NULL, 0U);

  	if (status == osOK)
  	{
  		log_size = sprintf((char*)log_payload, "w%.3fwa%.3fab%.3fbc%.3fc\r\n", quaternion.w, quaternion.x, quaternion.y, quaternion.z);
  		HAL_UART_Transmit_DMA(&huart2, log_payload, log_size);
  	}

    osDelay(8);
  }
#endif
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
