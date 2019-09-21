// count longest pallindromic substring 

#include<bits/stdc++.h>

using namespace std;

void clps(string str)
{
    vector<vector<bool>> strg(str.size(), vector<bool>(str.size(),0));
    //// this storage is having the count of palindromes occured

    string path = " ";

    int count =0;
    int length = INT_MIN;

    for(int gap = 0; gap<str.size(); gap++)
    {
        for(int i =0, j= i+gap ; j<str.size() ; i++, j++)
        {
            if(gap == 0)
            {
               strg[i][j] = 1;
            }
            // if exterems are matched
           else  if(gap == 1) 
            {
                if(str[i] == str[j])
                {
                    strg[i][j] = 1;
                }
                // strg[i][j] = str[i] == str[j]; // if extremes are equal then storage will have true
                // //now check if the diagonal is true
                // if(strg[i+1][j-1] == 1)
                // {
                //     strg[i][j] = 1;
                // }
                // else
                // {
                //     strg[i][j] = 0;                    
                // }
            } 
            else if(gap >1 && gap<= str.size()-1)
            {
                if(str[i] == str[j] && strg[i+1][j-1] == 1)
                {
                    strg[i][j] = 1;
                }
                // strg[i][j] = str[i] == str[j] && strg[i+1][j-1] == 1;
            }
              
            if(strg[i][j] == 1)
            {
                count++;
                length= gap+1;
                path = path+str[length];   
            }
          
        }
    } 


      for(int i=0; i< strg.size(); i++)
    {
        for(int j=0; j< strg[0].size(); j++)
        {
            cout<<strg[i][j]<<" ";
        }
        cout<<endl;
    }    

    cout<<"count : "<<count<< " len : "<<length<<endl;
    cout<<"path : "<<path<<endl;

    //   for(int i=; i< strg.size(); i++)
    // {
    //     for(int j=0; j< strg[0].size(); j++)
    //     {
    //         cout<<str[i][j]<<" ";
    //     }
    //     cout<<endl;
    // } 

    
}

int main(int argc, char** argv)
{
    string str = "abccbc";
    cout<<"size : "<<str.size()<<endl;
    clps(str);
}
