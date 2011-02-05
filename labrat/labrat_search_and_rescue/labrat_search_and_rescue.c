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

int Search(unsigned int lir, unsigned int cir, unsigned int rir)
{
	printAllXBee("lir: %d     cir: %d     rir: %d    \0", lir, cir, rir);
	
		if((cir < lir) && (cir < rir)) 
		{
			SetMotorSpeed(B_MOT, STOP, 255);
			printAllXBee("Target Ahead\0",0);
			return 1;
		}
		
		else if(lir < rir)
		{
			SetMotorSpeed(L_MOT, REV, 255);
			SetMotorSpeed(R_MOT, FWD, 255);
			printAllXBee("Target Left\0",0);
		}
		else
		{
			SetMotorSpeed(R_MOT, REV, 255);
			SetMotorSpeed(L_MOT, FWD, 255);
			printAllXBee("Target Right\0",0);
		}
		return 0;
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

void Stop()
{
	SetMotorSpeed(B_MOT, STOP, 0);
}


int main(void)
{	
	init();
	initADC();
	//initOptSensor();
	InitMotorPWM();
	SetMotorSpeed(B_MOT, STOP, 0);
	initXBee(XBEE_2X, 25);
	for(;;)
	{
		unsigned int lir, cir, rir;
		unsigned int liroffset = 10;
		unsigned int riroffset = 40;
		rir = getADC(0) - riroffset;
		cir = getADC(1);
		lir = getADC(2) - liroffset;
	
		if(bit_is_clear(PINC, PC6) && bit_is_clear(PINC, PC7)) 
		{ 
			Hault();
		}

		if(bit_is_clear(PINC, PC6)) 
		{
			printAllXBee("Left Bumper\0", 0);
			SetLED(ON);
			Stop();
		}

		if(bit_is_clear(PINC, PC7)) 
		{
			printAllXBee("Right Bumper\0", 0);
			SetLED(ON);
			Stop();
		}

		if (!bit_is_clear(PINC, PC6) && 
			!bit_is_clear(PINC, PC7))
		{ 
			SetLED(OFF);		
			if(Search(lir,cir,rir))
			{

				if( cir < 500) {ForwardHalf();}
				else if( cir < 800) {ForwardFull();}

				if( lir < rir - 80){ SetMotorSpeed(L_MOT, STOP, 0); }
				else if( lir - 80 > rir ){ SetMotorSpeed(R_MOT, STOP, 0); }
			}
		}
			
	
	}
        return(0);
}
