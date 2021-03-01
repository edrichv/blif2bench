#pragma once
#include<string>

class Gate{
private:
    std::string classname = "Gate";
public:
    Gate();
    std::string get_classname();
};

