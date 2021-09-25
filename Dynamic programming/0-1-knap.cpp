//header file
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){

    return (a>b)?a:b;
}
 int knap(int w,int n,int val[] ,int wt[]){
     int i,j;
     vector<vector<int>> k(n+1 ,vector<int>(w+1));
     //k[i][j]
     for(i=0;i<=n;i++){
         for(j=0;j<=w;j++){
             if(i==0 || j==0){
                  k[i][j]=0;
             }else if(wt[i-1]>j){
                  k[i][j] = k[i-1][j];
             }else{
                  k[i][j]=max(val[i-1]+ k[i-1][j-wt[i-1]], k[i-1][j]);
             }
         }
     }
     return k[n][w];

 }
int main(){
    int n,w,i,wt[n+1],val[n+1];
    cout<<" enter no. of element : ";
    cin>>n;
    cout<<"enter capacity of  knap: ";
    cin>>w;
    for(i=0;i<n;i++){
        cout<<"enter weight of  "<<i<<" th element of knep: ";
        cin>>wt[i];


    }
    for(i=0;i<n;i++){
        cout<<"netr value of "<<i<<" th  value of knap: ";
        cin>>val[i];

    }
    cout<<knap(w,n, val,wt);

}
