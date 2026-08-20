#include <iostream>
using namespace std;

int merge(int A[], int m, int B[], int n, int C[]){
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < m) {
        C[k++] = A[i++];
    }
    while (j < n) {
        C[k++] = B[j++];
    }
    return k;
}

int main(){
    int m, n;
    cout << "Enter the size of first array: ";
    cin >> m;
    int A[m];
    cout << "Enter the elements of first array: ";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    cout << "Enter the size of second array: ";
    cin >> n;
    int B[n];
    cout << "Enter the elements of second array: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    int C[m + n];
    int size = merge(A, m, B, n, C);
    cout << "Merged array: ";
    for (int i = 0; i < size; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}