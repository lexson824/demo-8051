#include <8052.h>
#include <string.h>
#include <stdlib.h>
#include "osc.h"
#include "serial.h"
#include "timer.h"

void delay(unsigned short ms)
{
    for (; ms > 0; ms--) {
        for (unsigned short i = MS_MACHINE_CYCLE_CNT / 12; i > 0; i--) {
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
        send_serial("idle-st...\r\n", 12);
        delay(2000);
        send_serial("idle-ed...\r\n", 12);
    }
}
