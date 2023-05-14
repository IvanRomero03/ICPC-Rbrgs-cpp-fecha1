//Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll get_subs(vector<ll> &v, ll n, vector<vector<ll>> &ady)
{
    ll suma = 0;
    if (v[n] != -1)
        return v[n];
    if (ady[n].size() == 0)
    {
        v[n] = 1;
        return 1;
    }
    else
    {
        for (auto &i : ady[n])
        {
            suma += get_subs(v, i, ady);
        }
    }
    v[n] = suma + 1;
    return suma + 1;
}

void dfs(vector<ll> &arr, ll n, ll cant, ll c, vector<vector<ll>> &adyc, vector<ll> &res)
{
    if (res[n] == -1)
    {
        arr[n] -= cant;
        if (arr[n] <= 0)
        {
            res[n] = c;
        }
    }
    for (auto &i : adyc[n])
    {
        dfs(arr, i, cant, c, adyc, res);
    }
}

int main()
{
    sync;
    ll n, q, a, b;
    cin >> n >> q;
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<ll>> v(n + 1);
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].pb(b);
    }
    vector<ll> a2(n + 1, -1);
    vector<ll> res(n + 1, -1);
    for (ll i = 1; i <= q; i++)
    {
        cin >> a >> b;
        ll cant = b / get_subs(a2, a, v);
        dfs(arr, a, cant, i, v, res);
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}