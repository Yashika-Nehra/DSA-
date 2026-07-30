#include <bits/stdc++.h>
using namespace std;

char stk[100];
int top = -1;
void push(char x){
    top=top+1;
    stk[top]=x;
}

char pop(){
    char x=stk[top];
    top=top-1;
    return x;
}

int priority(char x){
    if(x=='^'){
        return 3;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='('){
        return 0;
    }
    else{
        return -1;
    }
}


int main(){
    string exp;
    cin>>exp;
    int i=0;
    char x;
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
            cout<<exp[i];
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            {
                cout<<x;
            }
        }
        else
        {
            while(top!=-1 && priority(stk[top])>=priority(exp[i]))
            {
                cout<<pop();
            }
            push(exp[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        cout<<pop();
    }
}