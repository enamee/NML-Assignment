#include <bits/stdc++.h>
#include "include/luFactorization.h"
using namespace std;

typedef vector<vector<double>> mtrx;

vector<double> luFactorize(mtrx a) {
    auto matrixPair = lowerAndUpper(a);
    auto l = matrixPair.first;
    auto u = matrixPair.second;
    auto y = solOfY(l, a);
    auto x = solOfX(u, y);
    return x;
}