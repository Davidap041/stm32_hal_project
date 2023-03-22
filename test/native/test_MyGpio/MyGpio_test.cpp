#include <unity.h>
#include <MyGpio.hpp>

MyGpio *myGpio;

void setUp(void)
{
  // set stuff up here
  myGpio = new MyGpio();
}

void tearDown(void)
{
  // clean stuff up here
  delete myGpio;
}

void test_dumpTrue_should_return_true(void)
{
  // test stuff
  bool actual = myGpio->dumpTrue();
  int expected = true;
  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void test_dumpFalse_should_return_false(void)
{
  // more test stuff
  bool actual = myGpio->dumpFalse();
  int expected = false;
  TEST_ASSERT_EQUAL_INT32(expected, actual);
}

int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_dumpTrue_should_return_true);
  RUN_TEST(test_dumpFalse_should_return_false);
  return UNITY_END();
}
/**
 * For native dev-platform or for some embedded frameworks
 */
int main(void)
{
  return runUnityTests();
}
