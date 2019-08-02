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

struct Laptop{
  string n;
  ll p;
};

bool equal47(ll p){
  ll f[2]={0};
  while(p>0){
    if(p%10==4) f[0]++;
    else if(p%10==7) f[1]++;
    else return false;
    p=p/10;
  }

  return (f[0]!=0 && f[1]!=0 && f[0]==f[1])?true:false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  struct Laptop lap[n];
  ll ind=0;
  string name;
  ll price;
  fr(i,0,n){
    cin>>name>>price;
    if(equal47(price)==true){
      lap[ind].n=name;
      lap[ind].p=price;
      ind++;
    }
  }

  if(ind==0) cout<<-1;
  else{
    string selected;
    ll min_p=INF;
    fr(i,0,ind){
      if(lap[i].p<min_p){
        selected=lap[i].n;
        min_p=lap[i].p;
      }
    }
    cout<<selected;
  }

  return 0;
}
