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

  string t,s="",tmp="";
  cin>>t;

  ll ind=0,l,r;
  bool flag;

  fr(i,1,SZ(t)){
    flag=true;
    l=i;
    r=0;

    while(l<SZ(t) && r<SZ(t)){
      if(t[l]!=t[r]){
        flag=false;
        break;
      }
      else{
        l++;
        r++;
      }
    }

    if(flag){
      ind=i;
      break;
    }
  }

  if(ind==0){
    fr(i,0,k) s+=t;
  }
  else{
    s+=t;
    fr(i,SZ(t)-ind,SZ(t)) tmp+=t[i];
    fr(i,0,k-1) s+=tmp;
  }

  cout<<s;

  return 0;
}
