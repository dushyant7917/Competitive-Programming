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

  ll n,k;
  cin>>n>>k;
  ll h[n];
  fr(i,0,n) cin>>h[i];

  ll mx=0,mn=INF;
  fr(i,0,n){
    mx=max(mx,h[i]);
    mn=min(mn,h[i]);
  }

  if(mx==mn){
    cout<<0;
    return 0;
  }

  ll cnt[mx+1]={0};
  fr(i,0,n) cnt[h[i]]++;

  rf(i,mx-1,0) cnt[i]+=cnt[i+1];

  ll pos=mx-1,cuts=0,sum=0;
  while(true){
    sum+=cnt[pos+1];
    //cout<<"pos:"<<pos<<" cnt[pos+1]:"<<cnt[pos+1]<<" sum:"<<sum<<"\n";

    if(sum>k){
      cuts++;
      pos++;
      sum=0;
    }

    //cout<<"cuts:"<<cuts<<"\n";

    pos--;
    if(pos==mn-1){
      cuts++;
      break;
    }
  }

  cout<<cuts;

  return 0;
}
