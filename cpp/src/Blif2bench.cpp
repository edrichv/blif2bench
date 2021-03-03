#include "../include/Log.h"
#include "../include/toml++/toml.h"
#include "../include/Blifparse.h"
#include <fstream>

int main(){
    auto config = toml::parse_file( "../config.toml" );
    Blifparse::to_bench(config);
    return 0;
}