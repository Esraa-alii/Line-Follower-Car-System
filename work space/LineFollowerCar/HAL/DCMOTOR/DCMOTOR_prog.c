/*
 * DCMOTOR_prog.c
 *
 * Created: 10/2/2024 9:50:58 AM
 *  Author: Esraa ALI
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h" 
#include "../../MCAL/DIO/DIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"

void DCMOTOR_voidInit(void){
	#ifdef FIRST_MOTOR_ID
		DIO_voidSetPinDir(H_ENA_PORT,H_ENA_PIN,OUTPUT) ;
		DIO_voidSetPinDir(H_A1_PORT,H_A1_PIN,OUTPUT) ;
		DIO_voidSetPinDir(H_A2_PORT,H_A2_PIN,OUTPUT) ;
	#endif
	
	#ifdef SEC_MOTOR_ID
		DIO_voidSetPinDir(H_ENB_PORT,H_ENB_PIN,OUTPUT) ;
		DIO_voidSetPinDir(H_A3_PORT,H_A3_PIN,OUTPUT) ;
		DIO_voidSetPinDir(H_A4_PORT,H_A4_PIN,OUTPUT) ;
	#endif 
}
void DCMOTOR_voidCW(u8 id){
	
	
	if (id == FIRST_MOTOR_ID)
	{
		DIO_voidSetPinVal(H_ENA_PORT,H_ENA_PIN,HIGH) ; 
		DIO_voidSetPinVal(H_A1_PORT,H_A1_PIN,HIGH) ;
		DIO_voidSetPinVal(H_A2_PORT,H_A2_PIN,LOW) ;
	}
	else if(id==SEC_MOTOR_ID){
	DIO_voidSetPinVal(H_ENB_PORT,H_ENB_PIN,HIGH) ;
	DIO_voidSetPinVal(H_A3_PORT,H_A3_PIN,HIGH) ; 
	DIO_voidSetPinVal(H_A4_PORT,H_A4_PIN,LOW) ; 
	
	}
	}
void DCMOTOR_voidACW(u8 id){
	
	
	/*Drive motor cw */
	if (id == FIRST_MOTOR_ID)
	{
		DIO_voidSetPinVal(H_ENA_PORT,H_ENA_PIN,HIGH) ;
			DIO_voidSetPinVal(H_A1_PORT,H_A1_PIN,LOW) ;
			DIO_voidSetPinVal(H_A2_PORT,H_A2_PIN,HIGH) ;
	}
	else if(id == SEC_MOTOR_ID){
	DIO_voidSetPinVal(H_ENB_PORT,H_ENB_PIN,HIGH) ;
	DIO_voidSetPinVal(H_A3_PORT,H_A3_PIN,LOW) ;
	DIO_voidSetPinVal(H_A4_PORT,H_A4_PIN,HIGH) ;
	}
	}
	
void DCMOTOR_voidStop(u8 id){
	/*Drive motor cw */
	if (id ==FIRST_MOTOR_ID)
	{
		DIO_voidSetPinVal(H_ENA_PORT,H_ENA_PIN,LOW) ;
		 DIO_voidSetPinVal(H_A1_PORT,H_A1_PIN,LOW) ;
		 DIO_voidSetPinVal(H_A2_PORT,H_A2_PIN,LOW) ;
	}
	else if(id ==SEC_MOTOR_ID){
	DIO_voidSetPinVal(H_ENB_PORT,H_ENB_PIN,LOW) ;
	  DIO_voidSetPinVal(H_A3_PORT,H_A3_PIN,LOW) ;
	  DIO_voidSetPinVal(H_A4_PORT,H_A4_PIN,LOW) ;
	}
}


void DCMOTOR_voidForward(void){
	DCMOTOR_voidCW(FIRST_MOTOR_ID);
	DCMOTOR_voidCW(SEC_MOTOR_ID);
}
void DCMOTOR_voidBackword(void){
		DCMOTOR_voidACW(FIRST_MOTOR_ID);
		DCMOTOR_voidACW(SEC_MOTOR_ID);
}
void DCMOTOR_voidRight(void){
	DCMOTOR_voidCW(FIRST_MOTOR_ID);
	DCMOTOR_voidStop(SEC_MOTOR_ID);
}

void DCMOTOR_voidLeft(void){
	DCMOTOR_voidCW (SEC_MOTOR_ID);
	DCMOTOR_voidStop(FIRST_MOTOR_ID);
}