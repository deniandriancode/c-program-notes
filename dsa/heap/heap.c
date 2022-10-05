#include <stdio.h>

int size = 0;

void swap (int *, int *);
void heapify (int *, int, int);
void insert (int *, int);
void delete_root (int *, int);
void print_array (int *, int);

int
main (int argc, char *argv[])
{
        int array[10];

        insert(array, 3);
        insert(array, 4);
        insert(array, 9);
        insert(array, 5);
        insert(array, 2);

        printf("Max-Heap array: ");
        print_array(array, size);

        delete_root(array, 4);

        printf("After deleting an element: ");

        print_array(array, size);
        return 0;
}

void
swap (int *a, int *b)
{
        int temp = *b;
        *b = *a;
        *a = temp;
}

void
heapify (int array[], int size, int i)
{
        if (size == 1) {
                printf ("Single element in the heap\n");
        } else {
                int largest = i;
                int l = 2 * i + 1;
                int r = 2 * i + 2;
                if (l < size && array[l] > array[largest])
                        largest = l;
                if (r < size && array[r] > array[largest])
                        largest = r;
                if (largest != i) {
                        swap (&array[i], &array[largest]);
                        heapify (array, size, largest);
                }
        }
}

void
insert (int array[], int new_num)
{
        if (size == 0) {
                array[0] = new_num;
                size++;
        } else {
                array[size] = new_num;
                size++;
                for (int i = size / 2 - 1; i>= 0; i--) {
                        heapify (array, size, i);
                }
        }
}

void
delete_root (int array[], int num)
{
        int i;
        for (i = 0; i < size; i++)
                if (num == array[i])
                        break;

        swap (&array[i], &array[size - 1]);
        size--;
        for (i = size / 2 - 1; i >= 0; i--)
                heapify (array, size, i);
}

void
print_array (int array[], int n_size)
{
        for (int i = 0; i < n_size; ++i)
                printf ("%d ", array[i]);
        printf ("\n");
}
