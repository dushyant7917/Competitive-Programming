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
#define N 500005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool valley(ll a[],ll i){
  if(a[i]<a[i-1] && a[i]<a[i+1]) return true;
  else return false;
}

bool check(ll a[],ll i){
  if(a[i]+a[i+2]>=a[i+1]) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,ind,cur,left,right,cnt,prv;
  while(t--){
    cin>>n;

    ll a[n+2],b[n+2];

    fr(i,1,n+1){
      cin>>a[i];
      b[i]=a[i];
    }

    a[0]=a[n+1]=INF;

    ind=1;
    while(ind<=n){
      cur=left=ind;

      vector<ll> v;
      v.PB(0);
      cnt=1;

      if(valley(a,cur)) v.PB(cur);

      while(cur<=n-2 && valley(a,cur) && valley(a,cur+2) && check(a,cur)){
        cur+=2;
        cnt++;
        v.PB(cur);
      }

      right=cur;

      if(left==right && valley(a,left)) b[left]=-b[left];
      else if(left!=right){
        ll x=SZ(v);
        stack<ll> st;
        ll dp[x];
        dp[0]=0;
        dp[1]=a[v[1]];
        st.push(v[1]);
        prv=v[1]+3;

        fr(i,2,x){
          if(dp[i-2]+a[v[i]]>dp[i-1]){
            dp[i]=dp[i-2]+a[v[i]];
            st.push(v[i]);
            prv=v[i]+3;
          }
          else dp[i]=dp[i-1];
        }

        while(SZ(st)){
          if(prv-st.top()>=3){
            b[st.top()]=-b[st.top()];
            prv=st.top();
          }
          st.pop();
        }
      }
      else {}

      ind=right+1;
    }

    fr(i,1,n+1) cout<<b[i]<<" "; cout<<"\n";
  }

  return 0;
}
