#include<iostream>
#include <cstdlib>
using namespace std;

int main()
{
	double intHighNum = 1, intHighDen = 1, intLowNum = 0, intLowDen = 1, intTempNum, intTempDen, input, high = 1.0, low = 0.0, temp;
	int count;
	bool quit = false;
	do
	{
		cout << "Please enter the number you would like to approximate(decimal number between 1 and 0): ";
		cin >> input;
		if (input <= 0 || input >= 1)
			quit = true;
		if (!quit)
		{
			cout << "Please enter the number of repititions: ";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				intTempNum = intHighNum + intLowNum;
				intTempDen = intHighDen + intLowDen;
				temp = intTempNum / intTempDen;
				if (temp > input)
				{
					intHighNum = intTempNum;
					intHighDen = intTempDen;
					high = intHighNum / intHighDen;
				}
				else if (temp < input)
				{
					intLowNum = intTempNum;
					intLowDen = intTempDen;
					low = intLowNum / intLowDen;
				}
			}
			if (high - count > count - low)
				cout << "the answer is: " << intLowNum << "/" << intLowDen << endl;
			else
				cout << "the answer is: " << intHighNum << "/" << intHighDen << endl;
			intHighNum = 1;
			intHighDen = 1;
			intLowNum = 0;
			intLowDen = 1;
			high = 1.0;
			low = 0.0;
		}
	} while (!quit);
	return 0;
}