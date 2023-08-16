#include <stdio.h>
#include <math.h>

int primo(long long int n) {
    for (int i = (int) sqrt(n) ; i > 1; i--)
        if(!(n % i)) return 0;   
    return 1;
}


int main() {
    long long int n;
    scanf("%lli",&n);
    if(primo(n)) printf("N");
    else  printf("S");
    
    
}