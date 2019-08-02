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
#define N 1000002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool valid(ll n){
  if(abs(n)<=1000ll) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,ans2,x,ind;
  while(t--){
    cin>>n;
    ll a[n];
    ll f[N]={0};
    vector<ll> v;
    fr(i,0,n){
      cin>>a[i];
      if(a[i]<0){
        f[abs(a[i])+1000ll]++;
        if(f[abs(a[i])+1000ll]==1ll) v.PB(a[i]);
      }
      else{
        f[a[i]]++;
        if(f[a[i]]==1ll) v.PB(a[i]);
      }
    }

    ans2=0;

    fr(i,0,SZ(v)){
      if(v[i]<0){
        rf(j,0,max(-1000ll,v[i])){
          x=2ll*v[i]-j;
          //cout<<"Considering..."<<j<<" "<<x<<"\n";
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(j==0 && x==0) ans2+=(f[0]*(f[0]-1ll))/2;
            else if(j==0 && x!=0) ans2+=f[abs(x)+1000ll]*f[0];
            else if(j!=0 && x==0) ans2+=f[abs(j)+1000ll]*f[0];
            else if(j!=0 && x==j) ans2+=(f[abs(j)+1000ll]*(f[abs(j)+1000ll]-1ll))/2;
            else ans2+=f[(x<0)?abs(x)+1000ll:x]*f[abs(j)+1000ll];
          }
        }
        rf(j,max(-1000ll,2*v[i])-1ll,-1000ll){
          x=2ll*v[i]-j;
          //cout<<"Considering..."<<j<<" "<<x<<"\n";
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(x==j) ans2+=(f[abs(j)+1000ll]*(f[abs(j)+1000ll]-1ll))/2;
            else ans2+=f[(x<0)?abs(x)+1000ll:x]*f[abs(j)+1000ll];
          }
        }
        //cout<<"\n";
      }

      else{
        fr(j,0,min(1000ll,v[i])+1ll){
          x=2ll*v[i]-j;
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(j==0 && x==0) ans2+=(f[0]*(f[0]-1ll))/2;
            else if(j==0 && x!=0) ans2+=f[x]*f[0];
            else if(j!=0 && x==0) ans2+=f[j]*f[0];
            else if(j!=0 && x==j) ans2+=(f[j]*(f[j]-1))/2;
            else ans2+=f[(x<0)?abs(x)+1000ll:x]*f[j];
          }
        }
        fr(j,min(1000ll,2*v[i])+1ll,1000ll+1ll){
          x=2ll*v[i]-j;
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(x==j) ans2+=(f[j]*(f[j]-1ll))/2;
            else ans2+=f[(x<0)?abs(x)+1000ll:x]*f[j];
          }
        }
        //cout<<"\n";
      }
    }

    cout<<ans2<<"\n";

  }

  return 0;
}
