/*
 * main.c
 *
 *  Created on: May 9, 2017
 *      Author: matteo
 */

#include "F28x_Project.h"
#include "main.h"

////////////////////////////////////////////////////////////////////////////////
//
//
//
//  This firmware setup SCIA and SCIC and decodes commands from SCIC RX
//  calling decodeMsg(msg), the commands come from another external UART
//  The commands are then echoed back through SCIA TX to a serial terminal
//  on a pc via the usb host XDS100v2 onboard the LAUNCHXL F28377s
//
//
//
////////////////////////////////////////////////////////////////////////////////



#ifdef _LAUNCHXL_F28377S
#define _LED_GPIO    12
#else
#define _LED_GPIO    28
#endif

union {
   float f;
   int i;
   char c[4];
} c2f;

char receivedMsgA[16] = {0};
char receivedMsgC[16] = {0};
char line[16];
char *msg;


void main(void){


    //Always initialize the system with this func (PLL, WatchDog, enable Peripheral Clocks)
    InitSysCtrl();
    //MANTIENI QUESTO ORDINE DI AVVIO DELLE PERIFERICHE E INTERRUPT
    MyGpioSetup();
    MyISRSetup();
    MyXINTSetup();
    SCIAFifoInit();
    MySCIASetup();
    MySCICSetup();
    SCICFifoInit();

    //THE SYSTEM IS UNDER TESTS it should read from SCIC and echo from SCIA and also change behavior
    //on ctrl messages from both SCIC and SCIA
    //To write messages to the pc use SCIA
    //To write messages to other boards use SCIC


    msg = "\r\n\n\nHello World!\0";
    SCIASendMsg(msg);

    msg = "\r\nYou will enter a character, and the DSP will echo it back! \n\0";
    SCIASendMsg(msg);

    msg = "\r\nEnter a message: \0";
    SCIASendMsg(msg);


    while(1){

//        while(SciaRegs.SCIFFRX.bit.RXFFST == 0) {
//            if(ScicRegs.SCIFFRX.bit.RXFFST == 0){
//                //LED D9 blinks if the system is in IDLE waiting for an input from the user
//                GPIO_WritePin(_LED_GPIO, 0);
//                DELAY_US(200*500);
//                GPIO_WritePin(_LED_GPIO, 1);
//                DELAY_US(200*500);
//            }else {
//                ReceivedChar = ScicRegs.SCIRXBUF.all;
//                //I send back to the pc what I receive from the loop
//                msg = "  You sent: \0";
//                SCIASendMsg(msg);
//                SCIAXmit(ReceivedChar);
//            }
//        }
//
//        ReceivedChar = SciaRegs.SCIRXBUF.all;
//
//        //What i receive from the pc I send with the SCIC which is in loopback mode
//        SCICXmit(ReceivedChar);

//            GPIO_WritePin(_LED_GPIO, 0);
//            DELAY_US(200*500);
//            GPIO_WritePin(_LED_GPIO, 1);
//            DELAY_US(200*500);


    }

}

//SCIA is used on GPIO84 GPIO85 to communicate with the pc over the usb port

void MySCIASetup(void){

        //
        // Note: Clocks were turned on to the SCIA peripheral
        // in the InitSysCtrl() function
        //

        SciaRegs.SCICCR.all = 0x0007;   // 1 stop bit,  No loopback
                                        // No parity,8 char bits,
                                        // async mode, idle-line protocol
        SciaRegs.SCICTL1.all = 0x0003;  // enable TX, RX, internal SCICLK,
                                        // Disable RX ERR, SLEEP, TXWAKE
        SciaRegs.SCICTL2.all = 0x0003;
        SciaRegs.SCICTL2.bit.TXINTENA = 1;
        SciaRegs.SCICTL2.bit.RXBKINTENA = 1;
        //
        // SCIA at 9600 baud
        // @LSPCLK = 50 MHz (200 MHz SYSCLK) HBAUD = 0x02 and LBAUD = 0x8B.
        // @LSPCLK = 30 MHz (120 MHz SYSCLK) HBAUD = 0x01 and LBAUD = 0x86.
        // @LSPCLK = 25 MHz (100 MHz SYSCLK) HBAUD = 0x01 and LBAUD = 0x45
        // @LSPCLK = 50 MHZ (200 MHZ SYSCLK) SCIA @ 115200 HBAUD = 0x00 and LBAUD = 0x35.
        // @LSPCLK = 50 MHZ (200 MHZ SYSCLK) SCIA @ 9600 HBAUD = 0x02 and LBAUD = 0x8B.

        SciaRegs.SCIHBAUD.all    =0x02;
        SciaRegs.SCILBAUD.all    =0x8B;

        SciaRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset

}

//SCIC is used on GPIO89 GPIO90 to communicate with other systems
//////////////////////////////////////////////////////////////////
//                                                              //
//                                                              //
//             NO LOOPBACK ENABLED FOR TEST!!                   //
//                                                              //
//                                                              //
//////////////////////////////////////////////////////////////////


void MySCICSetup(void){

        //
        // Note: Clocks were turned on to the SCIC peripheral
        // in the InitSysCtrl() function
        //

        ScicRegs.SCICCR.all = 0x0007;   // 1 stop bit,  No loopback
                                        // No parity,8 char bits,
                                        // async mode, idle-line protocol
        ScicRegs.SCICTL1.all = 0x0003;  // enable TX, RX, internal SCICLK,
                                        // Disable RX ERR, SLEEP, TXWAKE
        ScicRegs.SCICTL2.all = 0x3;
        ScicRegs.SCICTL2.bit.TXINTENA = 1;
        ScicRegs.SCICTL2.bit.RXBKINTENA = 1;

        //
        // SCIC at 9600 baud
        // @LSPCLK = 50 MHz (200 MHz SYSCLK) HBAUD = 0x02 and LBAUD = 0x8B.
        // @LSPCLK = 30 MHz (120 MHz SYSCLK) HBAUD = 0x01 and LBAUD = 0x86.
        // @LSPCLK = 25 MHz (100 MHz SYSCLK) HBAUD = 0x01 and LBAUD = 0x45
        // @LSPCLK = 50 MHZ (200 MHZ SYSCLK) SCIC @ 115200 HBAUD = 0x00 and LBAUD = 0x35.
        // @LSPCLK = 50 MHZ (200 MHZ SYSCLK) SCIC @ 9600 HBAUD = 0x02 and LBAUD = 0x8B.

        ScicRegs.SCIHBAUD.all    =0x02;
        ScicRegs.SCILBAUD.all    =0x8B;



//        ScicRegs.SCICCR.bit.LOOPBKENA = 1; // Enable loop back
        ScicRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset
}


//Initialize the SCI FIFO

void SCIAFifoInit(void){

//DO NOT TOUCH SCIFFTX!!!
//    SciaRegs.SCIFFTX.all = 0xC065;
    SciaRegs.SCIFFTX.all = 0xE065; //WORKING INTERRUPT TRIGGER FOR FIFO WITH AT LEAST TWO POS FILL
//    SciaRegs.SCIFFTX.all = 0xE042; // FOR INTERRUPT TRIGGER WITH FIFO LESS THAN 2 POS
//IT SHOULD BE SET TO GIVE INTERRUPT WHEN THE FIFO IS FULL
    SciaRegs.SCIFFRX.all = 0xE06F;
    SciaRegs.SCIFFCT.all = 0x0;

}

//Write a single character in the output buffer

void SCIAXmit(int a){

    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}

        SciaRegs.SCITXBUF.bit.TXDT =a;
}

//Write a message (several characters) in the output buffer through SCIxXmit

void SCIASendMsg(char * msg){

    int i;
//    SciaRegs.SCIFFTX.bit.TXFIFORESET =1;  // enable TXFIFO
        i = 0;
        while(msg[i] != '\0')
        {
            SCIAXmit(msg[i]);
            i++;
        }

//        SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1 ;  // force TX-ISR
}



void SCICFifoInit(void){
    //The transmit FIFO can resume transmit or receive
    ScicRegs.SCIFFTX.all = 0xE065;
    //For receive FIFO sets that is calling interrupt whenever the FIFO has 16 words (byte)
    ScicRegs.SCIFFRX.all = 0xE06F;
    ScicRegs.SCIFFCT.all = 0x0;

}
void SCICXmit(int a){

    while (ScicRegs.SCIFFTX.bit.TXFFST != 0) {}
        ScicRegs.SCITXBUF.all =a;
}
void SCICSendMsg(char * msg){

    int i;
        i = 0;
        while(msg[i] != '\0')
        {
            SCICXmit(msg[i]);
            i++;
        }

}

interrupt void xint1_isr(void){
    int i;
    //if(GpioDataRegs.GPADAT.bit.GPIO12 == 1) GPIO_WritePin(_LED_GPIO, 0);
    for (i = 0; i<10;i++){
        GPIO_WritePin(_LED_GPIO, 0);
                        DELAY_US(1000*500);
                        GPIO_WritePin(_LED_GPIO, 1);
                        DELAY_US(1000*500);
    }
    // Acknowledge this interrupt to get more from group 1
    //
    //PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

interrupt void sciaRX_isr(void){
    //The FIFO is set to be full after 16 words
    int  i;
    int msgLen = SciaRegs.SCIFFRX.bit.RXFFIL;

    for(i=0;i<msgLen;i++) {
        receivedMsgA[i] = SciaRegs.SCIRXBUF.bit.SAR;
    }
//    msgDecoder(receivedMsgA);
    SciaRegs.SCIFFRX.bit.RXFIFORESET = 0;
    SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;
    SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;
    SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;


    for(i=0;i<msgLen;i++) {
       ScicRegs.SCITXBUF.bit.TXDT= receivedMsgC[i];
       receivedMsgA[i]=0;
       line[i]=0;
    }
    // Acknowledge this interrupt to get more from group 9
        //
        PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;


}

interrupt void sciaTX_isr(void){
    //For the configuration of the SCIFFTX reg, this interrupt is triggered when the SCIFFTXBUF
    //is less than or equal 5
    unsigned int i;

    // copy 16 character into SCI-A TX buffer

    for(i=0;i<16;i++) SciaRegs.SCITXBUF.all= receivedMsgA[i]; //SCITXBUF.bit.TXDT

    // Acknowledge this interrupt to receive more interrupts from group 9

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

interrupt void scicRX_isr(void){
    //The FIFO is set to be full after 16 words
        int  i;
        int msgLen = ScicRegs.SCIFFRX.bit.RXFFIL;

        for(i=0;i<msgLen;i++) {
            receivedMsgC[i] = ScicRegs.SCIRXBUF.bit.SAR;
        }
        msgDecoder(receivedMsgC);
        ScicRegs.SCIFFRX.bit.RXFIFORESET = 0;
        ScicRegs.SCIFFRX.bit.RXFIFORESET = 1;
        ScicRegs.SCIFFRX.bit.RXFFOVRCLR = 1;
        ScicRegs.SCIFFRX.bit.RXFFINTCLR = 1;


        for(i=0;i<msgLen;i++) {
    //        SciaRegs.SCITXBUF.bit.TXDT= receivedMsg[i];
           receivedMsgC[i]=0;
           line[i]=0;
        }
        // Acknowledge this interrupt to get more from group 9
            //
            PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

}

interrupt void scicTX_isr(void){
    //For the configuration of the SCIFFTX reg, this interrupt is triggered when the SCIFFTXBUF
    //is less than or equal 5
    unsigned int i;

    // copy 16 character into SCI-C TX buffer

    for(i=0;i<16;i++) ScicRegs.SCITXBUF.all= receivedMsgC[i]; //SCITXBUF.bit.TXDT

    // Acknowledge this interrupt to receive more interrupts from group 9

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;}

void MyGpioSetup(void){

    //To be sure that all the unused pins are initialized in a known default state
    InitGpio();

    //I use as input P71 that is PORT C GPIO6
    EALLOW;
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO71 = 0; //pin as input
    //When a pin is used as input is needed to provide a qualification and sampling freq, for XINT1
    //the only admitted sampling freq is SYSCLCK
    GpioCtrlRegs.GPCQSEL1.bit.GPIO71 = 0;

    //Enabling SCI A for pc communication via XDS100_v2 and SCI C for external uart communication
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 1;
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 1;
    GpioCtrlRegs.GPCGMUX2.bit.GPIO84 = 1;
    GpioCtrlRegs.GPCGMUX2.bit.GPIO85 = 1;
    GpioCtrlRegs.GPCMUX2.bit.GPIO90 = 2;        //SCI C RX to connect to Beaglebone's TX
    GpioCtrlRegs.GPCMUX2.bit.GPIO89 = 2;        //SCI C TX to connect to Beaglebone's RX
    GpioCtrlRegs.GPCGMUX2.bit.GPIO90 = 1;
    GpioCtrlRegs.GPCGMUX2.bit.GPIO89 = 1;

    EDIS;

    GPIO_SetupXINT1Gpio(71);

    GPIO_SetupPinOptions(_LED_GPIO, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(_LED_GPIO, GPIO_MUX_CPU1, 0);
    GPIO_WritePin(_LED_GPIO, 1);

}

void msgDecoder(char *inmsg){
    int i = 0;

    if(inmsg[0] == '\xff'){
        SCIASendMsg("\r\n OverFlow Occurred, pay attention to send maximum 16 bytes in a row\r\n");
    }else{
        if(inmsg[0] == 'D'){
            while(inmsg[i] != '\0' && i<3){
                c2f.c[i] = inmsg[i+1];
                i++;
            }
            SCIASendMsg("\r\n Float received :\r\n");
            strncat(line, c2f.c, 5);
            strncat(line, "\r\n\0", 5);
            SCIASendMsg(line);
            return;
        }
        else if(inmsg[0] == 'C'){
            SCIASendMsg("\r\n Command received :\r\n");
            SCIASendMsg(inmsg);
            c2f.i = strcmp(inmsg,"CRESET\0");
            SCIASendMsg(c2f.c);
            if(!strncmp(inmsg,"COFF\0",4)){
                SCIASendMsg("\r\nOFF\r\n\0");
            }
            else if(!strncmp(inmsg,"CON\0",3)){
                SCIASendMsg("\r\nON\r\n\0");
            }
            else if(!strncmp(inmsg,"CDEMO\0",5)){
                SCIASendMsg("\r\nDEMO\r\n\0");
            }
            else if(!strncmp(inmsg,"CRESET\0",6)){
                SCIASendMsg("\r\nRESET\r\n\0");
            }
            else{
                SCIASendMsg("\r\nNot able to recognize command\r\n\0");
            }

        }else {
            SCIASendMsg("\r\n Invalid format arrived\r\n\0");
        }
    }



}

void MyISRSetup(void){
    // Here we are going to initialize the PIE vectors, XBAR periph for muxing the GPIO pins to XINT

    //Disable all the interrupts for now
    DINT;
    //Initialize all the PIE registers to default state
    InitPieCtrl();
    //disable and clear CPU interrupts
    IER = 0x0000;
    IFR = 0x0000;
    //initialize all the PIE vectors to default state
    InitPieVectTable();
    //
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    //
    EALLOW;  // This is needed to write to EALLOW protected registers
    //PieVectTable.XINT1_INT = &xint1_isr;
    PieVectTable.SCIA_RX_INT = &sciaRX_isr;
    PieVectTable.SCIA_TX_INT = &sciaTX_isr;
    PieVectTable.SCIC_RX_INT = &scicRX_isr;
    PieVectTable.SCIC_TX_INT = &scicTX_isr;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    //
    //Here we initialize the registers to enable XINT1, SCIATX-RX and SCICTX-RX
    //
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    //PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
    PieCtrlRegs.PIEIER9.bit.INTx2 = 1;          // Enable the PIE for SCI A TX & RX
    PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
    PieCtrlRegs.PIEIER8.bit.INTx5 = 1;          // Enable the PIE for SCI C TX & RX
    PieCtrlRegs.PIEIER8.bit.INTx6 = 1;
    IER |= M_INT9;                            // Enable CPU for INT9 in which are interrupts for both XINT1 and SCIA SCIC
    EINT;                                       // Enable Global Interrupts
}

void MyXINTSetup(void){
    //Here the external interrupt periph XINT1 is set and initialized

       XintRegs.XINT1CR.bit.POLARITY = 1;          // Rising edge interrupt
       XintRegs.XINT1CR.bit.ENABLE = 1;            // Enable XINT1

}

