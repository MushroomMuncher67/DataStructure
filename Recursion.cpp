#include <iostream>
using namespace std;

int sum(int  n){
    
    // base condition
    if (n == 1)
     return  1 ;
     
    return n + sum(n - 1); 
}

int main() {
    int n = 5 ;
    cout <<  sum(n); 
    return 0;
}