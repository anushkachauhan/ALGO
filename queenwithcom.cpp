#include<iostream> // check 2 queens in 4 boxes but we need to find only the combinations whcih are not redundant 
#include<string>   // eg : (0,3)<->(3,0) etc
#include<vector>

using namespace std;

void queen(bool box[4], int sp, int cq, int tq, string asf){
    if(cq == tq){
        cout<<asf<<endl;
        return;
    }

    for(int i =sp+1; i<4; i++){
      
      if(box[i] == false){
          box[i] = true;
          queen (box, i,cq+1, tq, asf+ " q"+to_string(cq)+" b"+ to_string(i));
          box[i]=false;
          
      }
    } 
}

int main(int argc, char** argv){
    bool box[4] = {false, false, false, false};
    queen(box,-1,0, 2, " ");
}