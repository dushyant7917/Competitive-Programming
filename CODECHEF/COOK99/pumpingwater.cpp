#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll h[n+2],prv[n+2],nxt[n+2],left[n+2],right[n+2];
    fr(i,1,n+1) cin>>h[i];

    stack<ll> st;

    fr(i,1,n+1){
      while(SZ(st) && h[i]>h[st.top()]){
        nxt[st.top()]=i;
        st.pop();
      }
      st.push(i);
    }

    while(SZ(st)){
      nxt[st.top()]=n+1;
      st.pop();
    }

    rf(i,n,1){
      while(SZ(st) && h[i]>h[st.top()]){
        prv[st.top()]=i;
        st.pop();
      }
      st.push(i);
    }

    while(SZ(st)){
      prv[st.top()]=0;
      st.pop();
    }

    left[0]=right[n+1]=0;

    fr(i,1,n+1) left[i]=left[prv[i]]+1;
    rf(i,n,1) right[i]=right[nxt[i]]+1;

    ll ans=INF;
    fr(i,1,n) ans=min(ans,2+left[prv[i]]+right[nxt[i+1]]);
    ans=MIN(ans,left[n],right[1]);
    cout<<ans<<"\n";
  }

  return 0;
}
