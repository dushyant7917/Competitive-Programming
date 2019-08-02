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
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,p;
  while(t--){
    cin>>n>>p;
    if(n<3){
      cout<<"impossible\n";
      continue;
    }
    else{
      if(p<3){
        cout<<"impossible\n";
        continue;
      }
      else{
        string ans="";
        string a="";
        stack<char> s;

        fr(i,0,(p+1)/2){
          if(i%2==0) a+='a';
          else a+='b';
        }
        fr(i,0,p/2){
          s.push(a[i]);
        }
        while(!s.empty()){
          a+=s.top();
          s.pop();
        }
        fr(i,0,n/p){
          ans+=a;
        }

        cout<<ans<<"\n";
      }
    }
  }

  return 0;
}
