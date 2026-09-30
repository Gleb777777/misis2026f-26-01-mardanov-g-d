#include <iostream>
int main() {
    int n;
    int m;
    int a;
    std::cin >> n >> m >> a;
    long long answer;
    long long po_n;
    po_n = (n + a - 1) / a;
    long long po_m;
    po_m = (m + a - 1) / a;
    answer = po_n * po_m;
    std::cout << answer;
    return 0;
}