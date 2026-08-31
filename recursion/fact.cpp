#include <iostream>
using namespace std;

long long fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter a number to find its factorial: ";
    cin>>n;

    if(n<0){
        cout<<"Factorial is not defined for negative numbers"<<endl;
        return 0;
    }

    long long result=fact(n);
    cout<<"Factorial of "<<n<<" is: "<<result<<endl;
    return 0;
}