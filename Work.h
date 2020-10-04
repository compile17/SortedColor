#ifndef WORK_H
#define WORK_H

#include <iostream>
#include <vector>
#include <type_traits>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <random>
#include <ctime>
#include <exception>

class Work
{
public:
    static bool correctRule(std::string& str, std::unordered_map<char, std::string>& cont, bool& rev) noexcept;
    static std::string processing(std::string&& str, std::string&& rule, std::unordered_map<char, std::string>&& cont, bool reverse) noexcept;
    static std::string generateSequense(std::string& tmp, bool& stop) noexcept;
};

#endif // WORK_H
