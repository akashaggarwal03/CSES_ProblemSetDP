#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
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
int dp[1001][100001];
 
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
 
    vector<int>pages(n + 1);
    vector<int>price(n + 1);
 
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
 
    for(int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
 
 
 
    //dp[i][j]->maximum pages with cost j among i books.
   
 
    memset(dp, 0, sizeof dp);
 
 
 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            int res = dp[i - 1][j];
 
            if(j >= price[i])
            {
                res = max(res, (pages[i] % mod + dp[i - 1][j - price[i]] % mod) % mod);
            }
 
            dp[i][j] = res;
        }
    }
 
    cout << dp[n][x] << "\n";
 
 
    return 0;
}