#include <unity.h>
#include <MockUsart/MockUsart.hpp>

MockUsart* mockUsart;

void setUp(void)
{
  // set stuff up here
  mockUsart = new MockUsart();
}

void tearDown(void)
{
  // clean stuff up here
  delete mockUsart;
}

void test_initialize_usart_object(void)
{
  bool actual;
  int expected = true;
  // test stuff
  if (mockUsart)
  {
    actual = true;
  }
  else
  {
    actual = false;
  }

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
void test_dump_mock_implementation()
{
  bool actual;
  int expected = false;
  // test stuff
  actual = mockUsart->dumpImplementation();

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}
int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_initialize_usart_object);
  RUN_TEST(test_dump_mock_implementation);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{
  return runUnityTests();
}
