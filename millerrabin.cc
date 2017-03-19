#include<iostream>
#include<math.h>
#include<random>

using namespace std;

long fast_modular_exponentiation(long a, long b, long n){
    /*
    Doing Fast Modular Exponentiation a^b mod n
    */
    bitset<32> bbin(b);     //integer to 32 bit binary
    long c=0;
    long d=1;
    long flag=0;
    for(int i=32;i>=0;i--){
        if(bbin[i]==1)
            flag++;
        if(flag>0){
            c*=2;
            d=(d*d)%n;
            if(bbin[i]==1){
                c+=1;
                d=(d*a)%n;
            }
        }
    }
    return d;
}

int primality_test(long n){
    /*
    Miller-Rabin's Primality Test
    */
    long k=0;
    long q=n-1;
    while(q%2==0){
        q/=2;
        k+=1; 
    }
    long a;
    random_device rd;                                   //Random number
    mt19937 generator(rd());                            //generator with
    uniform_int_distribution<long> distribution(2,n-2); //uniform 
    a = distribution(generator);                        //distribution
    if(fast_modular_exponentiation(a,q,n) == 1)
        return 1;
    for(int j=1;j/2<k;j*=2){
        if(fast_modular_exponentiation(a,j*q,n)== n-1)
            return 1;
    }
    return 0;
}

int main(){
    
    int n,t;
    
    cout<<"Input n"<<endl;
    cin>>n;
    cout<<"How many time you wanted to check primality?"<<endl;
    cin>>t;
    
    int primality=1;
    for(int i=0;i<t;i++){
        if(primality_test(n)==0){
            primality=0;
            break;
        }
    } 
    
    if(primality==1)
        cout<<"Maybe Prime"<<endl;
    else
        cout<<"Composite"<<endl;

    return 0;
}
