#include<iostream>
#include<string>
using namespace std;

int count=0;

void queen(bool q[4][4], int cq, int tq){
    
    if(cq == tq){
        count+=1;
        return;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(q[i][j] == false){
              
            q[i][j] = true;
            queen(q, cq+1, tq);
            q[i][j] = false;
            }
           
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
  queen(q, 0, 4);
  cout<<"count : "<<count;
}