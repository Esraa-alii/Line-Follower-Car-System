/*
 * DCMOTOR_interface.h
 *
 * Created: 10/2/2024 9:50:37 AM
 *  Author: Esraa Ali
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define FIRST_MOTOR_ID  1
#define SEC_MOTOR_ID    2


void DCMOTOR_voidCW(u8 id) ; 
void DCMOTOR_voidACW(u8 id) ;
void DCMOTOR_voidStop(u8 id) ;
void DCMOTOR_voidForward(void);
void DCMOTOR_voidBackword(void);
void DCMOTOR_voidRight(void);
void DCMOTOR_voidLeft (void);
void DCMOTOR_voidInit(void);





#endif /* DCMOTOR_INTERFACE_H_ */