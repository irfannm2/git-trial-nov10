#include <iostream>

int translate_score(char score);
float calculate_gpa(char *score, unsigned int *sks, size_t n);

int main() {
    size_t n;
    char *score;
    unsigned int *sks;
    float gpa;
    short int rv = 0;

    std::cout << "Enter number of courses: ";
    std::cin >> n;
    score = new char[n];
    sks = new unsigned int[n];

    std::cout << "Enter courses scores (space separated): ";
    for (int i = 0; i < n; i++)
        std::cin >> score[i];
    std::cout << "Enter courses credits (space separated): ";
    for (int i = 0; i < n; i++)
        std::cin >> sks[i];

    gpa = calculate_gpa(score, sks, n);
    if (gpa < 0 || gpa > 4) {
        std::cout << "Illegal input\n";
        rv = 1;
    } else {
        std::cout << "GPA: " << gpa << '\n';
    };

    delete[] score;
    delete[] sks;
    return rv;
}

int translate_score(char score) {
    score = toupper(score);
    if (score < 65 || score > 69)
        return -1;
    return (int)-1 * (score - (65 + 4));
}

float calculate_gpa(char *score, unsigned int *sks, size_t n) {
    float total_score = 0;
    int total_credit = 0;
    int tr_score;
    for (int i = 0; i < n; i++) {
        tr_score = translate_score(score[i]);
        if (tr_score < 0)
            return -1;
        total_score += tr_score * sks[i];
        total_credit += sks[i];
    }
    return total_score / total_credit;
};
