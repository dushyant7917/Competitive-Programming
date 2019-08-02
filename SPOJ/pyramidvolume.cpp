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

dbl cosine(dbl a,dbl b,dbl c){
  return (a*a+b*b-c*c)/(2.0*a*b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  dbl AB,AC,AD,BC,BD,CD;
  dbl vol;
  dbl cos1,cos2,cos3;
  while(t--){
    cin>>AB>>AC>>AD>>BC>>BD>>CD;
    cos1=cosine(AD,BD,AB);
    cos2=cosine(BD,CD,BC);
    cos3=cosine(CD,AD,AC);
    vol=sqrt(1+2*cos1*cos2*cos3-cos1*cos1-cos2*cos2-cos3*cos3);
    vol=AD*BD*CD*vol/6.0;
    cout<<fixed<<setprecision(4)<<vol<<"\n";
  }

  return 0;
}
