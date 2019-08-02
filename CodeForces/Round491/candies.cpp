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

ll n;

ll F(ll k){
  ll v=0,p=0,cnt=n,m;
  //cout<<"k:"<<k<<"\n";

  ll ind=0;

  while(cnt && ind<20){
    //cout<<"cnt:"<<cnt<<" ";
    if(cnt>=k){
      v+=k;
      cnt-=k;
    }
    else{
      v+=cnt;
      cnt=0;
    }

    if(cnt){
      m=cnt/10;
      p+=m;
      cnt-=m;
    }
    //ind++;
    //cout<<cnt<<"\n\n";
  }

  //cout<<"v:"<<v<<"\n\n";

  return v;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll ans=INF;
  ll l=1,h=n,m;

  while(l<=h){
    m=(l+h)/2;
    if(2*F(m)>=n){
      ans=m;
      h=m-1;
    }
    else l=m+1;
  }

  cout<<ans;

  return 0;
}
