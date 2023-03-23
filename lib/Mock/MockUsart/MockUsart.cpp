#include "MockUsart.hpp"

bool MockUsart::setBaudRate(int baudRate)
{
    if (baudRate > 0 && baudRate < MAX_BAUD_RATE + 1)
    {
        this->baudRate = baudRate;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool MockUsart::setPins(int rx, int tx)
{
    if (rx > 0 && tx > 0)
    {
        this->pinRX = rx;
        this->pinTX = tx;
        return 1;
    }
    else
    {
        return 0;
    }
}

MockUsart::MockUsart()
{
}

MockUsart::~MockUsart()
{
}

bool MockUsart::begin()
{
    return true;
}

bool MockUsart::begin(int baudRate)
{
    bool status = this->setBaudRate(baudRate);
    return status;
}

bool MockUsart::begin(int rx, int tx)
{
    return this->setPins(rx, tx);
}

bool MockUsart::begin(int rx, int tx, int baudRate)
{
    bool sucess = true;
    if (!setBaudRate(baudRate))
        sucess = false;
    if (!setPins(rx, tx))
        sucess = false;
    return sucess;
}

int MockUsart::dumpImplementation() const
{
    return 0;
}
