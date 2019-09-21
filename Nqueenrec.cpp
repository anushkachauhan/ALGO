#include<bits/stdc++.h> // reactive code s
#include<vector>

using namespace std;

int N = 4; // size of board
bool isqueensafe(int r, int c, vector<vector<bool>>& board){
    
    //north 
    for(int i= r-1; i>=0; i-- ){
        if(board[i][c]== true ) // this means our queen is sitting there, so, we can't make our new queen sit in this place
           return false;
    }

    //south
    for(int i =r+1; i<N; i++){
        if(board[i][c] == true){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }

    //east
    for(int j=c+1; j<N; j++){
        if(board[r][j] == true){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }

    //west
    for(int j= c-1; j>=0; j--){
        if(board[r][j]==true){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }

    //north west
    for(int i=r-1, j=c-1; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }
    //north east
    for(int i= r-1, j = c+1; i>=0 && j<N; i--, j++ ){
        if(board[i][j]){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }

    //south west
    for(int i=r+1, j = c-1; i<N && j>=0; i++, j--){
        if(board[i][j]){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }

    //south east
    for(int i=r+1, j = c+1; i<board.size() && j<N; i++, j++){
        if(board[i][j]){  // this means our queen is sitting there, so, we can't make our new queen sit in this place
            return false;
        }
    }


    return true;  // now we've passed all the tests we can make our queen sit in the place passed in the func
}

bool isboardsafe(vector<vector<bool>>& board){
   for(int i =0 ; i< N; i++){
       for(int j=0; j<N; j++){
           if(board[i][j]){
               if(isqueensafe(i,j,board)==false){  //if our queen is not safe then don't print it
                   return false;
               }
           }
       }
   }
   return true;
}

void queen(int cq, int tq, vector<vector<bool>>& board){
  if(cq == tq){
        if(isboardsafe(board)){
            for(int i=0; i<N; i++){  //print karana hai
                for(int j=0; j<N; j++){
                    // board[i][j]= true;
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            } 
        }        
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j] == false){
              
              board[i][j] = true;
              queen(cq+1, tq, board);
              board[i][j] = false;
            }
           
        }
    }
}

int main(int argc, char** argv){
    vector<vector<bool>> board{
        { false,  false,  false,  false},
        { false,  false,  false,  false},
        { false,  false,  false,  false},
        { false,  false,  false,  false}
    };
    
    queen(0, 4, board);
}