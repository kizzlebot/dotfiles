Vim�UnDo� �.�m����|H����9���[	��7���e   2    */                             S)�    _�                             ����                                                                                                                                                                                                                                                                                                                                                             S&�    �   <   >   >      	LCDSeg[6] = characters[cnt];�   ;   =   >      	LCDSeg[5] = characters[cnt];�   :   <   >      	LCDSeg[4] = characters[cnt];�   9   ;   >      	LCDSeg[3] = characters[cnt];�   8   :   >      	LCDSeg[2] = characters[cnt];�   7   9   >      	LCDSeg[1] = characters[cnt];�   6   8   >      	LCDSeg[0] = characters[cnt];�   5   7   >      2	P2OUT ^= GREEN; // Toggle P1.0 using exclusive-OR�   -   /   >      @	__bis_SR_register(LPM0 + GIE);  // LPM0 with interrupts enabled�   ,   .   >      	__enable_interrupt();�   *   ,   >      	Init_LCD();�   )   +   >      H	P2DIR |= GREEN+ORANGE; 			// Set Px as output to be able to turn on LED�   (   *   >      G	TACCR0 = 0x7FFF ;				// TACCR0 is the upper limit of the timer = 32768�   '   )   >      9	TACTL = TASSEL_1 + MC_1; 		// [timerA -> ACLK][MODE: UP]�   &   (   >      (	CCTL0 = CCIE;					// Set up Timer+Clock�   %   '   >      	// Clock Set up�   #   %   >      3	WDTCTL = WDTPW + WDTHOLD; 		// Stop watchdog timer�   !   #   >      )	volatile unsigned int i; 		// <Volatile>�       "   >      )	volatile unsigned char a;		// <Volatile>�         >      b * 	   count every tenth of a second if SW1 is pressed and begin counting down when SW2 is pressed�         >      [ * 	4. Write a C-language program that counts up from 0 to 999 in decimal and displays this�         >      G * 	   Program should count up from 0 to F and then repeat indefinitely�         >      U * 	3. Write a C-language program that cna display the numbers 0 - 9 and Letters A-F.�         >       * 	   seven segment display.�         >      O * 	2. Write program to display the number 2 ( segments abdeg ) on the leftmost�         >       * 	   seven segment display.�         >      P * 	1. Write program to display the number 2 ( segments abdeg ) on the rightmost5�_�                       
    ����                                                                                                                                                                                                                                                                                                                                                             S'{�    �         >      #include "LCD_Ctrl.h"5�_�                            ����                                                                                                                                                                                                                                                                                                                                                 V       S)�     �                // Lab 4 - Part A2   // Not so sure    5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        S)�     �                 5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        S)�     �                 5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        S)�     �   
             P *  1. Write program to display the number 2 ( segments abdeg ) on the rightmost    *     seven segment display.5�_�                            ����                                                                                                                                                                                                                                                                                                                                                V       S)�     �                U *  3. Write a C-language program that cna display the numbers 0 - 9 and Letters A-F.   G *     Program should count up from 0 to F and then repeat indefinitely   [ *  4. Write a C-language program that counts up from 0 to 999 in decimal and displays this   b *     count every tenth of a second if SW1 is pressed and begin counting down when SW2 is pressed5�_�                            ����                                                                                                                                                                                                                                                                                                                                                V       S)�    �         3       *     seven segment display.   */�         3       */5��