#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

ll binarySearch(ll arr[], ll l, ll r, ll x)
{
  if (r >= l)
  {
    ll mid=l+(r-l)/2;

    // If the element is present at the middle itself
    if (arr[mid] == x)  return mid;

    // If element is smaller than mid, then it can only be present
    // in left subarray
    if(arr[mid] > x)
      return binarySearch(arr, l, mid-1, x);

    return binarySearch(arr, mid+1, r, x);
  }
  return -1;
}

int main(){
  ll n,m,k;
  cin>>n>>m>>k;

  if(m>n-1){
    cout<<-1;
    return 0;
  }

  ll b[n],range_sum[n]={};

  loop(0,n){
    cin>>b[i];
  }

  sort(b,b+n);
  cout<<binarySearch(b,4,n-1,3);

  return 0;
}
