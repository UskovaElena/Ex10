// Copyright 2021 Uskova
#include "postfix.h"

int main()
{
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2 << std::endl;  // 2 6 3 * 4 2 - / +
    std::string inf = "(2 * (3 - 2) + 5) * (2.2 + 3 * 6) - 3.7";
    std::string postf = infix2postfix(inf);
    std::cout << postf << std::endl;  // "2 3 2 - * 5 + 2.2 3 6 * + * 3.7 -"
}
