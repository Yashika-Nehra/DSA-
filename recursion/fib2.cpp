#include <iostream>
using namespace std;
int DAT[1001];

int fib(int n){
    if(n==1 || n==2){
        return DAT[n]=n-1;
    }
    else{
        if(DAT[n]==0){
            DAT[n]=fib(n-1)+fib(n-2);
        }
        return DAT[n];
    }
}

int main(){
    int n;
    cout<<"Enter the position of Fibonacci number: ";
    cin>>n;
    int result=fib(n);
    cout<<"Fibonacci number at position "<<n<<" is: "<<result<<endl;
    return 0;
}