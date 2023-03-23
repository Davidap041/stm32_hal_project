/* Includes*/
#include "main.h"
/* message uart functions dependence*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <MyUsart.hpp>
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
/** Define Declaraction constants*/
#define WELCOME_MSG "Welcome to the nucleo management console"
#define MAIN_MENU "Select the option you are interested in: "
#define PROMPT ">"
/* Private function prototypes */
/** Init clock and peripherals function*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* Function used in usart communication */
void printWelcomeMessage(void);
uint8_t readUserInput(void);
uint8_t processUserInput(uint8_t opt);

MyUsart *myUsart;

int main(void)
{
  uint8_t opt = 0;

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN WHILE */
  HAL_Delay(3000);
printMessage:
  printWelcomeMessage();

  while (1)
  {
    /* Read and White message*/
    opt = readUserInput();
    processUserInput(opt);
    if (opt == 3)
    {
      goto printMessage;
    }
    /* Blink Led Status */
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(400);
  }
}
/**
 * @brief Welcome message Print function
 * @param
 */
void printWelcomeMessage(void)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", strlen("\r\n"), HAL_MAX_DELAY);
  HAL_UART_Transmit(&huart1, (uint8_t *)WELCOME_MSG, strlen(WELCOME_MSG), HAL_MAX_DELAY);
  HAL_UART_Transmit(&huart1, (uint8_t *)"\r\n", strlen("\r\n"), HAL_MAX_DELAY);
  HAL_UART_Transmit(&huart1, (uint8_t *)MAIN_MENU, strlen(MAIN_MENU), HAL_MAX_DELAY);
}
/**
 * Read User Input
 */
uint8_t readUserInput(void)
{
  char readBuf[1];

  HAL_UART_Transmit(&huart1, (uint8_t *)PROMPT, strlen(PROMPT), HAL_MAX_DELAY);
  HAL_UART_Receive(&huart1, (uint8_t *)readBuf, 1, HAL_MAX_DELAY);

  return atoi(readBuf);
}
uint8_t processUserInput(uint8_t opt)
{
  char msg[31];

  if (!opt || opt > 3)
    return 0;

  sprintf(msg, "%d", opt);
  HAL_UART_Transmit(&huart1, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

  switch (opt)
  {
  case 1:
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    break;
  case 2:
    sprintf(msg, "\r\nUSER BUTTON status: %s",
            HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET ? "PRESSED" : "RELEASED");
    HAL_UART_Transmit(&huart1, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);
    break;
  case 3:
    return 2;
  };

  return 1;
}

/**
 * @brief System Clock Configuration
 * @retval None
 */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
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
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */
}
/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /*UART GPIO CONFIG */
  __HAL_RCC_GPIOA_CLK_ENABLE(); // for uart use

  /* LED GPIO CONFIG */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}