#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

typedef struct Bucket{
    float val;
    struct Bucket *next;
} Bucket;

int getRandom(int min, int max);
int* GenArr(int size);

float getMinF(float *Arr, int size);
float getMaxF(float *Arr, int size);
int getMax(int *Arr, int size);

void printArrayF(float *arr, int size);
void printArray(int *arr, int size);


void CountSort(int *Arr, int size);
void R_CountSort(int *Arr, int size, int exp);

void RadixSort(int *Arr, int size);

Bucket *createNode(float val);
void InsertInBucket(Bucket** head, float val);
void BucketSort(float *Arr, int size);




/*************************************************************************/
/*                              Main Sort                                */
/*************************************************************************/

int main(){
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    srand(time(0));
    

    int Sizes[] = {100, 1000, 10000, 100000, 1000000};
    int n = sizeof(Sizes)/sizeof(Sizes[0]);



    // printf("Counting Sort: \n");
    // printf("Input size \t   time taken\n");
    // printf("-----------------------------------\n");
    // for(int i=0; i<n; i++){
    //     int size = Sizes[i];
    //     int *Arr = GenArr(size);

    //     QueryPerformanceCounter(&start);
    //     CountSort(Arr, size);
    //     QueryPerformanceCounter(&end);

    //     double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
    //     printf("%-18d  %-5.2lf ns\n", size, time_taken);

    //     free(Arr);
    // }
    int Arr[] = {1,8,7,2,4,1};
    CountSort(Arr, 6);


    // printf("------------------------------------------------------------------------------\n");
    // printf("Radix Sort: \n");
    // printf("Input size \t   time taken\n");
    // printf("-----------------------------------\n");

    // for(int i=0; i<n; i++){
    //     int size = Sizes[i];
    //     int *Arr = GenArr(size);


    //     QueryPerformanceCounter(&start);
    //     RadixSort(Arr,size);
    //     QueryPerformanceCounter(&end);

    //     double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
    //     printf("%-18d  %-5.2lf ns\n", size, time_taken);

    //     free(Arr);
    // }
    
    
    // printf("------------------------------------------------------------------------------\n");
    // printf("Bucket Sort: \n");
    // printf("Input size \t   time taken\n");
    // printf("-----------------------------------\n");

    // for(int i=0; i<n; i++){
    //     int size = Sizes[i];
    //     float min = 1.0f, max = 999.0f;
    //     float* Arr = (float*)malloc(sizeof(float) * size);
    //     for (int i = 0; i < size; i++){
    //         Arr[i] = min + (float)rand() * (max - min);
    //     }


    //     QueryPerformanceCounter(&start);
    //     BucketSort(Arr, size);
    //     QueryPerformanceCounter(&end);

    //     double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
    //     printf("%-18d  %-5.2lf ns\n", size, time_taken);

    //     free(Arr);
    // }
}



/*************************************************************************/
/*                             Counting Sort                             */
/*************************************************************************/

void CountSort(int *Arr, int size){
    int max = getMax(Arr, size);

    int *count = (int*)calloc(max + 1, sizeof(int));
    if(count == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    
    for(int i=0; i < size; i++){
        count[Arr[i]]++;
    }

    printArray(count, max+1);
    
    
    for(int i=1; i <= max; i++){
        count[i] += count[i-1];
    }
    printArray(count, max+1);

    int *output = (int*)calloc(size, sizeof(int));
    if(output == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    for(int i = size-1; i >= 0; i--){
        output[--count[Arr[i]]] = Arr[i];
    }

    for(int i = 0; i < size; i++){
        Arr[i] = output[i];
    }

    free(count);
    free(output);
    
}



/*************************************************************************/
/*                              Redix Sort                               */
/*************************************************************************/

void R_CountSort(int *Arr, int size, int exp){
    int count[10];
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    
    for(int i=0; i < size; i++){
        count[((Arr[i] / exp) % 10 )]++;
    }
     
    for(int i=1; i < 10; i++){
        count[i] += count[i-1];
    }

    int *output = (int*)calloc(size, sizeof(int));
    if(output == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    for(int i = size-1; i >= 0; i--){
        output[--count[((Arr[i] / exp) % 10 )]] = Arr[i];
    }

    for(int i = 0; i < size; i++){
        Arr[i] = output[i];
    }

    free(output);
}

void RadixSort(int *Arr, int size){
    int max = getMax(Arr, size);
    for(int exp = 1; max / exp > 0; exp*=10){
        R_CountSort(Arr, size, exp);
    }

}



/*************************************************************************/
/*                              Bucket Sort                               */
/*************************************************************************/

Bucket *createNode(float val){
    Bucket *node = (Bucket*)malloc(sizeof(Bucket));
    node->val = val;
    node->next = NULL;

    return node;
}

void InsertInBucket(Bucket** head, float val){
    Bucket *node = createNode(val);

    if((*head) == NULL || (*head)->val >= val){
        node->next = *head;
        *head = node;
        return;
    }

    Bucket *cur = *head;
    while(cur->next != NULL && cur->next->val < val){
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;
 
}


void BucketSort(float *Arr, int size){
    Bucket **buckets = (Bucket**)calloc(size, sizeof(Bucket*));

    float min = getMinF(Arr, size);
    float max = getMaxF(Arr, size);

    for(int i=0; i<size; i++){
        int index = (int)((Arr[i] - min) / (max - min) * (size - 1));
        InsertInBucket(&buckets[index], Arr[i]);
    } 
    
    int j = 0;
    for(int i=0; i<size; i++){
        Bucket *temp = buckets[i];
        while(temp != NULL && j < size){
            Arr[j++] = temp->val; 
            Bucket *node = temp;
            temp = temp->next;
            free(node);
        }
    }

    free(buckets);
}



/*************************************************************************/
/*                         Helper Functions                              */
/*************************************************************************/

int getRandom(int min, int max){
    return min + rand()%(max-min);
}

int* GenArr(int size){
    int min = 1, max = 999;
    int* Arr = (int*)malloc(sizeof(int) * size);
    if(Arr == NULL){
        printf("Memory Allocation Error\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        Arr[i] = getRandom(min, max); 
    }

    return Arr;
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getMax(int *Arr, int size){
    int max = Arr[0]; 
    for(int i= 1; i < size; i++){
        if(max < Arr[i]) max = Arr[i];
    }

    return max;
}

float getMaxF(float *Arr, int size){
    float max = Arr[0];
    for(int i=0; i<size; i++){
        if(max < Arr[i]) max = Arr[i];
    }
    return max;
}

float getMinF(float *Arr, int size){
    float min = Arr[0];
    for(int i=0; i<size; i++){
        if(min > Arr[i]) min = Arr[i];
    }
    return min;
}

void printArrayF(float *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}
