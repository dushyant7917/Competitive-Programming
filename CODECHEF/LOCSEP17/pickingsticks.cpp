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

struct Sticks{
  ll l;
  ll r;
};

bool cmp(struct Sticks s1,struct Sticks s2){
  if(s1.l!=s2.l) return s1.l<s2.l;
  else return s1.r>s2.r;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  struct Sticks s[n];

  fr(i,0,n){
    cin>>s[i].l>>s[i].r;
  }

  sort(s,s+n,cmp);

  fr(i,0,n){
    cout<<s[i].l<<" "<<s[i].r<<"\n";
  }

  return 0;
}
