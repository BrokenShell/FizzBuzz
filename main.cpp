#include <iostream>
#include <functional>
#include <string>


std::string fizbuzz(int n) {
    auto test = [=](int d, std::string s, std::function<std::string(std::string)> f) {
        return n % d == 0 ? [=](std::string) { return s + f(""); } : f;
    };
    auto id = [](auto s) { return s; };
    auto fizz = std::bind(test, 3, "Fizz", std::placeholders::_1);
    auto buzz = std::bind(test, 5, "Buzz", std::placeholders::_1);
    return fizz(buzz(id))(std::to_string(n));
}

int main(int argc, const char * argv[]) {
    for (int i=1; i<101; ++i) {
        std::cout << fizbuzz(i) << '\n';
    }
}
