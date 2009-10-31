//MyTime.cpp 

#include <iostream>
#include "MyTime.h"
#include <ctime>
using namespace std;


MyTime::MyTime()
{
	_ticks = 0;
}

MyTime::MyTime(const MyTime & origMyTime)
{
	_ticks = origMyTime.GetTicks();
}

MyTime::MyTime(int initHrs, int initMins, int initSecs, int initMilisecs)
{
	long tempTicks = 0;
	while(initMilisecs >= 100)
	{
		initSecs++;
		initMilisecs -= 100;
	}
	while(initSecs >= 60)
	{
		initMins++;
		initSecs -= 60;
	}
	while(initMins >= 60)
	{
		initHrs++;
		initMins -= 60;
	}
	while(initHrs >= 24)
	{
		initHrs -= 24;
	}

	tempTicks += (initHrs * _ticksPerHour);
	tempTicks += (initMins * _ticksPerMinute);
	tempTicks += (initSecs * _ticksPerSecond);
	tempTicks += initMilisecs;
	_ticks = tempTicks;
}

MyTime::MyTime(int initHours, int initMinutes, int initSeconds)
{
	long tempTicks = 0;
	while(initSeconds >= 60)
	{
		initMinutes++;
		initSeconds -= 60;
	}
	while(initMinutes >= 60)
	{
		initHours++;
		initMinutes -= 60;
	}
	while(initHours >= 24)
	{
		initHours -= 24;
	}

	tempTicks += (initHours * _ticksPerHour);
	tempTicks += (initMinutes * _ticksPerMinute);
	tempTicks += (initSeconds * _ticksPerSecond);
	_ticks = tempTicks;
}
MyTime::MyTime(int initHours, int initMinutes)
{
	long tempTicks = 0;
	while(initMinutes >= 60)
	{
		initHours++;
		initMinutes -= 60;
	}
	while(initHours >= 24)
	{
		initHours -= 24;
	}

	tempTicks += (initHours * _ticksPerHour);
	tempTicks += (initMinutes * _ticksPerMinute);
	_ticks = tempTicks;

}
MyTime::MyTime(long initTicks)
{
	while(initTicks >_lastTickOfTheDay) initTicks -= _ticksPerDay;
	_ticks = initTicks;
}
 
 
// DESTRUCTOR
MyTime::~MyTime()
{
}
 
// METHODS
 
// Accessors and mutators for:
// hours, minutes, seconds, ticks

int MyTime::GetHours() const
{
	int curHours = (int) (_ticks / _ticksPerHour );
	return curHours;
}
void MyTime::SetHours(int newHours)
{
	while(newHours >= 24 ) newHours -= 24;
	int tempTicks = _ticks % _ticksPerHour;
	tempTicks += newHours * _ticksPerHour;
	_ticks = tempTicks;
}

int MyTime::GetMinutes() const
{
	int tempTicks = _ticks % _ticksPerHour;
	int curMinute = (int) (tempTicks / _ticksPerMinute );
	return curMinute;
}
void MyTime::SetMinutes(int newMinutes)
{
	while(newMinutes >= 60 ) newMinutes -= 60;
	int tempHours = (int) (_ticks / _ticksPerHour );
	int tempTicks = (_ticks % _ticksPerHour) % _ticksPerMinute;
	tempTicks += (newMinutes * _ticksPerMinute) + (tempHours * _ticksPerHour);
	_ticks = tempTicks;
}

int MyTime::GetSeconds() const
{
	int tempTicks = _ticks % _ticksPerMinute;
	int curSecond = (int) (tempTicks / _ticksPerSecond );
	return curSecond;

}
void MyTime::SetSeconds(int newSeconds)
{
	while(newSeconds >= 60 ) newSeconds -= 60;
	int tempHours = (int) (_ticks / _ticksPerHour );
	int tempMinutes = (int) ((_ticks % _ticksPerHour) / _ticksPerMinute);
	int tempTicks = ((_ticks % _ticksPerHour) % _ticksPerMinute) % _ticksPerSecond;
	tempTicks += (newSeconds * _ticksPerSecond) + (tempHours * _ticksPerHour) + (tempMinutes * _ticksPerMinute);
	_ticks = tempTicks;
}



long MyTime::GetTicks() const
{
	return _ticks;
}
void MyTime::SetTicks(int newTicks)
{
	while(newTicks >= _ticksPerDay ) newTicks -= _ticksPerDay;
	_ticks = newTicks;
}


// SetTime (various useful overloads)
      // Hours, Minutes, Seconds, Miliseconds
void MyTime::SetTime(int newHrs, int newMins, int newSecs, int newMilisecs)
{
	long tempTicks = 0;
	while(newMilisecs >= 100)
	{
		newSecs++;
		newMilisecs -= 100;
	}
	while(newSecs >= 60)
	{
		newMins++;
		newSecs -= 60;
	}
	while(newMins >= 60)
	{
		newHrs++;
		newMins -= 60;
	}
	while(newHrs >= 24)
	{
		newHrs -= 24;
	}

	tempTicks += (newHrs * _ticksPerHour);
	tempTicks += (newMins * _ticksPerMinute);
	tempTicks += (newSecs * _ticksPerSecond);
	tempTicks += newMilisecs;
	_ticks = tempTicks;

}
     
void MyTime::SetTime(int newHours, int newMinutes, int newSeconds)
{
	long tempTicks = 0;
	while(newSeconds >= 60)
	{
		newMinutes++;
		newSeconds -= 60;
	}
	while(newMinutes >= 60)
	{
		newHours++;
		newMinutes -= 60;
	}
	while(newHours >= 24)
	{
		newHours -= 24;
	}

	tempTicks += (newHours * _ticksPerHour);
	tempTicks += (newMinutes * _ticksPerMinute);
	tempTicks += (newSeconds * _ticksPerSecond);
	_ticks = tempTicks;
}
      
void MyTime::SetTime(int newHours, int newMinutes)
{
	long tempTicks = 0;
	while(newMinutes >= 60)
	{
		newHours++;
		newMinutes -= 60;
	}
	while(newHours >= 24)
	{
		newHours -= 24;
	}

	tempTicks += (newHours * _ticksPerHour);
	tempTicks += (newMinutes * _ticksPerMinute);
	_ticks = tempTicks;

}
      
void MyTime::SetTime(long newTicks)
{
	while(newTicks >= _ticksPerDay ) newTicks -= _ticksPerDay;
	_ticks = newTicks;
}
      
void MyTime::SetTime(const MyTime & aMyTime)
{
	_ticks = aMyTime.GetTicks();
}

// Now
// a static function that returns a MyTime object
//   initialized to the current time according to the system clock
MyTime MyTime::Now()
{
	time_t rawtime;
	time(& rawtime);
	struct tm * timeinfo;
	timeinfo = localtime( & rawtime);
	MyTime tempMyTime((timeinfo->tm_hour * _ticksPerHour) + (timeinfo->tm_min * _ticksPerMinute) + (timeinfo->tm_sec * _ticksPerSecond));
	return tempMyTime;
}

// Add (various useful methods)
// For adding amounts of time to this MyTime

void MyTime::AddHours(int moreHours)
{
	int tempTicks = _ticks;
	tempTicks += moreHours * _ticksPerHour;
	_ticks = tempTicks;
	while(_ticks >= _ticksPerDay) _ticks -= _ticksPerDay;

}

void MyTime::AddMinutes(int moreMinutes)
{
	int tempTicks = _ticks;
	tempTicks += moreMinutes * _ticksPerMinute;
	_ticks = tempTicks;
	while(_ticks >= _ticksPerDay) _ticks -= _ticksPerDay;
}

void MyTime::AddSeconds(long moreSeconds)
{
	int tempTicks = _ticks;
	tempTicks += moreSeconds * _ticksPerSecond;
	_ticks = tempTicks;
	while(_ticks >= _ticksPerDay) _ticks -= _ticksPerDay;
}

void MyTime::AddTicks(long moreTicks)
{
	int tempTicks = _ticks;
	tempTicks += moreTicks;
	_ticks = tempTicks;
	while(_ticks >= _ticksPerDay) _ticks -= _ticksPerDay;

}

void MyTime::AddTime(const MyTime & aMyTime)
{
	int tempTicks = _ticks;
	tempTicks += aMyTime.GetTicks();
	_ticks = tempTicks;
	while(_ticks >= _ticksPerDay) _ticks -= _ticksPerDay;

}

// Compare

int MyTime::Compare(const MyTime & aMyTime) const
{
	int tempTimeA = (int) this->_ticks;
	int tempTimeB = (int) aMyTime.GetTicks();
	return tempTimeA - tempTimeB;
}

// Equals
// Takes a MyTime argument
// Returns (true) if the argument has the same time
//   as this MyTime, otherwise it returns (false).
bool MyTime::Equals(const MyTime & aMyTime) const
{
	int tempTimeA = (int) this->_ticks;
	int tempTimeB = (int) aMyTime.GetTicks();
	if(tempTimeA == tempTimeB) return true;
	else return false;
}
 

// Subtract (various useful methods)
// For subtracting amounts of time to this MyTime    
   
void MyTime::SubtractHours(int lessHours)
{
	int tempTicks = _ticks;
	tempTicks -= lessHours * _ticksPerHour;
	_ticks = tempTicks;
	while(_ticks < 0) _ticks += _ticksPerDay;
}
      
void MyTime::SubtractMinutes(int lessMinutes)
{
	int tempTicks = _ticks;
	tempTicks -= lessMinutes * _ticksPerMinute;
	_ticks = tempTicks;
	while(_ticks < 0) _ticks += _ticksPerDay;

}
      
void MyTime::SubtractSeconds(long lessSeconds)
{
	int tempTicks = _ticks;
	tempTicks -= lessSeconds * _ticksPerSecond;
	_ticks = tempTicks;
	while(_ticks < 0) _ticks += _ticksPerDay;
}

void MyTime::SubtractTicks(long lessTicks)
{
	int tempTicks = _ticks;
	tempTicks -= lessTicks;
	_ticks = tempTicks;
	while(_ticks < 0) _ticks += _ticksPerDay;
}
      
void MyTime::SubtractTime(const MyTime & aMyTime)
{
	int tempTicks = _ticks;
	tempTicks -= aMyTime.GetTicks();
	_ticks = tempTicks;
	while(_ticks < 0) _ticks += _ticksPerDay;
}

// OVERLOADED OPERATORS
 
      // = (assignment - takes a MyTime)
MyTime MyTime::operator= (const MyTime & aMyTime)
{
	this->SetTime(aMyTime);
	return aMyTime;
}
 
// +, += (Addition - takes a MyTime)
MyTime MyTime::operator+ (const MyTime & aMyTime) const
{
	MyTime Temp;
	Temp.SetTime(*this) ;
	Temp.AddTime(aMyTime);
	return Temp;
}
MyTime MyTime::operator+= (const MyTime & aMyTime)
{
	this->AddTime(aMyTime);
	return *this;
}


// >, <, >=, <=, ==, != (boolean relational test operators)
bool MyTime::operator> (const MyTime & aMyTime) const 
{
	if(this->GetTicks() > aMyTime.GetTicks()) return true;
	else return false;
}

bool MyTime::operator< (const MyTime & aMyTime) const 
{
	if(this->GetTicks() < aMyTime.GetTicks()) return true;
	else return false;
}

bool MyTime::operator>= (const MyTime & aMyTime) const 
{
	if(this->GetTicks() >= aMyTime.GetTicks()) return true;
	else return false;
}

bool MyTime::operator<= (const MyTime & aMyTime) const 
{
	if(this->GetTicks() <= aMyTime.GetTicks()) return true;
	else return false;
}

bool MyTime::operator== (const MyTime & aMyTime) const 
{
	if(this->GetTicks() == aMyTime.GetTicks()) return true;
	else return false;
}

bool MyTime::operator!= (const MyTime & aMyTime) const 
{
	if(this->GetTicks() != aMyTime.GetTicks()) return true;
	else return false;
}

// <<, >> stream insertion and extraction
ostream & operator<< (ostream & os, const MyTime & aMyTime)
{
	os << "total ticks:" << aMyTime.GetTicks() <<endl<< "hours	   :" << aMyTime.GetHours() <<endl<< "minutes    :" << aMyTime.GetMinutes() <<endl<< "seconds    :" <<aMyTime.GetSeconds() <<endl<<endl;

	return os;

}

istream & operator>> (istream & is, MyTime & aMyTime)
{
	cout << "Enter Ticks: ";
	long tempTicks = 0;
	is >> tempTicks;
	while(tempTicks > MyTime::_ticksPerDay) tempTicks -= MyTime::_ticksPerDay;
	aMyTime._ticks = tempTicks;
	cout << endl;
	return is;
}