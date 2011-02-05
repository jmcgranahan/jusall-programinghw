/************************************************************
*              Basic Handy Atmel Functions
*	REV Info:
*        -Mike Chrisco - 11/11/2008-
*		 -Ryan Meuth - 11/23/2008 - merged LABRAT functions.
*		 -Ryan Meuth - 12/11/2008 - Added XBee Communications, SetMotorSpeed, 
*			Optical Sensor Init, Opt. Sensor Message Defines, 
*			Modified Serial Comm for 2X Operation, Added Clock functionality.
*		 -Mike Chrisco- 1-19-2009 - Updated printAll1 function and added functions to 
*           support signed numbers, doubles, and larger ints.
*          *NOTE: XBee Functions were not updated yet*
*		-Mike Chrisco- 2/22/2009-
*			XBee functions updated
*			Fixed Error in putCharXBee()
*		-Mike Chrisco- 5/16/2009-
*			Fixed error in getADC()
*			Cleaned up a few lines/comments
*			Fixed var size with printAll1()
*			Fixed var size with printAllXBee()
*		-Mike Chrisco- 10/26/2009-
*			Made putInt1 and putIntXBee wildly more efficient
*		-Mike Chrisco- 11/2/2009-
*			Fixed putInt to handle negatives correctly
*           -Mike Chrisco- 12/14/2009-
*                 Fixed getADC() MUX Issue
*       -rmeuth - 6/25/10
*			Modified for LABRAT_TH
*
*==========================================================
* DESCRIPTION:
* This source file will allow you to start using the LabRat
* quickly and help you through the slowest part of uController
* programming - figuring out all the register settings
* and binary math, although you should learn if you don't
* already know, someday... Enjoy.
*
* This file requires the AVR C library - available from the
* Atmel website and many other sources.
**************************************************************/



#include "LabRatUtils.h"

/***********************************************
* Basic I/O initialization function.  This should
* always be called once at the beginning of your
* program.  Clock options and default behaviors
* go here.
*
************************************************/

void init()
{
	DDRA = 0;
	DDRB = 0;  //default all Ports to Inputs
	DDRC = 0; 
	DDRD = 0;
	
	// Setup Outputs
	DDRA |= _BV(PA6); // User LED
	DDRB |= _BV(PB0); // Motor 1 Direction 
	DDRB |= _BV(PB1); // Motor 2 Direction

	DDRB |= _BV(PB3); // Motor 1 PWM
	DDRB |= _BV(PB4); // Motor 2 PWM
	
	//DDRD |= _BV(PD6); // GPIO
	//DDRD |= _BV(PD7); // GPIO

	// Opt. Sensor Interface (SPI)
	DDRB |= _BV(PB5); // MOSI
	DDRB &= ~_BV(PB6); // MISO
	DDRB |= _BV(PB7); // SCK

	
	SetLED(OFF);

	
	return;
}
/*********************************************
* Initialize UART1 with 8bit frame - 1 stop bit
* 9600 BAUD No-parity
*
**This will be expanded to be usable for all** 
*			**UARTs on the 324p**
***********************************************

void initUART1(int UART1Speed, int baudrate)
{
	
	UBRR1 = baudrate;
	
	if(UART1Speed)
		UCSR1A |= _BV(U2X1); // Set Double Speed

	UCSR1C = _BV(UCSZ10) | _BV(UCSZ11); //8 data bit frame 1 stop bit(default)
	UCSR1B = _BV(TXEN1) | _BV(RXEN1); //enable TX & RXers
}

/*********************************************
* Initialize XBee with 8bit frame - 1 stop bit
* 9600 BAUD No-parity
*
**This will be expanded to be usable for all** 
*			**UARTs on the 324p**
***********************************************/

void initXBee(int XBeeSpeed, int baudrate)
{
	
	/* Initialize XBee Serial */
	UBRR0 = baudrate;
	
	if(XBeeSpeed)
		UCSR0A |= _BV(U2X0); // Set Double Speed
	
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); //8 data bit frame 1 stop bit(default)
	UCSR0B = _BV(TXEN0) | _BV(RXEN0); //enable TX & RXers
}

/***********************************************
*  Initialize ADC.  This only enables them in 
* general. When getADC is called THEN the IO pin 
* changes functions.
***********************************************/

void initADC()
{
	
	/* Enable ADC */
	PRR &= !_BV(PRADC); //enable ADC in power reduction register
	ADMUX |= _BV(REFS0); //AVCC voltage ref
	ADCSRA |=  _BV(ADEN); //Enable ADC

	return;
}

/**********************************************
*  Sets which PWM outputs will be active 
* (overrides other pin functions). Use constants
* A0 - B2 to refer to pins. To initialize OC0A 
* pin, call:  initPWM(A0);
* Multiple arguments acceptable such as:
* initPWM(A0,B0,B2);
**********************************************/


void initPWM(int val, ...)
{
	va_list va;
	va_start(va,val);
  int j = val;
	for(j = val;j != -1; j = va_arg(va,int))
	{
		
		switch(j)
		{
			case A0:
				DDRB |= _BV(DDB3); //set OCR0A output
				TCCR0A |= _BV(WGM00) | _BV(COM0A1);
				TCCR0B |= _BV(CS01);
				OCR0A = 255;
				break;
			case B0:
				DDRB |= _BV(DDB4); //set OCR0A output
				TCCR0A |= _BV(WGM00) | _BV(COM0B1);
				TCCR0B |= _BV(CS01);
				OCR0B = 255;
				break;
			case A1:
				DDRD |= _BV(DDD4); //set OCR1A output
				TCCR1A |= _BV(WGM10) | _BV(COM1A1);
				TCCR1B |= _BV(CS11);
				OCR1A = 255;
				break;
			case B1:
				DDRD |= _BV(DDD5); //set OCR1A output
				TCCR1A |= _BV(WGM10) | _BV(COM1B1);
				TCCR1B |= _BV(CS11);
				OCR1B = 255;
				break;
			case A2:
				DDRD |= _BV(DDD7); //set OCR2A output
				TCCR2A |= _BV(WGM20) | _BV(COM2A1);
				TCCR2B |= _BV(CS21);
				OCR2A = 255;
				break;
			case B2:
				DDRD |= _BV(DDD6); //set OCR2B output
				TCCR2A |= _BV(WGM20) | _BV(COM2B1);
				TCCR2B |= _BV(CS21);
				OCR2B = 255;
				break;
		}
	}

	va_end(va);
	return;
}

/************************************************
* Sets a pwm level 0-255 representing 0-100% duty
* PWM must be initialized using initPWM. PWM1 and 2
*
* To set OC0A (PB3) to 50% call:
*	setLevel(A0, 127);
*
************************************************/


void setLevel(int num,int level)
{
	switch(num)
	{
		case A0:
			OCR0A = level;
			break;
		case B0:
			OCR0B = level;
			break;
        case A1:
			OCR1A = level;
			break;
		case B1:
			OCR1B = level;
			break;
        case A2:
			OCR2A = level;
			break;
		case B2:
			OCR2B = level;
			break;
	}
	return;
}

/****************************************
*Retrieves a 10-bit integer from 
*an ADC pin.  
*
*Pass a number 0 - 7 to select which
*ADC Input to read from
*****************************************/

uint16_t getADC(int ch)
{
	unsigned int result = 0;
	//putCharXBee('a');
    //while(!(ADCSRA & _BV(ADIF))); ///Ensure old conversion is 
	//putCharXBee('b');
    ADMUX &= 0xE0; //Clear MUX Bits
	ADMUX |= ch;	//set mux channel
	DIDR0 = ch; //Disable Input buffer
	
	ADCSRA |= _BV(ADSC); //start conv.
	//putCharXBee('c');
	while(!(ADCSRA & _BV(ADIF))); //wait for finish
	//putCharXBee('d');
	result = ADCL; //save low byte
	result |= (ADCH<<8); //append high byte
	
	return result;

}
/**********************************************
*  This function demonstrates how to configure
* an interrupt (the INT0 external one in
* this case). 
*  This is only a basic overview.  Read the
* datasheet (or about interrupts if you don't
* know what this is even for) to learn how
* to use this.

  void init_inter()
  {
	//DDRD &= 0xFB; //set PD2 to Input
	  EICRA = 0x02; //falling edge trig
	  EIMSK = 0x01; //enable INT0 intrpt
	  sei(); //enable global intrpts
  	return;
  }
*
*The serivce routine for this
* interrupt would be:
     ISR(INT0_vect)
     {
        doStuff();
     }
*
*******************************************/

/******************************************
* Gets a single character from
* USART1
*
*******************************************

unsigned char getChar1()
{
  char datah = 0;
  char datal = 0;
  char status = 0;

  while(!(UCSR1A & _BV(RXC1))); //wait for data
  status = UCSR1A;
  datah = UCSR1B;
  datal = UDR1;

  if (!(status&((1<<FE1)|(1<<DOR1)|(1<<UPE1))))
  {
  	return '?';
  }

  datah = (datah >> 1) & 0x01;
  return datal;

}

/********************************
*Write an integer 0-65536 to USART1
*(converts to ASCII equiv)
*
********************************

void putInt1(int num)
{
  uint16_t size = 1;
  uint16_t temp = num;
  if(num < 0)
  {
    putChar1('-');
	num = (0xFFFF-num)+1;
	temp = num;
  }
  while(temp>=10)  //determine Number size
  {
    size*=10;    //10,100
    temp/=10; //123,1
  }
  
  temp=1;
  while(size>0)   //Output Number
  {
    putChar1((num/size)+48);
    num-=((num/size)*size);      
    size /= 10;
  }    
	
  return;
}
/***********************************
* Write a character to USART1
*
* You can use a while loop and an
* array of chars to write strings
***********************************
void putChar1(char c)
{
	while(!(UCSR1A & _BV(UDRE1))); //wait for tx buffer to be ready
	UDR1 = c; //put chat to tx register
	while(!(UCSR1A & _BV(TXC1))); //wait for tx to finish
	return;
}

/****************************
* Write float to UART1
*
* Basically wrapper for
* printInt1(int) that adds
* decimal ability
*****************************
void putFloat1(double dbl)
{
	int whole = 0;
	double dec = 0;

	dec = dbl - (int)(dbl); //remove int part

	whole = (int)(dbl); //remove decimals

	dec*=1000;

	//remove sign from dec
	if(dec < 0)
	{
		dec *= -1;
	}

	putInt1(whole);
	putChar1('.');
	putInt1((int)(dec));

	return;
}

/****************************
* Write float to XBee (UART0)
*
* Basically wrapper for
* printIntXBee(int) that adds
* decimal ability
*****************************/
void putFloatXBee(double dbl)
{
	int whole = 0;
	double dec = 0;

	dec = dbl - (int)(dbl); //remove int part

	whole = (int)(dbl); //remove decimals

	dec*=1000;

	//remove sign from dec
	if(dec < 0)
	{
		dec *= -1;
	}

	putIntXBee(whole);
	putCharXBee('.');
	putIntXBee((int)(dec));

	return;
}


/****************************
* Custom printf-like function
*
* - %d = +/- int to 65536
* - %c = character code
* - %f = +/- float to 9999.9999 
* - If only printing a string, put '0' in
*    for second argument.
* - ADD '\0' TO END OF STRING TO 
*    PREVENT ISSUES
*****************************

void printAll1(const unsigned char *c, double var, ...)
{
	va_list ls;

	va_start(ls,var);
	int i = 0;
	uint8_t j = 0;

	while(c[i] != '\0')
	{
		while(c[i] != '%' && c[i] != '\0')
		{
			putChar1(c[i]);
			i++;
		}
		if(c[i] == '%')
		{
			i++;

			switch(c[i])
			{
				case 'd':
					if(j==0)  putInt1((int)var);
					else putInt1((int)(va_arg(ls,int)));
					break;
				case 'c':

					if(j==0)  putChar1((unsigned int)var);
					else putChar1(va_arg(ls,unsigned int));
					break;
				case 'f':
					if(j==0)  putFloat1((double)var);
					else putFloat1((double)va_arg(ls,double));
					break;
				default:
					putChar1(c[i-1]);
					putChar1(c[i]);
			}
			j=1;
		}
		i++;
	}
	va_end(ls);
	return;
}

/******************************************
* Gets a single character from
* XBee
*
*******************************************/

unsigned char getCharXBee()
{
  char datah = 0;
  char datal = 0;
  char status = 0;

  while(!(UCSR0A & _BV(RXC0))); //wait for data
  status = UCSR0A;
  datah = UCSR0B;
  datal = UDR0;

  if (!(status&((1<<FE0)|(1<<DOR0)|(1<<UPE0))))
  {
  	return '?';
  }

  datah = (datah >> 1) & 0x01;
  return datal;

}

/********************************
*Write an integer 0-999 to XBee
*(converts to ASCII equiv)
*
********************************/

void putIntXBee(int num)
{
  uint16_t size = 1;
  uint16_t temp = num;
  if(num < 0)
  {
    putCharXBee('-');
	num = (0xFFFF-num)+1;
	temp = num;
  }
  while(temp>=10)  //determine Number size
  {
    size*=10;    //10,100
    temp/=10; //123,1
  }
  
  temp=1;
  while(size>0)   //Output Number
  {
    putCharXBee((num/size)+48);
    num-=((num/size)*size);      
    size /= 10;
  }    
	
  return;
}

/***********************************
* Write a character to XBee
*
* You can use a while loop and an
* array of chars to write strings
***********************************/
void putCharXBee(char c)
{
	while(!(UCSR0A & _BV(UDRE0))); //wait for tx buffer to be ready
	UDR0 = c; //put chat to tx register
	while(!(UCSR0A & _BV(TXC0))); //wait for tx to finish
	return;
}

/****************************
* Custom printf-like function
* 		**XBee Version**
*
* - %d = +/- int to 65536
* - %c = character code
* - %f = +/- float to 9999.9999 
* - If only printing a string, put '0' in
*    for second argument.
* - ADD '\0' TO END OF STRING TO 
*    PREVENT ISSUES
*****************************/

void printAllXBee(const unsigned char *c, double var, ...)
{
	va_list ls2;
	va_start(ls2,var);
	int i = 0;
	uint8_t j = 0;

	while(c[i] != '\0')
	{
		while(c[i] != '%' && c[i] != '\0')
		{
			putCharXBee(c[i]);
			i++;
		}
		if(c[i] == '%')
		{
			i++;

			switch(c[i])
			{
				case 'd':
					if(j==0)  putIntXBee((int)var);
					else putIntXBee((int)(va_arg(ls2,int)));
					break;
				case 'c':

					if(j==0)  putCharXBee((unsigned int)var);
					else putCharXBee(va_arg(ls2,unsigned int));
					break;
				case 'f':
					if(j==0)  putFloatXBee((double)var);
					else putFloatXBee((double)va_arg(ls2,double));
					break;
				default:
					putCharXBee(c[i-1]);
					putCharXBee(c[i]);
			}
			j=1;
		}

		i++;

	}
	putCharXBee('\r');
	putCharXBee('\n');
	va_end(ls2);
	return;
}

/****************************
* Initialize Optical Sensor
*
*
*****************************/

void initOptSensor()
{
	//Setup SPI
	PRR &= ~_BV(PRSPI); //enable in PRR
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(CPOL) | _BV(SPR0) | _BV(SPR1) | _BV(CPHA);

	// Initialize Sensor
	OptSensorWrite(0x80, 0x80); // Addr = Config + MSB(WRITE) // POST
	_delay_ms(1000.0);
	OptSensorRead(DELTA_Y); // Read Delta_Y
	OptSensorRead(DELTA_X); // Read Delta_X
}

/****************************
* Write to Optical Sensor Register
* See Optical Sensor Datasheet
*
*****************************/

void OptSensorWrite(uint8_t addr, uint8_t data)
{
	SPDR = addr | 0x80;
	while(!(SPSR & _BV(SPIF)));

	_delay_us(30.0);

	SPDR = data;
	while(!(SPSR & _BV(SPIF)));
	_delay_us(30.0);
}

/****************************
* Read from Optical Sensor Register
* See Optical Sensor Datasheet
*
*****************************/
uint8_t OptSensorRead(uint8_t addr)
{
	uint8_t data = 0;
	SPDR = addr;
	while(!(SPSR & _BV(SPIF))); // Wait for Send
	_delay_us(100);
	SPDR = 0;

	while(!(SPSR & _BV(SPIF))); // Wait for Receive
	data = SPDR;
	_delay_us(30);
	return data;
}

/****************************
* Set User LED
* User LED Jumper Must Be Bridged
* See Header for State Defines
*****************************/
void SetLED(uint8_t state)
{
	if(state == ON)
		PORTA |= _BV(PA6);
	else
		PORTA &= ~_BV(PA6);
}

/****************************
* Set IR
* See Header for IR  and State Defines
*
****************************
void SetIR(uint8_t irnum, uint8_t state)
{
	if(irnum == R_IRLED)
	{
		if(state == ON)
			PORTB &= ~_BV(PB0);	// IR LEDs are active-low
		else
			PORTB |= _BV(PB0);
	}

	if(irnum == C_IRLED)
	{
		if(state == ON)
			PORTB &= ~_BV(PB1);
		else
			PORTB |= _BV(PB1);
	}

	if(irnum == L_IRLED)
	{
		if(state == ON)
			PORTB &= ~_BV(PB2);
		else
			PORTB |= _BV(PB2);
	}
}
*/
/**************************************************
* Set Motor(s) Binary Value Direction (Full on/off)
* See Header for Motor and Direction Defines
*
**************************************************/
void SetMotor(uint8_t motnum, uint8_t dir)
{
    if(motnum == B_MOT)
	{
		if(dir == FWD)
		{
			// Enable Both Motors
			PORTB |= _BV(PB3);
			PORTB |= _BV(PB4);

			// Set Forward
			PORTB |= _BV(PB0);
			PORTB |= _BV(PB1);
		}

		if(dir == REV)
		{
			// Enable Both Motors
			PORTB |= _BV(PB3);
			PORTB |= _BV(PB4);

			// Set Reverse
			PORTB &= ~_BV(PB0);
			PORTB &= ~_BV(PB1);
		}

		if(dir == BRAKE)
		{
			// Disable Both Motors
			PORTB &= ~_BV(PB3);
			PORTB &= ~_BV(PB4);
		}

		if(dir == STOP)
		{
			// Disable Both Motors
			PORTB &= ~_BV(PB3);
			PORTB &= ~_BV(PB4);
		}
	}

	if(motnum == L_MOT)
	{
		if(dir == FWD)
		{
			PORTB |= _BV(PB3); // Enable Motor 1
			PORTB |= _BV(PB0); // Motor 1 Fwd
		}

		if(dir == REV)
		{
			PORTB |= _BV(PB3); // Enable Motor 1
			PORTB &= ~_BV(PB0); // Motor 1 Rev
		}

		if(dir == BRAKE)
		{
			PORTB &= ~_BV(PB3); // Disable Motor 1

		}

		if(dir == STOP)
		{
			PORTB &= ~_BV(PB3); // Disable Motor 1
		}
	}

	if(motnum == R_MOT)
	{
		if(dir == FWD)
		{
			PORTB |= _BV(PB4); // Enable Motor 2
			PORTB |= _BV(PB1); // Motor 2 Fwd
		}

		if(dir == REV) 
		{
			PORTB |= _BV(PB4); // Enable Motor 2
			PORTB &= ~_BV(PB1); // Motor 2 Rev
		}

		if(dir == BRAKE)
		{
			PORTB &= ~_BV(PB4); // Disable Motor 2

		}

		if(dir == STOP)
		{
			PORTB &= ~_BV(PB4); // Disable Motor 2
		}
	}
}

/****************************
* Initialize Motor PWM Control
* 
*  
*****************************/
void InitMotorPWM()
{
	initPWM(A0, B0);
}

/****************************
* Set Motor(s) Speed Using PWM, Direction (Full on/off)
* See Header for Motor and Direction Defines
* InitMotorPWM() must be called before using this function.
*****************************/
void SetMotorSpeed(uint8_t motnum, uint8_t dir, uint8_t level) // Set Motor Speed Using PWM
{
	if(motnum == B_MOT)
	{
		if(dir == FWD)
		{
			// Set Speed
			OCR0A = level; // Motor 1 Level
			OCR0B = level; // Motor 2 Level

				// Set Direction (Forward)
			PORTB |= _BV(PB0);
			PORTB |= _BV(PB1);
		}

		if(dir == REV) 
		{
				// Set Speed
			OCR0A = level; // Motor 1 Level
			OCR0B = level; // Motor 2 Level

				// Set Direction (Reverse)
			PORTB &= ~_BV(PB0);
			PORTB &= ~_BV(PB1);
		}

		if(dir == BRAKE)
		{
				// Set Speed
			OCR0A = 0; // Motor 1 Level
			OCR0B = 0; // Motor 2 Level

				// Set Direction (Forward)
			PORTB |= _BV(PB0);
			PORTB |= _BV(PB1);
		}

		if(dir == STOP)
		{
				// Set Speed
			OCR0A = 0; // Motor 1 Level
			OCR0B = 0; // Motor 2 Level

				// Set Direction (Forward)
			PORTB |= _BV(PB0);
			PORTB |= _BV(PB1);
		}
	}

	if(motnum == L_MOT)
	{
		if(dir == FWD)
		{
			// Set Speed
			OCR0A = level; // Motor 1 Level
			
			// Set Direction (Forward)
			PORTB |= _BV(PB0);
		}

		if(dir == REV) 
		{
			// Set Speed
			OCR0A = level; // Motor 1 Level
			
			// Set Direction (Forward)
			PORTB &= ~_BV(PB0);
		}

		if(dir == BRAKE)
		{
			// Set Speed
			OCR0A = 0; // Motor 1 Level
			
			// Set Direction (Forward)
			PORTB |= _BV(PB0);
		}

		if(dir == STOP)
		{
			// Set Speed
			OCR0A = 0; // Motor 1 Level
			
			// Set Direction (Forward)
			PORTB |= _BV(PB0);
		}
	}

	if(motnum == R_MOT)
	{
		if(dir == FWD)
		{
			// Set Speed
			OCR0B = level; // Motor 2 Level

			// Set Direction (Forward)
			PORTB |= _BV(PB1);
		}

		if(dir == REV) 
		{
			// Set Speed
			OCR0B = level; // Motor 2 Level

			// Set Direction (Reverse)
			PORTB &= ~_BV(PB1);
		}

		if(dir == BRAKE)
		{
			// Set Speed
			OCR0B = 0; // Motor 2 Level

			// Set Direction (Forward)
			PORTB |= _BV(PB1);
		}

		if(dir == STOP)
		{
			// Set Speed
			OCR0B = 0; // Motor 2 Level

			// Set Direction (Forward)
			PORTB |= _BV(PB1);
		}
	}
}

/****************************
* Initialize Clock Functionality. 
* 
* Each Tick of the clock is 0.000124 seconds.
*****************************/
void initClock()
{
	unsigned char sreg_save;

	TCCR1A = 0;
	TCCR1B = _BV(CS10) | _BV(CS12); // Set Clock at 0.001024 ticks/s for 1Mhz clock
	sreg_save = SREG;
	cli();
	TCNT1 = 0x0000;
	SREG = sreg_save;
}

/****************************
* Get Number of Ticks Elapsed since last call of initClock() or getTimeElapsed()
* Each Tick of the clock is 0.000124 seconds.
* GetTime Elapsed must be called at most every 67 seconds, or the clock will overflow,
*	and the returned value will be invalid.
*****************************/
int getTimeElapsed()
{
	int i;
	unsigned char sreg_save;

	sreg_save = SREG;
	cli();
	i = TCNT1; // Get Current Clock Value
	TCNT1 = 0; // Reset Clock
	SREG = sreg_save;
	return i;
}
