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
 bool dp[100001][101];
 
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
 
    vector<int>vect(n+1);
    ll sum=0;
 
    for(int i = 1; i <=n; i++)
    {
        cin >> vect[i];
        sum+=vect[i];
    }
    sort(vect.begin(),vect.end());
 
    //dp[i][j]->if we can make sum i using first i coins.
 
    memset(dp,false,sizeof dp);
 
    for(int i=0;i<=n;i++)
        dp[0][i]=true;
 
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            dp[i][j]=dp[i][j-1];
            if(i>=vect[j])
            {
                dp[i][j]=dp[i][j] or dp[i-vect[j]][j-1];
            }
 
            
            
        }
    }
    // cout<<"cehfe";
 
    vector<int>res;
    // for(int i=0;i<=sum;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
 
    // int ans=0;
 
    for(int i=1;i<=sum;i++)
    {
        if(dp[i][n])
        {
            res.push_back(i);
        }
    }
 
    cout<<res.size()<<"\n";
    seethis(res);
 
    return 0;
}