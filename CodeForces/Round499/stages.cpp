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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  ll a[SZ(s)];
  fr(i,0,SZ(s)) a[i]=s[i]-'a'+1;
  sort(a,a+SZ(s));
  ll prv=-1,ans=0,cnt=0;
  fr(i,0,SZ(s)){
    //cout<<prv<<" "<<a[i]<<"\n";
    if(a[i]-prv>=2){
      ans+=a[i];
      cnt++;
      prv=a[i];
    }
    if(cnt==k) break;
  }

  if(cnt==k) cout<<ans;
  else cout<<-1;

  return 0;
}
