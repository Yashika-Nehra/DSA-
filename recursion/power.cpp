#include <iostream>
using namespace std;

long long DAT[1001];
int BASE;

long long power(int n){
    if(n==0){
        return DAT[0]=1;
    }
    if(DAT[n]==0){
        DAT[n]=BASE*power(n-1);
    }
    return DAT[n];
}
int main(){
    int base,n;
    cout<<"Enter base and power: ";
    cin>>base>>n;
    BASE=base;
    long long result=power(n);
    cout<<base<<"^"<<n<<" = "<<result<<endl;
    return 0;
}