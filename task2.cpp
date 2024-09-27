//SIMPLE CALCULATOR
#include<iostream>
using namespace std;
int main(){
    int a ,b;
    cout<<"enter first number: ";
    cin>>a;
    cout<<"enter second number: ";
    cin>>b;
    char operation;
    cout<<"select the operation to be performed: ";
    cin>>operation;
    if(operation=='+'){
     cout<<"Result is : "<<a+b<<endl;
    }
    else if(operation =='-'){
        cout<<"Result is : "<<a-b<<endl;
    }
    else if(operation=='*'){
        cout<<"Result is : "<<a*b<<endl;
    }
    else if(operation=='/'){
        cout<<"Result is : "<<a/b<<endl;
    }
    else{
        cout<<"Invalid";
    }
return 0;
}
    