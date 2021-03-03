#pragma once
#include "Bliffile.h"
#include "Gate.h"
#include "Str_cond.h"
#include <fstream>
#include <sstream>
#include "Log.h"

namespace Blifparse{
     void write_file(std::string path, std::vector<std::string> lines);
     void to_bench(toml::table config);
     std::vector<std::string> readlines(std::string in_path);
}