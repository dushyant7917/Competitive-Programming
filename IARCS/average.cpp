#include<bits/stdc++.h>

using namespace std;

int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int n;
  cin>>n;
  int s[n];
  int cnt=0,i,j,k;
  set<int> d;
  for(i=0;i<n;i++){
    cin>>s[i];
    //cout<<s[i]<<"\n";
    d.insert(s[i]);
  }

  vector<int> v;
  for(set<int>::iterator it=d.begin();it!=d.end();it++){
    v.push_back(*it);
  }
  sort(v.begin(),v.end());
  map<int,int> freq;

  // Calculating frequency
  for(i=0;i<v.size();i++){
    freq.insert(pair<int,int>(v[i],0));
    for(j=0;j<n;j++){
      if(s[j]==v[i])
        freq[v[i]]++;
    }
  }
  //

  int status;
  for(k=0;k<v.size();k++){
    i=0;
    j=v.size()-1;
    status=0;
    while(i<j){
      //cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" v[k]:"<<v[k]<<" v[i]:"<<v[i]<<" v[j]:"<<v[j]<<" sum:"<<v[i]+v[j]<<"\n";
      if(v[i]+v[j]==2*v[k]){
        cnt+=freq[v[k]];
        status=1;
        //cout<<"cnt:"<<cnt<<"\n";
        break;
      }
      else if(v[i]+v[j]<2*v[k]){
        i++;
      }
      else{
        j--;
      }
    }
    if(status==0 && freq[v[k]]>1){
      cnt+=freq[v[k]];
      //cout<<"cnt:"<<cnt<<"\n";
    }
  }

  //cout<<"\n";
  cout<<cnt;
  return 0;
}
