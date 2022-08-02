
int recv_serial(unsigned char *buffer, int len);
void send_serial(unsigned char *msg, int len);
void usart_interrupt(void) __interrupt 4;
void init_serial(void);
