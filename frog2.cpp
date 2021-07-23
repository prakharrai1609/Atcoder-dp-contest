/*    Author : Prakhar Rai    */
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define LB(x,num) lower_bound(x.begin(),x.end(),num) - x.begin()
#define UB(x,num) upper_bound(x.begin(),x.end(),num) - x.begin()
#define BS(x,num) binary_search(x.begin(),x.end(),num)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define vci vector<int>
#define vcll vector<ll>
#define vcd vector<long double>
#define line(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define newl "\n"
#define vc vector
#define loop(i,a,b) for(int i = a; i < b; i++)
#define lol(i,a,b) for(ll i = a; i < b; i++)
#define lod(i,a,b) for(ld i = 0; i < b; i++)
#define mod 1000000007
#define read(v,n) lol(i,0,n) {ll x; cin >> x; v.pb(x);}
#define run(a,x) for(auto x : a)
#define yes "YES"
#define no "NO"
ll cnt;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n, k; cin >> n >> k;
    vcll a(n);
    lol(i, 0, n) cin >> a[i];

    vcll dp(n, 0);

    for (ll i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (ll j = 1; j <= k; j++) {
            if ((i - j) >= 0) {
                dp[i] = min(dp[i], abs(a[i] - a[i - j]) + dp[i - j]);
            } else {
                break;
            }
        }
    }

    cout << dp[n - 1];
}
