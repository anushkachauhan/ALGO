#include<iostream>
#include<string>

using namespace std;

void coins( int arr[], int sum, int size, string asf){
 
if(sum == 0){
        cout<<asf<<endl;
        return;
}

   for(int i =0; i<size; i++ ){
       if(sum < 0){
           return;
       }
       else{
          coins(arr, sum - arr[i], size, asf+ to_string(arr[i]));
       }
      
   } 
}

int main(int argc, char** argv){
     int arr[] = {2,3,5};

    int size = sizeof(arr) / sizeof(int);

    coins(arr, 7, size, "");

}