#include "MyUsart.hpp"
class MockUsart : public MyUsart
{
private:
    /* data */
public:
    MockUsart(/* args */){};
    ~MockUsart(){};
    int dumpImplementation() const override;
};
