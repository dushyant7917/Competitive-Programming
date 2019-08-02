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
#define N 400005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll p[N];

void cal(){
  p[0]=1;
  fr(i,1,N) p[i]=(p[i-1]*31)%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  cal();

  string s;
  ll L,R,ans,h1,h2;

  while(t--){
    cin>>s;
    s+=s;

    ll pref[SZ(s)],suff[SZ(s)];
    pref[0]=(s[0]-'a');
    suff[SZ(s)-1]=(s[SZ(s)-1]-'a');

    fr(i,1,SZ(s)) pref[i]=(pref[i-1]+(((s[i]-'a')*p[i])%mod))%mod;
    rf(i,SZ(s)-2,0) suff[i]=(suff[i+1]+(((s[i]-'a')*p[SZ(s)-i-1])%mod))%mod;

    ans=0;

    fr(i,0,SZ(s)/2){
      L=i;
      R=i-1+SZ(s)/2;

      if(L>0) h1=(pref[R]-pref[L-1])%mod;
      else h1=pref[R];

      if(R<SZ(s)-1) h2=(suff[L]-suff[R+1])%mod;
      else h2=suff[L];

      if(h1<0) h1+=mod;
      if(h2<0) h2+=mod;

      h1=(h1*p[SZ(s)-R-1])%mod;
      h2=(h2*p[L])%mod;
      //cout<<h1<<" "<<h2<<"\n";

      if(h1==h2) ans++;
    }

    cout<<ans<<"\n";
  }

  return 0;
}
