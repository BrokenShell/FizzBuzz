#include <iostream>
#include <functional>
#include <string>


auto fizzbuzz(int n) -> std::string {
    auto test = [=](int d, const std::string& s, const std::function<std::string(std::string)>& f) {
        return n % d == 0 ? [=](const std::string&) { return s + f(""); } : f;
    };
    auto id = [](auto s) { return s; };
    auto fizz = [test](auto && a) { return test(3, "Fizz", std::forward<decltype(a)>(a)); };
    auto buzz = [test](auto && b) { return test(5, "Buzz", std::forward<decltype(b)>(b)); };
    return fizz(buzz(id))(std::to_string(n));
}

int main() {
    for (int i=1; i<101; ++i) {
        std::cout << fizzbuzz(i) << '\n';
    }
}
