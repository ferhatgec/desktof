/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>


class DesktofParser {
	std::string name;
	std::string icon;
	std::string exec;
	std::string _term;
	
	bool term;
public:
	void Parse(std::string file);
	void Run(std::string exec);
	void Execute_Run(std::string file);
};


#endif // PARSER_HPP
