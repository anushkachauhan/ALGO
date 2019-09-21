#include<iostream> // check 2 queens in 4 boxes 
#include<string>
#include<vector>

using namespace std;

void queen(bool box[4], int cq, int tq, string asf){
    if(cq == tq){
        cout<<asf<<endl;
        return;
    }

    for(int i =0; i<4; i++){
      
      if(box[i] == false){
          box[i] = true;
          queen (box, cq+1, tq, asf+ "q"+to_string(cq)+" b"+ to_string(i));
          box[i]=false;
          
      }
    } 
}

int main(int argc, char** argv){
    bool box[4] = {false, false, true, false};
    queen(box, 0, 2, " ");
}