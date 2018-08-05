#include <iostream>
using namespace std;

int countways(int n, int m)
{
    int count[n+1];
    count[0] = 0;

     for(int i =1; i<=n; i++){
     	if(i>m) // in case our no. of columns are greater then no. of rows (eg. 6X4)
     	{
           count[i] = count[i-1] + count[n-i];
     	}
     	else
     		 if(i<m){ // if no. of columns  are less then no. of rows
     		 	count[i]=1;
     		 }
     		 else
     		 	if(i == m){ // if no. of columns are equal to no. of rows
     		 		count[i] = 2;
     		 	}
     }
      for(int i=0 ; i<n; i++){
          count[i] += count[i];
      }
      return count[n];
}

int main()
{
   int n;// no. of rows
   int m;// no. of columns
   cin>>n;
   cin>>m;
   cout<<"no. of ways to arrange the tiles are : "<<countways(m,n);
   return 0;
}
