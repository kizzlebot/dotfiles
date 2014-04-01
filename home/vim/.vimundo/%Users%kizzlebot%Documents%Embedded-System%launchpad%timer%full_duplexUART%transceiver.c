Vim�UnDo� ��e���돃��ؤ����{�=�Y\+�SZ   �   #include <calibrations.h>                             SE     _�                             ����                                                                                                                                                                                                                                                                                                                                                             SD�     �   �   �   �      	} // switch�   �   �   �      		default:	break;�   �   �   �      
				break;�   �   �   �      				}�   �   �   �      $					__low_power_mode_off_on_exit();�   �   �   �      A					P1IE |= P1RX;		// restart P1 interrupts to receive next byte�   �   �   �      -					P1IFG = 0;			// clear P1 interrupt flags�   �   �   �      .					UART_FG &= ~RXbit;	// Rx done, clear flag�   �   �   �      ?					command = (RXBuffer >> 1) & 0xff;	// extract received byte�   �   �   �      /					TACCTL1 = 0;		// turn off timer interrupts�   �   �   �      				if (--Rx_bit_count==0) {�   �   �   �      9					RXBuffer = RXBuffer >> 1;			// otherwise just shift.�   �   �   �      				else�   �   �   �      F					RXBuffer = (RXBuffer | 0x400) >> 1;	// if mark, set bit and shift�   �   �   �      				if (P1IN & P1RX)�   �   �   �      7		case 2:	TACCR1 += bit_time;						// set next bit time�   �   �   �      	switch(TAIV) {�   �   �   �      +    if (Tx_bit_count == 0) {	// Tx Complete�   �   �   �      	}�   �   �   �      				return;�   �   �   �      2	default:	P1IFG = 0;	// clear any other interrupts�   �   �   �      				return;�   �   �   �      #				__low_power_mode_off_on_exit();�   �   �   �      				command=0xaf;�   �   �   �      2	case BTN1:	P1IFG = 0;	// clear the interrupt flag�   �   �   �      				return;�   �   �   �      %				UART_FG |= RXbit;	// mark Rx flag�   �   �   �      +				Rx_bit_count = 10;	// reset bit counter�   �   �   �      (				RXBuffer = 0;	// clear the Rx buffer�   �   �   �      -				TACCTL1 = CCIE;	// enable CCR1 interrupts�   �   �   �      >				P1IE &= ~P1RX;	// disable further interrupts until Rx done�   �   �   �      +				P1IFG = 0;  // clear the interrupt flag�   �   �   �      (	case P1RX:	TACCR1 = TAR + halfbit_time;�   �   �   �      	switch(P1IFG & P1I_MASK) {�   �   �   �      	 tx_byte('\n');�   �   �   �      	 tx_byte('\r');�   �   �   �      		tx_byte(message[i]);�   �   �   �      	for (i=0; i<16; i++)�   �   �   �      	int i;�   �   �   �      N    __delay_cycles(bit_time);	// let byte start transmission before continuing�      �   �      5    TACCTL0 = RST;            	// reset for start bit�   ~   �   �      9    TACCR0 = TAR + bit_time;	// set trigger for first bit�   }      �      /    TACCTL0 &= ~CCIFG;			// clear interupt flag�   |   ~   �      )    Tx_bit_count--;				// count start bit�   z   |   �      N    TXBuffer = (byte | 0xff00);	// prepare byte for transmission: add stop bit�   p   r   �      ?    P1IE = P1RX + BTN1;	// enable P1 interrupt on P1RX and BTN1�   o   q   �      8    P1IFG = 0;		// clear interrupt flags before enabling�   n   p   �      P    P1IES = P1RX + BTN1;	// interrupt on falling edge (start bit is high -> low)�   m   o   �      -    P1SEL = P1TX;	// Set P1.1 to TA0.0 Output�   k   m   �      +    P1OUT = P1TX;	// default to mark (idle)�   P   R   �      	}	// main�   K   M   �      "            			tx_string(message);�   J   L   �      *            			message="Invalid Command!";�   I   K   �      G            default:    command='z';	// signal bad command, go to sleep�   H   J   �                   			break;			// sleep�   G   I   �      (            			_BIS_SR(LPM0_bits + GIE);�   F   H   �      "            			tx_string(message);�   D   F   �                  			break;�   C   E   �      "            			tx_string(message);�   B   D   �      1            case 'c':	message="Repeated Message";�   A   C   �                  			break;�   @   B   �      "            			tx_string(message);�   ?   A   �      *            			message="Button Pressed!!";�   >   @   �      #            case 0xaf:	command='z';�   <   >   �      "            			tx_string(message);�   ;   =   �      *            			message="Toggled Grn LED.";�   :   <   �                  			command='z';�   9   ;   �      6            case 'g':   P1OUT ^= LED2;	// toggle green�   7   9   �      "            			tx_string(message);�   6   8   �      *            			message="Toggled Red LED.";�   5   7   �                  			command='z';�   4   6   �      4            case 'r':   P1OUT ^= LED1;	// toggle red�   /   1   �      @    __delay_cycles(1474560);	// Delay 0.2 s to let clocks settle�   )   +   �      B    char *message;		// pointer to array to store messages to send.�      !   �      /char command='z';			// default command is sleep�          �      1char Rx_bit_count=10;		// bit counter for receive�         �      Hchar Tx_bit_count=10;  		// bit counter for transmission, 8N1 is 10 bits�         �      Cchar UART_FG=0;     		// flags for UART: BIT0 is TX in process flag�         �      9int RXBuffer;		// Buffer for storing current receive byte�         �      Eint TXBuffer;       		// Buffer for storing current transmission byte�         �      J#define P1I_MASK	BIT2 + BIT3			// Mask P1 interrupts to just P1.2 and P1.3�         �      ##define P1RX		BIT2				// Rx on P1.2�         �      /#define P1TX        BIT1        		// Tx on P1.1�         �      '#define BTN1		BIT3				// Button on P1.3�         �      0#define LED2        BIT6				// Green LED on P1.6�         �      .#define LED1        BIT0				// Red LED on P1.0�         �      :#define RXbit		BIT1				//        bit in UART_FG to show Rx�         �      ?#define TXbit       BIT0				// Define bit in UART_FG to show Tx�         �      <#define IDLE        OUTMOD_1			// Timer_A stops interrupting�         �      H#define RST        (OUTMOD_5 + CCIE)	// Timer_A resets on next interrupt�         �      F#define SET        (OUTMOD_1 + CCIE)	// Timer_A sets on next interrupt�         �      ,#define bit_time    768      			// 9600 baud5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �                 F/* uartTXCVRG2231.c: Full-duplex UART transceiver for the MSP430G2231.    *    *    *  ::  Copyright 2012, MSPSCI   " *  ::  http://mspsci.blogspot.com    *    */5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �                  5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �          �      #include <msp430g2231.h>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �          �      #include <msp430g2531.h>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �          �      #include <msp430g2551.h>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrations.h>5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibration.h>5�_�      
           	          ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationU3.h>5�_�   	              
          ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationU.h>5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationUh>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationU>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationU>5�_�                           ����                                                                                                                                                                                                                                                                                                                                                  V        SD�     �         �      #include <calibrationUART.h>5�_�                        	    ����                                                                                                                                                                                                                                                                                                                                                  V        SD�    �         �      #include <calibrationUART.h"5��