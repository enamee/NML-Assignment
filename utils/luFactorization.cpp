#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double>> mtrx;

mtrx fixPivots(mtrx a) {
    int n = a.size();
    for (int i = 0; i < 2; i++) {  // running two times to ensure pivot fixing if possible
        for (int k = 0; k < n; k++) {
            if (!a[k][k]) {
                for (int i = 0; i < n; i++) {
                    if (i != k and a[i][k]) {
                        for (int j = 0; j < n+1; j++) {
                            swap(a[k][j], a[i][j]);
                        }
                        break;
                    }
                }
            }
        }
    }
    return a;
}

pair<mtrx, mtrx> lowerAndUpper(mtrx a) {
    int n = a.size();
    mtrx l(n, vector<double>(n, 0));
    mtrx u = l;
    for (int i = 0; i < n; i++) {
        l[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += l[i][k] * u[k][j];
            }
            if (j < i) l[i][j] = (a[i][j] - sum) / u[j][j];
            else {
                u[i][j] = a[i][j] - sum;
                if (u[i][j] == 0)  {
                    a = fixPivots(a);
                }
            } 
        }
    }
    return {l, u};
}

vector<double> solOfY(mtrx l, mtrx a) {
    int n = l.size();
    vector<double> y(n, 0);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += l[i][j] * y[j];
        }
        y[i] = a[i][n] - sum;
    }
    return y;
}

vector<double> solOfX(mtrx u, vector<double> y) {
    int n = u.size();
    vector<double> x(n, 0);
    for (int i = n-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < n; j++) {
            sum += u[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / u[i][i];
    }
    return x;
}