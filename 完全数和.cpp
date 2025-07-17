#include<iostream>
using namespace std;
int sumc(int x){
    int sum=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            if(i*i!=x){
                sum+=i+x/i;
            }
            else{
                sum+=i;
            }
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(sumc(i)==i){
            cout<<i<<endl;
        }
    }
    return 0;
}