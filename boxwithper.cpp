#include<iostream> 
#include<string>
#include<vector>

using namespace std;

void queen(bool box[4], int cb, int cq, int tq, string asf){ // 4 is box size
    
    if(cb == 4 ){
       
        if(cq == tq){

            cout<<asf<<endl;
        }
       
        return;
    }
      
      queen(box,cb+1,cq,tq,asf);
      if(box[cb] == false){
          box[cb] = true;
          queen (box,cb+1, cq+1, tq, asf+ " q"+ to_string(cq) + " b" + to_string(cb) );
          box[cb]=false;
      }
      
     
}

int main(int argc, char** argv){
    bool box[4] = {false, false, false, false};
    string asf = " ";
    queen(box, 0 , 0, 2, asf);  
    /*
    box is a bool array of size 4
    cb - thr currrent box
    cq - current queen
    tq - total queen
    asf - answer so far
    */
}