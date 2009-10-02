#include <iostream>
#include <time.h>
#include <cstdlib>
#define TEST_LENGTH 30

using namespace std;

void LineBreak();
void PreIncVsPostInc();
void NestedVsUnNested();
void CaseVsIfelse();
void GlobalVsScoped();
void InitVsSetting();

long double a = 0;
long double b = 0;
long double c;
long double d;
int NumberOfTests = 0;
clock_t endwait;


int main ()
{
	srand ( time(NULL) );
	PreIncVsPostInc();
	LineBreak();
	InitVsSetting();
	LineBreak();
	NestedVsUnNested();
	LineBreak();
	CaseVsIfelse();
	LineBreak();
	GlobalVsScoped();
	LineBreak();
	
	c = ((a-b)/(TEST_LENGTH * NumberOfTests));
	d = a/b;
	printf("A: %e     B: %e    Difference: %f o/s \n ratio: %f   \n", a , b , c, d );
	system("PAUSE");
		return 0;
}


void LineBreak()
{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void PreIncVsPostInc()
	{
		
		NumberOfTests += 2;
		long double CounterA = 0, CounterB = 0;
		printf ("Starting preincrement test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			++CounterA;
			
		}
	
		printf ("Starting postincrement test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
			CounterB++;
		}
		
		int Difference = (CounterA-CounterB)/TEST_LENGTH;
		cout << "preinc: " << CounterA << ".  postinc: " << CounterB << ".  difference: " << Difference << " per seccond."<<endl;
		a += CounterA;
		b += CounterB;

	}





void NestedVsUnNested()
	{
		NumberOfTests += 2;
		long double CounterA = 0, CounterB = 0;
		int Ones = 0 , Tens = 0 , Hundreds = 0 , Thousands = 0, TenThousands = 0;
	
		printf ("Starting ElseIf Test...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;

		while (clock() < endwait)
		{
			
			long double a = (rand() * 3);
			
			//cout << a << endl;
			if(a >=10000 )
			{
				TenThousands++;
			}
			else if(a >=1000 && a <10000)
			{
				Thousands++;
			}
			else if(a >=100 && a <1000)
			{
				Hundreds++;
			}
			else if(a >= 10 && a <100)
			{
				Tens++;
			}
			else
			{
				Ones++;
			}

			CounterA++;
		}

		printf ("Starting UnNested Test...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		
		while (clock() < endwait)
		{
			
			long double a = (rand()* 3 );
			
			//cout << a << endl;
			if(a >=10000 )
			{
				TenThousands++;
			}
			if(a >=1000 && a <10000)
			{
				Thousands++;
			}
			if(a >=100 && a <1000)
			{
				Hundreds++;
			}
			if(a >= 10 && a <100)
			{
				Tens++;
			}
			if(a < 10)
			{
				Ones++;
			}

			CounterB++;
		}
		int Difference = (CounterA-CounterB)/TEST_LENGTH;
		cout << "ones: " << Ones << "  Tens: " << Tens << "  Hundreds: " << Hundreds << endl;
		cout << "Thousands: " << Thousands << "  TenThousands: " << TenThousands << endl;
		cout << "If: " << CounterA << ".  Else if: " << CounterB << ".  difference: " << Difference << " per seccond."<<endl;
		a += CounterA;
		b += CounterB;

	}

void CaseVsIfelse()
{
	NumberOfTests += 2;
	long double CounterA = 0, CounterB = 0;
	int One = 0, Two = 0, Three = 0 , Four = 0, Five = 0, Six = 0 , Seven = 0, Eight = 0, Nine = 0, Ten = 0;

	
	printf ("Starting ElseIf Test...\n");
	endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
	while (clock() < endwait)
	{
			
		int a = (rand() % 10 + 1);
			
		//cout << a << endl;
		if(a == 1)
		{
			One++;
		}
		else if(a == 2)
		{
			Two++;
		}
		else if(a == 3)
		{
			Three++;
		}
		else if(a == 4)
		{
			Four++;
		}
		else if(a == 5)
		{
			Five++;
		}
		else if(a == 6)
		{
			Six++;
		}
		else if(a == 7)
		{
			Seven++;
		}
		else if(a == 8)
		{
			Eight++;
		}
		else if(a == 9)
		{
			Nine++;
		}
		else if(a == 10)
		{
			Ten++;
		}

			CounterA++;
	}
	
	printf ("Starting Switching Test...\n");
	endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
	
	
	while (clock() < endwait)
	{
			
		int a = (rand()%10 + 1 );
			
		//cout << a << endl;
		switch(a) {
			case 1:
				One++;
				break;
			case 2:
				Two++;
				break;
			case 3:
				Three++;
				break;	
			case 4:
				Four++;
				break;
			case 5:
				Five++;
				break;
			case 6:
				Six++;
				break;
			case 7:
				Seven++;
				break;
			case 8:
				Eight++;
				break;
			case 9:
				Nine++;
				break;
			case 10:
				Ten++;
				break;
				
		}
				CounterB++;
	}

	int Difference = (CounterA-CounterB)/TEST_LENGTH;
	cout << "Ones: " << One << " Twos: " << Two << "  Threes: " << Three << endl;
	cout << "Fours: " << Four << "  Fives: " << Five << "  Sixes: " << Six <<endl;
	cout << "Eights: " << Eight << "  Nines: " << Nine << "  Tens: " << Ten <<endl;
	cout << "Else If: " << CounterA << ".  Switch: " << CounterB << ".  Difference: " << Difference << " per seccond."<<endl;
	a += CounterA;
	b += CounterB;
}

void GlobalVsScoped()
{
	NumberOfTests += 2;
	long double CounterA = 0, CounterB = 0;

		printf ("Starting Global Counter test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			int Counter;
			for(Counter = 0; Counter < 9 ; Counter++)
			{
				for(Counter = 0; Counter < 9 ; Counter++)
				{
					for(Counter = 0; Counter < 9 ; Counter++)
					{
						for(Counter = 0; Counter < 9 ; Counter++)
						{
						   //do nothing
						}
					}
				}
			}
			CounterA++;
		}

		printf ("Starting Scoped Counter test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			for(int CounterA = 0; CounterA < 9 ; CounterA++)
			{
				for(int CounterB = 0; CounterB < 9 ; CounterB++)
				{
					for(int CounterC = 0; CounterC < 9 ; CounterC++)
					{
						for(int CounterD = 0; CounterD < 9 ; CounterD++)
						{
						   //do nothing
						}
					}
				}
			}
			CounterB++;
		}

		int Difference = (CounterA-CounterB)/TEST_LENGTH;

		cout << "Global: " << CounterA << ".  Scoped: " << CounterB << ".  Difference: " << Difference << " per seccond."<<endl;
		a += CounterA;
		b += CounterB;
}

void InitVsSetting()
{
		NumberOfTests += 2;
		long double CounterA = 0, CounterB = 0;
		printf ("Starting Initialize test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			double Array [50] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			CounterA++;			
		}
	
		printf ("Starting Set test ...\n");
		endwait = clock() + TEST_LENGTH * CLOCKS_PER_SEC ;
		while (clock() < endwait)
		{
			double Array [50];
			Array[0] = 1;
			Array[1] = 1;
			Array[2] = 1;
			Array[3] = 1;
			Array[4] = 1;
			Array[5] = 1;
			Array[6] = 1;
			Array[7] = 1;
			Array[8] = 1;
			Array[9] = 1;
			Array[10] = 1;
			Array[11] = 1;
			Array[12] = 1;
			Array[13] = 1;
			Array[14] = 1;
			Array[15] = 1;
			Array[16] = 1;
			Array[17] = 1;
			Array[18] = 1;
			Array[19] = 1;
			Array[20] = 1;
			Array[21] = 1;
			Array[22] = 1;
			Array[23] = 1;
			Array[24] = 1;
			Array[25] = 1;
			Array[26] = 1;
			Array[27] = 1;
			Array[28] = 1;
			Array[29] = 1;
			Array[30] = 1;
			Array[31] = 1;
			Array[32] = 1;
			Array[33] = 1;
			Array[34] = 1;
			Array[35] = 1;
			Array[36] = 1;
			Array[37] = 1;
			Array[38] = 1;
			Array[39] = 1;
			Array[40] = 1;
			Array[41] = 1;
			Array[42] = 1;
			Array[43] = 1;
			Array[44] = 1;
			Array[45] = 1;
			Array[46] = 1;
			Array[47] = 1;
			Array[48] = 1;
			Array[49] = 1;
			
			CounterB++;
		}
		
		int Difference = (CounterA-CounterB)/TEST_LENGTH;
		cout << "Initialize: " << CounterA << ".  Set: " << CounterB << ".  Difference: " << Difference << " per seccond."<<endl;
		a += CounterA;
		b += CounterB;
}