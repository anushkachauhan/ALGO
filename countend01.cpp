#include<bits/stdc++.h>

using namespace std;

void count01(int len)
{
    vector<vector<int>>count(2, vector<int>(len+1,0) );
    // row will show the zeros and colm will show the count

    for(int j=0; j<=len; j++)
    {
        for(int  i=0; i<2; i++)
        {
            if( j == 0 )
            {
                count[i][j] = 0;
            }
            else if( j == 1)
            {
                count[i][j] = 1;
            }
            else if(i == 0)
            {
                count[i][j] = count[i+1][j-1];   
            }
            else
            {
                count[i][j] = count[i][j-1] + count[i-1][j-1];                   
            }
            
        }
    }
   for(int i=0; i<2; i++)
    {
        for(int j=0; j<=len; j++)
        {
            cout<<count[i][j]<<" ";
        }
        cout<<endl;
    }    


}

int main(int argc, char** argv )
{
    int len = 4;
    // length of the string 
    count01(len);
}