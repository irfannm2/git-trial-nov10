#define MAX_SAMPLE_SIZE 10

#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>

void randomize_data(int *data, size_t sz);
void insertion_sort(int *data, size_t sz, bool (*key)(int, int));
void selection_sort(int *data, size_t sz, bool (*key)(int, int));
inline bool ascending(int a, int b);
inline bool descending(int a, int b);
void print_array_sample(int *data, size_t sz);

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;

    int choice;
    int *data (0);
    size_t sz (0);
    void (*sorting_alg)(int *, size_t, bool (*)(int, int));
    bool (*key)(int, int);

    while (1) {
        std::cout << "Please choose an operation.\n"
                  << "\t1. Enter the number of data to be sorted\n"
                  << "\t2. Generate random data\n"
                  << "\t3. Sort the data in ascending using the insertion sort method\n"
                  << "\t4. Sort the data in descending using the insertion sort method\n"
                  << "\t5. Sort the data in ascending using the selection sort method\n"
                  << "\t6. Sort the data in descending using the selection sort method\n"
                  << "\t7. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cout << "\n\n";

        if (choice == 1) {
            std::cout << "Enter the number of data to be stored: ";
            std::cin >> sz;
            if (data) delete[] data;
            data = new int[sz]();
        } else if (choice == 2) {
            if (sz == 0) {
                std::cout << "Specify data size first.\n";
            } else {
                randomize_data(data, sz);
                std::cout << "Randomized " << sz << " data\n";
            }
        } else if (choice > 2 && choice <= 6) {
            choice -= 3;
            sorting_alg = choice < 2 ? insertion_sort : selection_sort;
            key = choice % 2 == 0 ? ascending : descending;
            
            auto t1 = high_resolution_clock::now();
            sorting_alg(data, sz, key);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> sorting_time = t2 - t1;

            std::cout << "Sorting time: " << sorting_time.count() << "ms\n";
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid input\n";
        }
        
        std::cout << '\n';
        print_array_sample(data, sz);
        std::cout << '\n';
    }

    if (data) delete[] data;
    return 0;
}

void randomize_data(int *data, size_t sz) {
    std::srand(std::time(NULL));
    for (int i = 0; i < sz; i++) {
        data[i] = std::rand();
    }
}

void insertion_sort(int *data, size_t sz, bool (*key)(int, int)) {
    int i, j, temp;
    
    for (i = 1; i < sz; i++) {
        j = i - 1;
        temp = data[i];
        while (key(data[j], temp) && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

void selection_sort(int *data, size_t sz, bool (*key)(int, int)) {
    int i, j, k;

    for (i = 0; i < sz; i++) {
        k = i;
        for (j = k + 1; j < sz; j++) {
            if (key(data[k], data[j])) {
                k = j;
            }
        }
        std::swap(data[i], data[k]);
    }
}

inline bool ascending(int a, int b) {
    return a > b;
}

inline bool descending(int a, int b) {
    return a < b;
}

void print_array_sample(int *data, size_t sz) {
    if (!data) 
        return;

    for (int i = 0; i < sz && i < MAX_SAMPLE_SIZE; i++) {
        std::cout << data[i];
        if (i != (int)(sz - 1) && i != MAX_SAMPLE_SIZE - 1) {
            std::cout << ", ";
        }
    }

    if (sz > MAX_SAMPLE_SIZE) {
        std::cout << ", ...";
    }
    std::cout << '\n';
}
