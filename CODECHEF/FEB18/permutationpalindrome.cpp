#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  string s;
  ll no,ne,l,r,ind;

  while(t--){
    cin>>s;
    n=SZ(s);

    ll a[n];

    vector<ll> f[26];
    fr(i,0,n) f[s[i]-'a'].PB(i+1);

    no=ne=0;
    fr(i,0,26){
      if(SZ(f[i])){
        if(SZ(f[i])&1) no++;
        else ne++;
      }
    }

    if(n&1){
      if(no!=1) cout<<-1;
      else{
        l=r=n/2;
        fr(i,0,26) if(SZ(f[i])&1) ind=i;
        a[n/2]=f[ind][0];
        l--;
        r++;
        fr(i,0,26){
          if(SZ(f[i])){
            if(i==ind){
              fr(j,1,SZ(f[i])){
                a[l--]=f[i][j];
                j++;
                a[r++]=f[i][j];
              }
            }
            else{
              fr(j,0,SZ(f[i])){
                a[l--]=f[i][j];
                j++;
                a[r++]=f[i][j];
              }
            }
          }
        }

        fr(i,0,n) cout<<a[i]<<" ";
      }
    }

    else{
      if(no!=0) cout<<-1;
      else{
        l=(n/2)-1,r=n/2;
        fr(i,0,26){
          if(SZ(f[i])){
            fr(j,0,SZ(f[i])){
              a[l--]=f[i][j];
              j++;
              a[r++]=f[i][j];
            }
          }
        }

        fr(i,0,n) cout<<a[i]<<" ";
      }
    }

    cout<<"\n";
  }

  return 0;
}
