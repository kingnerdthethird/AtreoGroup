#include "stdafx.h"
#include "Proponent.h"

Proponent::Proponent(){

}

Proponent::~Proponent(){

}

void Proponent::RetrieveAttributes(vector<string> values) {
	for (int i = 0; i < values.size(); i++) {
		attributes.push_back(values[i]);
	}
}

void Proponent::SetName() {
	name = attributes[0];
}

void Proponent::SetType() {
	if (name.find("Blower") != string::npos) {
		type = "BLOWER";
	}
	else if (name.find("Device") != string::npos) {
		type = "STATION";
	}
	else if (name.find("Diverter") != string::npos) {
		type = "DIVERTER";
	}
	else if (name.find("Pipe") != string::npos) {
		type = "PIPE";
	}
	else {
		type = "UNKNOWN";
	}
}

void Proponent::SetEverything() {
	SetType();
	SetName();
	
}

string Proponent::PrintName() {
	return "\t\t<NAME>" + name + "</NAME>\n";
}

string Proponent::PrintType() {
	return "\t\t<TYPE>" + type + "</TYPE>\n";
}

string Proponent::PrintEverything() {
	string output;
	output += PrintName();
	output += PrintType();
	return output;
}

string Proponent::ReturnName() {
	return name;
}

string Proponent::ReturnType() {
	return type;
}

vector<string> Proponent::ReturnAttributes() {
	return attributes;
}