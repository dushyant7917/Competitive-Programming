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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,a,l;
  string s;
  string base1="abc",base2="aababb";
  string ans[9]={"","1 a","1 ab","2 aab","2 aabb","3 abaaa","3 aaabab","3 aaababb","3 aaababbb"};

  while(t--){
    cin>>n>>a;
    if(a==1){
      s="";
      l=n;
      fr(i,0,n){
        s+='a';
      }
      cout<<l<<" "<<s<<"\n";
    }
    else if(a>2){
      s="";
      l=1;
      fr(i,0,n/3){
        s+=base1;
      }
      fr(i,0,n%3){
        s+=base1[i];
      }
      cout<<l<<" "<<s<<"\n";
    }
    else if(a==2 && n>8){
      s="";
      l=4;
      fr(i,0,n/6){
        s+=base2;
      }
      fr(i,0,n%6){
        s+=base2[i];
      }
      cout<<l<<" "<<s<<"\n";
    }
    else{
      cout<<ans[n]<<"\n";
    }
  }

  return 0;
}
