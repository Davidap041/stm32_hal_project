#include <unity.h>
#include <myUsart.hpp>

MyUsart *myUsart;

void setUp(void)
{
  // set stuff up here
  myUsart = new MyUsart();
}

void tearDown(void)
{
  // clean stuff up here
  delete myUsart;
}

void test_initialize_usart_object(void)
{
  bool actual;
  int expected = true;
  // test stuff
  if (myUsart)
  {
    actual = true;
  }
  else
  {
    actual = false;
  }

  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_initialize_usart_object);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{
  return runUnityTests();
}
