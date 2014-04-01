Vim�UnDo� ��ܒ��ss��c�)v{MrU��09�ؚlE   q   #pragma vector = TIMERA1_VECTOR   d                          SF.    _�                             ����                                                                                                                                                                                                                                                                                                                                                  V        SEK     �                 /**   \file   launchpad.c   D\brief  TI LaunchPad hardware-specific functions and device drivers.       ;Copyright (c) 2011-2012 by Gene Kozin <gkozin(at)yahoo.com>       HThis code is licensed under a Creative Commons Attribution NonCommercial   LShareAlike 3.0 Unported License (CC BY-NC-SA 3.0). For terms and confitions,   please retef to:   5    http://creativecommons.org/licenses/by-nc-sa/3.0/       6The following diagram shows the MSP430 pin assignment:                 MSP430G2231           +------------+   !        |       P1.0 |--> Red LED   "        |       P1.1 |--> UART TxD   "        | CCI1A/P1.2 |<-- UART RxD   %        |       P1.3 |<-- Push Button   #        |       P1.6 |--> Green LED           +------------+   */5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        SEL    �                  5�_�                            ����                                                                                                                                                                                                                                                                                                                                                V       SEg     �                /**   $\brief  Initializes system hardware.   **/5�_�                            ����                                                                                                                                                                                                                                                                                                                                                V       SEq     �         t      void sys_init(void)   {�         t      {5�_�                            ����                                                                                                                                                                                                                                                                                                                                                V       SE�    �         s    5�_�                    .        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   1   3          **/�   0   2          9600 bps Baud rate.�   /   1          Jbeen transmitted. For example, it takes 1.04 ms to transmit a character at�   .   0          HThis is a blocking function. It will not return untill the character has�   -   /          3\brief  Transmits a single character using Timer_A.5�_�                    .       ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   -   /   t      5  \brief  Transmits a single character using Timer_A.5�_�      	              4        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   2   4   t      void sys_putch(char c)   {�   3   5   t      {5�_�      
           	   S        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   R   T   s      <\brief  Suspend execution for a specified number of seconds.5�_�   	              
   g        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   e   g   s      "__interrupt void timerA1_isr(void)   {�   f   h   s      {5�_�   
                 c        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�    �   b   d   r      4\brief  Timer_A1 interrupt handler: System heartbeat5�_�                    c        ����                                                                                                                                                                                                                                                                                                                            -           2           V        SE�     �   b   d          3brief  Timer_A1 interrupt handler: System heartbeat5�_�                    V        ����                                                                                                                                                                                                                                                                                                                            3           P           V        SE�    �   T   V   r      void sys_sleep(unsigned s)   {�   U   W   r      {5�_�                    d       ����                                                                                                                                                                                                                                                                                                                            U           _           V        SF'     �   c   e   q      #pragma vector = TIMERA1_VECTOR5�_�                     d       ����                                                                                                                                                                                                                                                                                                                            U           _           V        SF-    5��