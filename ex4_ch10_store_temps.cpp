#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Reading {
	int hour;
	double temperature;
	char unit;
};

int main()
{
	
	ofstream ost{ "raw_temps_ex4.txt" };
	std::vector<Reading> temps;

	for (int i = 0; i < 25; i++)
	{
		temps.push_back(Reading{ i, 32.0 + i , 'f'});
	}
	for(int i = 25; i < 50; i++)
	{
		temps.push_back(Reading{25 + i, 10.0 + i, 'c'});
	}
	for (int i = 0; i < temps.size(); i++)
	{
		ost << temps[i].hour<<endl << temps[i].temperature<<endl << temps[i].unit <<endl;
	}
	cin.get();
	return 0;
}