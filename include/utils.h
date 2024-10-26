#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double>> mtrx;

vector<double> luFactorize(mtrx a);
void Jacobi(vector<vector<double>>&A,int step,int n);
