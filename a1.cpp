#include<iostream>
using namespace std;
int main()
{
    int n ;
    cout<<"enter number";
    cin>>n;
    // int sum = 0;

    while (n % 2 ==0)
    {
        cout<<"number is even "<<endl;
    }
    else{
        cout<<"number is odd"<<endl;
    }
    // cout << sum << endl;
    return 0;
}