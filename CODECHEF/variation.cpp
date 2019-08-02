#include<bits/stdc++.h>
using namespace std;

typedef long int li;

int main(){
  li n,k;
  cin>>n>>k;

  li a[n],i,j,cnt=0;

  for(i=0;i<n;i++)
    cin>>a[i];

  sort(a,a+n);

  // O(n^2)
  /*
  for(i=0;i<n-1;i++){
    j=i+1;
    while(j<n){
      if(abs(a[i]-a[j])>=k){
        cnt+=n-j;
        break;
      }
      j++;
    }
  }
  */

  //The above algo helps to understand below algo

  // O(nlogn)
  i=0;j=0;
  while(i<n && j<n){
    if(a[j]-a[i]>=k){
      i++;
      cnt+=n-j;
    }
    else{
      j++;
    }
  }

  cout<<cnt;
  return 0;
}
