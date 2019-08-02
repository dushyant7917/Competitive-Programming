#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

// NOTE: big numbers have to be inputed as strings in c++

bool cmp(string p,string q){
  ll l1=p.size(), l2=q.size();
  if(l1==l2){
    return p<q;
  }
  else{
    return l1<l2;
  }
}

int main(){
  ll n;
  cin>>n;
  string a[n];
  loop(0,n){
    cin>>a[i];
  }

  sort(a,a+n,cmp);

  loop(0,n){
    cout<<a[i]<<"\n";
  }

  return 0;
}
