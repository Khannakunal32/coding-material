#include<iostream>
// #include<stdio.h>
// #include<conio.h>

using namespace std;

int main() {
    int row, colm;
    cin>> row>> colm;
    for(int i=0; i<row; i++ ) {
        for (int j=0; j<colm; j++) {
            if(i==0||i==(row-1)||j==0||j==(colm-1))
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}