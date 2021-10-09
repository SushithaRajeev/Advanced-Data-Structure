#include "assign3SHJ986.h"


int main() {
   cout << "*** Please read README file before executing the program***" << endl;

   int n, k;
   cout << "Enter the number of elements n: ";
   cin >> n;
   cout << "Enter the value of K:";
   cin >> k;
   int arr[n];    //create an array with given number of elements
   int i, temp, random;
   //int m = sizeof(arr) / sizeof(arr[0]);
   //cout << "Enter elements:";

   for (i = 0; i < n; i++) {
      arr[i] = i;
   }

   for (i = 0; i < n; i++){
      temp = arr[i];  
      random = rand() % n; //need to change value 100 and 1000 for 100 and 1000 array sequence*
      arr[i] = arr[random];
      arr[random] = temp;
   }
   cout << "Array before sorting: \n";
   display(arr, n);
   
   gettimeofday(&start, NULL);
   InsertionSort(arr, n);
   cout << "\nArray after Insertion Sorting: ";
   display(arr, n);
   gettimeofday(&end, NULL); 
   time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
   time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;   
   cout << "Time taken by InsertionSort program is : " << fixed << time_taken << setprecision(10); 
   cout << " sec\n"; 
   
   gettimeofday(&start, NULL);
   MergeSort(arr, 0, n - 1);
   cout << "\nArray after Merge Sorting: ";
   display(arr, n);
   gettimeofday(&end, NULL); 
   time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
   time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;   
   cout << "Time taken by MergeSort program is : " << fixed << time_taken << setprecision(10); 
   cout << " sec\n"; 
   
   gettimeofday(&start, NULL);
   quickSort(arr, 0, n - 1);
   cout << "\nArray after QuickSort: ";
   display(arr, n);
   gettimeofday(&end, NULL); 
   time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
   time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;   
   cout << "Time taken by QuickSort program is : " << fixed << time_taken << setprecision(10); 
   cout << " sec\n";

   gettimeofday(&start, NULL);
   QuickInsertion(arr, n, k);
   cout << "\nArray after Quick-InsertionSort: ";
   display(arr, n);
   gettimeofday(&end, NULL); 
   time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
   time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;   
   cout << "Time taken by QuickInsertionSort program is : " << fixed << time_taken << setprecision(10); 
   cout << " sec\n";

}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void swapping(int *a, int *b) {     //swap the content of a and b
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void InsertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
   }
    
}

void Merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; 
   nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //merge temp arrays to real array
   while(i < nl && j < nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i < nl) {       //extra element in left array
      array[k] = larr[i];
      i++; 
      k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; 
      k++;
   }
}
void MergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      MergeSort(array, l, m);
      MergeSort(array, m+1, r);
      Merge(array, l, m, r);
   }
}

int partition (int array[], int low, int high)  
{  
    int pivot = array[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j < high; j++)  
    {  
        // If current element is smaller than the pivot  
        if (array[j] <= pivot)  
        {  
            i++; // increment index of smaller element  
            swapping(&array[i], &array[j]);  
        }  
    }  
    swapping(&array[i + 1], &array[high]);  
    return (i + 1);  
} 

void quickSort(int array[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(array, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(array, low, pi - 1);  
        quickSort(array, pi + 1, high);  
    }  
    
}

void QuickInsertion(int array[], int n, int k)
{
     if(k < n){
        //cout << "\nThe value of K < N, hence sorting using Insertion Sort";
        InsertionSort(array, n);
     }   
     else{
        //cout << "\nThe value of K > N, hence sorting using quick Sort";
        quickSort(array, 0, n - 1);
     }  
}
