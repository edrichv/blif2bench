#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

namespace strcond{
    void trim_spaces(std::string& line);
    void to_upper_case(std::string& line);
    void to_lower_case(std::string& line);  
    std::vector<std::string> split(std::string str, char delim);
}