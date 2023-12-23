#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {

    int n;
    cin >> n;

    string proibida, bracelete, bracelete_invertido;

    while(n--)
    {
        cin >> proibida >> bracelete;
        bracelete = bracelete_invertido = bracelete + bracelete.substr(0,proibida.size() - 1);
        reverse(bracelete_invertido.begin(), bracelete_invertido.end());

        if(bracelete.find(proibida) != string::npos || bracelete_invertido.find(proibida) != string::npos) cout << "S\n";
        else cout << "N\n";


    }







}
