#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<double>> mtrx;
mtrx fixPivots(mtrx);
pair<mtrx, mtrx> lowerAndUpper(mtrx);
vector<double> solOfY(mtrx, mtrx);
vector<double> solOfX(mtrx, vector<double>);
