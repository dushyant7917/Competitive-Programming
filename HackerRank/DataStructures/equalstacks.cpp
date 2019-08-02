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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n1,n2,n3;
  cin>>n1>>n2>>n3;

  ll c1[n1],c2[n2],c3[n3];
  ll h1=0,h2=0,h3=0;

  fr(i,1,n1+1){
    cin>>c1[i];
    h1+=c1[i];
  }
  fr(i,1,n2+1){
    cin>>c2[i];
    h2+=c2[i];
  }
  fr(i,1,n3+1){
    cin>>c3[i];
    h3+=c3[i];
  }

  reverse(c1+1,c1+n1+1);
  reverse(c2+1,c2+n2+1);
  reverse(c3+1,c3+n3+1);

  while(h1!=h2 || h1!=h3){
    if(h1>h2) h1-=c1[n1],n1--;
    if(h1>h3) h1-=c1[n1],n1--;
    if(h1<h2) h2-=c2[n2],n2--;
    if(h3<h2) h2-=c2[n2],n2--;
    if(h3>h1) h3-=c3[n3],n3--;
    if(h3>h2) h3-=c3[n3],n3--;
  }

  cout<<MIN(h1,h2,h3);

  return 0;
}
