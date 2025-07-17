#include<iostream>
using namespace std;
bool prime(int m){
    for(int i=2;i<m;i++){
        if(m%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n/2;i++){
        if(prime(i)&&prime(n-i)){
            cout<<i<<" "<<n-i<<endl;
        }
    }
    return 0;
}