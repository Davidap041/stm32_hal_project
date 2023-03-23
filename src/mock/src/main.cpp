#include <stdio.h>
#include <MyGpio.hpp>
#include <MockUsart/MockUsart.hpp>
MyGpio *myg;
MockUsart *mockUsart;

int main()
{
    myg = new MyGpio();
    mockUsart = new MockUsart();
    printf("Hello World from PlatformIO!\n");
    return 0;
}