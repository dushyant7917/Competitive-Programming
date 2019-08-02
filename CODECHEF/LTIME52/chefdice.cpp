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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    ll a[n];
    fr(i,0,n) cin>>a[i];




    ll o[7]={0};
    set<ll> s[7];
    ll prv=a[0],cur;
    fr(i,1,n){
      cur=a[i];
      cout<<prv<<" "<<cur<<"\n";
      s[prv].insert(cur);
      s[cur].insert(prv);
      prv=cur;
    }
    /*
    ll cnt=0;
    fr(i,1,7) if(s[i].size()>=2) cnt++;
    if(cnt>=4){
      fr(i,1,7){
        if(s[i].size()>=2){
          set<ll>::iterator itr;
          for(itr=s[i].begin();itr!=s[i].end();itr++){
            if(o[*itr]==0){
              ll d=*itr;
              itr++;
              if(o[*itr]==0){
                o[d]=*itr;
                o[*itr]=d;
                break;
              }
            }
          }
        }
      }

      ll p=0,q=0;
      fr(i,1,7){
        if(o[i]==0) p=i;
        if(p!=0 && o[i]==0){
          q=i;
          break;
        }
      }
      o[p]=q;
      o[q]=p;

      fr(i,1,7) cout<<o[i]<<" ";

      cout<<"\n";
    }
    else{
      cout<<-1<<"\n";
      continue;
    }
    */
    cout<<"\n";
  }

  return 0;
}
