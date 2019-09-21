#include<iostream>
#include<string>

using namespace std;

void coins( int arr[] , int sum, int size, string asf, int sp){
 


  if(sum == 0){
        cout<<asf<<endl;
         return;
    }        
   if(sum<0){
       return;
   }

     for(int i =sp; i< size; i++){
       
          coins(arr, sum - arr[i], size, asf+ to_string(arr[i]), i);

     }
              

}

int main(int argc, char** argv){
     int arr[] = {2,3,5};

    int size = sizeof(arr) / sizeof(int);

    coins(arr, 9, size, "", 0);

}