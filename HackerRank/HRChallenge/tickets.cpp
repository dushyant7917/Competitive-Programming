#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

ll mask(string t){
  ll m=0;
  fr(i,0,SZ(t)){
    m+=(t[i]-'0')*pow(2,SZ(t)-i-1);
  }
  return m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll f[1<<10];
  fr(i,0,1<<10) f[i]=0;

  ll n;
  cin>>n;

  string s,t;
  fr(i,0,n){
    cin>>s;

    ll cnt[10]={0};
    fr(j,0,SZ(s)) cnt[s[j]-'0']=1;

    t="";
    fr(j,0,10){
      if(cnt[j]) t+='1';
      else t+='0';
    }

    f[mask(t)]++;
  }

  ll ans=0;

  fr(i,0,1<<10){
    fr(j,i,1<<10){
      if((i|j)==1023){
        if(i==j) ans+=(f[i]*(f[i]-1))/2;
        else ans+=f[i]*f[j];
      }
    }
  }

  cout<<ans;

  return 0;
}
