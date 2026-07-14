/*
 * Newton-Raphson Method (Command Line Interface Version)
 * * This program calculates the root of the function f(x) = x^2 - 2 
 * using the Newton-Raphson iteration method.
  
 * * Usage: 
 * ./NewtonRaphson.exe <initial_guess>
 * * How it works:
 * 1. Takes an initial guess (x0) as a command-line argument.
 * 2. Uses the formula: x_{n+1} = x_n - f(x_n) / f'(x_n)
 * 3. Iterates until the difference between consecutive values is 
 * less than the defined epsilon (0.000001).
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double f(double x) {
    return (x * x) - 2.0;
}

double derivative_f(double x) {
    return 2.0 * x;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: NewtonRaphson.exe <initial_guess>" << endl;
        return 1;
    }

    double x = stod(argv[1]);
    double epsilon = 0.000001;
    int step = 1;
    int max_iterations = 50;

    cout << fixed << setprecision(6);
    cout << "--- Newton-Raphson Iteration Starting ---" << endl;

    while (step <= max_iterations) {
        double fx = f(x);
        double dfx = derivative_f(x);

        if (dfx == 0.0) {
            cout << "Derivative is zero, mathematical error! Process stopped." << endl;
            return 1;
        }

        double next_x = x - (fx / dfx);

        cout << "Step " << step << ": x = " << x << " -> New x = " << next_x << endl;

        if (abs(next_x - x) < epsilon) {
            cout << "\nRoot successfully found! Value: " << next_x << endl;
            break;
        }

        x = next_x;
        step++;
    }

    return 0;
}