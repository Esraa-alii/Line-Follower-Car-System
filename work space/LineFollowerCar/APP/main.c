/*
 * LineFollowerCar.c
 *
 * Created: 13/10/2024 16:19:47
 * Author : Esraa Ali
 */ 
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/DCMOTOR/DCMOTOR_interface.h"



int main(void)
{
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,INPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN1,INPUT);
	u8 IR1_value, IR2_value;
	DCMOTOR_voidInit();
	
    while (1) 
    {
		IR1_value = DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN0);
		IR2_value = DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN1);
		
		if(IR1_value == 0 && IR2_value == 0){
			DCMOTOR_voidStop(FIRST_MOTOR_ID);
			DCMOTOR_voidStop(SEC_MOTOR_ID);
		}
		else if( IR1_value == 1 && IR2_value == 0 ){
			DCMOTOR_voidRight();
		}
		else if( IR1_value == 0 && IR2_value == 1 ){
			DCMOTOR_voidLeft();
		}
		else if( IR1_value == 1 && IR2_value == 1 ){
			DCMOTOR_voidForward();
		}
    }
}

