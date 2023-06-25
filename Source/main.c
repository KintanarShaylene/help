#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String499[500];
int main ()
{
    //Mode 1 = Insertion, Mode 2 = Selection, Mode 3 = Shell, Mode 4 = Merge
    int mode = 4;
    int i, j;
    long long count;
    long long countMerge = 0;
    long startTime, endTime;
    int sizes[7] = {100, 25000, 50000, 75000, 100000, 100000, 100000};
    String499 fileNames[7] = {"random100.txt", "random25000.txt", "random50000.txt", "random75000.txt", "almostsorted.txt", "random100000.txt", "totallyreversed.txt"};
    Record* recordArray;

    switch (mode) {
        case 1:
            printf("\tInsertion Sort:\n\n");
            for (i = 0; i < 7; i++) {
                recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
                readFile(recordArray, fileNames[i]);
                count = insertionSortCount(recordArray, sizes[i]);
                printf("\t%-21s - %lld\n", fileNames[i], count);
                free(recordArray);
                recordArray = NULL;

                printf("\tTrials:\n");
                for (j = 0; j < 5; j++) {
                    recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
                    readFile(recordArray, fileNames[i]);
                    startTime = currentTimeMillis();
                    insertionSort(recordArray, sizes[i]);
                    endTime = currentTimeMillis();
                    printf("\t\t%d - %ld\n", j + 1, endTime - startTime);
                    free(recordArray);
                    recordArray = NULL;
                }
                printf("\n");
            }

            printf("\n");
        break;

    case 2:
        printf("\tSelection Sort:\n\n");
        for (i = 0; i < 7; i++) {
            recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
            readFile(recordArray, fileNames[i]);
            count = selectionSortCount(recordArray, sizes[i]);
            printf("\t%-21s - %lld\n", fileNames[i], count);
            free(recordArray);
            recordArray = NULL;

            printf("\tTrials:\n");
            for (j = 0; j < 5; j++) {
                recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
                readFile(recordArray, fileNames[i]);
                startTime = currentTimeMillis();
                selectionSort(recordArray, sizes[i]);
                endTime = currentTimeMillis();
                printf("\t\t%d - %ld\n", j + 1, endTime - startTime);
                free(recordArray);
                recordArray = NULL;
            }
            printf("\n");
        }

        printf("\n");
    break;

    case 3:
        printf("\tShell Sort:\n\n");
        for (i = 0; i < 7; i++) {
            recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
            readFile(recordArray, fileNames[i]);
            count = shellSortCount(recordArray, sizes[i]);
            printf("\t%-21s - %lld\n", fileNames[i], count);
            free(recordArray);
            recordArray = NULL;

            printf("\tTrials:\n");
            for (j = 0; j < 5; j++) {
                recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
                readFile(recordArray, fileNames[i]);
                startTime = currentTimeMillis();
                shellSort(recordArray, sizes[i]);
                endTime = currentTimeMillis();
                printf("\t\t%d - %ld\n", j + 1, endTime - startTime);
                free(recordArray);
                recordArray = NULL;
            }
            printf("\n");
        }

        printf("\n");
    break;

    case 4:
        printf("\tMerge Sort:\n\n");
        for (i = 0; i < 7; i++) {
            recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
            readFile(recordArray, fileNames[i]);
            countMerge = mergeSortCount(recordArray, 0, sizes[i] - 1);
            printf("\t%-21s - %-lld\n", fileNames[i], countMerge);
            free(recordArray);
            recordArray = NULL;

            printf("\tTrials:\n");
            for (j = 0; j < 5; j++) {
                recordArray = (Record*) malloc (sizeof(Record) * sizes[i]);
                readFile(recordArray, fileNames[i]);
                startTime = currentTimeMillis();
                mergeSort(recordArray, 0, sizes[i] - 1);
                endTime = currentTimeMillis();
                printf("\t\t%d - %ld\n", j + 1, endTime - startTime);
                free(recordArray);
                recordArray = NULL;
            }
            printf("\n");
        }
        printf("\n");
    break;
    }

    return 0;
}
