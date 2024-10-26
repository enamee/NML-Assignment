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