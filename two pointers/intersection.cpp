#include <iostream>
#include <algorithm>
using namespace std;

int intersection(int A[], int m, int B[], int n, int C[]){
    sort(A, A+m);
    sort(B, B+n);
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j]) i++;
        else if(A[i]>B[j]) j++;
        else{
            C[k++]=A[i++];
            j++;
        }
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
    int C[min(m,n)];
    int size = intersection(A, m, B, n, C);
    cout<<"Intersection of the two arrays is: ";
    for(int i=0;i<size;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
    return 0;
}                       