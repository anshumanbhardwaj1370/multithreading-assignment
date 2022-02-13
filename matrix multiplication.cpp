/**************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <bits/stdc++.h>
#include <pthread.h>
#include <chrono>

#define N 4         // I HAVE USED FOUR THREADS 
#define num 1024    // THIS VARIABLE DECIDES MATRIX SIZE
using namespace std;
using namespace std::chrono;
// ---------------------------------------GLOBAL VARIABLES-----------------------------------------------------------------------------------


vector<vector<int>> a(num,vector<int>(num)),b(num,vector<int>(num));            //INPUT MATRICES 
vector<vector<int>> res(num,vector<int>(num));                                  //OUTPUT MATRIX

int c=0;             //VARIABLE FOR CALCULATION OF PARTICULAR PRORTION FOR EACH THREAD                                                           


// ---------------------------------------HELPING FUNCTION------------------------------------------------------------------------------------

void* fun(void *arg)            // THIS FUNCTION PREOCESSES FOR EACH THREAD
{
    long long x=c++;
    // cout<<x<<endl;
    
    for (int i=x*num/4;i<(x+1)*num/4;i++)
    {
        for (int j=0;j<num;j++)
        {
            res[i][j]=0;
            for (int k=0;k<num;k++)
            res[i][j]+=a[i][k]*b[k][j];
        }
        // cout<<i<<endl;
        
    }
    
    return nullptr;             // AS THIS FUNCTION IS OF VOID POINTER TYPE
}

// -------------------------------------------MAIN--------------------------------------------------------------------------------------------



int main()
{
    // ---------------------------------------INITIALISATION-------------------------------------------------------------------
    
    for (int  i=0;i<num;i++)
    {
        for (int j=0;j<num;j++)
        {
            a[i][j]=i;
            b[i][j]=j;
        }
    }
    
    
    
    
    //----------------------------------------SEQUENTIAL PROGRAM------------------------------------
    
    
    auto start=high_resolution_clock::now();
    
    for (int  i=0;i<num;i++)
    {
        for (int j=0;j<num;j++)
        {
            res[i][j]=0;
            for (int k=0;k<num;k++)
            res[i][j]+=a[i][k]*b[k][j];
        }
    }
    // for (int  i=0;i<num;i++)
    // {
    //     for (int j=0;j<num;j++)
    //     {
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    
    
    // ----------------------------------------USING PTHREAD-----------------------------------------------
    
    start=high_resolution_clock::now();
    pthread_t thread[N];
    // cout<<"a"<<endl;
    
    for (int i=0;i<N;i++)
    {
        pthread_create(&thread[i],NULL,fun,NULL);//  HERE WE CREATE THREADS WITH NO ARGUMENT AND fun FUNCTION WILL TAKE CHARGE FOR COMPUTATIONS
    }
    
    // for (int  i=0;i<num;i++)
    // {
    //     for (int j=0;j<num;j++)
    //     {
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for (int i=0;i<N;i++)
    {
        pthread_join(thread[i],NULL);            //THIS WILL WAIT UNTIL THE THREAD IS COMPLETED AND SINCE WE ARE NOT RETURNING ANYTHING SO WE HAVE GIVEN NULL HERE
    }
    
    
    
    stop=high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds> (stop-start);
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    
}
