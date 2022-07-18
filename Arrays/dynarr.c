#include <stdio.h>
#include <stdlib.h>

/*
    STRUCTS
*/
typedef struct DynArr
{
    double *items;
    int size;
    int len;
} dynarr_t;

// Used in the indexof() function
typedef struct IndexArr
{
    int *indexes;
    int len;
} indexarr_t;

/*
    FUNCTIONS
*/
dynarr_t initdynarr()
{
    dynarr_t arr;
    arr.size = 2;
    arr.len = 0;
    arr.items = (double *) malloc(sizeof(double) * arr.size);
    return arr;
}

void printdynarr(dynarr_t arr)
{
    printf("{ ");
    for (int i = 0; i<arr.len; i++)
        printf("%lf ", arr.items[i]);
    printf("}\n");
}

void add(dynarr_t *arr, double n)
{
    if (arr->size <= arr->len)
    {
        double temp[arr->len];
        int i;
        for (i = 0; i<arr->len; i++)
            temp[i] = arr->items[i];
        arr->size*=2;
        free(arr->items);
        arr->items = (double *) malloc(sizeof(double) * arr->size);
        for (i = 0; i<arr->len; i++)
            arr->items[i] = temp[i];
    }
    arr->items[arr->len] = n;
    arr->len++;
}

void pop(dynarr_t *arr, int ind)
{
    arr->len--;
    double temp[arr->len];

    int i;
    int count = 0;
    for (i = 0; i<=arr->len; i++)
    {
        if (i != ind)
        {
            temp[count] = arr->items[i];
            count++;
        }
    }
    
    free(arr->items);
    arr->items = (double *) malloc(sizeof(double) * arr->size);
    for (i = 0; i<arr->len; i++)
        arr->items[i] = temp[i];
}

indexarr_t indexof(dynarr_t arr, double n)
{
    int list[arr.len];
    int list_size = 0;
    int i;

    for (i = 0; i< arr.len; i++)
        if (arr.items[i] == n)
        {
            list[list_size] = i;
            list_size++;
        }
    
    if (list_size == 0)
    {
        indexarr_t temp;
        temp.indexes = (int *) malloc(sizeof(int) * 1);
        temp.indexes[0] = -1;
        temp.len = 1;
        return temp;
    }
    indexarr_t temp;
    temp.indexes = (int *) malloc(sizeof(int) * list_size);
    temp.len = list_size;
    for (i = 0; i<list_size; i++)
        temp.indexes[i] = list[i];
    return temp;
}

void yeet(dynarr_t *arr, double n)
{
    indexarr_t ind = indexof(*arr, n);
    if (ind.indexes[0] == -1) return;

    for (int i = 0; i<ind.len; i++)
    {
        pop(arr, ind.indexes[i]);
    }
    free(ind.indexes);
}

/*
    TESTS
*/
int main()
{
    dynarr_t arr = initdynarr();
    int i;

    // Add Test
    printf("\nAdd test:\n");
    for (i = 0; i<5; i++)
    {
        add(&arr, i+1);
        printdynarr(arr);
        printf("Length: %d Size: %d\n", arr.len, arr.size);
    }

    // Pop Test
    printf("\nPop test:\n");
    printf("Popping index 3:\n");
    pop(&arr, 3);
    printdynarr(arr);
    printf("Length: %d Size: %d\n", arr.len, arr.size);

    // Indexof Test
    printf("\nIndexof test:\n");
    add(&arr, 1);
    printdynarr(arr);

    indexarr_t pack = indexof(arr, 1);
    printf("Indexes of 1: ");
    for (i = 0; i<2; i++)
        printf("%d ", pack.indexes[i]);
    printf("\nNumber of found indexes: %d\n", pack.len);

    indexarr_t asd = indexof(arr, 10);
    printf("Index of 10: %d\n", asd.indexes[0]);
    printf("Number of found indexes: %d\n", asd.len);

    // Yeet Test
    printf("\nYeet test:\n");
    printf("Yeeting 1:\n");
    yeet(&arr, 1);
    printdynarr(arr);
    printf("Yeeting 10:\n");
    yeet(&arr, 10);
    printdynarr(arr);

    return 0;
}