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
// bool cmp(const pair<int,int> &a)
// { return a.first<a.second; }
 
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
struct work
{
    ll start,end,money;
};
 
bool cmp(work a,work b)
{
    return (a.end<b.end);
}
 
ll solve(work arr[],ll i)
{
   ll low=0,high=i-1;
 
   ll idx=-1;
   while(low<=high)
   {
        ll mid= low + (high-low)/2;
 
        if(arr[mid].end<arr[i].start)
        {
            idx=mid;
            low=mid+1;
        }
        else
            high=mid-1;
   }
 
   return idx;
}
 
int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
 
    ll n;
     cin>>n;
 
    struct work arr[n];
 
    for(ll i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].end>>arr[i].money;
 
    sort(arr,arr+n,cmp);
 
    vector<ll>dp(n,0);
 
    //dp[i]->defined as the maximum money till the ith project.
 
    dp[0]=arr[0].money;
 
    for(int i=1;i<n;i++)
    {
        ll temp=arr[i].money;
 
        ll last= solve(arr,i);
 
        if(last!=-1)
            temp+=dp[last];
 
        dp[i]=max(dp[i-1],temp);
    }
 
    cout<<dp[n-1]<<"\n";
 
    
    return 0;
}