#include <bits/stdc++.h>
#include "luFactorization.h"
using namespace std;

typedef vector<vector<double>> mtrx;

double func(vector<int> e, double x) {
    double res = 0;
    for (int i=0; i<e.size(); ++i) {
        res += e[i] * pow(x, e.size()-i-1);
    }
    return res;
}

pair<int, int> getRange(vector<int> e, int start) {
    int count = 0;
    for (int i=start; ; i++) {
        if (func(e, i)*func(e, i+1) <= 0) {
            return {i, i+1};
        }
    }
    return {NULL, NULL};
}

vector<double> luFactorize(mtrx a) {
    auto matrixPair = lowerAndUpper(a);
    auto l = matrixPair.first;
    auto u = matrixPair.second;
    auto y = solOfY(l, a);
    auto x = solOfX(u, y);
    return x;
}
void Jacobi(vector<vector<double>>&A,int step,int n)
     {

   vector<double>X0(n+1,0);

    vector<double>X(n+1,0);
    int t =step;

   //ouble err = .000001;
    int p=0;
while (t--) {


for(int i=1;i<=n;i++){
X[i]=(1.0/A[i][i]);
    double cons=A[i][n+1];
    double sum=0;

    for(int j=1;j<=n;j++){
        if(j==i){
            continue;
        }
        sum+=X0[i]*A[i][j];
    }
X[i]=X[i]*(cons-sum);
}


       //ut << "Step " << i+1 << " : ";
       //cou<<"(x"<<i+1<<" - x "<<i<<")= " <<xn - x1 << "|\t\t (y"<<i+1<<" - y"<<i<<")= "<<  yn - y1<< "|\t\t (z"<<i+1<<" - z"<<i<<")= " << zn - z1 << endl;



    p++;
    for(int i=1;i<=n;i++)
         {

           X0[i]=X[i];
        }

}




cout<<endl<<endl<<"Steps "<<p<<"\t\t Final Output"<<endl;
for(int i=1;i<=n;i++){
    cout<<"X"<<i<<" "<<X[i]<<endl;
}

}
void Gauss_seidal(vector<vector<double>>A,int step,int n)
{

   vector<double>X0(n+1,0);

    vector<double>X(n+1,0);
    int t =step;

   //ouble err = .000001;
    int p= 0;
while (t--) {


for(int i=1;i<=n;i++){
X[i]=(1.0/A[i][i]);
    double cons=A[i][n+1];
    double sum=0;

    for(int j=1;j<=n;j++){
        if(j==i){
            continue;
        }
        sum+=X0[i]*A[i][j];
    }
X[i]=X[i]*(cons-sum);

for(int k=1;k<=i;k++){
    X0[k]=X[k];
}

}





        p++;
for(int i=1;i<=n;i++)
         {

           X0[i]=X[i];
        }

}



cout<<endl<<endl<<"Steps "<<p<<"\t\t Final Output"<<endl;
for(int i=1;i<=n;i++){
    cout<<"X"<<i<<" "<<X[i]<<endl;
}

}
void Newton_rapson(double a,double b,double c)
{


    double a1;


    a1=2*a;
    double x0=0,x1;
    double fx,fx1;
    int step=0;
    while(true){
            fx=a*x0*x0+b*x0+c;
    fx1=a1*x0+b;
step++;
    if(fx==0){
        cout<<"The final answer="<<x0<<endl;
        return;
    }
    if(fx1==0){
        cout<<"Mathematical Error"<<endl;

        break;

    }
     x1=x0-(fx/fx1);

    fx=a*x1*x1+b*x1+c;
    if(fx==0){
        cout<<"The final answer="<<x1<<endl;
       return;

    }
    if(abs(x1-x0)<=.00001){
        cout<<"The final answer="<<x1<<endl;
        break;

    }
    x0=x1;
    }}
    void Secant_method(double a,double b,double c)
{


    double a1;


    //a1=2*a;
    double x1,x2,x3;
    cout<<"Enter the initial assumed value of x1 and x2"<<endl;
    cin>>x1>>x2;
    double fx1,fx2;
    int step=0;
    while(true){
            fx1=a*x1*x1+b*x1+c;
    fx2=a*x2*x2+b*x2+c;
step++;
    if(fx1==0){
        cout<<"The final answer="<<x1<<endl;
        return;
    }
     if(fx2==0){
        cout<<"The final answer="<<x2<<endl;
        exit(0);
    }
    if(abs(fx1-fx2)==0){
        cout<<"Mathematical Error"<<endl;

        break;

    }
     x3=x2-(fx2*(x2-x1))/(fx2-fx1);


    double fx3=a*x3*x3+b*x3+c;
    if(fx3==0){
        cout<<"The final answer="<<x3<<endl;
       return;

    }
    if(abs(x3-x2)<=.00001){
        cout<<"The final answer="<<x3<<endl;
        break;

    }
    x1=x2,x2=x3;

    }

}

double bisection(vector<int> e, double start, double tolerance) {
    auto range = getRange(e, start);
    double a = range.first, b = range.second;
    if (func(e, a) == 0) return a;
    if (func(e, b) == 0) return b;

    if (func(e, a) * func(e, b) >= 0) {
        cout << "You have not assumed right a and b\n";
        return NAN;
    }
    double c = a;
    while (abs((b-a)) >= tolerance) {
        // Find middle point
        c = (a+b)/2;
 
        // Check if middle point is root
        if (func(e, c) == 0.0)
            break;
 
        // Decide the side to repeat the steps
        else if (func(e, c)*func(e, a) < 0)
            b = c;
        else
            a = c;
        // cout << "Approximate root: " << c << endl;
        // cout << abs(11.099-c) << endl;
        // cout << abs(b-a) << endl;
    }
    return c;
}

double falsePosition(vector<int> e, double start, double tolerance) {
    auto range = getRange(e, start);
    double a = range.first, b = range.second;
    if (func(e, a) == 0) return a;
    if (func(e, b) == 0) return b;

    if (func(e, a) * func(e, b) >= 0) {
        cout << "You have not assumed right a and b\n";
        return NAN;
    }
    double c = a;
    while (abs((b-a)) >= tolerance) {
        // Find intersection point
        c = (a*func(e, b)-b*func(e, a))/(func(e, b)-func(e, a));
 
        // Check if intersection point is root
        if (func(e, c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(e, c)*func(e, a) < 0)
            b = c;
        else
            a = c;
        // cout << "Approximate root: " << c << endl;
        // cout << abs(11.099-c) << endl;
        // cout << abs(b-a) << endl;
    }
    return c;
}