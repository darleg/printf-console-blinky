#include "mbed.h"
#include "OnBoard.h"

//Creating a new RGB led object using PWM outputs
RGB AZRGB(RedRGB, GreenRGB, BlueRGB);

DigitalOut ledg(led1);
DigitalOut ledb(led2);
DigitalOut ledy(led3);

static BufferedSerial az(TX, RX);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &az;
}

int main()
{

    while (true) {
        printf("Toggle green  led1\r\n");
        AZRGB.RGBcolor(0.0,0.75,0.0); //green
        ledg = !ledg;
        ThisThread::sleep_for(delay200ms);
        printf("Toggle blue   led2\r\n");
        AZRGB.RGBcolor(0.0,0.0,0.75); //blue
        ledb = !ledb;
        ThisThread::sleep_for(delay200ms);
        printf("Toggle yellow led3\r\n");
        AZRGB.RGBcolor(0.75,0.75,0.0); //yellow
        ledy = !ledy;
        ThisThread::sleep_for(delay200ms);
    }
}
