#include <iostream>

int main()
{
    int r, c, n;


    std::cin >> r >> c;

    int *somas = new int[r+c];

    for (int i = 0; i < r+c; i++) somas[i] = 0;\

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            std::cin >> n;
            somas[i] += n;
            somas[r+j] += n;

        }
    }

    int maior;
    for (int i = 0; i < r+c; i++)
        if(i == 0 || somas[i] > maior) maior = somas[i];

    std::cout << maior << '\n';
}
