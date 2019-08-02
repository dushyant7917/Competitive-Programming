#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,ind,last;

  while(t--){
    cin>>n;
    ll a[n],ans[n]={0};
    fr(i,0,n) cin>>a[i];

    stack<ll> st;
    ind=0;

    while(ind<n){
      if(SZ(st)<=1) st.push(ind++);
      else{
        last=st.top();
        st.pop();
        if(a[last]<a[st.top()] && a[last]<a[ind]){
          ans[last]=max(ans[last],ans[ind])+1;
          ans[ind]=ans[last];
        }
        else{
          st.push(last);
          st.push(ind++);
        }
      }
    }

    while(SZ(st)){
      ans[st.top()]=0;
      st.pop();
    }

    fr(i,0,n) cout<<ans[i]<<" "; cout<<"\n";
  }

  return 0;
}
