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

    std::vector<std::string> out_lines;
    auto split_dict = bf.get_split_dict();
    
    // Write model name
    out_lines.push_back("# " + bf.get_model_name());
    // Write inputs
    for(std::string node : bf.get_inputs()){
        out_lines.push_back("input(" + node + ")");
    }  
    // Write outputs
    for(std::string node : bf.get_outputs()){
        out_lines.push_back("output(" + node + ")");
    }
    // Write gate assignment
    std::string out = "";
    for(Gate gate : bf.get_gate_list()){
        out = gate.outputs[0] + " = " + gate.gate_type + "(";
        // Add all gate inputs
        for (std::string g_in_i : gate.inputs){
            if (split_dict.find(g_in_i) != split_dict.end()) g_in_i = split_dict[g_in_i];
            out += g_in_i + ",";
        }
        // Remove unwanted "," and end line
        out.erase(out.end()-1);
        out += ")";
        out_lines.push_back(out);
    }
    write_file(out_bench, out_lines);
    log("Converted\n" + in_blif + "\nto\n" + out_bench + "\nsuccesfully!");
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
