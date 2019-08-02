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
#define sz(s) s.size()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k,s,cnt,carry,f,np;
  while(t--){
    cin>>n>>k>>s;
    cnt=0;
    carry=0;
    f=1;
    fr(i,1,s+1){
      //cout<<"day:"<<i<<" "<<carry<<"\n";

      if(i%7!=0){
        if(carry>=k){
          carry=carry-k;
        }
        else if(k>carry && carry+n>=k){
          cnt++;
          carry=(carry+n)-k;
        }
        else{
          f=0;
          break;
        }
      }
      else{
        if(carry>=k){
          carry=carry-k;
        }
        else{
          np=0;
          while(cnt<(i-(i/7)) && carry<k){
            cnt++;
            carry=carry+n;
            if(carry>=k){
              carry=carry-k;
              np=1;
              break;
            }
          }
          if(!np){
            f=0;
            break;
          }
        }
      }
    }
    if(f) cout<<cnt<<"\n";
    else cout<<-1<<"\n";
  }

  return 0;
}
