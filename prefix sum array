#include <bits/stdc++.h>
#include <pthread.h>
#include <chrono>

#define N 4   // I HAVE USED FOUR THREADS 
#define num 4096   // THIS VARIABLE DECIDES ARRAY SIZE
using namespace std;
using namespace std::chrono;

// ------------------------------------------GLOBAL VARIABLES--------------------------------------------------------------
int k=0;              //VARIABLE FOR CALCULATION OF PARTICULAR PRORTION FOR EACH THREAD
                                                        // 
int v[num];             // INPUT ARRAY
int psum[num+1];        // PREFIX SUM ARRAY

// ---------------------------------------HELPING FUNCTION------------------------------------------------------------------------------------


void* fun(void *arg)    // THIS FUNCTION PREOCESSES FOR EACH THREAD
{
    long long x=k;
    // psum[x]=v[x];
    // cout<<x<<endl;
    for (int i=x*num/N+1;i<=(x+1)*num/N;i++)
    {
        
        psum[i]=psum[i-1]+v[i-1];
        // cout<<psum[i]<<" "<<psum[i-1]<<" "<<x<<endl;
    }
    k++;
    return nullptr;// AS THIS FUNCTION IS OF VOID POINTER TYPE 
}

// -------------------------------------------MAIN--------------------------------------------------------------------------------------------


int main()
{
    // ----------------------------------------INITIALISATION----------------------------------------------------------------------------------

    
    for (int i=0;i<num;i++)
    {
        v[i]=i;
    }
    
    
    //----------------------------------------SEQUENTIAL PROGRAM------------------------------------

    
    auto start=high_resolution_clock::now();
    
    psum[0]=0;
    for (int i=1;i<=num;i++)
    {
        psum[i]=psum[i-1]+v[i-1];
    }
    long long ans=0;
    for (int i=1;i<=num;i++)
    {
        // cout<<psum[i]<<" ";
        ans+=psum[i];
    }
    cout<<ans<<endl;
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    

    // ----------------------------------------USING PTHREAD-----------------------------------------------


    start=high_resolution_clock::now();
    pthread_t thread[N];
    // cout<<"a"<<endl;
    
    for (int i=0;i<N;i++)
    {
        pthread_create(&thread[i],NULL,fun,NULL);   //  HERE WE CREATE THREADS WITH NO ARGUMENT AND fun FUNCTION WILL TAKE CHARGE FOR COMPUTATIONS
    }
    for (int i=0;i<N;i++)
    {
        pthread_join(thread[i],NULL);               //THIS WILL WAIT UNTIL THE THREAD IS COMPLETED AND SINCE WE ARE NOT RETURNING ANYTHING SO WE HAVE GIVEN NULL HERE
    }
    ans=0;
    for (int i=1;i<=num;i++)
    {
        // cout<<psum[i]<<" ";
        ans+=psum[i];
    }
    cout<<ans<<endl;
    
    // for (int i=num/4;i<num;i++)
    // {
    //     int x=i-(i%(num/4))-1;
    //     psum[i]+=x;
    // }
    
    
    // cout<<"a"<<endl;
    stop=high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    
}
