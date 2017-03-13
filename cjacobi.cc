#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

long jacobi(long a, long n){
    if(a<=1)
        return a;
    else if(a%2==1){
        if((a%4==3)&&(n%4==3))
            return (-1 * jacobi(n%a, a));
        else
            return jacobi(n%a, a);
    }
    else{
        if((n%8==1)||(n%8==7))
            return jacobi(a/2, n);
        else
            return (-1 * jacobi(a/2, n));
    }
}

long findQR(long a, long n){
    for(long i=0; i<((n/2)+2); i++){
        if(((int)pow(i,2)%n)==a)
            return i;
    }
}

int main(){
    long x,y;

    cout << "Input a: ";
    cin >> x;
    cout << "Input n: ";
    cin >> y;

    if(x<=0)
        x = x%y + y;
    long jacobian;
    jacobian = jacobi(x, y);
    
    cout <<"Jacobi("<< x <<", "<< y <<") = "<< jacobian <<endl;
    
    if(jacobian == 1)
        cout <<"X which fulfilled X^2 congruent with "<< x <<" (mod " << y <<") is " << findQR(x, y) << endl;

    return 0;
}


