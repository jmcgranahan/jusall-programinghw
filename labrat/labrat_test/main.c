#include "LabRatUtils.h"

int main(void)
{
	init();
	for(;;)
	{
		
		 // Set LED0
		SetLED(ON);
		
		
		// Motor Tests
		SetMotor(L_MOT, FWD);
		SetIR(L_IRLED, ON);
		_delay_ms(2000.0);
		SetMotor(L_MOT, REV);
		_delay_ms(2000.0);
		SetMotor(L_MOT, STOP);
		_delay_ms(2000.0);

		// Clear LED0;
		SetIR(L_IRLED, OFF);
		SetLED(OFF);
		SetIR(C_IRLED, ON);

		// Motor Tests
		SetMotor(R_MOT, FWD);
		_delay_ms(2000.0);
		SetMotor(R_MOT, REV);
		_delay_ms(2000.0);
		SetIR(C_IRLED, OFF);
		SetIR(R_IRLED, ON);
		SetMotor(R_MOT, STOP);
		_delay_ms(4000.0);
		SetIR(R_IRLED, OFF);
  		/*
		// Sensor Tests
		
		// IRLED Tests
		
		SetIR(R_IRLED, ON);
		pause(PAUSE_T);
		while(bit_is_clear(PINA, PA3)) // Right IR RCV
		{
			SetLED(ON);
			pause(PAUSE_T);
			SetLED(OFF);
			pause(PAUSE_T);
		}
		SetIR(R_IRLED, OFF);
		
		
		SetIR(C_IRLED, ON);
		pause(PAUSE_T);
		while(bit_is_clear(PINA, PA2))
		{
			SetLED(ON);
			pause(PAUSE_T/2);
			SetLED(OFF);
			pause(PAUSE_T/2);
		}
		SetIR(C_IRLED, OFF); 

		SetIR(L_IRLED, ON);
		pause(PAUSE_T);
		while(bit_is_clear(PINA, PA1)) // Left IR RCV
		{
			SetLED(ON);
			pause(PAUSE_T/4);
			SetLED(OFF);
			pause(PAUSE_T/4);
		}
		SetIR(L_IRLED, OFF);

		// Bumpers
		while(bit_is_clear(PIND, PD5) ) // || bit_is_clear(PIND, PD5)) // 
		{
			SetLED(ON);
		}
		SetLED(OFF); */

/*	
		// Optical Sensor Test
		
		// Initialize Sensor
		PORTC &= ~_BV(PC3); // Disable Shutdown
		_delay_ms(150.0);  // Wait 1.5 secs
		PORTC |= _BV(PC7); // Enable NCS
		//_delay_us(1.0);
		
		SetLED(ON);
		_delay_ms(100.0);
		SetLED(OFF);	
		// Setup SPI
	        _delay_ms(100.0);	
		SPCR = _BV(SPE) | _BV(MSTR) | _BV(CPOL) | _BV(SPR0) | _BV(SPR1) | _BV(CPHA);
		
		// Initialize Sensor
		SetLED(ON);
		OptSensorWrite(0x3A, 0x5A); // Addr = 0x3A + MSB(WRITE) // POST
		_delay_ms(100.0);
		SetLED(OFF);
		_delay_ms(100.0);
		OptSensorRead(0x02); // Read Motion Status
		OptSensorRead(0x03); // Read Delta_X
		OptSensorRead(0x04); // Read Delta_Y
		//OptSensorWrite(0x01, 0x01); // Self-Test


		SetLED(ON);
		_delay_ms(100.0);
		SetLED(OFF);
		
		
		for(;;)
		{
			data = OptSensorRead(0x02);
			while(data & _BV(7)) // Motion!
			{
				OptSensorRead(0x03);
				OptSensorRead(0x04);
				data = OptSensorRead(0x02);
				SetLED(ON);
			}
			
			SetLED(OFF); 
			//_delay_ms(10.0); 
		} */
		
	}
        return(0);
}
// vim:set ts=4 sts=4 sw=4 et
