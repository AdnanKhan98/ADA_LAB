#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {15, 5, 20, 1, 7, 10, 30};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    heapSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
