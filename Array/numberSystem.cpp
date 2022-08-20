#include<iostream>
using namespace std;

int main() {
    int x; cin>>x;

    //decimal to binary conversion
    string str="";
    while(x>=1) {
        str=to_string(x%2)+str;
            k=k/2;
    }
    int xbin=stoi(str);
    cout<<xbin;
}