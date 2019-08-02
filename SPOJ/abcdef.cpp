#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll s[n];
  fr(i,0,n) cin>>s[i];

  vector<ll> lhs,rhs;

  fr(a,0,n){
    fr(b,0,n){
      fr(c,0,n){
        lhs.PB((s[a]*s[b])+s[c]);
      }
    }
  }

  fr(d,0,n){
    fr(e,0,n){
      fr(f,0,n){
        if(s[d]!=0){
          rhs.PB(s[d]*(s[f]+s[e]));
        }
      }
    }
  }

  set<ll> st;
  fr(i,0,lhs.size()){
    st.insert(lhs[i]);
  }

  sort(lhs.begin(),lhs.end());
  sort(rhs.begin(),rhs.end());


  set<ll>::iterator itr;
  ll ans=0;
  ll a_lb,a_ub,b_lb,b_ub;
  for(itr=st.begin();itr!=st.end();itr++){
    a_ub=upper_bound(lhs.begin(),lhs.end(),(*itr))-lhs.begin();
    a_lb=lower_bound(lhs.begin(),lhs.end(),(*itr))-lhs.begin();

    b_ub=upper_bound(rhs.begin(),rhs.end(),(*itr))-rhs.begin();
    b_lb=lower_bound(rhs.begin(),rhs.end(),(*itr))-rhs.begin();

    ans+=(a_ub-a_lb)*(b_ub-b_lb);
  }

  cout<<ans;

  return 0;
}
