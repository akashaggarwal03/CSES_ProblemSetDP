#include"bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sz(a) int((a).size())
#define mod 1000000007
#define inf LLONG_MAX
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
template <typename T>
inline T gcd(T a, T b)
{
    while (b != 0) swap(b, a %= b);
    return a;
}
 
template <typename T>
inline void seethis(vector<T>vect)
{
    for(T x : vect)
        cout << x << " ";
    cout << "\n";
}
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//LCM
int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}
 
//For sort by second
bool cmp(const pair<int, int> &a)
{
    return a.first < a.second;
}
 
//Tree
/* const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];*/
 
//ModPower
ll modpower(ll a, ll b, ll c)
{
    ll res = 1;
    while(b)
    {
        if(b & 1LL)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}
vector<int>solve(ll n)
{
    vector<int>res;
    while(n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}
int dp[1000001];
 
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
 
 
    //dp[i]->mini steps to reduce it to 1;
    for(int i = 1; i <= 9; i++)
        dp[i] = 1;
 
    for(int i = 10; i <= n; i++)
    {
        vector<int>digits = solve(i);
        int res = INT_MAX;
        // seethis(digits);
        for(int x : digits)
        {
            if(x != 0)
            {
                res = min(res, 1 + dp[i - x]);
            }
 
        }
        dp[i]=res;
    }
 
 
    // for(int i=10;i<=27;i++)
    //     cout<<dp[i]<<" ";
    // cout<<"\n";
 
    cout<<dp[n]<<"\n";
 
 
    return 0;
}