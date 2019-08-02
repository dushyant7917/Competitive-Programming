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

ll n,k;
ll b[N];

struct Card{
  ll val;
  ll num;
};

bool cmp(struct Card c1,struct Card c2){
  return c1.val<c2.val;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll ans,total_cards,total_sum,tc,req;
  while(t--){
    cin>>n>>k;

    struct Card c[n];
    total_cards=total_sum=0;

    fr(i,0,n) cin>>c[i].val;
    fr(i,0,n) cin>>c[i].num;
    fr(i,0,k) cin>>b[i];

    fr(i,0,n){
      total_sum+=c[i].val*c[i].num;
      total_cards+=c[i].num;
    }

    tc=total_cards;

    sort(c,c+n,cmp);

    vector<ll> a1,a2;

    fr(i,0,k){
      if(total_cards<=0) break;

      // chefs turn
      if(i%2==0){
        a1.PB(abs(total_cards-b[i]));
        total_cards-=abs(total_cards-b[i]);
      }
      // chefus turn
      else{
        a2.PB(abs(total_cards-b[i]));
        total_cards-=abs(total_cards-b[i]);
      }
    }

    ll l=0,r=0;
    fr(i,0,SZ(a1)) l+=a1[i];
    fr(i,0,SZ(a2)) r+=a2[i];

    req=l;
    fr(i,0,n){
      if(req==0) break;
      else{
        if(c[i].num<=req){
          req-=c[i].num;
          c[i].num=0;
        }
        else{
          c[i].num-=req;
          req=0;
        }
      }
    }

    req=r;
    rf(i,n-1,0){
      if(req==0) break;
      else{
        if(c[i].num<=req){
          req-=c[i].num;
          c[i].num=0;
        }
        else{
          c[i].num-=req;
          req=0;
        }
      }
    }

    ans=0;
    fr(i,0,n) ans+=c[i].val*c[i].num;
    cout<<ans<<"\n";
  }

  return 0;
}
