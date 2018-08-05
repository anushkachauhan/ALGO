#include<iostream>
using namespace std;
int main(){
    int t=1;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a[n];
        int i;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int count[n] = {0};
        for(i=0;i<n;i++)   {
            count[i]=0;
        } 
        for(i=0;i<n;i++){
            count[a[i]]++;
        }
        for(i=0;i<n;i++){
            cout<<count[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<n;i++){
            if(count[i]>n/2)
            break;
        }
            if(i==n)
            cout<<"no majority element in the array";
            else
            cout<<"majority element is "<<i;

            cout<<endl;
            t--;
    }
  return 0;
}