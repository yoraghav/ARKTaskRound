
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
const int sizen = 1000;

long long costMatrixA[sizen][sizen];
long long costMatrixB[sizen][sizen];
long long ansMatrixA[sizen+1][sizen+1];
long long ansMatrixB[sizen+1][sizen+1];

long long productMat[sizen][sizen];

//the function where all the values for each i and j in matrix A and B are calculated and saved in the cost matrices
void buildans(){
    int n=sizen;
    for(int i=0;i<n+1;i++){
        ansMatrixA[n][i]=11;
        ansMatrixA[i][n]=11;
        
        ansMatrixB[n][i]=0;
        ansMatrixB[i][n]=0;
    }
    
    ansMatrixA[n-1][n-1]=costMatrixA[n-1][n-1];
    
    ansMatrixB[n-1][n-1]=costMatrixB[n-1][n-1];
    
    int i=n-1,j=n-1;
    while(i!=-1){
        ansMatrixA[i][j]=min(ansMatrixA[i][j+1],ansMatrixA[i+1][j])+costMatrixA[i][j];
        
        
        ansMatrixB[i][j]=max(ansMatrixB[i][j+1],ansMatrixB[i+1][j])+costMatrixB[i][j];
        
        if(j==0){j=n-1;i--;}
        else{j--;}
    }
}


int main()
{
    
    int i, j, k;
    // initialisation
    for (i = 0; i < sizen; i++)
    {
        for (j = 0; j < sizen; j++)
        {
            costMatrixA[i][j] = 1 + rand() % 10;
            costMatrixB[i][j] = 1 + rand() % 10;
            productMat[i][j] = 0;
        }
    }
    
    buildans();
    
    vector<long long int> filterArray;

    for (i = 0; i < 4*sizen; i++)
    {
        filterArray.push_back(rand()%2);
    }
    
    
    
    vector<long long int> smallerB(4*sizen);
    
    
    vector<long long int> finalMat(sizen/4);
    
    
//    now we reduce the nxn B matrix into an 4xn matrix with four columns wrt each row variation in the filter array i.e. weve added each of the row element of the costB array multiplied w the respective filter and added them into one single element of the smallerB array and now since there are 4 variations for each row in filterarray weve created 4 columns with same procedure -
    for (i = 0; i < sizen; i+=4)
    {
        for (k = 0; k < 4; k++){
            int sum=0;
            for (j = 0; j < sizen; j++)
            {
            sum += ansMatrixB[i+k][j]*filterArray[k*sizen+j];
            }
            smallerB[k*sizen+i]=sum;
        }
        
    }
    
    
//to create the final matrix now we multiply each set of 4 rows in A (nxn) with the smaller B(4xn) to get a single element in the final matrix
    
    for (i = 0; i < sizen; i+=4)
    {
        int sum=0;
        for (k = 0; k < 4; k++){
           for (j = 0; j < sizen; j++)
            {
                sum+=ansMatrixA[i+k][j]*smallerB[k*sizen+j];
            }
        }
        finalMat[i/4]=sum;
    }

    return 0;
}

//1622449459
//2809310 --> 54   {sizen = 12}   first level

