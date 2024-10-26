#include <bits/stdc++.h>
#include "include/utils.h"
using namespace std;

typedef vector<vector<double>> mtrx;

void appInterface() {
    cout << "Select a method" << endl;
    cout << "1. Jacobi Iterative Method" << endl;
    cout << "2. Gauss-Seidel Iterative Method" << endl;
    cout << "3. Gauss Elimination" << endl;
    cout << "4. Gauss Jordan Elimination" << endl;
    cout << "5. LU Factorization" << endl;
    cout << "6. Bi-section Method" << endl;
    cout << "7. False Position Method" << endl;
    cout << "8. Secant Method" << endl;
    cout << "9. Newton-Raphson Method" << endl;
    cout << "10. Runge-Kutta Method" << endl;
    cout << "11. Matrix Inversion" << endl;
    cout << "12. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        // Jacobi Iterative Method
    } else if (choice == 2) {
        // Gauss-Seidel Iterative Method
    } else if (choice == 3) {
        // Gauss Elimination
    } else if (choice == 4) {
        // Gauss Jordan Elimination
    } else if (choice == 5) {
        // LU Factorization
        cout << "No. of equations: " << endl;
        int n;
        cin >> n;
        mtrx a(n, vector<double>(n+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n+1; j++) {
                cin >> a[i][j];
            }
        }
        auto res = luFactorize(a);
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
    } else if (choice == 6) {
        // Bi-section Method
    } else if (choice == 7) {
        // False Position Method
    } else if (choice == 8) {
        // Secant Method
    } else if (choice == 9) {
        // Newton-Raphson Method
    } else if (choice == 10) {
        // Runge-Kutta Method
    } else if (choice == 11) {
        // Matrix Inversion
    } else if (choice == 12) {
        // Exit
    } else {
        cout << "Invalid choice" << endl;
    }
}