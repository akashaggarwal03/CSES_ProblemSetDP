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
 
void add_self(ll &a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
 
long long int dp[100001][101];
 
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //What is important here ?
    //The last filled value will determine the number of
    //ways by which i can fill the current index.
    //dp[i][v]->number of ways to fill the ith index
    //if v is filled at this locatiuon.
 
 
    int n, m;
    cin >> n >> m;
 
    vector<int>vect(n + 1);
    f(i, 1, n + 1)
    cin >> vect[i];
 
    if(vect[1] == 0)
    {
        for(int i = 1; i <= m; i++)
            dp[1][i] = 1;
    }
 
    
    if(vect[1]!=0)
        dp[1][vect[1]]=1;
 
    for(int i = 2; i <= n; i++)
    {
        if(vect[i] == 0)
        {
            for(int j = 1; j <= m; j++)
            {
                ll res=0;
                for(int k=-1;k<=1;k++)
                {
                    add_self(res,dp[i-1][j+k]);
                }
                dp[i][j]=res;
            }
        }
        else
        {
            dp[i][vect[i]] = (dp[i - 1][vect[i]] % mod + dp[i - 1][vect[i] - 1] % mod  + dp[i - 1][vect[i] + 1] % mod) % mod;
        }
 
    }
 
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
 
    ll ans = 0;
 
    for(int i = 1; i <= m; i++)
    {
        add_self(ans, dp[n][i]);
    }
 
    cout << ans << "\n";
    return 0;
}