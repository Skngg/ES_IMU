/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
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

typedef enum {
	LSM6DSL_id = 0,
	LSM303AGR_XL_id,
	LSM303AGR_MG_id
} sensor_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim7;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
volatile uint8_t tim_flag =0;

static axis3bit16_t data_raw_acceleration;
static axis3bit16_t data_raw_gyro;
static axis3bit16_t data_raw_magneto;

static float acceleration_mg[3];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM7_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
static int32_t lsm6dsl_read(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len);
static int32_t lsm6dsl_write(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len);

static int32_t lsm303agr_mg_read(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len);
static int32_t lsm303agr_mg_write(void *handle, uint8_t Reg, uint8_t *Bufp,
		uint16_t len);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM7_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  RetargetInit(&huart2);
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

	// Test communication with the sensors and reset thair settings
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
	lsm303agr_mag_set_rst_mode_set(&lsm303agr_ctx,
			LSM303AGR_SENS_OFF_CANC_EVERY_ODR);
	lsm303agr_mag_operating_mode_set(&lsm303agr_ctx, LSM303AGR_CONTINUOUS_MODE);

//	HAL_TIM_Base_Start_IT(&htim7);


	memset(data_raw_acceleration.u8bit, 0x00, 3 * sizeof(int16_t));
	memset(data_raw_gyro.u8bit, 0x00, 3 * sizeof(int16_t));
	memset(data_raw_magneto.u8bit, 0x00, 3 * sizeof(int16_t));

	printf("***** BEGIN MEASUREMENTS *****\r\n");

	Algorithm_initialize();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		lsm6dsl_acceleration_raw_get(&lsm6dsl_ctx, data_raw_acceleration.u8bit);
		lsm6dsl_angular_rate_raw_get(&lsm6dsl_ctx, data_raw_gyro.u8bit);
		//lsm303agr_magnetic_raw_get(&lsm303agr_ctx, data_raw_magneto.u8bit);

//		printf("Accl: %d %d %d\r\n", data_raw_acceleration.i16bit[0], data_raw_acceleration.i16bit[1], data_raw_acceleration.i16bit[2]);
//		printf("Gyro: %d %d %d\r\n", data_raw_gyro.i16bit[0], data_raw_gyro.i16bit[1], data_raw_gyro.i16bit[2]);
		//printf("Magn: %d %d %d\r\n", data_raw_magneto.i16bit[0], data_raw_magneto.i16bit[1], data_raw_magneto.i16bit[2]);

		Algorithm_U.AccX = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[0])*0.00981;
		Algorithm_U.AccY = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[1])*0.00981;
		Algorithm_U.AccZ = lsm6dsl_from_fs2g_to_mg(data_raw_acceleration.i16bit[2])*0.00981;
		Algorithm_U.GyroX = lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[0])*0.001;
		Algorithm_U.GyroY = lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[1])*0.001;
		Algorithm_U.GyroZ = lsm6dsl_from_fs125dps_to_mdps(data_raw_gyro.i16bit[2])*0.001;
		Algorithm_step();

		printf("EulXYZ: %f %f %f\r\n", Algorithm_Y.EulXYZ[0], Algorithm_Y.EulXYZ[1], Algorithm_Y.EulXYZ[2]);

//			acceleration_mg[0] = lsm6dsl_from_fs2g_to_mg(
//					data_raw_acceleration.i16bit[0]);
//			acceleration_mg[1] = lsm6dsl_from_fs2g_to_mg(
//					data_raw_acceleration.i16bit[1]);
//			acceleration_mg[2] = lsm6dsl_from_fs2g_to_mg(
//					data_raw_acceleration.i16bit[2]);
		HAL_Delay(10);
//		if (tim_flag) {
//			tim_flag = 0;
//			HAL_TIM_Base_Start_IT(&htim7);
//		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 15999;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 999;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED2_Pin */
  GPIO_InitStruct.Pin = LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	while(1);
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
