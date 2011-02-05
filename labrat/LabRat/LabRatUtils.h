/************************************************************
*              Basic Handy Atmel Functions
*              -Mike Chrisco - 11/11/2008-
*
* This source file will allow you to start using the Atmel
* quickly and help you through the slowest part of uController
* programming - figuring out all the register settings
* and binary math, although you should learn if you don't
* already know, someday... Enjoy.

* This file requires the AVR C library - available from the
* Atmel website and many other sources.
*
* DETAILED COMMENTS IN .C File
**************************************************************/

#ifndef LABRATUTILS_H
#define LABRATUTILS_H

#define F_CPU 8000000UL // 1 Mhz

#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <math.h>
#include <inttypes.h>
#include <stdarg.h>
#include <util/delay.h>
#include <avr/interrupt.h>  //avr interrupt macros
#include <stdio.h>

// Baud Rate Values for 1MHz Operation

#define UART1_1X 0 // Set UART1 to Normal speed, Use BAUD speeds. For 1x speed, baud of 9600: initUART1(UART1_1X, BAUD_9600);
#define UART1_2X 1 // Set UART1 to Double speed, Use BAUD2X speeds. For 2x speed, baud of 9600: initUART1(UART1_2X, BAUD2X_9600);

#define XBEE_1X 0 // Set XBee to Normal speed, Use BAUD speeds. For 1x speed, baud of 9600: initXBee(XBEE_1X, BAUD_9600);
#define XBEE_2X 1 // Set XBee to Normal speed, Use BAUD speeds. For 2x speed, baud of 9600: initUART1(XBEE_2X, BAUD2X_9600);

#define BAUD_2400 25 // 0.2% Error
#define BAUD_4800 12 // 0.2% Error
#define BAUD_9600 6	// 7.0% Error
#define BAUD_14400 3 // 8.5% Error
#define BAUD_19200 2 // 8.5% Error
#define BAUD_28800 1 // 8.5% Error

#define BAUD2X_2400 51 // 0.2% Error
#define BAUD2X_4800 25 // 0.2% Error
#define BAUD2X_9600 12 // 0.2% Error
#define BAUD2X_14400 8 // 3.5% Error
#define BAUD2X_28800 3 // 7.0% Error
#define BAUD2X_38400 2 // 8.5% Error
#define BAUD2X_57600 1 // 8.5% Error


#define A0 1 //PWM constants
#define B0 2
#define A1 3
#define B1 4
#define A2 5
#define B2 6

#define ON 1
#define OFF 0

#define B_MOT 0
#define L_MOT 1
#define R_MOT 2


#define L_IRLED 1
#define C_IRLED 2
#define R_IRLED 3

#define L_IRRCV 1
#define C_IRRCV 2
#define R_IRRCV 3

#define FWD 1
#define REV 0
#define BRAKE 2
#define STOP 3

#define L_BUMP 4
#define R_BUMP 5

#define SETBAUD0 BAUD_9600
#define SETBAUD1 BAUD_9600  // Set UART1 Baud Rate

#define CONFIG 0x00
#define STATUS 0x01
#define DELTA_Y 0x02
#define DELTA_X 0x03
#define SQUAL 0x04
#define MAX_PIXEL 0x05
#define MIN_PIXEL 0x06
#define PIXEL_SUM 0x07
#define PIXEL_GRAB 0x08
#define SHUTTER_UPPER 0x09
#define SHUTTER_LOWER 0x0A
#define INV_PROD_ID 0x11

/* DETAILED COMMENTS IN .C File */
void init(); // Initialize General Robot Functionality
void initADC(); // Initialize A/D Conversion Hardware
void initOptSensor();
void initClock();


void setLevel(int num, int level); // Set PWM Level
void initPWM(int val, ...); // Initialize PWM Channels
uint16_t getADC(int ch);  // Get Analog to Digital from Channel
int getTimeElapsed(); // 

/* UART Read/Write Functions
void initUART1(int UART1Speed, int baudrate); // Initialize UART 1 (SV1)
unsigned char getChar1(); // Get Character from UART1
void printAll1(const unsigned char *c, double var, ...); // Print String to UART1
void putChar1(char c); // Print Character to UART1
void putInt1(int num); // Print Number(in ASCII) to UART1
void putFloat1(double dbl); */

// XBee Read/Write Functions
void initXBee(int XBeeSpeed, int baudrate); // Initialize XBee Comm port
unsigned char getCharXBee(); // Get Character from XBee
void printAllXBee(const unsigned char *c, double var, ...); // Print String to XBee
void putCharXBee(char c); // Print Character to XBee
void putIntXBee(int num); // Print Number(in ASCII) to XBee
void putFloatXBee(double dbl);

void SetLED(uint8_t state); // Set User LED State
void SetMotor(uint8_t motnum, uint8_t dir); // Set Motor(s) Direction - Full on/off
//void SetIR(uint8_t irnum, uint8_t state); // Set IR LED State - Deprecated for LabRat_TH v1
void OptSensorWrite(uint8_t addr, uint8_t data); // Write to Optical Sensor
uint8_t OptSensorRead(uint8_t addr); // Read From Optical Sensor


void InitMotorPWM();
void SetMotorSpeed(uint8_t motnum, uint8_t dir, uint8_t level); // Set Motor Speed Using PWM

#endif
