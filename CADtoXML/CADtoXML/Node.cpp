#include "stdafx.h"
#include "Node.h"

Node::Node(){

}

Node::~Node(){

}

void Node::SetAttributes(){
	layer = attributes[2];
}

void Node::SetNodeNum(){
	nodenum = "0";
}

void Node::SetIPAddress() {
	ip_address = "0.0.0.0";
}

void Node::SetDefault(string input_default) {
	default_variable = input_default;
}

void Node::SetLocation(string site) {
	location = site;
	has_location = true;
}

void Node::SetZone(int num_zones) {
	for (int i = 1; i <= num_zones; i++) {
		stringstream stream;
		string number;
		stream << i;
		number = stream.str();
		if (layer.find(number) != string::npos) {
			zone = number;
			has_zone = true;
			break;
		}
	}
}

void Node::SetParent(string parent, string distance) {
	parent_nodenum = parent;
	parent_distance = distance;
	has_parent = true;
}

void Node::SetStateChangeTime() {
	state_change_time = "0";
}

void Node::SetChildren(string child) {
	children.push_back(child);
	has_children = true;
}

void Node::SetEverything() {
	SetType();
	SetName();
	SetNodeNum();
	SetIPAddress();
	SetStateChangeTime();
}

string Node::PrintNodeNum() {
	return "\t\t<NODENUM>" + nodenum + "</NODENUM>\n";
}

string Node::PrintIPAddress() {
	return "\t\t<IPADDR>" + ip_address + "</IPADDR>\n";
}

string Node::PrintDefault() {
	if (nodenum.compare(default_variable) == 0) {
		return "\t\t<DEFAULT>" + default_variable + "</DEFAULT>\n";
	}
	else {
		return "";
	}
}

string Node::PrintLocation() {
	if (has_location) {
		return "\t\t<LOCATION>" + location + "</LOCATION>\n";
	}
	else {
		return "";
	}
}

string Node::PrintZone() {
	if (has_zone) {
		return "\t\t<ZONE>" + zone + "</ZONE>\n";
	}
	else {
		return "";
	}
}

string Node::PrintParentNodeNum() {
	if (has_parent) {
		return "\t\t<PARENT>" + parent_nodenum + "</PARENT>\n";
	}
	else {
		return "";
	}
}

string Node::PrintParentDistance() {
	if (has_parent) {
		return "\t\t<DISTANCE>" + parent_distance + "</PARENT>\n";
	}
	else {
		return "";
	}
}

string Node::PrintStateChangeTime() {
	return "\t\t<STATECHANGETIME>" + state_change_time + "</STATECHANGETIME>\n";
}

string Node::PrintChildren() {
	string output;
	if (has_children) {
		for (int i = 0; i < children.size(); i++) {
			stringstream converter;
			string portnum;
			converter << i + 1;
			portnum = converter.str();

			output += "\t\t<CHILDREN>\n";
			output += "\t\t\t<NODENUM>";
			output += children[i];
			output += "</NODENUM>\n";
			output += "\t\t\t<PORTNUM>";
			output += portnum;
			output += "</PORTNUM>\n";
			output += "\t\t</CHILDREN>\n";
		}
		return output;
	}
	else {
		return "";
	}
}

string Node::PrintEverything() {
	string output;
	output += "\t<NODE>\n";
	output += PrintName();
	output += PrintDefault();
	output += PrintNodeNum();
	output += PrintIPAddress();
	output += PrintLocation();
	output += PrintType();
	output += PrintZone();
	output += PrintParentNodeNum();
	output += PrintParentDistance();
	output += PrintStateChangeTime();
	output += PrintChildren();
	output += "\t</NODE>\n";
	return output;
}

string Node::ReturnNodeNum() {
	return nodenum;
}

string Node::ReturnIPAddress() {
	return ip_address;
}

string Node::ReturnDefault() {
	return default_variable;
}

string Node::ReturnLocation() {
	return location;
}

string Node::ReturnLayer() {
	return layer;
}

string Node::ReturnZone() {
	return zone;
}

string Node::ReturnParentNodeNum() {
	return parent_nodenum;
}

string Node::ReturnParentDistance() {
	return parent_distance;
}

string Node::ReturnStateChangeTime() {
	return state_change_time;
}

vector<string> Node::ReturnChildren() {
	return children;
}

bool Node::ReturnHasParent() {
	return has_parent;
}

bool Node::ReturnHasChildren() {
	return has_children;
}

bool Node::ReturnHasLocation() {
	return has_location;
}

bool Node::ReturnHasZone() {
	return has_zone;
}