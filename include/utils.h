#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double>> mtrx;

vector<double> luFactorize(mtrx a);
void Jacobi(vector<vector<double>>&A,int step,int n);
void Gauss_seidal(vector<vector<double>>A,int step,int n);
void Newton_rapson(double a,double b,double c);
void Secant_method(double a,double b,double c);