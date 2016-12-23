#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

struct Reading {
	int hour;
	double temperature;
	char unit;
};

double get_F(const Reading &reading)
{
	if(reading.unit == 'f')
		return reading.temperature;
	return reading.temperature * 1.8 + 32;
}

int main()
{
	ifstream ist{ "raw_temps_ex4.txt" };
	std::vector<Reading> temps;

	while (true)
	{
		int hour;
		double temperature;
		char unit;
		ist >> hour >> temperature >> unit;
		if (ist.fail())
			break;
		cout<<"hour, temparature, unit: "<<hour<<", "<<temperature<<", "<<unit<<endl;
		temps.push_back(Reading{ hour, temperature, unit });
	}
	double temp_sum = 0;
	for (int i = 0; i < temps.size(); i++)
	{
		temp_sum += get_F(temps[i]);
	}
	cout << "mean temperature: " << temp_sum / temps.size() <<" F"<< endl;
	vector<double> temperatures;
	for (int i = 0; i < temps.size(); i++)
	{
		temperatures.push_back(get_F(temps[i]));
	}
	sort(temperatures.begin(), temperatures.end());
	cout << " median temperature: " << temperatures[temperatures.size() / 2] << endl;
	return 0;
}