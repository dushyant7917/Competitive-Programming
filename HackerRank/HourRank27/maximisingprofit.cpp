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
#define N 300002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  multiset<ll> left,right;
  ll ans=-2e18;

  ll a1,a2,b,c1,c2;
  multiset<ll>::iterator itr1,itr2;

  if(n<3){
    cout<<-1;
    return 0;
  }

  left.insert(a[0]);
  fr(i,2,n) right.insert(a[i]);

  fr(i,1,n-1){
    b=a[i];
    itr1=left.lower_bound(b);
    itr2=right.upper_bound(b);

    if(itr1!=left.begin() && itr2!=right.end()){
      a1=*left.begin();
      a2=*(--itr1);
      c1=*itr2;
      c2=*right.rbegin();

      ans=max(ans,a1*b*c1);
      ans=max(ans,a1*b*c2);
      ans=max(ans,a2*b*c1);
      ans=max(ans,a2*b*c2);
    }

    right.erase(right.find(a[i+1]));
    left.insert(a[i]);
  }

  if(ans==-2e18) cout<<-1;
  else cout<<ans;

  return 0;
}
