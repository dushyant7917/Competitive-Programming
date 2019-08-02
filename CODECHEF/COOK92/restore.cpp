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

ll solve(){
  ll n,m,k;
  cin>>n>>m>>k;

  ll a[n],dx[n],inc[n],dec[n];

  fr(i,0,n){
    cin>>a[i];
    inc[i]=dec[i]=0;
  }

  char ty;
  ll l,r;
  fr(i,0,m){
    cin>>ty>>l>>r;
    l--;
    r--;
    if(ty=='I'){
      inc[l]++;
      inc[r]--;
    }
    else{
      dec[l]++;
      dec[r]--;
    }
  }

  ll rise=0,fall=0;
  fr(i,0,n){
    rise+=inc[i];
    fall+=dec[i];
    if(rise && fall) return 0;
    else if(rise) dx[i]=1;
    else if(fall) dx[i]=-1;
    else dx[i]=0;
  }

  ll ans=1;

  ll i=0,x,mx,mn,sum;
  bool flag;

  while(i<n){
    l=r=i;
    while(r<n && dx[r]!=0) r++;

    flag=true; // true means all elements in range [l,r] are -1

    fr(ind,l,r+1){
      if(a[ind]!=-1){
        flag=false;
        fr(j,ind+1,r+1){
          x=a[j-1]+dx[j-1];
          if(a[j]!=-1 && a[j]!=x) return 0;
          a[j]=x;
          if(a[j]<=0 || a[j]>k) return 0;
        }
        rf(j,ind-1,l){
          x=a[j+1]-dx[j];
          if(a[j]!=-1 && a[j]!=x) return 0;
          a[j]=x;
          if(a[j]<=0 || a[j]>k) return 0;
        }
        break;
      }
    }

    // all elements in range [l,r] are not -1
    if(flag){
      sum=mx=mn=0;
      fr(j,l,r){
        sum+=dx[j];
        mx=max(mx,sum);
        mn=min(mn,sum);
      }
      if(mx-mn+1>k) return 0;
      ans=(ans*(k-mx+mn))%mod;
    }

    i=r+1;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--) cout<<solve()<<"\n";

  return 0;
}
