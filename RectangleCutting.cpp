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
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }
 
template <typename T>
inline void seethis(vector<T>vect)
{
    for(T x:vect)
        cout<<x<<" ";
    cout<<"\n";
}
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//LCM
int lcm(int a, int b) {  return a * (b / gcd(a, b)); }
 
//For sort by second
bool cmp(const pair<int,int> &a)
{ return a.first<a.second; }
 
//Tree
/* const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];*/
 
//ModPower
ll modpower(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1LL)
            res=(res*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return res;
}
ll dp[501][501];
 
ll solve(ll a,ll b)
{
    if(a==b)
        return 0;
 
    if(dp[a][b]!=-1)
        return dp[a][b];
 
    ll res=inf;
    //Horiozontal cut:
    for(int i=1;i<a;i++)
    {
        res=min(res,1+ solve(i,b)+solve(a-i,b));
    }
    //vertical cut:
 
    for(int i=1;i<b;i++)
    {
        res=min(res,1+solve(a,i)+solve(a,b-i));
    }
    
    return dp[a][b]=res;
}
 
int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a,b;
        cin>>a>>b;
 
 
 
    // The questions asks about the minimum number of times we need to cut the rectangle 
    //to get a square.
    //dp[i][j]->minimum number if ways to cut a rectangle of size ixj into a square
 
        memset(dp,-1,sizeof dp);
 
        cout<<solve(a,b)<<"\n";
    
    return 0;
}