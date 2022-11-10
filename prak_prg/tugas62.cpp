#include <iostream>

struct Student {
    int ID;
    float midtermScore;
    float finalScore;
    float averageScore() { return (midtermScore + finalScore) / 2.0f; };
};

int main() {
    int sz;
    std::cout << "Enter the number of students: ";
    std::cin >> sz;
    if (sz <= 0 || sz > 50) {
        std::cout << "Illegal input\n";
        exit(-1);
    }
    Student students[sz];
    std::cout << '\n';

    for (int i = 0; i < sz; i++) {
        std::cout << "Enter student ID: ";
        std::cin >> students[i].ID;
        std::cout << "Enter midterm exam score: ";
        std::cin >> students[i].midtermScore;
        std::cout << "Enter final exam score: ";
        std::cin >> students[i].finalScore;
        std::cout << '\n';
    }

    for (int i = 0; i < sz; i++) {
        std::cout << "Student ID: " << students[i].ID << '\n';
        std::cout << "Average: " << students[i].averageScore() << "\n\n";
    }
    return 0;
}