#include<stdio.h>

int arr[10],n;

int partition(int low,int high){
    int i=low+1;
    int j=high;

    while (i<=j)
    {
        while(arr[low]>arr[i] && i<=high)
        i=i+1;

        while(arr[low]<arr[j] && j>low)
        j=j-1;

        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
            arr[low]=arr[j];
            arr[j]=temp;

    return j;
}

void quicksort(int low,int high){
    if(low<high){
        int j=partition(low,high);
        quicksort(low,j-1);
        quicksort(j+1,high);
    }
}

int main(){

    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
