#include <8052.h>
#include <string.h>
#include <stdlib.h>
#include "serial.h"

void delay(int us)
{
    for (int i = 0; i < us; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
            }
        }
    }
}

void setup()
{
    //PCON |= SMOD;
    //TMOD = 0b01000000;
    TMOD = 0x20;
    TL1 = 0xFD;
    TH1 = 0xFD;
    TR1 = 1;
    REN = 1;
    SM0 = 0;
    SM1 = 1;
    EA = 1;
    ES = 1;

    void *tt = malloc(100);
    free(tt);
}

void main()
{
    setup();

    unsigned char msg[16] = {0};

    for (;;) {
        send_serial("recv: ", 6);
        memset(msg, 0, sizeof(msg));
        int len = recv_serial(msg, sizeof(msg));
        send_serial(msg, len);
        send_serial("\r\n", 2);
        delay(100);
    }
}
