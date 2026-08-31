#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    int start=0, end=s.length()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    if(isPalindrome(s)){
        cout<<s<<" is a palindrome"<<endl;
    }
    else{
        cout<<s<<" is not a palindrome"<<endl;
    }
    return 0;
}