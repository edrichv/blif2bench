#include "../include/Log.h"
#include "../include/toml++/toml.h"
#include "../include/Blifparse.h"
#include <fstream>

int main(){
    auto config = toml::parse_file( "config.toml" );
    log(config["BBGT"]["DFF"].value_or("Not found"));
    std::vector<std::string> lines = Blifparse::readlines("config.toml");
    log(lines[0]);
    log(lines[1]);
    log(lines[2]);
    log(lines[3]);
    log("hello");
    return 0;
}