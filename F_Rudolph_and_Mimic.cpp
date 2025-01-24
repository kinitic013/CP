#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll array_compare(const vi &a, const vi &b) {
    REP(i, 0, a.size()) {
        if (a[i]>b[i]) return i;
    }
    return -1;
}

void solve(ll t) {
    ll n;
    cin >> n;
    vi arr(n + 1);
    vi count(10, 0);

    REP(i, 1, n + 1) {
        cin >> arr[i];
        count[arr[i]]++;
    }

    vi new_count(10, 0);

    cout << "- 0 " << endl; cout.flush();
    REP(i, 1, n + 1) {
        cin>>arr[i];
        new_count[arr[i]]++;
    }
    ll type = array_compare(new_count,count);
    if(type == -1)
    {
        count = new_count;
        new_count = vi(10,0);
        cout << "- 0 " << endl; cout.flush();
        REP(i, 1, n + 1) {
            cin>>arr[i];
            new_count[arr[i]]++;
        }
        type = array_compare(new_count,count);
    }
    vi out;
    REP(i, 1, n + 1) {
        if (arr[i] != type) {
            out.push_back(i);
        }
    }
    cout<<"- "<<out.size()<<" "<<flush;
    for(auto x : out)
        cout<<x<<" ";
    
    cout << endl; cout.flush();

    count = vi(10,0);
    count[type] = new_count[type];
    n = n - out.size();
    {
        new_count = vi(10,0);
        cout << "- 0 "; cout.flush();
        REP(i, 1, n + 1) {
            cin>>arr[i];
            new_count[arr[i]]++;
        }
    }
    type = array_compare(new_count,count);
    if(type == -1)
    {
        count = new_count;
        new_count = vi(10,0);
        cout << "- 0 "; cout.flush();
        REP(i, 1, n + 1) {
            cin>>arr[i];
            new_count[arr[i]]++;
        }
        type = array_compare(new_count,count);
    }
    REP(i, 1, n + 1) {
        if (arr[i] == type) {
            cout << "! " << i << endl;
            cout.flush();
            return;
        }
    }
    cout << "WA" << endl;
    return;
}

int main() {
    fast();
    ll t;
    cin >> t;
    REP(T, 1, t + 1) {
        solve(T);
    }
    return 0;
}
