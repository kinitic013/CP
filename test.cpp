#include <bits/stdc++.h>
using namespace std;
//{
    #ifdef lawfung
    #define debug(...) do {\
        fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
        _DO(__VA_ARGS__);\
    }while(0)
    template<typename I> void _DO(I&&x) {cerr << x << '\n';}
    template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
    #else
    #define debug(...)
    #endif
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    typedef long double ld;
    #define F first
    #define S second
    #define ALL(x) (x).begin(),(x).end()
    #define SZ(x)   (ll)x.size()
    // #define pb push_back
    #define eb emplace_back
    #define stp setprecision(30)<<fixed
    #define YES cout<<"YES"<<'\n'
    #define NO cout<<"NO"<<'\n'
    #define Yes cout<<"Yes"<<'\n'
    #define No cout<<"No"<<'\n'
    const ll INF = 0x3f3f3f3f3f3f3f3f;
    const int NF = 0x3f3f3f3f;
    // const ll MOD = 998244353;
    const ll MOD = 998244353;
    const ll MO3 = 1e9 + 87;
    const ll MO4 = 1e9 + 93;
    const ld PI=3.14159265358979323846264338327950288;
    const ld eps=1e-7;
//}
const ll MAX = 1e6 + 6, Mlg = __lg(MAX) + 2;
ll sz;
ll pre[MAX], suf[MAX];
string s;
void build() {
	for(int i = 2; i <= sz; ++ i) {
		pre[i] = pre[i - 1];
		if(s[i] == 'v' && s[i - 1] == 'v')
			pre[i] ++;
	}
	for(int i = sz - 1; i ; --i ) {
		suf[i] = suf[i + 1];
		if(s[i] == s[i + 1] && s[i] == 'v') {
			suf[i] ++;
		}
	}
	return;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    a += b;
    ll ans = 1;
    while(a --) {
    	ans = (ans + ans) % MOD;
    }
    cout << ans << '\n';
    return 0;
}