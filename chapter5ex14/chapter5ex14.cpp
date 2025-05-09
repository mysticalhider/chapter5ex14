// chapter5ex14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector> // i wanted to get myslef familuar before i did thoes assignments
#include <algorithm>// searched and found that i could use this to sort https://www.geeksforgeeks.org/sort-c-stl/
using namespace std;

double numofstudents()
{
	int numofs;
	cout << "How many students do you have in your calss?" << endl;
	cin >> numofs;
	return numofs;
}

vector<string> readnames(int numofs)
{
	ifstream infile("C:/Users/perri/Downloads/names.txt");
	vector<string> names = {};
	string line;
	if (!infile) 
	{ 
		cout << "error reading file. exiting" << endl; 
	}
	for (int i = 0; i < numofs && getline(infile,line); i ++)
	{
		names.push_back(line);
	}
	infile.close();
	sort(names.begin(), names.end()); // sorts the whole file alpabeticly
	
	return names;

}
int main()
{
	bool exit = 0;
	double num;
	do {
		num = numofstudents();
		if (num < 0 || num > 25)
		{
			cout << "that is not a valid selection, please enter in a new number" << endl;
			num = numofstudents();
		}
		vector<string> names = readnames(num);
		for (auto i : names)
		{
			cout << i << endl;
		}

		cout << "Type 1 to exit; 0 to cont. " << endl;
		cin >> exit;
		switch (exit)
		{
		case 1:
			break;
		case 0:
			cout << "continueing... " << endl;
			break;
		default:
			cout << "invalid selection, exiting";
			exit = 1;
			break;
		}
		
	} while (exit == 0);
}

