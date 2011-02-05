#include "LabRatUtils.h"

/*void Hault()
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
	SetMotorSpeed(L_MOT, FWD, 128);
	SetMotorSpeed(R_MOT, FWD, 128);
}

int main(void)
{
	unsigned int CIRT = 900;
	unsigned int LIRT = 910;
	unsigned int RIRT = 940;
	init();
	initADC();
	InitMotorPWM();
	SetMotorSpeed(B_MOT, STOP, 0);
	initXBee(XBEE_2X, 25);
	for(;;)
	{
		
		
		if(bit_is_clear(PINC, PC6) && bit_is_clear(PINC, PC7)) 
		{ 
			Hault();
		}

		if(bit_is_clear(PINC, PC6)) 
		{
			SetLED(ON);
		}

		if(bit_is_clear(PINC, PC7)) 
		{
			SetLED(ON);
		}
		
		
		printAllXBee("lir: %d     cir: %d     rir: %d    \0", getADC(2), getADC(1), getADC(0));
		
		if (getADC(1) < CIRT)
		{
			SetLED(ON);
		}
		else if (getADC(0) < RIRT)
		{
			SetLED(ON);
		}
		else if (getADC(2) < LIRT)
		{
			SetLED(ON);
		}




	
	}
        return(0);
}
// vim:set ts=4 sts=4 sw=4 et
*/
int ledPin = //pin of custom led ;
int inputPin = //input of pir sensor;
int val = 0; // sensor off
int Pin = //number of pin;

void setup()
{


Set (ledPin, OUTPUT);
Set(inputPin, INPUT);


}

void loop()
{
val= digitalRead (inputPin);
if (val== ON);
{
digitalWrite (ledPin, ON);
_delay_ms(100);
digitalWrite (ledPin,OFF);
delay(100)}
