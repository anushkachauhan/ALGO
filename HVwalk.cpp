#include<bits/stdc++.h>

using namespace std;


int walk(int r, int c)
{
    
    vector<vector<int>>ans(r+1, vector<int>(c+1,0));

    // storage is assigned with the 0 value in every cell

    for(int i=r; i>=0; i--)
    {
        for(int j=c; j>=0; j--)
        {
            if(i==r &&j==c)
            {
               ans[i][j] =1;
                  
            }
            else if(i==r)
            {
                 ans[i][j] = ans[i][j+1];
               
            }
            else if(j == c)
            {
                 ans[i][j] = ans[i+1][j];
            }
            else
            {
                ans[i][j] = ans[i][j+1] + ans[i+1][j];
            }
            
        }
    }
    return ans[0][0];

}

int walk2(int r, int c)
{
    // vector<int>ans(r+1, vector<int>(c+1,0));
    // finding the number of paths 
    vector<vector<int>>ans(r+1, vector<int>(c+1,0));

    // storage is assigned with the 0 value in every cell

    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=c; j++)
        {
            if(i==0 &&j==0)
            {
               ans[i][j] =1;
            }
            else if(i==0)
            {
                 ans[i][j] = ans[i][j-1];
               
            }
            else if(j == 0)
            {
                 ans[i][j] = ans[i-1][j];
            }
            else
            {
                ans[i][j] = ans[i][j-1] + ans[i-1][j];
            }
            
        }
    }

    return ans[r][c];

}

void print_paths(int cr, int cc, int er, int ec, vector<vector<int>>& ans, string psf)
{
    if(cc == ec  && cr == er){
        cout<<psf<<endl;
    }
    else if(cr == er){
        //move horizontally
        print_paths(cr, cc+1, er, ec, ans, psf+"H");
    }
    else if(cc == ec){
        print_paths(cr+1, cc, er, ec, ans, psf+"V");
        
    }
    else
    {
        // move both "H"  and "V"
        if(ans[cr+1][cc] < ans[cr][cc+1]){
            print_paths(cr+1, cc, er, ec, ans , psf+"V");     
        }
        else if(ans[cr][cc+1] < ans[cr+1][cc])
        {   print_paths(cr, cc+1, er, ec, ans, psf+"H");
        }
        else
        {
            print_paths(cr+1, cc, er, ec, ans, psf+"V");
            print_paths(cr, cc+1, er, ec, ans, psf+"H");
            
        }
        

    }
    
}

void cheap_walk( vector<vector<int>> &mat)
{

    // find the cheapest walk from sec to dest

    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>>ans(r, vector<int>(c,0));
    // storage is assigned with the 0 value in every cell

    for(int i=r-1; i>=0; i--)
    {
        for(int j=c-1; j>=0; j--)
        {
            if(i==r-1 && j==c-1 )
            {
               ans[i][j] = mat[i][j];
                  
            }
            else if(i==r-1)
            {   // move vertically 
                 ans[i][j] = mat[i][j] + ans[i][j+1];
               
            }
            else if(j == c-1)
            {
                 ans[i][j] = mat[i][j] + ans[i+1][j];
            }
            else
            {
                // if(ans[i][j+1] > ans[i+1][j])
                //    {ans[i][j] = mat[i][j] + ans[i+1][j];}
                //    else
                //    {
                //        /* code */
                //      ans[i][j] = mat[i][j] + ans[i][j+1];

                //    }

                   ans[i][j] = min(ans[i+1][j], ans[i][j+1]) +mat[i][j];
                   
            }
            
        }
    }
    cout<< ans[0][0]<<endl;


    print_paths(0, 0, mat.size()-1, mat[0].size()-1, ans, " ");

}

int main(int argc, char** argv){
  
    
    vector<vector<int>> mat{
        {2,1,3,0,4,3},
        {1,0,1,2,7,1},
        {0,1,0,4,1,9},
        {1,2,1,1,4,2},
        {7,0,3,9,5,8}
        } ;

        // int cc =3;
        // int cr = 2;
        // int er = 5;
        // int ec = 5;
     
    // cout<< walk(2,3)<<endl;
    // cout<<walk2(2,3) <<endl;
    cheap_walk(mat);
    return 0;
}

