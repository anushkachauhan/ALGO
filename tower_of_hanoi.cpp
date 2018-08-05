#include <iostream>
using namespace std;
int count = 0; // no. of moves taken to solve
void towerofhanoi(int n, int src, int dest, int helper){

    //base case when no disk is present
    if(n == 0)
       return;
    
     // first step is to move n-1 disks to the helper
     towerofhanoi(n-1, src, helper, dest);
     count++;
     cout<<"Move "<<n<<"th disk from T"<<src<<" to T"<<dest<<endl;
     // moving the disks from helper to destination now
     towerofhanoi(n-1, helper , dest, src);  
   

}

int main(){
  int n; // no. of disks
  cin>> n;
  towerofhanoi(n,1,2,3);
  cout<<count<<endl;
  return 0;
}
