#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
// #define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define LINF 1e18
#define unsigned int
 
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a;i<b;i++)

using namespace std;

bool is_odd_power_of_two(long long n) {
    if (n == 0 || (n & (n - 1)) != 0)
        return false;
    int exponent = 0;
    while (n > 1) {
        n >>= 1;
        exponent++;
    }
    return exponent % 2 == 1;
}

ll big2(ll n) {
    ll k = 1;
    while (k <= n) {
        k = k<< 1; 
    }
    return k/2;
}


void countbits(ll n, int &count_even_bits, int &count_odd_bits) {
    count_even_bits = 0;
    count_odd_bits = 0;
    int position = 0;
    while (n > 0) {
        if (n & 1) {
            if (position % 2 == 0)
                count_even_bits++;
            else
                count_odd_bits++;
        }
        n >>= 1;
        position++;
    }
}


int main() {

    int t;
    cin >> t;
    while (t--) {
    ll n, x;
    cin >> n >> x;
    if (n <= x || is_odd_power_of_two(n))
    {
        cout << 1 << endl;
        continue;
    }

    if ((x == 0) &&(n%2==1)) {
        cout << -1 << endl;
        continue;
    }
    ll n2 = n;

    int xop = 0;
    ll mask = ~xop;
    if (x > 0)
    {
        int biggest2 = big2(x);
        if (x < (2 * biggest2 - 1))
        {
            x = biggest2 - 1;
            mask = ~x;
        }
        else{
            mask = ~x;
        }

        n = n & mask;
        xop++;
    }



    int count_odd_bits = 0;
    int count_even_bits = 0;
    countbits(n, count_even_bits, count_odd_bits);

    int ans = 0;
    ans+=  count_even_bits;
    ans+=  count_odd_bits*2;


    {
        n2 = n;
    }

    cout << ans +xop << endl;

    }

}