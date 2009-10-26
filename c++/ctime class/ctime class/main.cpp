#include <iostream>
using namespace std;

#include <ctime>

int main()
{
	time_t rawtime;

	time(& rawtime);

	struct tm * timeinfo;

	timeinfo = localtime( & rawtime);

	cout << timeinfo->tm_hour << '.' << timeinfo->tm_min << '.' << timeinfo->tm_sec << endl;

	return 0;
}