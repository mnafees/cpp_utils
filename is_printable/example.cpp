#include <vector>

#include "is_printable.hpp"

struct C {};

template<typename _Tp>
std::ostream& operator<<(std::ostream& os, const std::vector<_Tp>& v) {
    for (const auto& el : v) {
        os << el;
    }
    return os;
}

int main(int argc, const char* argv[]) {
    std::cout << std::boolalpha;
    std::cout << is_printable_v<int> << std::endl;
    std::cout << is_printable_v<unsigned char> << std::endl;
    std::cout << is_printable_v<double> << std::endl;
    std::cout << is_printable_v<std::vector<int>> << std::endl;

    C c;
    std::cout << is_printable_v<decltype(c)> << std::endl;

    return 0;
}
