#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeInsertionSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeInsertionSort(arr, left, middle);
        mergeInsertionSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void printVector(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arrValues[] = {9, 1, 6, 4, 3, 2, 8, 5, 7};
    std::vector<int> arr(arrValues, arrValues + sizeof(arrValues) / sizeof(arrValues[0]));
    std::cout << "Original array: ";
    printVector(arr);

    mergeInsertionSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printVector(arr);

    return 0;
}

