#include <algorithm>
#include <iomanip>
#include <iostream>

struct Karung {
    int C;
    int W;
    double kg_cost() { return (double)C / W; };
    static bool comp(Karung &a, Karung &b) {
        return a.kg_cost() > b.kg_cost();
    };
};

int main() {
    int N, X;
    Karung *K;
    double total_cost;

    std::cin >> N;
    std::cin >> X;

    K = new Karung[N];

    for (int i = 0; i < N; i++) {
        std::cin >> K[i].W;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> K[i].C;
    }

    std::sort(K, K + N, Karung::comp);

    for (int i = 0; i < N && X > 0; i++) {
        int kg = X < K[i].W ? X : K[i].W;
        total_cost += K[i].kg_cost() * kg;
        X -= kg;
    }

    std::cout << std::setprecision(5) << std::fixed << total_cost << '\n';

    delete[] K;

    return 0;
}
