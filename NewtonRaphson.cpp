#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 * This program demonstrates the Newton-Raphson Method.
 * It finds the root of the function f(x) = x^2 - 2 (which is the square root of 2).
 */

double f(double x) {
    return (x * x) - 2.0;
}

double derivative_f(double x) {
    return 2.0 * x;
}

int main() {
    double x = 1.0; 
    double epsilon = 0.000001; 
    int step = 1;
    int max_iterations = 50; 

    cout << fixed << setprecision(6);
    cout << "--- Newton-Raphson Iteration Starting ---" << endl;

    while (step <= max_iterations) {
        double fx = f(x);
        double dfx = derivative_f(x);

        if (dfx == 0.0) {
            cout << "Turev sifir oldu, matematiksel hata! Islem durduruldu." << endl;
            break;
        }

        double next_x = x - (fx / dfx);

        cout << "Step " << step << ": x = " << x << " -> New x = " << next_x << endl;

        if (abs(next_x - x) < epsilon) {
            cout << "\nKok basariyla bulundu! Deger: " << next_x << endl;
            break;
        }
        x = next_x;
        step++;
    }
    return 0;
}