#pragma once
#include<string>
#include<vector>
#include<unordered_map>
#include "Str_cond.h"
#include "toml++/toml.h"
#include "Gate.h"

class Bliffile{
private:
    std::string path;
    toml::table config;
    std::vector<Gate> gate_list;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::unordered_map<std::string, std::string> split_dict;
    std::vector<std::string> file_lines;
    std::string model_name;
    void parse();
    void condition();
public:
    Bliffile(std::string path, toml::table config);
    std::vector<std::string> get_inputs();
    std::vector<std::string> get_outputs();
    std::string get_path();
    std::vector<Gate> get_gate_list();
    std::unordered_map<std::string, std::string> get_split_dict();
    std::vector<std::string> get_file_lines();
    std::string get_model_name();

};