#include "unique_ptr.h"

#include <iostream>
#include <utility>

int main(int argc, const char* argv[]) {
    unique_ptr<int> i(new int);
    *i = 55;
    auto j = std::move(i);
    std::cout << *j << std::endl;
    if (!i) {
        std::cout << "i no longer contains a valid pointer" << std::endl;
    }

    return 0;
}
