

// solution.cpp
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>

#define PIPE1 "/tmp/pipe1"  // solution to interactor
#define PIPE2 "/tmp/pipe2"  // interactor to solution
#define BUFFER_SIZE 1024

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int fd_write, fd_read;

// Modified function to handle pipe communication for queries
ll query(ll a, ll b) {
    string query = "? " + to_string(a) + " " + to_string(b) + "\n";
    write(fd_write, query.c_str(), query.length());
    fsync(fd_write);  // Ensure write is complete
    
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (read(fd_read, buffer, BUFFER_SIZE) <= 0) {
        usleep(1000);  // Wait a bit if no data
    }
    
    return stoll(buffer);
}

void print_answer(const vi& parent, ll n) {
    string answer = "! ";
    REP(i,1,n) {
        answer += to_string(parent[i]) + " ";
    }
    answer += "\n";
    write(fd_write, answer.c_str(), answer.length());
    fsync(fd_write);  // Ensure write is complete
}

// ... rest of your solution code remains the same ...

void solve(ll t)
{
    // Read N through pipe
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(fd_read, buffer, BUFFER_SIZE);
    ll n = stoll(buffer);

    vi parent(n,0);
    parent[1] = 0;
    vb state(n,false);
    
    vi ones;
    ones.pb(1);
    
    // n-2 queries
    // n-2 queries
    REP(i,2,n)
    {
        cout<<"? "<<1<<" "<<i<<endl;
        cout.flush();
        ll r;cin>>r;
        if(r == 0)
        {
            ll last_idx = ones.size() - 1;
            parent[i] = ones[last_idx];
            ones.pb(i);
            state[i] = 1;
        }
    }
    vi last;//size = ones[1] - ones[0] - 1
    REP(i,2,ones[1])
    {
        parent[i] = 0;
        last.pb(i);
    }
    ll pointer = 2;
    REP(i,1,ones.size()-1)
    {
        ll start = ones[i] + 1;
        ll end = ones[i+1];
        ll j = 0;
        while(j < last.size() && start<end)
        {
            parent[start] = last[j];
            last[j] = start;
            start++;
            j++;
        }
    }

    pointer = ones[ones.size()-1] + 1;
    int i=0;
    while(pointer<n && i<last.size())
    {
        if(i == last.size() - 1)
        {
            i++;
            break;
        }
        ll last_acc = last[i];
        ll r = query(last_acc, pointer);
        if(r == 0) // end
        {
            parent[pointer] = last[i];
            last[i] = pointer;
            pointer++;
        }
        else
        {
            // i++;
        }
        i++;
    }

    i = max(i-1,0);
    while(pointer<n)
    {
        parent[pointer] = last[i];
        last[i] = pointer;
        pointer++;
    }

    print_answer(parent, n);
}
int main()
{
    // First open read pipe
    cout << "Solution: Opening read pipe..." << endl;
    fd_read = open(PIPE2, O_RDONLY);
    if (fd_read < 0) {
        cerr << "Failed to open read pipe" << endl;
        return 1;
    }
    
    // Then open write pipe
    cout << "Solution: Opening write pipe..." << endl;
    fd_write = open(PIPE1, O_WRONLY);
    if (fd_write < 0) {
        cerr << "Failed to open write pipe" << endl;
        close(fd_read);
        return 1;
    }
    
    cout << "Solution: Pipes opened successfully" << endl;
    
    // Read number of test cases
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (read(fd_read, buffer, BUFFER_SIZE) <= 0) {
        usleep(1000);  // Wait a bit if no data
    }
    ll t = stoll(buffer);
    
    cout << "Solution: Received " << t << " test cases" << endl;
    
    REP(T,1,t+1)
    {
        solve(T);
    }
    
    // Cleanup
    close(fd_write);
    close(fd_read);
    
    return 0;
}