#include <unity.h>
#include <HalGpio/HalGpio.hpp>

void SystemClock_Config(void);

HalGpio *halGpio;

void setUp(void)
{
  halGpio = new HalGpio();
}

void tearDown(void)
{
  // clean stuff up here
  // delete halGpio;
}

void test_dumpTrue_should_return_true(void)
{
  // test stuff
  bool actual = halGpio->dumpTrue();
  int expected = true;
  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void test_dumpFalse_should_return_false(void)
{
  // more test stuff
  bool actual = halGpio->dumpFalse();
  int expected = false;
  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void test_should_initialize(void)
{
  bool actual = false;
  bool expected = true;
  if (halGpio != NULL)
  {
    actual = true;
  }
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_set_pin(void)
{
  int16_t actual, expected;

  /* Pin 0 selected    */
  halGpio->setPin(0);
  actual = halGpio->getPin();
  expected = ((uint16_t)0x0001);
  TEST_ASSERT_EQUAL_HEX16(expected, actual);

  /* Pin 10 selected   */
  halGpio->setPin(10);
  actual = halGpio->getPin();
  expected = ((uint16_t)0x0400);
  TEST_ASSERT_EQUAL_HEX16(expected, actual);

  /* Pin 15 selected   */
  halGpio->setPin(15);
  actual = halGpio->getPin();
  expected = ((uint16_t)0x8000);
  TEST_ASSERT_EQUAL_HEX16(expected, actual);
}
void test_should_set_as_input(void)
{
  uint16_t actual = 1;
  uint16_t expected = 0;
  halGpio->setPinAsInput(0);
  actual = halGpio->getMode();

  TEST_ASSERT_EQUAL_HEX16(expected, actual);
}
void test_should_set_as_output_default(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_set_as_output_mode(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_set_as_output_mode_alternative(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_set_as_output_pull_down_mode(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_set_as_output_pull_up_mode(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_return_true_when_pin_high(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_return_false_when_pin_down(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_return_true_when_pin_toogle(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_return_false_when_pin_toogle(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_not_configure_pull_mode_when_input(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_not_clean_outpul_signal_when_input(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_not_set_outpul_signal_when_input(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
void test_should_not_toggle_outpul_signal_when_input(void)
{
  bool actual = false;
  bool expected = true;
  TEST_ASSERT_EQUAL_INT(expected, actual);
}
int runUnityTests(void)
{
  UNITY_BEGIN();
  // Unit Tests
  RUN_TEST(test_should_initialize);
  RUN_TEST(test_should_set_pin);
  RUN_TEST(test_should_set_as_input);
  RUN_TEST(test_should_set_as_output_default);
  RUN_TEST(test_should_set_as_output_mode);
  RUN_TEST(test_should_set_as_output_mode_alternative);
  RUN_TEST(test_should_set_as_output_pull_down_mode);
  RUN_TEST(test_should_set_as_output_pull_up_mode);
  RUN_TEST(test_should_return_true_when_pin_high);
  RUN_TEST(test_should_return_false_when_pin_down);
  RUN_TEST(test_should_return_true_when_pin_toogle);
  RUN_TEST(test_should_return_false_when_pin_toogle);
  // Functional Tests
  RUN_TEST(test_should_not_configure_pull_mode_when_input);
  RUN_TEST(test_should_not_clean_outpul_signal_when_input);
  RUN_TEST(test_should_not_set_outpul_signal_when_input);
  RUN_TEST(test_should_not_toggle_outpul_signal_when_input);
  RUN_TEST(test_dumpTrue_should_return_true);
  RUN_TEST(test_dumpFalse_should_return_false);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{             // set stuff up here
  HAL_Init(); // initialize the HAL library
  /* Configure the system clock */
  SystemClock_Config();

  HAL_Delay(2000); // service delay
  runUnityTests();

  while (1)
  {
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
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
    // Error_Handler();
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
    // Error_Handler();
  }
}