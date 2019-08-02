#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string s;
  ll f[3]={0};
  fr(i,0,n){
    cin>>s;
    if(s[0]=='1' && s[2]=='4') f[0]++;
    else if(s[0]=='1' && s[2]=='2') f[1]++;
    else f[2]++;
  }

  ll d,cnt=0;

  // combining 1*(1/4) + 1*(3/4) = 1
  d=min(f[0],f[2]);
  cnt+=d;
  f[0]-=d;
  f[2]-=d;

  // combining 2*(1/2) = 1
  cnt+=f[1]/2;
  f[1]=f[1]%2;

  // combining 2*(1/4) + 1*(1/2) = 1
  if(f[1]==1 && f[0]>=2){
    cnt++;
    f[0]-=2;
    f[1]=0;
  }
  else if(f[1]==1 && f[0]==1){
    cnt++;
    f[0]=f[1]=0;
  }
  else {}

  d=min(f[0]/4,f[1]);
  cnt+=d;
  f[0]-=(2*d);
  f[1]-=d;

  // combining 4*(1/4) = 1
  cnt+=f[0]/4;
  if(f[0]%4==0) f[0]=0;
  else f[0]=1;

  // combining rest of the left slices
  cnt+=f[0]+f[1]+f[2];

  cout<<(cnt+1);

  return 0;
}
