#include "LabRatUtils.h"

void Hault()
{
	SetMotorSpeed(B_MOT, STOP, 0); 
	for(int i=0; i < 10; i++)
	{
		SetLED(ON);
		_delay_ms(250);
		SetLED(OFF);
		_delay_ms(250);
		SetLED(ON);
		_delay_ms(250);
		SetLED(OFF);
		_delay_ms(250);
	}
}
	
void ForwardFull()
{
	SetMotorSpeed(L_MOT, FWD, 255);
	SetMotorSpeed(R_MOT, FWD, 255);
}

void ForwardHalf()
{
	SetMotorSpeed(L_MOT, FWD, 145);
	SetMotorSpeed(R_MOT, FWD, 128);
}

int main(void)
{
	//char dx, dy;
	//char lb = 0, rb = 0;
	unsigned int CIRT = 900;
	unsigned int LIRT = 910;
	unsigned int RIRT = 940;
	init();
	initADC();
	//initOptSensor();
	InitMotorPWM();
	SetMotorSpeed(B_MOT, STOP, 0);
	initXBee(XBEE_2X, 25);
	for(;;)
	{
		// Bumpers
		
		if(bit_is_clear(PINC, PC6) && bit_is_clear(PINC, PC7)) 
		{ 
			Hault();
		}

		if(bit_is_clear(PINC, PC6)) 
		{
			printAllXBee("Left Bumper\0", 0);

			SetLED(ON);
			SetMotor(B_MOT, REV);
			_delay_ms(1250);
			SetMotor(L_MOT, FWD);
			_delay_ms(1000);
		}

		if(bit_is_clear(PINC, PC7)) 
		{
			printAllXBee("Right Bumper\0", 0);
			
			SetLED(ON);
			SetMotor(B_MOT, REV);
			_delay_ms(1250);
			SetMotor(R_MOT, FWD);
			_delay_ms(1000);
		}
		
		
		//printAllXBee("lir: %d     cir: %d     rir: %d    \0", getADC(2), getADC(1), getADC(0));
		
		if (getADC(1) < CIRT)
		{
			SetLED(ON);
			if (getADC(0) < RIRT)
			{
				SetMotor(B_MOT, REV);
				_delay_ms(500);
				SetMotor(R_MOT, FWD);
				_delay_ms(1000);
			}
			else if (getADC(2) < LIRT)
			{
				SetMotor(B_MOT, REV);
				_delay_ms(500);
				SetMotor(L_MOT, FWD);
				_delay_ms(1000);
			}
			else 
			{
				SetMotor(B_MOT, REV);
				_delay_ms(500);
				SetMotor(L_MOT, FWD);
				_delay_ms(1000);
			}
		}


		else if (getADC(0) < RIRT)
		{
			SetLED(ON);
			SetMotorSpeed(R_MOT, FWD, 120 );
			SetMotorSpeed(L_MOT, REV, 250 );
			_delay_ms(1250);
		}
		else if (getADC(2) < LIRT)
		{
			SetLED(ON);
			SetMotorSpeed(L_MOT, FWD, 120 );
			SetMotorSpeed(R_MOT, REV, 250 );
			_delay_ms(1250);
		}

		if (!bit_is_clear(PINC, PC6) && 
			!bit_is_clear(PINC, PC7) &&
			!(getADC(0) < RIRT) &&
			!(getADC(1) < CIRT) &&
			!(getADC(2) < LIRT)) 
		{ 
			SetLED(OFF);
			ForwardFull();
		}


	
	}
        return(0);
}
// vim:set ts=4 sts=4 sw=4 et
