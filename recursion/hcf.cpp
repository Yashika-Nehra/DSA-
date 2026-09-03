#include <iostream>
using namespace std;

int DAT[1001][1001];

int hcf(int a, int b){
    if(b==0){
        return a;
    }
    if(DAT[a][b]==0){
        DAT[a][b]=hcf(b, a%b);
    }
    return DAT[a][b];
}
int main(){
    int a,b;
    cout<<"Enter two numbers to find their HCF: ";
    cin>>a>>b;
    int result=hcf(a,b);
    cout<<"HCF of "<<a<<" and "<<b<<" is: "<<result<<endl;
    return 0;
}