#include <bits/stdc++.h>
using namespace std;

int stk[100];
int top = -1;

void push(int x){
    top++;
    stk[top]=x;
}

int pop(){
    int x=stk[top];
    top--;
    return x;
}

int main(){
    string exp;
    cin>>exp;
    int i=0,x;
    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            int num=0;
            while(exp[i]!=',' && exp[i]!='\0'){
                num=num*10+(exp[i]-'0');
                i++;
            }
            push(num);
            if(exp[i]==',')
                i++;
        }
        else{
            int a=pop();
            int b=pop();
            switch(exp[i]){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
            }
            i++;
        }
    }
    cout<<pop()<<endl;
}