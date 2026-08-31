#include <iostream>
using namespace std;

void reverseArray(int A[], int n){
    int start=0, end=n-1;
    while(start<end){
        int temp=A[start];
        A[start]=A[end];
        A[end]=temp;
        start++;
        end--;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    reverseArray(A, n);
    cout<<"Reversed array is: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}