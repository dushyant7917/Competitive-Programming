#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

ll allOnes(ll ind){
  ll num=0;
  rf(i,ind,0) num+=pow(2,i);
  return num;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll l,r,x,y,bx;

  while(t--){
    cin>>x>>l>>r;

    y=0;

    rf(i,31,0){
      bx=(x&(ll)pow(2,i))?1:0;
      //cout<<"bit:"<<i<<" -> ";

      if(bx){
        if(y>=l){
          //cout<<"1.1 "<<y<<"\n";
        }
        else if(y<l && y+allOnes(i-1)>=l){
          //cout<<"1.2 "<<y<<"\n";
        }
        else{
          y+=pow(2,i);
          //cout<<"1.3 "<<y<<"\n";
        }
      }

      else{
        if(y+pow(2,i)<=r){
          y+=pow(2,i);
          //cout<<"2.1 "<<y<<"\n";
        }
        else{
          //cout<<"2.2 "<<y<<"\n";
        }
      }
    }

    //cout<<"\n";
    cout<<(x^y)<<"\n";
  }

  return 0;
}
