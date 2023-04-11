//
// Created by light on 29.09.2022.
//

#include <iostream>
#include <vector>

using namespace std;


const int N = 10;
char a[2*N];
int count = 0;

void rec(int i, int balance){
    if (i == 2*N){
        if (balance == 0){
            count++;
            if (count == 8644){
                for(char j : a){
                    cout << j << " ";

                }
                cout << endl;
            }

        }
        return;

    }
    a[i] = '(';
    rec(i+1, balance+1);
    if (balance == 0)
        return;
    a[i] = ')';
    rec(i+1, balance-1);
    }

int main(){
    rec(0, 0);
}