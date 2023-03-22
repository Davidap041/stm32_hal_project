#include "unity.h"
#include "add_test.hpp"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void)
{
    TEST_ASSERT_EQUAL_INT32(4, add(1, 3));
}

void test_function_should_doAlsoDoBlah(void)
{
    TEST_ASSERT_EQUAL_INT32(4, add(3, 1));
}

int runUnityTests(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
int main(void)
{
    return runUnityTests();
}
