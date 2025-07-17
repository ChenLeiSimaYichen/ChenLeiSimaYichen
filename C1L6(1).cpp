#include<iostream>
using namespace std;
int main(){
    int m,n,x,mum=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(mum+x<n){
            mum+=x;
        }
        else{
            cout<<i;
            break;
        }
        
    }
    return 0;
}