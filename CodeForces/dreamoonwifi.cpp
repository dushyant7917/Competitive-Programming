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

ll nCr(ll n,ll r) {
  if(r>n/2) r=n-r;
  ll ans=1;
  
  fr(i,1,r+1){
    ans*=n-r+i;
    ans/=i;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1,s2;
  cin>>s1>>s2;

  ll pos1=0;
  fr(i,0,s1.size()){
    if(s1[i]=='+') pos1++;
    else pos1--;
  }
  ll pos2=0,q=0;
  fr(i,0,s2.size()){
    if(s2[i]=='+') pos2++;
    else if(s2[i]=='-') pos2--;
    else q++;
  }

  dbl ans=0.0;
  if(!q && pos1==pos2) ans=1.0;
  else if(abs(pos1-pos2)>q) ans=0.0;
  else if((pos1-pos2+q)&1) ans=0.0;
  else{
    ans=nCr(q,(q+abs(pos1-pos2))/2)/(dbl)(1<<q);
  }
  cout<<fixed<<setprecision(12)<<ans;

  return 0;
}
