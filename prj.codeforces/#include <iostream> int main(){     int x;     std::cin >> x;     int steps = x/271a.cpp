#include <iostream>
int main(){
    int god;
    std::cin >> god;
    while (true){
        god += 1;
        int god1 = god / 1000;
        int god2 = (god / 100) % 10;
        int god3 = (god / 10) % 10;
        int god4 = god % 10;
    if (god1 != god2 && god1 != god3 && god1 != god4 &&
    god2 != god3 && god2 != god4 &&
    god3 != god4){
        std::cout << god;
        break;
    }
    }
}
