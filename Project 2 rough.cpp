//NAME: David Boatright
//PROGRAM: PGM2
//DATE: 8/28/2024
//DESCRIPTION:Ask the user for four numbers and organizes and displays those numbers.
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main()
{
	char choice = 'y';
	const int listSize = 4;
	int list[listSize];
	while (tolower(choice) != 'n') {
		int sum = 0;
		// Gets user input, adds it to the list then adds it to a sum.
		for (int i = 0; i < listSize; i++) {
			int input;
			cout << "Enter number " << i + 1 <<":";
			cin >> input;
			list[i] = input;
			sum += list[i];
		}
		// Selection sort- sorts the list.
		for (int i = 0; i < listSize - 1; i++) {
			int temp;
			int smallestIn = i;
			for (int j = i; j < listSize; j++) {
				if (list[j] < list[smallestIn]) {
					smallestIn = j;
				}
			}
			temp = list[i];
			list[i] = list[smallestIn];
			list[smallestIn] = temp;
		}
		// Outputs the data in various ways.
		cout << "Largest: " << list[listSize - 1] << endl;
		cout << "Smallest: " << list[0] << endl;
		cout << fixed << setprecision(2) << "Average: " << sum / (float)listSize << endl;
		cout << "Ascending Order:" << endl;
		for (int i = 0; i < listSize; i++) {
			cout << list[i] << endl;
		}
		cout << "Descending Order:" << endl;
		for (int i = listSize - 1; i >= 0; i--) {
			cout << list[i] << endl;
		}
		// Prompts the user to continue the list.
		cout << "Go again? (y/n)";
		cin >> choice;
	}
}
