#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define sz(s) s.size()

ll x;
ll mark[1000001];

bool F(ll n,ll s1,ll s2){
  if(n==0) return s1==s2;
  if(n==x) return F(n-1,s1,s2);

  if(s1<s2){
    mark[n]=0;
    if(F(n-1,s1+n,s2)) return true;
    mark[n]=1;
    if(F(n-1,s1,s2+n)) return true;
  }
  else{
    mark[n]=1;
    if(F(n-1,s1,s2+n)) return true;
    mark[n]=0;
    if(F(n-1,s1+n,s2)) return true;
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,sum;
  while(t--){
    cin>>x>>n;

    sum=((n*(n+1))/2)-x;

    if(n==1) cout<<2;
    else if(sum&1 || n<=3) cout<<"impossible";
    else{
      if(F(n,0,0)){
        mark[x]=2;
        fr(i,1,n+1) cout<<mark[i];
      }
      else cout<<"impossible";
    }
    cout<<"\n";
  }

  return 0;
}
