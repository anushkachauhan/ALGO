#include<iostream>
using namespace std;
int main()
 {  //ease the array
	//code
	int t;
	cin>>t;
	while(t>0){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i<n; i++){
	        cin>>a[i];
	    }
	    
	    for(int i=0; i<n-1; i++){
	        if(a[i]!=0){
	            if(a[i+1] == a[i]){
	                a[i]= 2*a[i];
	                a[i+1] = 0;
                    
	            }
	        }
	    }
	    int ans[n] ={0};
	    int j=0 ; 
	    for(int i = 0; i<n; i++){
	        if(a[i]!=0){
	            ans[j]=a[i];
	            j++;
	        }
	    }
	    for(int i = 0;i<n;i++){
	        cout<<ans[i]<<" ";
	    }
        t--;
        cout<<endl;
	}
	return 0;
}