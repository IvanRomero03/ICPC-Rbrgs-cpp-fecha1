//Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005
#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    sync;
    ll n, a, val = 0;
    ll b = 0;
    string in;
    unordered_set<ll> s;
    cin >> n;
    unordered_map<ll, bool> mapa;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        string g = "";
        for (ll j = 0; j < a; j++)
        {
            cin >> in;
            g += in[0];
        }
        ll suma = 0;
        ll prim = MAXN;
        ll p_val = 1;
        for (ll i = 0; i < a; i++)
        {
            ll temp = toInta(g.at(i)) + 1;
            p_val = ((p_val * prim) % MOD + 1);
            suma = ((temp + suma) * p_val % MOD + 1);
        }
        if (s.find(suma) == s.end())
        {
            s.insert(suma);
        }
        else
        {
            if (mapa[suma] == false)
            {
                b++;
                mapa[suma] = true;
            }
        }
    }
    if (b > s.size())
    {
        cout << 0 << endl;
        return 0;
    }
    cout << s.size() - b << endl;
    return 0;
}