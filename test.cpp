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

int low(int l, int r, vi &v, int t)
{
    cout << l << " " << r << endl;
    int mid = (r - l) / 2 + l;
    while (l < r)
    {
        cout << l << " " << r << endl;

        mid = (r - l) / 2 + l;
        cout << mid << endl;
        if (v[mid] == t)
        {
        }
        if (v[mid] >= t)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return mid;
}

int main()
{
    sync;
    vector<int> asd = {3, 4, 7, 7, 7, 9, 9, 10};
    // cout << bs_up(0, asd.size() - 1, asd, 7) << endl;
    // cout << bs_low(0, asd.size() - 1, asd, 7) << endl;
    // cout << bs_up(0, asd.size() - 1, asd, 11) << endl;
    // cout << bs_low(0, asd.size() - 1, asd, 11) << endl;
    // cout << bs_up(0, asd.size() - 1, asd, 1) << endl;
    // cout << bs_low(0, asd.size() - 1, asd, 1) << endl;
    // cout << bs_up(0, asd.size() - 1, asd, 10) << endl;
    // cout << bs_low(0, asd.size() - 1, asd, 10) << endl;
    cout << (upper_bound(asd.begin(), asd.end(), 5) - asd.begin() - 1) << endl;
    cout << (*(upper_bound(asd.begin(), asd.end(), 5) - 1)) << endl;
    return 0;
}