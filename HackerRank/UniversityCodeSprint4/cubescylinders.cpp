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

struct Cube{
  ll len;
  ll num;
};

struct Cylinder{
  ll rad;
  ll cap;
};

bool cmp_rad(struct Cylinder c1,struct Cylinder c2){
  return c1.rad>c2.rad;
}

bool cmp_len(struct Cube c1,struct Cube c2){
  return c1.len>c2.len;
}

bool check(ll rad,ll len){
  if(sqrt(2)*len < 2*rad) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  struct Cube cube[n];
  struct Cylinder cylinder[m];

  fr(i,0,n) cin>>cube[i].len;
  fr(i,0,n) cin>>cube[i].num;
  fr(i,0,m) cin>>cylinder[i].rad;
  fr(i,0,m) cin>>cylinder[i].cap;

  sort(cylinder,cylinder+m,cmp_rad);
  sort(cube,cube+n,cmp_len);

  ll ans=0;
  fr(i,0,m){
    fr(j,0,n){
      while(cylinder[i].cap>0 && cube[j].num>0 && check(cylinder[i].rad,cube[j].len)){
        cylinder[i].cap--;
        cube[j].num--;
        ans++;
      }
    }
  }

  cout<<ans;

  return 0;
}
