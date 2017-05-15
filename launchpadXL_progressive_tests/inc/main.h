/*
 * main.h
 *
 *  Created on: May 9, 2017
 *      Author: matteo
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_




void MyGpioSetup(void);
void MyISRSetup(void);
void MyXINTSetup(void);
void MySCIASetup(void);
void MySCICSetup(void);
void SCIAFifoInit(void);
void SCIAXmit(int a);
void SCIASendMsg(char * msg);
void SCICFifoInit(void);
void SCICXmit(int a);
void SCICSendMsg(char * msg);
void copyMsg(char * msg);
void msgDecoder(char *msg);
//char* concat(char *msg1, int len1, char *msg2, int len2);

// function that are redefined here, the ISR routine is forced to look for them in the main file
interrupt void xint1_isr(void);
interrupt void sciaRX_isr(void);
interrupt void sciaTX_isr(void);
interrupt void scicRX_isr(void);
interrupt void scicTX_isr(void);
//interrupt void scic_isr(void);


#endif /* INC_MAIN_H_ */
