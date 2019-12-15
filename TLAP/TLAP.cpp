// TLAP.cpp : Defines the entry point for the application.
//

#include "TLAP.h"

using namespace std;


int main()
{
	//_02_01_pr_chr();
	//_02_02_pr_rows();
	//_02_03_pr_half_square();
	//_02_04_pr_pyramid();
	//_02_05_luhn_01();
	//_02_05_luhn_02();
	//_02_05_luhn_03();
	//_02_05_luhn_04();
	//_02_05_luhn_05();
	//_02_05_luhn_06();
	//_02_05_luhn_07();
	//_02_05_luhn_08();
	_02_05_luhn_09();
	return 0;
}



// Think like a programmer, chapter 2, 13, Luhn (09)
// READ INTEGERS

int _02_05_luhn_09() {
	char response;
	int number;
	int posCount = 0;
	int negCount = 0;

	cout << "Please enter 10 integers separated by <ENTER>: ";

	for (int i = 0; i < 10; i++) {
		cin >> number;
		if (number > 0) posCount++;
		if (number < 0) negCount++;
	}

	cout << "Do you want the (p)ositive or (n)egative number count? ";
	cin >> response;

	if (response == 'p')
		cout << "The positive count is " << posCount << "\n";

	else if (response == 'n')
		cout << "The negative count is " << negCount << "\n";

	return 0;
}



// Think like a programmer, chapter 2, 12, Luhn (08)
// SIMPLE CHECKSUM VALIDATION, VARIABLE LENGTH BUT EVEN 
int _02_05_luhn_08() {
	char digit; 
	int checksum = 0;
	int pos = 1;

	cout << "Enter a number with an even number of digits: ";
	digit = cin.get();

	while (digit != 10) {
		if (pos % 2 == 0) {
			checksum += digit - '0';
		} else {
			checksum += doubleDigitValue_01(digit - '0');
		}

		digit = cin.get();
		pos++;
	}
	
	cout << "Checksum is: " << checksum << "\n";
	if (checksum % 10 == 0) {
		cout << "Checksum is divisible by 10, checksum is valid.\n";
	}
	else {
		cout << "Checksum is not divisible by 10, checksum is invalid.\n";
	}

	return 0;
}


// Think like a programmer, chapter 2, 11, Luhn (07)
// READ CHARS ONE BY ONE
// Find "Enter" int value
int _02_05_luhn_07() {
	cout << "Enter a number: ";
	char digit;
	while (true) {
		digit = cin.get();
		cout << int(digit) << " ";
	}
	return 0;
}



// Think like a programmer, chapter 2, 10, Luhn (06)
// SIMPLE CHECKSUM VALIDATION, FIXED LENGTH (2)
int _02_05_luhn_06() {
	char digit;
	int checksum = 0;
	cout << "Enter a 6 digits number: ";

	for (int pos = 1; pos <= 6; pos++) {
		cin >> digit;

		if (pos %2 == 0) {
			checksum += digit - '0';
		} else {
			checksum += doubleDigitValue_01(digit - '0');
		}
	}
	cout << "Checksum is: " << checksum << "\n";
	if (checksum % 10 == 0) {
		cout << "Checksum is divisible by 10, checksum is valid.\n";
	} else {
		cout << "Checksum is not divisible by 10, checksum is invalid.\n";
	}

	return 0;
}


// Think like a programmer, chapter 2, 09, Luhn (05)
// SIMPLE CHECKSUM VALIDATION, FIXED LENGTH (1)
int _02_05_luhn_05() {
	char digit;
	int checksum = 0;
	cout << "Enter a 6 digits number: ";

	for (int pos = 0; pos < 6; pos++) {
		cin >> digit; 
		checksum += digit - '0';
	}
	cout << "Checksum is: " << checksum << "\n";
	if (checksum % 10 == 0) {
		cout << "Checksum is divisible by 10, checksum is valid.\n";
	} else {
		cout << "Checksum is not divisible by 10, checksum is invalid.\n";
	}

	return 0;
}

// Think like a programmer, chapter 2, 08, Luhn (04)
// Reading each digit separately (2).
// Chars to int.
int _02_05_luhn_04() {
	char digit;
	int sum;

	cout << "Enter a one-digit number: ";
	digit = cin.get();

	sum = digit - '0'; // conversion

	cout << "Is the sum of digits " << sum << "?\n";

	return 0;

}


// Think like a programmer, chapter 2, 07, Luhn (03)
// Reading each digit separately (1).
// Chars to int.
int _02_05_luhn_03() {
	char digit; 
	int sum;

	cout << "Enter a one-digit number: ";
	digit = cin.get();

	sum = digit; // conversion

	cout << "Is the sum of digits " << sum << "?\n";

	return 0;
}



// Think like a programmer, chapter 2, 06, Luhn (02)
// Treating doubled numbers 10 and greater according to their individual digits (2).
// Function definitions
int _02_05_luhn_02()
{
	int digit;
	int dblDigit;

	cout << "Enter a single number digit (0-9): ";
	cin >> digit;

	dblDigit = doubleDigitValue_01(digit);

	
	cout << "Sum of digits is: " << dblDigit << "\n";

	return 0;
}

// Think like a programmer, chapter 2, 06, Luhn (02)
int doubleDigitValue_01(int digit) {
	int dblDigit;
	int sum;

	dblDigit = digit * 2;

	if (dblDigit >= 10)
		sum = 1 + (dblDigit % 10);
	else
		sum = dblDigit;

	return sum;
}


// Think like a programmer, chapter 2, 05, Luhn (01)
// Treating doubled numbers 10 and greater according to their individual digits (1)
int _02_05_luhn_01()
{
	int digit;
	int dblDigit; 
	int sum;

	cout <<  "Enter a single number digit (0-9): ";
	cin >> digit;

	dblDigit = digit * 2;

	if (dblDigit >= 10) 
		sum = 1 + (dblDigit % 10);
	else 
		sum = dblDigit; 
	
	cout << "Sum of digits is: " << dblDigit << "\n";

	return 0;
}


// Think like a programmer, chapter 2, 04, print pyramid
int _02_04_pr_pyramid()
{
	for (int row = 0; row <= 8; row++) {
		for (int chr = 0; chr <= abs(4 - row); chr++) {
			cout << "#";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";

	for (int row = 0; row <= 8; row++) {
		for (int chr = 0; chr <= 4 - abs(4 - row); chr++) {
			cout << "#";
		}
		cout << "\n";
	}
	
	return 0;
}

// Think like a programmer, chapter 2, 01, print half squares
int _02_03_pr_half_square()
{
	for (int row = 0; row <= 4; row++) {
		for (int chr = 0; chr <= (4 - row); chr++) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;

}


// Think like a programmer, chapter 2, 01, print rows
int _02_02_pr_rows()
{
	for (int row = 0; row <= 4; row++) {
		for (int chr = 0; chr <= 4; chr++) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
// Think like a programmer, chapter 2, 01, print chars
int _02_01_pr_chr()
{
	for (int chr = 0; chr <= 4; chr++) {
		cout << "#";
	}
	cout << "\n";
	return 0;
}