#include <8052.h>
#include <string.h>

int recv_idx = 0;
unsigned char recv_buffer[16] = "yon";

//int send_idx = 0;
//unsigned char send_buffer[32];

int recv_serial(unsigned char *buffer, int size)
{
    int retval = 0;
    ES = 0;
    if (size >= recv_idx) {
        memcpy(buffer, recv_buffer, recv_idx);
        retval = recv_idx;
        recv_idx = 0;
    } else {
        memcpy(buffer, recv_buffer, size);
        retval = size;
        recv_idx -= size;
        memmove(recv_buffer, recv_buffer + size, recv_idx);
    }
    ES = 1;
    return retval;
}

void send_serial(unsigned char *msg, int len)
{
    ES = 0;
    for (int i = 0; i < len; i++) {
        SBUF = msg[i];
        while (TI == 0)
            ;
        TI = 0;
    }
    ES = 1;
}

void usart_interrupt(void) __interrupt 4
{
    if (RI == 1) {
        if (recv_idx < sizeof(recv_buffer))
            recv_buffer[recv_idx++] = SBUF;
        else {
            unsigned char err[] = "recv buffer is full!\r\n";
            send_serial(err, strlen(err));
        }
        RI = 0;
    } else if (TI == 1) {
        TI = 0;
    }
}
