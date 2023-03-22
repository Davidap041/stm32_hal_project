#include "test_main.h"
#include "unity_config.h"

#define USARTx USART1
#define USARTx_CLK_ENABLE() __HAL_RCC_USART1_CLK_ENABLE()
#define USARTx_CLK_DISABLE() __HAL_RCC_USART1_CLK_DISABLE()
#define USARTx_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()
#define USARTx_TX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()

// #define USARTx_FORCE_RESET() __HAL_RCC_USART1_FORCE_RESET()
// #define USARTx_RELEASE_RESET() __HAL_RCC_USART1_RELEASE_RESET()

#define USARTx_TX_PIN  GPIO_PIN_8 | GPIO_PIN_9
#define USARTx_TX_GPIO_PORT GPIOA
// #define USARTx_TX_AF GPIO_AF7_USART2
#define USARTx_RX_PIN GPIO_PIN_10
#define USARTx_RX_GPIO_PORT GPIOA
// #define USARTx_RX_AF GPIO_AF7_USART2

UART_HandleTypeDef huartx;

void unityOutputStart()
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* Peripheral clock enable */
  __HAL_RCC_USART1_CLK_ENABLE();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  /**USART1 GPIO Configuration
  PA8     ------> USART1_CK
  PA9     ------> USART1_TX
  PA10     ------> USART1_RX
  */
  GPIO_InitStruct.Pin = USARTx_TX_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  huartx.Instance = USARTx;
  huartx.Init.BaudRate = 115200;
  huartx.Init.WordLength = UART_WORDLENGTH_8B;
  huartx.Init.StopBits = UART_STOPBITS_1;
  huartx.Init.Parity = UART_PARITY_NONE;
  huartx.Init.Mode = UART_MODE_TX_RX;
  huartx.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huartx.Init.OverSampling = UART_OVERSAMPLING_16;

  if (HAL_UART_Init(&huartx) != HAL_OK)
  {
    while (1)
    {
    }
  }
}

void unityOutputChar(char c)
{
  HAL_UART_Transmit(&huartx, (uint8_t *)(&c), 1, 1000);
}

void unityOutputFlush() {}

void unityOutputComplete()
{
  USARTx_CLK_DISABLE();
  USARTx_RX_GPIO_CLK_DISABLE();
  USARTx_TX_GPIO_CLK_DISABLE();
}