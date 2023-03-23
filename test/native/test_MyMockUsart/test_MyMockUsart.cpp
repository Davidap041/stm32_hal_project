#include <unity.h>
#include <MockUsart/MockUsart.hpp>

MockUsart mockUsart;

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_initialize_usart_begin(void)
{
  bool actual;
  int expected = true;
  // test stuff
  actual = mockUsart.begin();

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
void test_initialize_usart_begin_baud_rate(void)
{
  int expected = true;
  bool actual;
  // test stuff
  actual = mockUsart.begin(115200);

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
void test_initialize_usart_begin_custom_pin(void)
{
  bool actual;
  int expected = true;
  // test stuff
  actual = mockUsart.begin(115200);

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
void test_initialize_usart_begin_custom_pin_and_baudrate(void)
{
  bool actual;
  int expected = true;
  // test stuff
  actual = mockUsart.begin(9, 10, 115200);

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void test_dump_mock_implementation()
{
  bool actual;
  int expected = false;
  // test stuff

  actual = mockUsart.dumpImplementation();

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_dump_mock_implementation);
  RUN_TEST(test_initialize_usart_begin);
  RUN_TEST(test_initialize_usart_begin_baud_rate);
  RUN_TEST(test_initialize_usart_begin_custom_pin);
  RUN_TEST(test_initialize_usart_begin_custom_pin_and_baudrate);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{
  return runUnityTests();
}
