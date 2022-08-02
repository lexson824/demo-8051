#include <8052.h>
#include <string.h>
#include "serial.h"

void timer0_interrupt(void) __interrupt 1
{
    static int cnt = 0;
    TH0 = (65536 - 45872) / 256;
    TL0 = (65536 - 45872) % 256;
    cnt++;

    if (cnt >= 20) {
        unsigned char msg[] = "hello from timer0\r\n";
        send_serial(msg, strlen(msg));
        cnt = 0;
    }
}

void init_timer(void)
{
    TMOD = 0b00000001 + (TMOD & 0b11110000);
    TH0 = (65536 - 45872) / 256;
    TL0 = (65536 - 45872) % 256;
    TR0 = 1;
    ET0 = 1;
}
