/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include <Parser.hpp>

#include <FileSystemPlusPlus.h>
#include <StringTools.h>
#include <ExecutePlusPlus.hpp>

/* 
* Template Desktop file 
	[Desktop Entry]
	Name=Fegeya Gemini
	Exec=gemini
	Icon=/usr/share/pixmaps/gemini/gemini.png
	Type=Application
	Categories=GTK;GNOME;TerminalEmulator;
	Terminal=false
*/

void 
DesktofParser::Parse(std::string file) {
	name = fsplusplus::FindStringWithReturn(file, "Name=");
	icon = fsplusplus::FindStringWithReturn(file, "Icon=");
	exec = fsplusplus::FindStringWithReturn(file, "Exec=");
	_term = fsplusplus::FindStringWithReturn(file, "Terminal=");
	 					
	if(name != "null")
		name = stringtools::EraseAllSubString(name, "Name=");
	
	if(icon != "null")
		icon = stringtools::EraseAllSubString(icon, "Icon=");
	
	if(exec != "null")
		exec = stringtools::EraseAllSubString(exec, "Exec=");
	
	if(_term != "null")
		if(stringtools::EraseAllSubString(_term, "Terminal=") == "false")
			term = false;
		else
			term = true;
	
	
	if(exec != "null")
		exec = stringtools::EraseAllSubString(exec, "\n");
		
	Run(exec);
}

void
DesktofParser::Run(std::string exec) {
	ExecutePlusPlus _run;
	
	_run.ExecuteName("Desktof");
	
	_run.RunFunction(exec);
}


void
DesktofParser::Execute_Run(std::string file) {
	exec = fsplusplus::FindStringWithReturn(file, "Exec=");
	
	if(exec != "null")
		exec = stringtools::EraseAllSubString(exec, "Exec=");
	
	if(exec != "null")
		exec = stringtools::EraseAllSubString(exec, "\n");
	
	ExecutePlusPlus _run;
	
	_run.ExecuteName("Desktof");
	
	_run.RunFunction(exec);
}
