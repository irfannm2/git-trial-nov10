#include <iostream>
#include <algorithm>

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

float median(int *arr, size_t s) {
    int mid;

    std::sort(arr, arr + s);
    mid = s / 2 - 1;
    return (arr[mid] + arr[s - mid - 1])/2.0f;
}
