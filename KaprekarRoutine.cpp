/*
 * Kaprekar's Routine (Command Line Interface Version)
 * * This program demonstrates the Kaprekar's Routine for 4-digit numbers.
 * It is designed to run directly from the command line without interactive prompts.
 * * Usage: 
 * ./KaprekarRoutine.exe <4_digit_number>
 
 * * How it works:
 * 1. Takes a valid 4-digit number (with at least two different digits) as an argument.
 * 2. Arranges its digits in descending order to find the largest possible number.
 * 3. Arranges its digits in ascending order to find the smallest possible number.
 * 4. Subtracts the smallest number from the largest number.
 * 5. This process is repeated with the new result until the Kaprekar constant (6174) is reached.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int FindLargestNumber(int number) {
    int digits[4];
    digits[0] = number % 10;
    digits[1] = (number / 10) % 10;
    digits[2] = (number / 100) % 10;
    digits[3] = (number / 1000) % 10;
    
    sort(digits, digits + 4, greater<int>());
    
    return (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + digits[3];
}

int FindSmallestNumber(int number) {
    int digits[4];
    digits[0] = number % 10;
    digits[1] = (number / 10) % 10;
    digits[2] = (number / 100) % 10;
    digits[3] = (number / 1000) % 10;  
    
    sort(digits, digits + 4);
    
    return (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + digits[3];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: KaprekarRoutine.exe <4_digit_number>" << endl;
        return 1;
    }

    int number = stoi(argv[1]);

    if (number % 1111 == 0 || number < 1000 || number > 9999) {
        cout << "Error: Please enter a valid 4-digit number with at least two different digits." << endl;
        return 1;
    }

    int step = 1;
    
    while (number != 6174) {
        int largestNumber = FindLargestNumber(number);
        int smallestNumber = FindSmallestNumber(number);
        int newNumber = largestNumber - smallestNumber;
        
        cout << "Step " << step << ": " << largestNumber << " - " << smallestNumber << " = " << newNumber << endl;
        
        number = newNumber;
        step++;
    }

    return 0;
}