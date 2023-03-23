#include <unity.h>
#include <HalUsart/HalUsart.hpp>

HalUsart* halUsart;

void setUp(void)
{
  // set stuff up here
  halUsart = new HalUsart();
}

void tearDown(void)
{
  // clean stuff up here
  delete halUsart;
}

void test_initialize_usart_object(void)
{
  bool actual;
  int expected = true;
  // test stuff
  if (halUsart)
  {
    actual = true;
  }
  else
  {
    actual = false;
  }

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
void test_dump_hal_implementation()
{
  bool actual;
  int expected = true;
  // test stuff
  actual = halUsart->dumpImplementation();

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_initialize_usart_object);
  RUN_TEST(test_dump_hal_implementation);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{
  return runUnityTests();
}
