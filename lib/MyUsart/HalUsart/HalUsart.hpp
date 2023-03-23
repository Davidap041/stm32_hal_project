#include "MyUsart.hpp"
class HalUsart : public MyUsart
{
private:
    /* data */
public:
    HalUsart(/* args */);
    ~HalUsart();
    int dumpImplementation() const override;
};

