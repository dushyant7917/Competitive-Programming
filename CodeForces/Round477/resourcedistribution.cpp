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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Server{
  ll ind,resource;
};

bool cmp(Server s1,Server s2){
  return s1.resource<s2.resource;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,x1,x2;
  cin>>n>>x1>>x2;

  Server a[n];

  fr(i,0,n){
    cin>>a[i].resource;
    a[i].ind=i+1;
  }

  sort(a,a+n,cmp);

  ll ind2,ind1;
  bool flag;

  flag=false;

  rf(i,n-1,0){
    if(a[i].resource*(n-i)>=x2){
      flag=true;
      ind2=i;
      break;
    }
  }

  if(flag){
    flag=false;

    rf(i,ind2-1,0){
      if(a[i].resource*(ind2-i)>=x1){
        flag=true;
        ind1=i;
        break;
      }
    }

    if(flag){
      cout<<"Yes\n";
      cout<<ind2-ind1<<" "<<n-ind2<<"\n";
      fr(i,ind1,ind2) cout<<a[i].ind<<" "; cout<<"\n";
      fr(i,ind2,n) cout<<a[i].ind<<" ";
      return 0;
    }
  }

  flag=false;

  rf(i,n-1,0){
    if(a[i].resource*(n-i)>=x1){
      flag=true;
      ind2=i;
      break;
    }
  }

  if(flag){
    flag=false;

    rf(i,ind2-1,0){
      if(a[i].resource*(ind2-i)>=x2){
        flag=true;
        ind1=i;
        break;
      }
    }

    if(flag){
      cout<<"Yes\n";
      cout<<n-ind2<<" "<<ind2-ind1<<"\n";
      fr(i,ind2,n) cout<<a[i].ind<<" "; cout<<"\n";
      fr(i,ind1,ind2) cout<<a[i].ind<<" ";
      return 0;
    }
  }

  cout<<"No";

  return 0;
}
