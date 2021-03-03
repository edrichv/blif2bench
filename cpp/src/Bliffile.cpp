#include "../include/Bliffile.h"
#include "../include/Blifparse.h"

Bliffile::Bliffile(std::string path, toml::table config){
    Bliffile::path = path;
    Bliffile::config = config;
    // Store all file lines in list
    Bliffile::file_lines = Blifparse::readlines(path);
	// condition lines for parsing
    condition();
	parse();
}
void Bliffile::parse(){
	std::vector<std::string> component;
	std::vector<std::string> g_in;
	std::vector<std::string> g_out;
    for(std::string line : file_lines){
		std::stringstream ss(line);
		std::string item;
		component.clear();
		while (std::getline(ss, item, ' ')) {
			if (strcmp(item.c_str(), "#") == 0) continue;
			component.push_back(item);
		}
		std::string command = component[0];
		std::string temp = component[1];
		if(command.compare(".GATE") == 0){
			g_in.clear();
			g_out.clear();
			int i;
			for(i = 2; i<component.size(); i++){
				std::string comp = component[i];
				if (comp.find("IN")!= std::string::npos){
					g_in.push_back(strcond::split(comp, '=')[1]);
				}
				else if (comp.find("OUT") != std::string::npos){
					g_out.push_back(strcond::split(comp, '=')[1]);
				}
			}
			if (temp.compare("SPLIT") == 0){
				for (std::string output : g_out){
					split_dict[output] = g_in[0];
				}	
			}else{
				Gate temp_gate = {config["BBGT"][temp].value_or("and"),g_in,g_out};
				gate_list.push_back(temp_gate);
			}	
		}else if (command.compare(".MODEL") == 0){
			model_name = temp;
		}else if (command.compare(".INPUTS") == 0){
			std::string input_i;
			int i;
			for (i = 1; i<component.size(); i++){
				input_i = component[i];
				if (input_i.compare("CLK") != 0){
					inputs.push_back(input_i);
				}
			}		
		}else if (command.compare(".OUTPUTS") == 0){
			std::string output_i;
			int i;
			for (i = 1; i<component.size(); i++){
				output_i = component[i];
				outputs.push_back(output_i);	
			}	
		}else if (command.compare(".END") == 0){
			return;
		}
    }     
}
void Bliffile::condition(){
	int i;
    for(i=0; i<file_lines.size(); i++){
        std::string line = file_lines[i];
        strcond::trim_spaces(line);
		strcond::to_upper_case(line);
        file_lines[i] = line;
    }
}