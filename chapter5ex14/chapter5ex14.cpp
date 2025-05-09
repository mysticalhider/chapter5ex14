/*
File Name : chapter5ex14.cpp
Programmer : Perrin
Requirements :
updated main so it reads a diffrent file and goes to end of list
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector> // i wanted to get myslef familuar before i did thoes assignments
#include <algorithm>// searched and found that i could use this to sort https://www.geeksforgeeks.org/sort-c-stl/
using namespace std;

vector<string> readnames()
{
	ifstream infile("C:/Users/perri/Downloads/LineUp.txt");
	vector<string> names = {};
	string line;
	if (!infile) 
	{ 
		cout << "error reading file. exiting" << endl; 
	}
	while (getline(infile,line))
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
	do {
		vector<string> names = readnames();
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

