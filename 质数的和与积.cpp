#include<iostream>
using namespace std;
bool prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int S,maxx=0;
    cin>>S;
    for(int i=2;i<=S;i++){
        if(prime(i)&&prime(S-i)){
            if(i*(S-i)>maxx){
                maxx=i*(S-i);
        }
    }
    }
    cout<<maxx;
    return 0;
}