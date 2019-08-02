#include<bits/stdc++.h>

using namespace std;
typedef long int li;

int main(){
  li n,h,i;
  cin>>n>>h;

  li boxes[n];
  for(i=0;i<n;i++){
    cin>>boxes[i];
  }

  li cmd,cur_pos=0, load=0;
  do{
    cin>>cmd;
    if(cmd==0){
      break;
    }
    if(cmd==1 && cur_pos!=0){
      cur_pos--;
      continue;
    }
    if(cmd==2 && cur_pos!=n-1){
      cur_pos++;
      continue;
    }
    if(cmd==3 && load==0 && boxes[cur_pos]>0){
      load=1;
      boxes[cur_pos]--;
      continue;
    }
    if(cmd==4 && load==1 && boxes[cur_pos]<h){
      load=0;
      boxes[cur_pos]++;
      continue;
    }
  }while(cmd!=0);

  for(i=0;i<n;i++){
    cout<<boxes[i]<<" ";
  }

  return 0;
}
