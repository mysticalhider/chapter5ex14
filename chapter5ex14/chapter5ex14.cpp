/*
File Name: chapter5ex14.cpp
Programmer: Perrin
Requirements: 

Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.

Once all the names have been read, it reports which student would be at the front of the line and

which one would be at the end of the line. You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.

i ended up just sorting the whole list
*/

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

