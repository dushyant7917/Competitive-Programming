#include <bits/stdc++.h>
using namespace std;


char mat[50][50];
int visited[50][50];
int countv=0; // hold the final answer for each case
int n,m; // row and column

void dfsTraversal(int r,int col, int DepthNow)
{
     /*Updating the answer if required*/
     countv=max(DepthNow,countv);

     /*These 8 values are for the all the adjacent
     8 blocks int the 2D array*/

     int rr[8]={-1,-1,-1,0,0,1,1,1};
     int cc[8]={-1,0,1,-1,1,-1,0,1};

     for(int i=0;i<8;++i)
     {
          /*Generating indices of the 8 adjacent blocks*/
          int tempr=r+rr[i];
          int tempc=col+cc[i];

          /*Checking if the temporary row and column generated are
          within the bounds of the the matrix*/

          if((tempr>=0 && tempr<n) && (tempc>=0 && tempc<m) && !visited[tempr][tempc])
          {
               /*If the character in the adjacent block is
               consecutive character with repect to the
               character in present block*/

               if(mat[tempr][tempc]== mat[r][col] + 1)
               {
                    visited[tempr][tempc]=1;
                    dfsTraversal(tempr,tempc,DepthNow+1);
               }
          }
     }
}

int main() {

     scanf("%d%d",&n,&m);
     int caseCount=0;
     /*Loop runs till both n and m are non-zero*/
     while(n && m)
     {
          countv=0;
          caseCount++;
          for(int i=0;i<n;++i)
               for(int j=0;j<m;++j)
               {
                    cin>>mat[i][j];
                    visited[i][j]=0;
               }
          /*The following loop is used to run multisource DFS
          on all blocks having an 'A*/
          for(int i=0;i<n;++i)
               for(int j=0;j<m;++j)
               {
                    if(mat[i][j]=='A')
                    {
                         visited[i][j]=1;
                         dfsTraversal(i,j,1);
                    }
               }
          printf("Case %d: %d\n",caseCount,countv);
          scanf("%d%d",&n,&m);
     }
     return 0;
}
