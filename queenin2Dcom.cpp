#include<iostream>
#include<string>
using namespace std;

int count=0;

void queen(bool q[4][4], int cq, int tq, int sp){
    
    if(cq == tq){
        count+=1;
        return;
    }
    for(int i=sp; i<15; i++){
       int row =  i/4;
       int col = i%4;
        
        if(q[row][col] == false){
              
            q[row][col] = true;
            queen(q, cq+1, tq, i);
            q[row][col] = false;
            }
           
       
    }
}

int main(int argc, char** argv){
  
  bool q[4][4] = {
      {false, false, false, false},
      {false, false, false, false},
      {false, false, false, false},
      {false, false, false, false}
  };
  queen(q, 0, 4,-1);
  cout<<"count : "<<count;
}