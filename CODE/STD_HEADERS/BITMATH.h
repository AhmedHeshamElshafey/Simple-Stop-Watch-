/*
 * BITMATH.h
 *
 * Created: 18/09/2024 04:52:33 م
 *  Author: LENOVO
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define  SET_BIT(Reg,Bit)    ((Reg)=(1<<(Bit))|(Reg))
#define  CLEAR_BIT(Reg,Bit)  ((Reg)=(~(1<<(Bit)))&(Reg))
#define  READ_BIT(Reg,Bit)   (((Reg)>>(Bit))&1)
#define  TOGGLE_BIT(Reg,Bit) ((Reg)=(1<<(Bit))^(Reg))


#endif /* BITMATH_H_ */