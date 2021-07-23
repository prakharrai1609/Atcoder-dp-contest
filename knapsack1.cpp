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

    ll n, c; cin >> n >> c;
    vcll w(n), cost(n);

    for (ll i = 0; i < n; i++) {
        cin >> w[i];
        cin >> cost[i];
    }

    vc<vcll> dp(n + 1, vcll (c + 1, 0));
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= c; j++) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], cost[i - 1] + dp[i - 1][j - w[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // lol(i, 0, n + 1) {
    //     lol(j, 0, c + 1) {
    //         cout << dp[i][j] << ' ';
    //     } cout << newl;
    // }

    cout << dp[n][c];

}
