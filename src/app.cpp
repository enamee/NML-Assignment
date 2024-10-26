#include <bits/stdc++.h>
#include <python.h>
#include "include/utils.h"
using namespace std;

typedef vector<vector<double>> mtrx;

void executePythonScript(const string &moduleName)
{
    PyObject *pName = PyUnicode_FromString(moduleName.c_str());
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL)
    {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "main");
        if (pFunc && PyCallable_Check(pFunc))
        {
            PyObject *pValue = PyObject_CallObject(pFunc, NULL);
            Py_XDECREF(pValue);
        }
        else
        {
            cerr << "Function 'main' not found in module '" << moduleName << "'" << endl;
            PyErr_Print();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else
    {
        PyErr_Print();
        cerr << "Failed to load module '" << moduleName << "'" << endl;
    }
}

void appInterface()
{
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
    if (choice == 1)
    {
        // Jacobi Iterative Method
        int n, step;

        cout << "Enter the number of Equations:" << endl;
        cin >> n;
        cout << "Enter the number of steps" << endl;
        cin >> step;
        vector<vector<double>> A(n + 1, vector<double>(n + 2));
        cout << "Enter the coefficents of the equations" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                cin >> A[i][j];
            }
        }
        Jacobi(A, step, n);
    }
    else if (choice == 2)
    {
        // Gauss-Seidel Iterative Method
        int n, step;

        cout << "Enter the number of Equations:" << endl;
        cin >> n;
        cout << "Enter the number of steps" << endl;
        cin >> step;
        vector<vector<double>> A(n + 1, vector<double>(n + 2));
        cout << "Enter the coefficents of the equations" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                cin >> A[i][j];
            }
        }

        Gauss_seidal(A, step, n);
    }
    else if (choice == 3)
    {
        // Gauss Elimination
        executePythonScript("utils/Gauss_eli");
    }
    else if (choice == 4)
    {
        // Gauss Jordan Elimination
        executePythonScript("utils/Gauss_Jordan");
    }
    else if (choice == 5)
    {
        // LU Factorization
        cout << "No. of equations: " << endl;
        int n;
        cin >> n;
        mtrx a(n, vector<double>(n + 1, 0));
        cout << "Enter the coefficents of the equations" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cin >> a[i][j];
            }
        }
        auto res = luFactorize(a);
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
    }
    else if (choice == 6)
    {
        // Bi-section Method
        int highestPower;
        cout << "Highest power of x in f(x): ";
        cin >> highestPower;
        vector<int> e = vector<int>(highestPower + 1);
        cout << "Coefficients values (from x^n to x^0): ";
        for (auto &c : e)
        {
            cin >> c;
        }
        cout << "Enter the value to search from: ";
        double start;
        cin >> start;
        cout << "Enter tolerance: ";
        double tolerance;
        cin >> tolerance;
        cout << "Approximate root: " << bisection(e, start, tolerance);
    }
    else if (choice == 7)
    {
        // False Position Method
        int highestPower;
        cout << "Highest power of x in f(x): ";
        cin >> highestPower;
        vector<int> e = vector<int>(highestPower + 1);
        cout << "Coefficients values (from x^n to x^0): ";
        for (auto &c : e)
        {
            cin >> c;
        }
        cout << "Enter the value to search from: ";
        double start;
        cin >> start;
        cout << "Enter tolerance: ";
        double tolerance;
        cin >> tolerance;
        cout << "Approximate root: " << falsePosition(e, start, tolerance);
    }
    else if (choice == 8)
    {
        // Secant Method
        cout << "enter the coefficients of the equation" << endl;
        double a, b, c;
        cin >> a >> b >> c;
        Secant_method(a, b, c);
    }
    else if (choice == 9)
    {
        // Newton-Raphson Method
        cout << "enter the coefficients of the equation" << endl;
        double a, b, c;
        cin >> a >> b >> c;

        Newton_rapson(a, b, c);
    }
    else if (choice == 10)
    {
        // Runge-Kutta Method
        executePythonScript("utils/Runge_kutta");
    }
    else if (choice == 11)
    {
        // Matrix Inversion
        executePythonScript("utils/Matrix_inverse");
    }
    else if (choice == 12)
    {
        // Exit
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}