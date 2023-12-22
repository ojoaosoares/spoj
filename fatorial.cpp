#include <iostream>
#include <cmath>

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int fatorialLastDigit(long long int n) {

    if (n < 10)
        return dig[n];

    // Check whether tens (or second last) digit
    // is odd or even
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7
    // Applying formula for even and odd cases.
    if (((n/10)%10)%2 == 0)
        return (6*fatorialLastDigit(n/5)*dig[n%10]) % 10;
    else
        return (4*fatorialLastDigit(n/5)*dig[n%10]) % 10;



}

int main() {

    int cont = 1;
    long long n;

    while(std::cin >> n)
        std::cout << "Instancia " <<  cont++ << '\n' << fatorialLastDigit(n) << '\n';


}
