#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll k;

void recurse ( array a, int n )
{
  set<ll> b;
	consider all 2^n subsets of a[]
  fr(i,0,n){
    fr(j,i,n){

    }
  }
	{
		x = bitwise OR of elements in the subsets
		add x into "b" if it is not present yet
	}
	if(b.size()==(1<<k))
	{
    cout<<"Won";
		return;
	}
	recurse(b,b.size());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout<<(1<<0);
  /*
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
  }
  */

  return 0;
}
