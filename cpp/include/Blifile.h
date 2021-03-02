#pragma once
#include<string>
#include<vector>
#include<unordered_map>

class Blifile{
private:
    std::string path;
    std::vector<std::string> config;
    std::vector<std::string> gate_list;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::unordered_map<std::string, std::string> split_dict;
    std::vector<std::string> file_lines;
    void parse();
    void condition(std::vector<std::string> &file_lines);
   
public:
    Blifile(std::string gate_type, 
        std::vector<std::string> inputs, 
        std::vector<std::string> output);
    std::vector<std::string> get_inputs();
    std::vector<std::string> get_outputs();
};