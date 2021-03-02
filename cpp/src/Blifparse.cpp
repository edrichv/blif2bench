#include "../include/Blifparse.h"

void Blifparse::write_file(std::string path, std::vector<std::string> lines){
    std::ofstream out(path);
	for (std::string line : lines) {
		out << line << std::endl;
	}
    out.close();
}
void Blifparse::to_bench(std::string in_path, std::string out_path, std::string config){
    return;
}
std::vector<std::string> Blifparse::readlines(std::string in_path){
    std::ifstream is;
    is = std::ifstream(in_path);
    std::vector<std::string> lines;

    while (is.good()) {
		std::string line;
		std::getline(is, line);
		if (line.compare("") == 0) continue;
        strcond::reformat_line(line);
        lines.push_back(line);
    }
    is.close();

    return lines;
}
