#include<bits/stdc++.h>

using namespace std;

typedef long int li;
#define loop(a,b) for(li i=a;i<b;i++)

int main(){
  li n,x,y;
  cin>>n>>x>>y;
  li a[n][2];
  vector<li> v,w;

  loop(0,n){
    cin>>a[i][0]>>a[i][1];
  }
  li p,q;
  loop(0,x){
    cin>>p;
    v.push_back(p);
  }
  loop(0,y){
    cin>>q;
    w.push_back(q);
  }

  sort(v.begin(), v.end());
  sort(w.begin(), w.end());

  li min=2*(1000000)+1;
  li lv,lw;

  loop(0,n){
    lv=upper_bound(v.begin(), v.end(), a[i][0])-v.begin()-1;
    lw=lower_bound(w.begin(), w.end(), a[i][1])-w.begin();
    if(lw>=w.size() || lv>=v.size() || lw<0 || lv<0){
      continue;
    }
    if(w[lw]-v[lv]+1<min){
      min=w[lw]-v[lv]+1;
    }
  }

  cout<<min;

  return 0;
}
