#include <iostream>

struct Date {
    int day;
    int month;
    bool isValid() {
        if (day > 31 || month > 12 || day < 1 || month < 1 ||
            month == 2 && day > 29)
            return false;
        return true;
    };
    int flatten() { return month * 100 + day; };
};

struct Zodiac {
    std::string name;
    Date start;
    Date end;
};

Zodiac zodiacData[] = {
    {"Aries", 21, 3, 19, 4},         {"Taurus", 20, 4, 20, 5},
    {"Gemini", 21, 5, 20, 6},        {"Cancer", 21, 6, 22, 7},
    {"Leo", 23, 7, 22, 8},           {"Virgo", 23, 8, 22, 9},
    {"Libra", 23, 9, 22, 10},        {"Scorpio", 23, 10, 21, 11},
    {"Sagittarius", 22, 11, 21, 12}, {"Capricorn", 22, 12, 19, 1},
    {"Aquarius", 20, 1, 18, 2},      {"Pisces", 19, 2, 20, 3}};

Zodiac *determineZodiac(Date);

int main() {
    Date birthDate;

    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDate.day;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthDate.month;

    if (!birthDate.isValid()) {
        std::cout << "Invalid birth date. Exiting." << '\n';
        exit(-1);
    }

    Zodiac *z = determineZodiac(birthDate);
    std::cout << "Your zodiac is " << z->name << '\n';
    return 0;
}

Zodiac *determineZodiac(Date birthDate) {
    for (int i = 0; i < 12; i++) {
        Zodiac *z = &zodiacData[i];        
        int b = birthDate.flatten();
        int s = z->start.flatten();
        int e = z->end.flatten();

        if (s <= b && b <= e)
            return z;
    }
    return 0;
}