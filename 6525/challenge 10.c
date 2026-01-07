#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;
    int n, i;

    // Swap two numbers
    printf("Enter two numbers to swap: ");
    scanf("%d %d", &x, &y);

    printf("Before swap: x = %d, y = %d\n", x, y);
    printf("Addresses: &x = %p, &y = %p\n", (void*)&x, (void*)&y);

    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n\n", x, y);

    // Array traversal using pointers
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i); // pointer arithmetic instead of indexing
    }

    printf("Array elements using pointers:\n");
    int *ptr = arr;
    for (i = 0; i < n; i++)
    {
        printf("Value: %d, Address: %p\n", *(ptr + i), (void*)(ptr + i));
    }

    return 0;
}
