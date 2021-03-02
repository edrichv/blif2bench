#include "../include/Str_cond.h"

void strcond::reformat_line(std::string &line) {
	strcond::trim_spaces(line);
	strcond::to_upper_case(line);
}

void strcond::trim_spaces(std::string &line) {
	std::stringstream ss;
	char prevchar = ' ';
	for (int i = 0; i < line.length(); i++) {
		char thischar = line.at(i);
		if (thischar == '\t') {
			thischar = ' ';
			ss << thischar;
		}
		else if (prevchar == ' ' && thischar == ' ');
		else if (thischar != '\n' && thischar != '\r') ss << thischar;
		prevchar = thischar;
	}
	line = ss.str();
}
void strcond::to_upper_case(std::string &line) {
	std::transform(line.begin(), line.end(), line.begin(), ::toupper);
}