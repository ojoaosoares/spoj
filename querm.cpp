#include <iostream>

int main()
{
    int n,number, cont = 1;
    while(true) {
        std::cin >> n;

        if(n == 0) break;

        for (int i = 1; i <= n ; i++) {

            std::cin >> number;

            if(number == i) {
                std::cout << "Teste " << cont++ << '\n';
                std::cout << i  << '\n';

            }

        }
    }





    return 0;
}
