#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_literals;

using Index = int;

Index NaiveStringMatcher(std::string_view text, std::string_view pattern) {
    int n = static_cast<int>(text.size());

    int m = static_cast<int>(pattern.size());

    int last_possible_pos = n - m;

    for (int i = 0; i < last_possible_pos; ++i) {
        bool match = true;

        for (int j = 0; j < m; ++j) {
            if (pattern[j] != text[i + j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::string text = "abcdefg"s;
    std::string pattern = "cd"s;

    std::cout << NaiveStringMatcher(text, pattern) << '\n';

    return 0;
}