#pragma once
#include "Blifile.h"
#include "Gate.h"

namespace Blifparse{
     void write_file(std::string path, std::vector<std::string> lines);
     void to_bench(std::string in_path, std::string out_path, std::string config);
}