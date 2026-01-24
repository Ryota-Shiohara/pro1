#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMO_LENGTH 200000
#define LOOP_LENGTH 200000

// #define MEMO_LENGTH 94800000
// #define LOOP_LENGTH 83170000

// #define MEMO_LENGTH 83170000
// #define LOOP_LENGTH 83170000

typedef struct CollatzNode {
    int index;
    int chain_length;
    unsigned long long odd_num;
} CollatzNode;

CollatzNode CollatzNodeList[MEMO_LENGTH];

int calculate_chain_length(unsigned long long n);
void storeCollatzNode(int index, unsigned long long odd_num, int chain_length);
void printCollatzNode(CollatzNode node);
void printAllCollatzNodes(int mod);

void swap(CollatzNode *a, CollatzNode *b);
CollatzNode *simpleSort(CollatzNode *array, int length);
void quickSort(CollatzNode *array, int left, int right);

int calculate_chain_length(unsigned long long n) {
    if (n == 1) {
        return 1;
    }

    while (n % 2 == 0) {
        n /= 2;
        if (n == 1) {
            return 1;
        }
    }

    unsigned long long index = (n + 1) / 2;

    if (index < MEMO_LENGTH && CollatzNodeList[index].odd_num != 0) {
        return CollatzNodeList[index].chain_length;
    }

    unsigned long long next_n = 3 * n + 1;
    if (next_n < n) {
        fprintf(stderr, "Overflow detected for n = %llu\n", n);
        exit(1);
    }

    int chain_length = 1 + calculate_chain_length(next_n);

    if (0 < index && index < MEMO_LENGTH) {
        storeCollatzNode(index, n, chain_length);
    }
    return chain_length;
}

void storeCollatzNode(int index, unsigned long long odd_num, int chain_length) {
    CollatzNodeList[index].index = index;
    CollatzNodeList[index].odd_num = odd_num;
    CollatzNodeList[index].chain_length = chain_length;
}

void printCollatzNode(CollatzNode node) {
    printf("Index: %d, Odd Number: %llu, Chain Length: %d\n", node.index,
           node.odd_num, node.chain_length);
}

void printAllCollatzNodes(int mod) {
    for (int i = 0; i < LOOP_LENGTH; i += mod) {
        printCollatzNode(CollatzNodeList[i]);
    }
}

void swap(CollatzNode *a, CollatzNode *b) {
    CollatzNode temp = *a;
    *a = *b;
    *b = temp;
}

CollatzNode *simpleSort(CollatzNode *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i].chain_length > array[j].chain_length) {
                swap(&array[i], &array[j]);
            }
        }
    }
    return array;
}

void quickSort(CollatzNode *array, int left, int right) {
    if (left >= right) {
        return;
    }

    CollatzNode pivot = array[(left + right) / 2];
    int i = left;
    int j = right;

    do {
        while (array[i].chain_length < pivot.chain_length) {
            i++;
        }
        while (array[j].chain_length > pivot.chain_length) {
            j--;
        }
        if (i <= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    } while (i <= j);

    quickSort(array, left, j);
    quickSort(array, i, right);
}

int main() {

    for (int i = 0; i < MEMO_LENGTH; i++) {
        storeCollatzNode(i, 0, 0);
    }

    int max_length = 0;
    int max_index = 0;

    for (int i = 1; i < LOOP_LENGTH; i++) {
        int length = calculate_chain_length(2 * i - 1);
        if (length > max_length) {
            max_length = length;
            max_index = i;
        }
        storeCollatzNode(i, 2 * i - 1, length);
    }

    printAllCollatzNodes(100000);
    printf("Max Chain Length: %d for Odd Number: %llu\n", max_length,
           CollatzNodeList[max_index].odd_num);

    double start_time = (double)clock() / CLOCKS_PER_SEC;
    quickSort(CollatzNodeList, 1, LOOP_LENGTH - 1);
    // simpleSort(CollatzNodeList, LOOP_LENGTH - 1);
    double end_time = (double)clock() / CLOCKS_PER_SEC;
    printAllCollatzNodes(100000);
    printf("Sorting Time: %f seconds\n", end_time - start_time);

    return 0;
}