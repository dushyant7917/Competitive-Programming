#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

dbl num_subarrays(ll n){
  return (dbl)((n*(n+1))/2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  bool flag=false;

  while(t--){
    cin>>n;

    dbl a[n];
    // avg of median of subarrays of below two array sets will always lie in range [n-1,n+1]
    fr(i,0,n) a[i]=(dbl)(2*i+2); // a[i]=(dbl)(2*i+1)

    /*
    dbl median_sum=0;
    fr(i,0,n){
      fr(j,i,n){
        if(i==j) median_sum+=a[i]; // subarray is a[i or j]
        else if((j-i)%2==0) median_sum+=a[(j+i)/2]; // subarray is a[i] to a[j] and is of odd length
        else median_sum+=(a[(j+i)/2]+a[((j+i)/2)+1])/(2.0); // subarray is a[i] to a[j] and is of even length
      }
    }

    dbl median_avg=median_sum/num_subarrays(n);

    if( ((dbl)(n-1))<=median_avg && median_avg<=((dbl)(n+1)) ){
      fr(i,0,n) cout<<a[i]<<" ";
      cout<<"\n";
    }
    else cout<<"-1\n";
    */

    fr(i,0,n) cout<<a[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
