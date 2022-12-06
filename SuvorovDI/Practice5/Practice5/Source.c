#include <stdio.h>
#include <string.h>
#define SIZE 8

//char names[SIZE][30] = {"firstFile.txt", "MyFile.txt", "presentation.pttx", "soPDF.pdf", "Secondfile.pdf", "idkFile.txt", "iNeedThisFile.txt", "myImportant.docx"};
//int weight[SIZE] = { 128, 3472, 300, 450, 200, 1526, 120, 1200 };

void quick_sort(int* mas, int size) {
    // start & end of array
    int i = 0;
    int j = size - 1;

    //middle
    int mid = mas[size / 2];

    // greater -- to right, less -- to left
    do {
        while (mas[i] < mid) {
            i++;
        }

        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //if there are something to sort
    if (j > 0) {
        // left part
        quick_sort(mas, j + 1);
    }
    if (i < size) {
        // right part
        quick_sort(&mas[i], size - i);
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* L;
    int* R;
    L = (int*)malloc(n1 * sizeof(int));
    R = (int*)malloc(n2 * sizeof(int));

    //Copy to temperary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temperary arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy ending of L, if it's exists
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy ending of R, if it's exists
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(R);
    free(L);

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void bubble_sort(int arr[], int len) {
    int i, j, tmp;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

}

void print_gap() {
    printf("\n-----------------------------------\n");
}

void print_array(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d \n", arr[i]);
    }
}

int main() {
    int array[8] = { 123, 147, 111, 109, 1202, 100, 111, 1122 };
    int a_size = sizeof(array) / sizeof(array[0]);

    /*int* copy = (int*)malloc(a_size * sizeof(int));

    memcpy(&copy, &array, a_size * sizeof(int));*/

    printf("fgsfgasfgas");

    mergeSort(array, 1, a_size - 4);

    print_array(array, a_size);

    /*free(copy);*/

    return 0;
}