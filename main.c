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

void main()
{
    init_serial();

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
