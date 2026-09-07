#include <iostream>
int main(){
    int x;
    std::cin >> x;
    int steps = x/5;
    if (x != 0){
        steps += 1;
    }
    std::cout << steps;

    return 0;
}
