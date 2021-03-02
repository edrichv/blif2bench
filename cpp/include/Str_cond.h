#pragma once
#include <string>
#include <sstream>
#include <algorithm>

namespace strcond{
    void reformat_line(std::string& line);
    void trim_spaces(std::string& line);
    void to_upper_case(std::string& line);  
}