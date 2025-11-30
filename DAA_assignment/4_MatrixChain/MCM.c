#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<windows.h>

#define MIN(a,b)((a)<(b)? (a):(b))
int name = 65; //ascii of A

int MatrixChainOrder_recursive(int *matrices, int i, int j, int **s);
int MatrixChainOrder_DP(int *matrices, int i, int j, int **dp, int **s);
int MatrixChainOrder_iterative(int *matrices, int size, int **s);
void printOptimalParens(int **s, int i, int j);
void printArray(int **arr, int m, int n);


int main(){
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    int x;
    double time_taken;


    //20 matrices
    // int Matrices[21] = {12, 20, 35, 55, 65, 70, 68, 75, 40, 38, 42, 50, 18, 24, 30, 28, 48, 56, 60, 80, 82};
    int Matrices[] = {30,35,15,5,10,20,25};
    int n = sizeof(Matrices) / sizeof(Matrices[0]);

    int **dp = (int **)calloc(n, sizeof(int *));
    int **s = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        s[i] = (int *)calloc(n, sizeof(int));
        dp[i] = (int *)calloc(n, sizeof(int));
        for(int j = 0; j<n; j++) dp[i][j] = -1;
        dp[i][i] = 0;
    }


    /*----------------------------------MatrixChainOrder_recursive----------------------------------*/

    QueryPerformanceCounter(&start);
        x =  MatrixChainOrder_recursive(Matrices, 1, n-1, s);
    QueryPerformanceCounter(&end);

    time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;
    
    printf("\nMinimum number of multiplications using recursion: %d\n", x);
    printf("optimal Parentheses: ");
    name = 65;
    printOptimalParens(s, 1, n-1);
    printf("\ntime taken: %20.2lf ns\n\n", time_taken);

    /*----------------------------------MatrixChainOrder_DP----------------------------------*/

    QueryPerformanceCounter(&start);
        x =  MatrixChainOrder_DP(Matrices, 1, n-1, dp, s);
    QueryPerformanceCounter(&end);
    time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;

    printf("Minimum number of multiplications using DP (recursive): %d\n", x);
    printf("optimal Parentheses: ");
    name = 65;
    printOptimalParens(s, 1, n-1);
    printf("\ntime taken: %20.2lf ns\n\n", time_taken);

    /*----------------------------------MatrixChainOrder_iterative----------------------------------*/
    
    QueryPerformanceCounter(&start);
        x =  MatrixChainOrder_iterative(Matrices, n, s);
    QueryPerformanceCounter(&end);
    time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;

    printf("Minimum number of multiplications using DP (iterative): %d\n", x);
    printf("optimal Parentheses: ");
    name = 65;
    printOptimalParens(s, 1, n-1);
    printf("\ntime taken: %20.2lf ns\n\n", time_taken);


    printArray(dp, n, n);
    printArray(s, n, n);

    return 0;
}


void printArray(int **arr, int m, int n){
    for(int i = 1; i< m; i++){
        for(int j = 1; j< n; j++){
            printf("%10d ", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}



/*************************************************************************/
/*                          recursive method                             */
/*************************************************************************/

int MatrixChainOrder_recursive(int *matrices, int i, int j, int **s){
    if(i < 1 || i>j) return -1;

    if(i == j) return 0;

    int cost = INT_MAX;
    for(int k = i; k<j; k++){
       int Newcost = MatrixChainOrder_recursive(matrices, i, k, s) + MatrixChainOrder_recursive(matrices, k+1, j, s) + matrices[i-1]*matrices[k]*matrices[j];  
       
       if(Newcost < cost){
            cost = Newcost;
            s[i][j] = k;
       }
    }

    return cost;
}



/*************************************************************************/
/*                  recursive method with memorization                   */
/*************************************************************************/

int MatrixChainOrder_DP(int *matrices, int i, int j, int **dp, int **s){
    if(i < 1 || i>j) return -1;

    if(i == j) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int cost = INT_MAX;
    for(int k = i; k<j; k++){
       int Newcost = MatrixChainOrder_DP(matrices, i, k, dp, s) + MatrixChainOrder_DP(matrices, k+1, j, dp, s) + matrices[i-1]*matrices[k]*matrices[j];  
       
       if(Newcost < cost){
            cost = Newcost;
            dp[i][j] = cost;
            s[i][j] = k;
       }
    }

    return cost;
}


/*************************************************************************/
/*                          iterative method                             */
/*************************************************************************/

int MatrixChainOrder_iterative(int *matrices, int size, int **s){

    int dp[size][size];
    
    for(int i = 1; i<size;i++){
        dp[i][i] = 0;
    }
    
    // chain length L2 = A x B, L3 = A x B x C, etc
    for(int L = 2; L<size; L++){ // minimum chain length can be 2: multiplication of 2 matrix
        
        // starting point for combinations
        for(int i = 1; i < size-L+1; i++){
            int j = i+L-1;  // end index

            // for chain of lenght 3 (L3)
            // i = 1, j = 3: A x B x C
            // i = 2, j = 4: B x C x D
            // i = 3, j = 5: C x D x E

            
            // for break points
            // for chain of lenght 3 (L3)
            // i = 1, j = 3: A x B x C
            //     k = 1: (A)(BC)
            //     k = 2: (AB)(C)
            // i = 2, j = 4: B x C x D
            //     k = 2: (B)(CD)
            //     k = 3: (BC)(D)
            
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                // printf("[%d %d] = %d + %d + %d x %d x %d = %d \n\b",i ,j , dp[i][k], dp[k+1][j],  matrices[i-1], matrices[k], matrices[j], dp[i][k] + dp[k+1][j] + matrices[i-1] * matrices[k] * matrices[j]);
                int cost = dp[i][k] + dp[k+1][j] + matrices[i-1] * matrices[k] * matrices[j];
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[1][size-1];
}



/*************************************************************************/
/*                    printing Optimal Parentheses                       */
/*************************************************************************/

void printOptimalParens(int **s, int i, int j){
    if (i==j) {
        printf("%c", (char) name); 
        name++;
    }
    else{
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        printf(")");
    }
}
