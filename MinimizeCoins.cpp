#include"bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sz(a) int((a).size())
#define mod 1000000007
#define inf 1e6+1
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
 
vector<ll>dp(1000001, -1);
vector<ll>coins;
 
ll solve(ll sum, ll n)
{
    if(sum == 0)
    {
        
        return 0;
    }
    if(sum < 0)
        return inf;
 
    if(dp[sum] != -1)
        return dp[sum];
 
    ll res = inf;
    for(int i = 0; i < n; i++)
    {
        if(sum >= coins[i])
            res = min(res, 1 + solve(sum - coins[i], n));
        else
            break;
 
        
    }
 
 
    return dp[sum]=res;
}
 
 
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
 
    ll x;
    cin >> x;
 
    f(i, 0, n)
    {
        ll val;
        cin >> val;
        coins.push_back(val);
    }
 
    sort(coins.begin(), coins.end());
 
   ll ans=solve(x,n);
 
   if(ans==inf)
    cout<<"-1\n";
else
    cout<<ans<<"\n";
 
    return 0;
}