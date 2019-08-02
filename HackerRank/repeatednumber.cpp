#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];

  ll max_size=0;
  fr(0,n){
    cin>>a[i];
    max_size=max(max_size,a[i]);
  }

  // Method 1 : works in O(n) with O(2n) space
  map<ll,ll> freq;
  fr(0,n){
    freq[a[i]]++;
    if(freq[a[i]]>1){
      cout<<a[i];
      break;
    }
  }

  // Method 2 : works in O(n) time but requires extra O(max(a[0],a[1]...a[n-1])) space
  /*
  ll freq[max_size+1]={};
  fr(0,n){
    freq[a[i]]++;
    if(freq[a[i]]>1){
      cout<<a[i];
      break;
    }
  }
  */

  // method 3 : works in O(nlogn)
  /*
  sort(a,a+n);

  fr(0,n){
    if(binary_search(a+i+1,a+n,a[i])){
      cout<<a[i];
      break;
    }
  }
  */

  // method 4 : works in O(nlogn)
  /*
  sort(a,a+n);

  fr(0,n){
    if(a[i]==a[i+1]){
      cout<<a[i];
      break;
    }
  }
  */

  return 0;
}
