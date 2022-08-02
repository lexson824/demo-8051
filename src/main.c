#include <8052.h>
#include <string.h>
#include <stdlib.h>
#include "serial.h"
#include "timer.h"

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
    init_timer();
    EA = 1;

    unsigned char msg[16] = {0};

    for (;;) {
        memset(msg, 0, sizeof(msg));
        int len = recv_serial(msg, sizeof(msg));
        if (len) {
            send_serial("echo: ", 6);
            send_serial(msg, len);
            send_serial("\r\n", 2);
        }
        delay(100);
    }
}
