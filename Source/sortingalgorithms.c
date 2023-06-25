#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void swap(Record *a, Record *b){
    Record c;
    c = *a;
    *a = *b;
    *b = c;
}

void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    int i, j;
    Record key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j].idNumber > key.idNumber) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

long long insertionSortCount (Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    int i, j;
    long long ctr = 0;
    Record key;

    for (i = 1; i < n; i++) {                              ctr++;
        key = arr[i];                                      ctr++;
        j = i - 1;                                         ctr++;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j].idNumber > key.idNumber) { ctr++;
            arr[j + 1] = arr[j];                           ctr++;
            j = j - 1;                                     ctr++;
        }                                                  ctr++;

        arr[j + 1] = key;                                  ctr++;
    }                                                      ctr++;

    return ctr;
}


void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j].idNumber < arr[minIndex].idNumber) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[i], &arr[minIndex]);
    }
}

long long selectionSortCount(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    int i, j, minIndex;
    long long ctr = 0;

    for (i = 0; i < n - 1; i++) {                           ctr++;
        minIndex = i;                                       ctr++;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {                       ctr++;
            if (arr[j].idNumber < arr[minIndex].idNumber) {
                minIndex = j;                               ctr++;
            }                                               ctr++;
        }                                                   ctr++;                                                

        // Swap the found minimum element with the first element
        swap(&arr[i], &arr[minIndex]);                      ctr+=3;
    }                                                       ctr++;
    return ctr;
}



void merge(Record arr[], int p, int q, int r)
{
    int ctr = 0;
    int i, j, k;
    int n1 = q - p + 1; 
    int n2 = r - q;

    // Create dynamic temporary arrays
    Record* L = (Record*)malloc(n1 * sizeof(Record)); 
    Record* R = (Record*)malloc(n2 * sizeof(Record));

    // Copy data to temporary arrays
 
    for (i = 0; i < n1; i++){ 
        L[i] = arr[p + i]; }
    
    for (j = 0; j < n2; j++){
        R[j] = arr[q + 1 + j]; }

    // Merge the temporary arrays back into arr[]
    i = 0; 
    j = 0; 
    k = p; 

     while (i < n1 || j < n2) { 
         if (i < n1 && j < n2) {
            if (L[i].idNumber <= R[j].idNumber) { 
                arr[k] = L[i]; 
                i++;
            } else {
                arr[k] = R[j]; 
                j++; 
            }
            k++;
        } else {
             if (i < n1) {
                arr[k] = L[i]; 
                i++; 
            } else {
                arr[k] = R[j]; 
                j++; 
            }
            k++; 
        }
    }
}

int mergeCount (Record arr[], int p, int q, int r)
{
    int ctr = 0;
    int i, j, k;
    int n1 = q - p + 1; ctr++;
    int n2 = r - q;ctr++;

    // Create dynamic temporary arrays
    Record* L = (Record*)malloc(n1 * sizeof(Record)); ctr++;
    Record* R = (Record*)malloc(n2 * sizeof(Record));ctr++;

    // Copy data to temporary arrays
    ctr++;
    for (i = 0; i < n1; i++){ ctr++;
        L[i] = arr[p + i]; ctr++;}
    ctr++;
    for (j = 0; j < n2; j++){ctr++;
        R[j] = arr[q + 1 + j]; ctr++;}

    // Merge the temporary arrays back into arr[]
    i = 0; ctr++;
    j = 0; ctr++;
    k = p; ctr++;

    ctr++; while (i < n1 || j < n2) { ctr++;
        ctr++; if (i < n1 && j < n2) {
            ctr++;if (L[i].idNumber <= R[j].idNumber) { 
                arr[k] = L[i]; ctr++;
                i++;ctr++;
            } else {
                arr[k] = R[j]; ctr++;
                j++; ctr++;
            }
            k++; ctr++;
        } else {
            ctr++; if (i < n1) {
                arr[k] = L[i]; ctr++;
                i++; ctr++;
            } else {
                arr[k] = R[j]; ctr++;
                j++; ctr++;
            }
            k++; ctr++;
        }
    }
    return ctr;
}


int mergeSortCount (Record arr[], int p, int r) {
    int ctr = 0;
    int q;
    ctr++; if (p < r) {
        q = p + (r - p) / 2; ctr++;

        // Sort first and second halves
        ctr += mergeSortCount(arr, p, q);
        ctr += mergeSortCount(arr, q + 1, r);

        // Merge the sorted halves
        ctr+= mergeCount(arr, p, q, r);
        return ctr;
    }

}


void mergeSort(Record *arr, int p, int r)
{
    // TODO: Implement this sorting algorithm here.
    if (p < r) {
        int q = p + (r - p) / 2;

        // Sort first and second halves
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        // Merge the sorted halves
        merge(arr, p, q, r);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/
void shellSort (Record* arr, int n)
{
    int gap, i, j;
    Record temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap].idNumber > temp.idNumber; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

long long shellSortCount (Record* arr, int n)
{
    long long ctr = 0;
    int gap, i, j;
    Record temp;

    for (gap = n/2; gap > 0; gap /= 2) { ctr++;

        for (i = gap; i < n; i++) {      ctr++;

            temp = arr[i];               ctr++;

            for (j = i; j >= gap && arr[j - gap].idNumber > temp.idNumber; j -= gap) { ctr++;

                arr[j] = arr[j - gap]; ctr++;

            } ctr++;

            arr[j] = temp; ctr++;

        } ctr++;

    } ctr++;

    return ctr;
}

#endif