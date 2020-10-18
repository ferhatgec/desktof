/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>

#include <Parser.hpp>

void HelpFunction(const char* arg) {
	std::cout << arg << " <argument>\n" <<
	"argument:\n" << "--p : Parse & run (.desktop file)\n" <<
	"--r : Parse (exec) & run (.desktop file)\n";   
}


int main(int argc, char** argv) {
	DesktofParser parser;
	
	if(argc > 1) {
		std::string _arg(argv[1]);
		std::string _file(argv[2]);
		
		if(_arg == "--p")
			parser.Parse(_file);
		else if(_arg == "--r")
			parser.Execute_Run(_file);
			
	} else HelpFunction(argv[0]);
	 
	return 0;
}
