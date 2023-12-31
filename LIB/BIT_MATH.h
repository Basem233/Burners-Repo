
/* File Gaurd by ifndef & endif */
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_POSITION)     REG |= (1<<BIT_POSITION)
#define CLEAR_BIT(REG,BIT_POSITION)   REG &= ~(1<<BIT_POSITION)
#define GET_BIT(REG,BIT_POSITION)     REG & (1<<BIT_POSITION)
#define TOGGLE_BIT(REG,BIT_POSITION)  REG ^= (1<<BIT_POSITION)

#endif