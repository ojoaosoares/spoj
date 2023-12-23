#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    cin >> n;

    bool isOrdered;
    string palavra;

    while (n--)
    {

        cin >> palavra;

         isOrdered = true;

        for (int i = 1; i < (int) palavra.size(); i++)
        {
            if (tolower(palavra[i]) <= tolower(palavra[i-1]))
            {
                isOrdered = false;
                break;
            }
        }

        cout << palavra;
        if (isOrdered) cout << ": O\n";
        else cout << ": N\n";

    }

}
