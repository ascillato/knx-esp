#include "knx/platform.h"
#include <ESP8266WiFi.h>
#include <WifiUDP.h>

class EspPlatform : public Platform
{
public:
    EspPlatform();

    // ip stuff
    uint32_t currentIpAddress();
    uint32_t currentSubnetMask();
    uint32_t currentDefaultGateway();
    void macAddress(uint8_t* addr);

    // basic stuff
    uint32_t millis();
    void mdelay(uint32_t millis);
    void restart();
    void fatalError();

    //multicast
    void setupMultiCast(uint32_t addr, uint16_t port);
    void closeMultiCast();
    bool sendBytes(uint8_t* buffer, uint16_t len);
    int readBytes(uint8_t* buffer, uint16_t maxLen);

    //memory
    uint8_t* getEepromBuffer(uint16_t size);
    void commitToEeprom();
private:
    uint32_t _mulitcastAddr;
    uint16_t _mulitcastPort;
    WiFiUDP _udp;
};

