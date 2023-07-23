#include <stdio.h>
int c[50];

void merge(int arr[], int low, int mid, int high) {
    int i= low ;
    int j =  mid+1;
    int k=0;
    
    while (i <=mid  && j <=high) {
        if (arr[i] <= arr[j]) {
            c[k] = arr[i];
            i++;
            k++;
        } else {
            c[k] = arr[j];
            j++;
            k++;
        }
        
    }

    while (i <=mid) {
        c[k] = arr[i];
        i++;
        k++;
    }

 
    while (j <= high) {
        c[k] = arr[j];
        j++;
        k++;
    }

    for(k = 0 ; k < (high-low+1) ; k++)
        arr[low + k] = c[k];
}



void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low+high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
 

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
   

    return 0;
}
