#include "../include/Blifparse.h"

void Blifparse::write_file(std::string path, std::vector<std::string> lines){
    std::ofstream out(path);
	for (std::string line : lines) {
		out << line << std::endl;
	}
    out.close();
}
void Blifparse::to_bench(toml::table config){
    std::string work_dir = config["Files"]["work_dir"].value_or("Not Found");
    std::string in_blif = work_dir + config["Files"]["in_blif"].value_or("Not Found");
    std::string out_bench = work_dir + config["Files"]["out_bench"].value_or("Not Found");
    Bliffile bf(in_blif, config);
}
std::vector<std::string> Blifparse::readlines(std::string in_path){
    std::ifstream is;
    is = std::ifstream(in_path);
    std::vector<std::string> lines;

    while (is.good()) {
		std::string line;
		std::getline(is, line);
		if (line.compare("") == 0) continue;
        lines.push_back(line);
    }
    is.close();

    return lines;
}
