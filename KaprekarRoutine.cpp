#include <iostream>
#include <algorithm>
using namespace std;

/*
 * This program demonstrates the Kaprekar's Routine for 4 digit numbers.
 * * How it works:
 * 1. Takes a valid 4 digit number from the user (not all digits the same).
 * 2. Arranges its digits in descending order to find the largest possible number.
 * 3. Arranges its digits in ascending order to find the smallest possible number.
 * 4. Subtracts the smallest number from the largest number.
 * 5. This process is repeated with the new result until the Kaprekar constant (6174) is reached.
 */

int FindLargestNumber(int number) {
    int digits[4];

    digits[0] = number % 10;
    digits[1] = (number / 10) % 10;
    digits[2] = (number / 100) % 10;
    digits[3] = (number / 1000) % 10;

    sort(digits, digits + 4, greater<int>());

    int largestNumber = (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + digits[3];
    return largestNumber;
}

int FindSmallestNumber(int number) {
    int digits[4];

    digits[0] = number % 10;
    digits[1] = (number / 10) % 10;
    digits[2] = (number / 100) % 10;
    digits[3] = (number / 1000) % 10;  

    sort(digits, digits + 4);

    int smallestNumber = (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + digits[3];
    return smallestNumber;
}

int main() {
    int number = 0;

    while (number % 1111 == 0 || (number < 1000 || number > 9999)) {
        cout << "Please enter a 4-digit number with at least two different digits:" << endl;
        cin >> number;
        
        if (number % 1111 == 0) {
            cout << "All digits of the number you entered are the same." << endl;
        }
        else if (number < 1000 || number > 9999) {
            cout << "The number you entered is not 4 digits long." << endl;
        }
        else {
            break;
        }
    }  
    
    int step = 1;
    cout << "\n--- Kaprekar Routine Starting ---" << endl;
    
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