/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define MOTOR_NUM              4U

#define ENC_M1                 0U
#define ENC_M2                 1U
#define ENC_M3                 2U
#define ENC_M4                 3U

#define DF_ENCODER_LINES       448U
#define DF_MOTOR_REDUCTION     38U
#define DF_WHEEL_DIAMETER_MM   97.0f
#define DF_WHEEL_POLARITY      1.0f

#define ENCODER_MULTIPLE       4U
#define ENCODER_COUNTS_REV     (DF_ENCODER_LINES * ENCODER_MULTIPLE)
#define WHEEL_COUNTS_REV       (ENCODER_COUNTS_REV * DF_MOTOR_REDUCTION)
#define WHEEL_CIRCUMFERENCE_MM (3.14159265f * DF_WHEEL_DIAMETER_MM)
#define COUNTS_PER_MM          ((float)WHEEL_COUNTS_REV / WHEEL_CIRCUMFERENCE_MM)
#define ENCODER_SAMPLE_MS      10U

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Encoder_Init(void);
uint16_t Encoder_GetCount(uint8_t motor_id);
float Encoder_GetSpeed(uint8_t motor_id);
float Encoder_GetSpeedMMps(uint8_t motor_id);
void Encoder_UpdateSpeed(void);

extern volatile float g_wheel_speed_mmps[MOTOR_NUM];

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED0_Pin GPIO_PIN_5
#define LED0_GPIO_Port GPIOE
#define AIN1_Pin GPIO_PIN_0
#define AIN1_GPIO_Port GPIOD
#define AIN2_Pin GPIO_PIN_1
#define AIN2_GPIO_Port GPIOD
#define BIN1_Pin GPIO_PIN_2
#define BIN1_GPIO_Port GPIOD
#define BIN2_Pin GPIO_PIN_3
#define BIN2_GPIO_Port GPIOD
#define CIN1_Pin GPIO_PIN_4
#define CIN1_GPIO_Port GPIOD
#define CIN2_Pin GPIO_PIN_5
#define CIN2_GPIO_Port GPIOD
#define DIN1_Pin GPIO_PIN_6
#define DIN1_GPIO_Port GPIOD
#define DIN2_Pin GPIO_PIN_7
#define DIN2_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
