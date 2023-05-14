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
#define toInta(c) (c - 'a')
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    sync;
    int n, a, c;
    cin >> n;
    string temp;
    unordered_set<ll> sv;
    unordered_map<ll, bool> mp;
    for (int i = 0; i < n; i++){
        cin >> a;
        ll val = 0;
        ll prim = 37;
        ll pot = prim;
        for(int j = 0; j < a; j++){
            cin >> temp;
            val += (pot*(toInta(temp[0]) + 1))%MOD;
            pot = (prim* pot)%MOD;
        }
        if(sv.find(val) == sv.end()){
            sv.insert(val);
        } else {
            if(mp[val] == false){
                c++;
                mp[val] = true;
            }
        }
        
    }

    return 0;
}