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

int main()
{
    sync;
    int n, q;
    int type, k, a, b;
    priority_queue<int, vi, greater<int>> pq;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(a);
    }
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> k;
            if (v.back() < k)
            {
                v.pb(k);
            }
            else
            {
                vi::iterator itr = upper_bound(v.begin(), v.end(), k);
                auto aaaa = (*itr);
                int indx = (itr - v.begin());
                v[indx] = k;
                // if (v[itr - v.begin()] == k)
                // {
                //     int indx = (itr - v.begin());
                //     if (v[indx] == k)
                //     {
                //         v[indx + 1] = k;
                //     }
                //     else
                //     {
                //         v[indx] = k;
                //     }
                //     cout << "aaa" << v[indx] << endl;
                // }
            }
        }
        else
        {
            cin >> a >> b;
            vi::iterator up = upper_bound(v.begin(), v.end(), b);
            vi::iterator low = lower_bound(v.begin(), v.end(), a);
            cout << (up - low) << endl;
        }
    }

    return 0;
}