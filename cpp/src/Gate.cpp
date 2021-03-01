#include "../include/Gate.h"

Gate::Gate(){
    Gate::classname = "gate123";
}

std::string Gate::get_classname(){
    return Gate::classname;
}


