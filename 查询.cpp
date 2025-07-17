#include<iostream>
using namespace std;
int a2[105];
int main(){
    int n,a[105],p1=-1,p2=-1,pos1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>p1){
            p1=a[i];
            pos1=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=pos1){
            a2[i]=a[i];
        }
    }
    for(int j=1;j<=n;j++){
        if(a2[j]>p2){
            p2=a2[j];
        }
    }
    cout<<p2;
    
    return 0;
}