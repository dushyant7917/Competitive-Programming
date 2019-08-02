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
ll a[N];
bool bit[N][32];
ll one[N][32],sum[N][32];
ll p[N][32],s[N][32];

ll bitToNum(ll b[32]){
  ll num=0;

  fr(i,0,32) if(b[i]) num+=(1<<i);

  return num;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,1,n+1) cin>>a[i];

  fr(i,1,n+1){
    fr(j,0,32){
      if(a[i]&(1<<j)) bit[i][j]=1;
      else bit[i][j]=0;
    }
  }

  fr(j,0,32) sum[0][j]=0;

  fr(i,1,n+1){
    fr(j,0,32){
      sum[i][j]=sum[i-1][j]+bit[i][j];
    }
  }

  fr(j,0,32){
    if(bit[1][j]) p[1][j]=1;
    else bit[1][j]=0;

    if(bit[n][j]) s[n][j]=1;
    else s[n][j]=0;

    if(bit[n][j]) one[n][j]=n;
    else one[n][j]=-1;
  }

  fr(i,2,n+1){
    fr(j,0,32){
      if(bit[i][j] || p[i-1][j]) p[i][j]=1;
      else p[i][j]=0;
    }
  }

  rf(i,n-1,1){
    fr(j,0,32){
      if(bit[i][j] || s[i+1][j]) s[i][j]=1;
      else s[i][j]=0;

      if(bit[i][j]) one[i][j]=i;
      else one[i][j]=one[i+1][j];
    }
  }

  ll pos;

  ll ans=0;

  fr(i,1,n+1){
    vector<ll> v;
    map<ll,ll> mp;

    fr(j,0,32){
      if(!s[i][j] || one[i][j]==-1) continue;
      pos=one[i][j];
      if(mp[pos]) continue;
      v.PB(pos);
      mp[pos]=1;
    }

    sort(v.begin(),v.end(),greater<ll>());

    ll prv=n+1;

    fr(j,0,SZ(v)){
      //cout<<"pos:"<<v[j]<<"\n";
      ll b[32]={0};

      fr(k,0,32){
        if(sum[v[j]][k]-sum[i-1][k]) b[k]=1;
      }
      //cout<<"ans+=:"<<bitToNum(b)<<"*"<<(prv-v[j])<<"\n";
      ans+=bitToNum(b)*(prv-v[j]);
      prv=v[j];
    }
    //cout<<ans;
    //cout<<"\n\n";
  }

  cout<<ans;

  return 0;
}
