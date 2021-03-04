#include "../include/Log.h"
#include "../include/toml++/toml.h"
#include "../include/Blifparse.h"
#include <fstream>

int main(int argc, char **argv){
    if(argc < 2){
        log("Not enough arguments"); 
        return 1;
    } 
    auto config = toml::parse_file(std::string(argv[1]));
    Blifparse::to_bench(config);
    return 0;
}