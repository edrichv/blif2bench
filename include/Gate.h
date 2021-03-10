#pragma once
#include<string>
#include<vector>

typedef struct Gate
{
    std::string gate_type;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
}Gate;