#include<iostream>
#include "Die.h"
#include<iomanip>
using namespace std;
// client code to use the Die class goes here
void display(int die[],int  size);


int main()
{
	//int count = 0;
	//int numSides;
	Die numside1(6);
	Die numside2(12);
	int die1[7] = { 0 };
	
	int die2[13] = { 0 };
	for (int i = 0; i < 1000000; i++)
	{
		numside1.roll();
		numside2.roll();
		die1[numside1.getValue()] =die1[numside1.getValue()] + 1;
		die2[numside2.getValue()] =die2[numside2.getValue()] + 1;
	}
	
	display(die1, 7);
	display(die2, 13);
	return 0;
}
void display(int die[], int size)
{
	cout << "stat for " << size - 1 << " sided die" << endl;
	
	for (int i = 1; i < size; i++)
	{
		cout << fixed << setprecision(2) << endl;

		cout << "Side  " << i << ": " << (static_cast<double>(die[i] *100)) / 1000000 << "%" << endl;
	}
}