#include <iostream>

void sort(int *arr, size_t s);
float median(int *arr, size_t s);

int main() {
    int *arr;
    size_t N;
    
    std::cout << "N = ";
    std::cin >> N;

    arr = new int[N];
    std::cout << "Elements (space-separated) = ";
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];

    std::cout << "Median = " << median(arr, N) << '\n';

    delete[] arr;

    return 0;
}

void sort(int *arr, size_t s) {
    int temp, i, j;

    for (i = 1; i < s; i++) {
        j = i - 1;
        temp = arr[i];
        while (arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

float median(int *arr, size_t s) {
    int mid;

    sort(arr, s);
    mid = s / 2 - 1;
    return (arr[mid]+arr[s-mid-1])/2.0f;
}
