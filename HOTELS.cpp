#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll maximum = 0, sum = 0, left = 0, right = 0;

    while (right < n && maximum != m)
    {
        if (sum + arr[right] <= m)
        {
            sum += arr[right];
            right++;
        }

        else
        {
            sum -= arr[left];
            left++;
        }

        maximum = max(maximum, sum);
    }

    cout << maximum << '\n';
}
