#include <iostream>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << B << endl;
        return;
    }
    towerOfHanoi(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << B << endl;
    towerOfHanoi(n - 1, C, B, A);

}
int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}