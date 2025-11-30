// #include<stdio.h>
// #include<windows.h>
// #include<stdlib.h>
// #include<time.h>


// void swap(int* arr, int i, int j);
// void printArray(int arr[], int size);

// int getRandom(int min, int max);
// int* GenArr(int size);

// //Quick Sort
// int pivot(int *arr, int left, int right);
// void quickSort(int *arr, int left, int right);


// //MergeSort
// void mergeSort(int arr[], int i, int j);
// void merge(int arr[], int i, int mid, int j);


// //HeapSort
// void HeapSort(int Arr[], int n);
// void buildHeap(int Arr[], int n);
// void Heapify(int Arr[], int n, int i);



// int main(){
//     LARGE_INTEGER freq, start, end;
//     QueryPerformanceFrequency(&freq);
//     srand(time(0));
    

//     int Sizes[] = {100, 1000, 10000, 100000, 1000000};
//     int n = sizeof(Sizes)/sizeof(Sizes[0]);

//     printf("quick sort: \n");
//     printf("Input size \t   time taken\n");
//     printf("-----------------------------------\n");
//     for(int i=0; i<n; i++){
//         int size = Sizes[i];
//         int *Arr = GenArr(size);

//         QueryPerformanceCounter(&start);
//         quickSort(Arr, 0, size - 1);
//         QueryPerformanceCounter(&end);

//         double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
//         printf("%-18d  %-5.2lf ns\n", size, time_taken);

//         free(Arr);
//     }

//     printf("------------------------------------------------------------------------------\n");
//     printf("merge sort: \n");
//     printf("Input size \t   time taken\n");
//     printf("-----------------------------------\n");

//     for(int i=0; i<n; i++){
//         int size = Sizes[i];
//         int *Arr = GenArr(size);


//         QueryPerformanceCounter(&start);
//         mergeSort(Arr, 0, size-1);
//         QueryPerformanceCounter(&end);

//         double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
//         printf("%-18d  %-5.2lf ns\n", size, time_taken);

//         free(Arr);
//     }
    
    
//     printf("------------------------------------------------------------------------------\n");
//     printf("Heap sort: \n");
//     printf("Input size \t   time taken\n");
//     printf("-----------------------------------\n");

//     for(int i=0; i<n; i++){
//         int size = Sizes[i];
//         int *Arr = GenArr(size);


//         QueryPerformanceCounter(&start);
//         HeapSort(Arr, size);
//         QueryPerformanceCounter(&end);

//         double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
//         printf("%-18d  %-5.2lf ns\n", size, time_taken);

//         free(Arr);
//     }
// }



// /*************************************************************************/
// /*                              Quick Sort                               */
// /*************************************************************************/
// int pivot(int *arr, int left, int right){
//     int pivotIndex = left;
//     int swapIndex = pivotIndex;

//     for(int i = pivotIndex + 1; i<= right ; i++){
//         if(arr[i] < arr[pivotIndex]){
//             swapIndex++;
//             swap(arr, swapIndex , i);
//         }
//     }

//     swap(arr, swapIndex, pivotIndex);
//     return swapIndex;
// }

// void quickSort(int *arr, int left, int right){
//     if(left < right){
//         int index = pivot(arr, left, right);
//         quickSort(arr, left, index-1);
//         quickSort(arr,index+1, right);
//     }
// }



// /*************************************************************************/
// /*                              Merge Sort                               */
// /*************************************************************************/
// void merge(int arr[], int i, int mid, int j){
//     int mergedArray[j-i+1];
//     int Index=0;
//     int x = i, y = mid+1;

//     while(x <= mid && y <= j){
//         if(arr[x] <= arr[y]){
//             mergedArray[Index] = arr[x];
//             x++;
//         } else{
//             mergedArray[Index] = arr[y];
//             y++; 
//         }
//         Index++;
//     }

//     while(x<=mid){
//         mergedArray[Index] = arr[x];
//         Index++;
//         x++;
//     }

//     while(y<=j){
//         mergedArray[Index] = arr[y];
//         Index++;
//         y++; 
//     }

//     for (int k = 0; k < Index; k++) {
//         arr[i + k] = mergedArray[k];
//     }
 
// }


// void mergeSort(int arr[], int i, int j){
//     if(i>=j) return;

//     int mid = i + (j-i)/2;

//     mergeSort(arr, i, mid);
//     mergeSort(arr, mid+1, j);
//     merge(arr, i, mid, j);
// }



// /*************************************************************************/
// /*                        Heap Sort (using Max Heap)                     */
// /*************************************************************************/

// void Heapify(int Arr[], int n, int i){
//     int l,r,max;

//     l = 2*i+1;
//     r = 2*i+2;
//     max = i;
//     if(l<n && Arr[l] > Arr[max]){
//         max = l;
//     }
//     if(r<n && Arr[r] > Arr[max]){
//         max = r;
//     }
//     if( max != i){
//         swap(Arr, i, max);
//         Heapify(Arr, n, max);
//     }
// }

// void buildHeap(int Arr[], int n){
//     for(int i = n/2; i >= 0; i--){
//         Heapify(Arr, n, i);
//     }
// }

// void HeapSort(int Arr[], int n){
//     buildHeap(Arr, n);
//     for(int i = n-1; i>=0; i--){
//         swap(Arr, 0, i);
//         Heapify(Arr, i, 0);
//     }
// }



// /*************************************************************************/
// /*                             Helper Functions                          */
// /*************************************************************************/

// void swap(int* arr, int i, int j) {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int getRandom(int min, int max){
//     return min + rand()%(max-min);
// }

// int* GenArr(int size){
//     int min = 1, max = 999;
//     int* Arr = (int*)malloc(sizeof(int) * size);
//     for (int i = 0; i < size; i++) {
//         Arr[i] = getRandom(min, max); 
//     }
//     return Arr;
// }


#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void swap(int* arr, int i, int j);
void printArray(int arr[], int size);
int getRandom(int min, int max);
int* GenArr(int size);
//Quick Sort
int pivot(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
//MergeSort
void mergeSort(int arr[], int i, int j);
void merge(int arr[], int i, int mid, int j);
int main(){
    // LARGE_INTEGER freq, start, end;
    // QueryPerformanceFrequency(&freq);
    // srand(time(0));
    // int Sizes[] = {100, 1000, 10000, 100000, 1000000};
    // int n = sizeof(Sizes)/sizeof(Sizes[0]);
    // printf("quick sort: \n Input size \t   time taken\n");
    // printf("-----------------------------------\n");
    // for(int i=0; i<n; i++){
    //     int size = Sizes[i];
    //     int *Arr = GenArr(size);
    //     QueryPerformanceCounter(&start);
    //     quickSort(Arr, 0, size - 1);
    //     QueryPerformanceCounter(&end);
    //     double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
    //     printf("%-18d  %-5.2lf ns\n", size, time_taken);
    //     free(Arr);
    // }
    // printf("------------------------------------------------------------------------------\n");
    // printf("merge sort: \n Input size \t   time taken\n");
    // printf("-----------------------------------\n");
    // for(int i=0; i<n; i++){
    //     int size = Sizes[i];
    //     int *Arr = GenArr(size);
    //     QueryPerformanceCounter(&start);
    //     mergeSort(Arr, 0, size-1);
    //     QueryPerformanceCounter(&end);
    //     double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
    //     printf("%-18d  %-5.2lf ns\n", size, time_taken);
    //     free(Arr);
    // }
    int Arr[] = {12, 3, 5, 7, 4, 19, 26};
    for(int i =0;i<7;i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
    mergeSort(Arr, 0, 6);

    for(int i =0;i<7;i++){
        printf("%d ", Arr[i]);
    }

}
/*************************************************************************/
/*                              Quick Sort                               */
/*************************************************************************/
int pivot(int *arr, int left, int right){
    int pivotIndex = left;
    int swapIndex = pivotIndex;
    for(int i = pivotIndex + 1; i<= right ; i++){
        if(arr[i] < arr[pivotIndex]){
            swapIndex++;
            swap(arr, swapIndex , i);
        }
    }
    swap(arr, swapIndex, pivotIndex);
    return swapIndex;
}
 
void quickSort(int *arr, int left, int right){
    if(left < right){
        int index = pivot(arr, left, right);
        quickSort(arr, left, index-1);
        quickSort(arr,index+1, right);
    }
}
/*************************************************************************/
/*                              Merge Sort                               */
/*************************************************************************/
void merge(int arr[], int i, int mid, int j){
    int mergedArray[j-i+1];
    int Index=0, x = i, y = mid+1;
    while(x <= mid && y <= j){
        if(arr[x] <= arr[y])
            mergedArray[Index++] = arr[x++];
        else
            mergedArray[Index++] = arr[y++];
    }
    while(x<=mid){ mergedArray[Index++] = arr[x++];}
    while(y<=j){ mergedArray[Index++] = arr[y++];}

    for (int k = 0; k < Index; k++) arr[i + k] = mergedArray[k];
}
void mergeSort(int arr[], int i, int j){
    if(i>=j) return;
    int mid = i + (j-i)/2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
    merge(arr, i, mid, j);
}
/*************************************************************************/
/*                             Helper Functions                          */
/*************************************************************************/
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int getRandom(int min, int max){ return min + rand()%(max-min);}
int* GenArr(int size){
    int min = 1, max = 999;
    int* Arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        Arr[i] = getRandom(min, max); 
    return Arr;
}
 
