#include <iostream>
#include <algorithm>
using namespace std;

int difference(int A[], int m, int B[], int n, int C[]){
    sort(A, A+m);
    sort(B, B+n);
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j]){
            C[k++]=A[i++];
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    while(i<m){
        C[k++]=A[i++];
    }
    return k;
}
int main(){
    int m,n;
    cout<<"Enter the size of first array: ";
    cin>>m;
    int A[m];
    cout<<"Enter the elements of first array: ";
    for(int i=0;i<m;i++){
        cin>>A[i];
    }
    cout<<"Enter the size of second array: ";
    cin>>n;
    int B[n];
    cout<<"Enter the elements of second array: ";
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    int C[m];
    int size = difference(A, m, B, n, C);
    cout<<"Difference of the two arrays (A - B) is: ";
    for(int i=0;i<size;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
    return 0;
}