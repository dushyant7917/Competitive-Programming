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
#define N 1000000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Q{
  ll x;
  ll ind;
  ll ans;
};

bool cmp_x(struct Q q1,struct Q q2){
  return q1.x<q2.x;
}

bool cmp_ind(struct Q q1,struct Q q2){
  return q1.ind<q2.ind;
}

struct Q q[200];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin>>n;

  fr(i,0,n){
    cin>>q[i].x;
    q[i].ind=i;
  }

  sort(q,q+n,cmp_x);

  ll l=0,r=1,b=0,dist=2,c1,c2;
  fr(i,0,n){
    q[i].ans=INF;

    c1=b+abs(l-q[i].x);
    c2=(b+1)+abs(r-q[i].x);
    q[i].ans=MIN(q[i].ans,c1,c2);

    //cout<<"b:"<<b<<" l:"<<l<<" r:"<<r<<"\n";
    //cout<<"c1:"<<c1<<" c2:"<<c2<<"\n";

    while(r<q[i].x){
      l=r;
      r=r+dist;
      dist++;
      b++;
      c1=b+abs(l-q[i].x);
      c2=(b+1)+abs(r-q[i].x);
      q[i].ans=MIN(q[i].ans,c1,c2);
      //cout<<"b:"<<b<<" l:"<<l<<" r:"<<r<<"\n";
      //cout<<"c1:"<<c1<<" c2:"<<c2<<"\n";
    }

    //cout<<q[i].x<<"\n\n";
  }

  sort(q,q+n,cmp_ind);

  fr(i,0,n) cout<<q[i].ans<<"\n";

  return 0;
}
