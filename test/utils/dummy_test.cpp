#include "CppUTest/TestHarness.h"
#include "HalGpio.hpp"
// create a test group
TEST_GROUP(dummy_test){

};

// create a test for that test group
TEST (dummy_test, pass_me){
    CHECK_EQUAL(1,1);
}

TEST (dummy_test, fail_me_not){
    CHECK_EQUAL(0,0);
}