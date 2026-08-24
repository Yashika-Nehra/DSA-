#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int L, int mid, int R) {
    int n1 = mid - L + 1;
    int n2 = R - mid;

    int Larr[n1], Rarr[n2];

    for (int i = 0; i < n1; i++)
        Larr[i] = A[L + i];
    for (int j = 0; j < n2; j++)
        Rarr[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = L;

    while (i < n1 && j < n2) {
        if (Larr[i] <= Rarr[j]) {
            A[k++] = Larr[i++];
        } else {
            A[k++] = Rarr[j++];
        }
    }

    while (i < n1) {
        A[k++] = Larr[i++];
    }

    while (j < n2) {
        A[k++] = Rarr[j++];
    }
}

void mergeSort(int A[], int L, int R) {
    if (L >= R) return;

    int mid = L + (R - L) / 2;

    mergeSort(A, L, mid);
    mergeSort(A, mid + 1, R);
    merge(A, L, mid, R);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}