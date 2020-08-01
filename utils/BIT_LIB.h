/*
 * BIT_LIB.h
 *
 *  Created on: 13 September, 2018
 *      Author: Amr Elzawawy
 */
#ifndef BIT_LIB
#define BIT_LIB

#define SET_BIT(byte, bit_no) ((byte) |= (1 << bit_no))
#define RESET_BIT(byte,bit_no) (byte &= ~(1<< bit_no))
#define GET_BIT(byte,bit_no) ((byte>>bit_no)& 1)
#define TOGGLE_BIT(byte,bit_no) (byte ^= (1<<bit_no))
#define ASSIGN_BIT(byte,bit_no,value)	byte = (byte & (~(1<<bit_no)))|(value<<bit_no)
#define concByteHelper(x7,x6,x5,x4,x3,x2,x1,x0) 0b##x7##x6##x5##x4##x3##x2##x1##x0
#define concByte(x7,x6,x5,x4,x3,x2,x1,x0) concByteHelper(x0,x1,x2,x3,x4,x5,x6,x7)


#endif
