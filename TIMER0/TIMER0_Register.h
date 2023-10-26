/*
 * TIMER0_Register.h
 *
 *  Created on: 26 Oct 2023
 *      Author: DELL
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

/********      [TIMER0] Registers       *********/
#define     TCCR0_REG        *((volatile u8*)0x53)     // Timer/Counter Control Register
#define     TCNT0_REG        *((volatile u8*)0x52)     // Timer/Counter Register
#define     OCR0_REG         *((volatile u8*)0x5C)     // Output Compare Register
#define     TIMSK_REG        *((volatile u8*)0x59)     // Timer/Counter Interrupt Mask Register
#define     TIFR_REG         *((volatile u8*)0x58)     // Timer/Counter Interrupt Flag Register
#define     SFIOR_REG        *((volatile u8*)0x50)     // Special Function IO Register
/*================================================================================================================*/

#endif /* TIMER0_REGISTER_H_ */
