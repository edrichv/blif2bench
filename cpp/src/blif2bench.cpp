#include <iostream>
#include "../include/Log.h"
#include "../include/toml++/toml.h"
#include <fstream>

int main(){
    auto config = toml::parse_file( "config.toml" );
    log(config["BBGT"]["DFF"].value_or("Not found"));
    log("hello");
    return 0;
}