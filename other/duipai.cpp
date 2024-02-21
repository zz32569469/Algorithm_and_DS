#include<bits/stdc++.h>

using namespace std;

int main(){
    while (1){
        system("generate.exe > in.txt");
        system("test.exe < in.txt > baoli.txt");
        system("contest.exe < in.txt > solution.txt");
        if (system("fc solution.txt baoli.txt")) break;
    }
    return 0;
}