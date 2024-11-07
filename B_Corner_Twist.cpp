// ============================================================================ //
// ||                                                                        || //
// ||                                                                        || //
// ||                              Badal Kumar                               || //
// ||                                2020-24                                 || //
// ||                                                                        || //
// ============================================================================ //

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <climits>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

//--------------------------------------------------------------------------------------------------------------------------------------

#define MOD 1e9+7
#define Badal cin.sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long int
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vpp vector<pair<int,int>>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout << endl
#define endl "\n"
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));

//--------------------------------------------------------------------------------------------------------------------------------------
#define ll long long
const int N = 1000001;
// Use Binomial(n, r, mod) instead of nCr
 
// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

//--------------------------------------------------------------------------------------------------------------------------------------

uint power(int x, int y, int p =  MOD){
    unsigned long long res = 1;
    
    x = x % p;
    while (y > 0){
        
        if (y & 1)
            res = (res * x) % p;
        
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

//--------------------------------------------------------------------------------------------------------------------------------------

int toInt(string s) {int res; stringstream ss; ss<<s; ss>>res; return res; }
string toString(int n) { stringstream ss; ss<<n; return ss.str(); }

//--------------------------------------------------------------------------------------------------------------------------------------

int mex(vi &arr)
{
    int n = arr.size();
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        if (mp[i] == 0)
        {
            return i;
        }
    }
    return n + 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------

bool isPalindrome(string &s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

//--------------------------------------------------------------------------------------------------------------------------------------

uint modInverse(int n, int p=MOD){       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
    return power(n, p - 2, p);
}

//--------------------------------------------------------------------------------------------------------------------------------------

int gcd (int a, int b) { return a ? gcd (b % a, a) : b; }
int lcm (int a, int b) {return (a*b) / gcd(a, b);}

//--------------------------------------------------------------------------------------------------------------------------------------

uint nCr(int n, int r, int p=MOD){     // faster calculation..
    if (n < r)
        return 0;
    
    if (r == 0)
        return 1;
    
    vector<int> fac(n+1,0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

//--------------------------------------------------------------------------------------------------------------------------------------

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<endl; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

//--------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
struct ex_gcd {
    T g, a_coeff, b_coeff;
};
 
template <typename T>
ex_gcd<T> extended_gcd(T a, T b) {
    T x = a, y = b;
    T ax = 1, ay = 0;
    T bx = 0, by = 1;
    while (x) {
        T k = y / x;
        y %= x; std::swap(x, y);
        ay -= k * ax; std::swap(ax, ay);
        by -= k * bx; std::swap(bx, by);
    }
    return {y, ay, by};
}
 
template <int m>
struct modular_int {
    static constexpr int mod = (int) 1e9 + 7;
    static constexpr uint32_t umod = (uint32_t) m;
 
    uint32_t val;
 
    modular_int() : val(0) {}
    modular_int(int64_t x) : val(norm(x)) {}
 
    explicit operator int() const { return val; }
 
    modular_int neg() {
        modular_int res;
        res.val = val ? umod - val : 0;
        return res;
    }
 
    modular_int inv() const {
        ex_gcd res = extended_gcd((int) val, mod);
        return modular_int(res.a_coeff);
    }
    friend modular_int inv(const modular_int& a) {
        return a.inv();
    }
 
    modular_int& operator += (const modular_int& rhs) { 
        val += rhs.val; val -= (val >= umod ? umod : 0);
        return *this;
    }
    modular_int& operator -= (const modular_int& rhs) {
        val += umod - rhs.val; val -= (val >= umod ? umod : 0);
        return *this;
    }
    modular_int& operator *= (const modular_int& rhs) {
        val = uint32_t(uint64_t(val) * uint64_t(rhs.val) % umod);
        return *this;
    }
    modular_int& operator /= (const modular_int& rhs) {
        return *this *= rhs.inv();
    }
    modular_int& operator ++ () {
        val = (val == umod - 1 ? 0 : val + 1);
        return *this;
    }
    modular_int* operator -- () {
        val = (val == 0 ? umod - 1 : val - 1);
        return *this;
    }
 
    friend modular_int operator + (const modular_int& lhs, const modular_int& rhs) {
        return modular_int(lhs.val) += rhs; 
    }
    friend modular_int operator - (const modular_int& lhs, const modular_int& rhs) {
        return modular_int(lhs.val) -= rhs; 
    }
    friend modular_int operator * (const modular_int& lhs, const modular_int& rhs) { 
        return modular_int(lhs.val) *= rhs; 
    }
    friend modular_int operator / (const modular_int& lhs, const modular_int& rhs) { 
        return modular_int(lhs.val) /= rhs; 
    }
 
    friend std::ostream& operator << (std::ostream& out, const modular_int& z) { return out << z.val; }
    friend std::istream& operator >> (std::istream& in, modular_int& z) { int v; in >> v; z = modular_int(v); return in; }
 
    friend bool operator == (const modular_int& lhs, const modular_int& rhs) { return lhs.val == rhs.val; };
    friend bool operator != (const modular_int& lhs, const modular_int& rhs) { return lhs.val != rhs.val; };
 
    modular_int pow(int64_t n) const {
        assert(0 <= n);
        modular_int x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
 
    static uint32_t norm(int64_t x) {
        x %= mod; if (x < 0) x += mod;
        return (uint32_t) x;
    } 
};
 
// const int md = 998244353;
const int md = (int) 1e9 + 7;
using mint = modular_int<md>;

//--------------------------------------------------------------------------------------------------------------------------------------
void Solve(){
	int n;  cin >> n;
	string s; cin >> s;
	int ans = 0;
	string bin = string(n + 1, '0');
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {

			for(int k = i; k <= j;) {
				if(s[k] == '0') {
					k++;
				}else {
					int cnt = (s[k] == '1');
					cnt += (k < n - 1 && s[k + 1] == '1');
					cnt += (k < n - 2 && s[k + 2] == '1');

					ans += (cnt / 3);
					ans += (cnt % 3 != 0);
					k += 3;
				}
			}
			
		}
 	}   

	cout << ans << endl;
}

int32_t main (){
    Badal;

    // ll p = 1000000007;
    // InverseofNumber(p);
    // InverseofFactorial(p);
    // factorial(p);

    int tc = 1;
    cin >> tc;
    while (tc--){
        Solve();
    }
}
