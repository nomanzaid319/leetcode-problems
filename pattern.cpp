#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter values";
    cin>>n;
    for(int i = 0 ;i < n ; i++){
        for(int j = 1 ; j <=n ; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    // for charachters

    for(int i = 0;i<n;i++){
        char ch = 'A';

        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
            ch=ch+1;
        }
        cout<<endl;
        // ch++;
    }

    
    return 0;
}