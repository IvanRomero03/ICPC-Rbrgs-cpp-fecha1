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

int bs_up(int l, int r, vector<int> &v, int t)
{
    if (l >= r)
        return l;
    int mid = (r - l) / 2 + l;

    if (v[mid] == t)
    {
        if ((mid == v.size() - 1) || v[mid + 1] != t)
        {
            return mid;
        }
        else
        {
            return bs_up(mid + 1, r, v, t);
        }
    }
    if (v[mid] > t)
    {
        return bs_up(l, mid - 1, v, t);
    }
    else
    {
        return bs_up(mid + 1, r, v, t);
    }
}

int bs_low(int l, int r, vi &v, int t)
{
    if (l >= r)
        return r;
    int mid = (r - l) / 2 + l;

    if (v[mid] == t)
    {
        if (mid == 0 || v[mid - 1] != t)
        {
            return mid;
        }
        else
        {
            return bs_low(l, mid - 1, v, t);
        }
    }
    if (v[mid] > t)
    {
        return bs_up(l, mid - 1, v, t);
    }
    else
    {
        return bs_up(mid + 1, r, v, t);
    }
}

int main()
{
    sync;
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    int in, b, c, k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    vi vec;
    while (!pq.empty())
    {
        vec.pb(pq.top());
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    for (int i = 0; i < q; i++)
    {
        cin >> in;
        if (in == 1)
        {
            cin >> k;
            // if k > vec[-1] then add
            // upper_bound k
            // if k then change the largest after k
            if (k > vec.back())
            {
                cout << "agregue " << k << endl;
                vec.pb(k);
            }
            else
            {
                int indx = bs_up(0, vec.size() - 1, vec, k);
                cout << "found " << indx << " " << vec[indx] << endl;
                if (indx != vec.size() - 1)
                {
                    if (vec[indx] == k)
                    {
                        vec[indx + 1] = k;
                    }
                    else if (vec[indx] > k)
                    {
                        vec[indx] = k;
                    }
                    else
                    {
                        vec[indx + 1] = k;
                    }
                }
            }
        }
        else
        {
            cin >> b >> c;
            int low = lower_bound(vec.begin(), vec.end(), b);
            cout << (low - vec.begin()) << endl;
            int up = bs_up(0, vec.size() - 1, vec, c);
            // lower_bound b
            // upper_bound c
            // c - b
        }
    }

    return 0;
}