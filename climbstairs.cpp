#include<bits/stdc++.h>
#include<iostream>
#include<chrono>
using namespace std;

int climb_stairs(int num, vector<int>& qb)
{

    if(num == 0){            /// on 0 it will return the space (ground floor area)  you're alrady at soln
        return 1; 
   }
    if(num< 0){          // basement--> there is no way to climb out   
       return 0 ; 
   }
    if(qb[num] != 0)
   {
       return qb[num];
   }
   
   int pfnm1 = climb_stairs(num -1, qb); // number after moving 1
   int pfnm2 = climb_stairs(num -2, qb); // number after moving 2
   int pfnm3 = climb_stairs(num -3, qb);  // number after moving 3 in path
   int mr = pfnm1+pfnm2+pfnm3;

   qb[num] = mr;
   cout<<num<<" - "<<mr<<endl;
   return mr;
}

int climb_stairs_tabulation(int num)
{

    vector<int> qb(num+1, 0);
    
//     if(num< 0){          // basement--> there is no way to climb out
       
//        qb[num] =0 ; 
//    }
   qb[0] = 1;
   qb[1] = 1;
   qb[2] = 2;


    for(int i=3; i<num ;i++){
         qb[i] = qb[i -1] + qb[i-2] + qb[i-3];
         cout<<i<<" -- "<< qb[i]<<endl;

        //  qb[i]+ = qb[i-1];
        //  qb[i] = i>=2 ? qb[]

    }

//    qb[num] = mr;
//    cout<<num<<" - "<<mr<<endl;
//    return mr;  
     return qb[num];
}

int main(int argc, char** argv)
{
    int stairs = 7;

    vector<int> qb(stairs+1, 0);
    cout<<climb_stairs(stairs, qb);

    // cout<<climb_stairs_tabulation(stairs);


}