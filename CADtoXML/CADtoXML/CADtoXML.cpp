#include "stdafx.h"
#include "Proponent.h"
#include "Node.h"
#include "Pipe.h"
#include "Blower.h"
#include "Device.h"
#include "Diverter.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

ofstream output;
vector<Node *> master_node_list;
vector<Pipe *> master_pipe_list;
string input_default;
string default_location;
int number_of_zones;

void SetUpFile(int station, int velocity, int timedelay);
void EndFile();
void RetrieveValues();
void PrintToFile();
void FindParents();
void FindChildren();
void AddToLists(vector<string> values);
void AddToNodes(vector<string> values);
void AddToPipes(vector<string> values);

int main(){
	cout << "Please enter desired name of output file: ";
	string file_name;
	cin >> file_name;
	cout << "File will be named: " << file_name << ".xml" << endl;
	output.open(file_name + ".xml");
	cout << "Please enter desired station for Master: ";
	int station;
	cin >> station;
	cout << "Please enter desired velocity for simulation: ";
	int velocity;
	cin >> velocity;
	cout << "Please enter desired time delay for simulation: ";
	int timedelay;
	cin >> timedelay;
	cout << "Please enter desired default station NodeNum: ";
	cin >> input_default;
	cout << "Please enter desired default location: ";
	cin >> default_location;
	cout << "Please enter the number of zones: ";
	cin >> number_of_zones;

	cout << "Setting up file..." << endl;
	SetUpFile(station, velocity, timedelay);
	cout << "File is now set up." << endl;
	
	RetrieveValues();
	FindChildren();
	FindParents();
	PrintToFile();

	EndFile();
	output.close();
	cout << "File is now completed." << endl;
	system("PAUSE");
	return 0;
}

void SetUpFile(int station, int velocity, int timedelay) {
	if (output.is_open()) {
		output << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		output << "<CONFIG>" << endl;
		output << "\t<STATIONNODENUM>" << station << "</STATIONNODENUM>" << endl;
		output << "\t<VELOCITY>" << velocity << "</VELOCITY>" << endl;
		output << "\t<TIMESCALE>" << timedelay << "</TIMESCALE>" << endl;
		output << "\t<NODE>" << endl;
		output << "\t\t<NAME>Master</NAME>" << endl;
		output << "\t\t<NODENUM>0</NODENUM>" << endl;
		output << "\t\t<IPADDR>0.0.0.0</IPADDR>" << endl;
		output << "\t\t<LOCATION>Master</LOCATION>" << endl;
		output << "\t\t<ZONE>0</ZONE>" << endl;
		output << "\t\t<PARENT>0</PARENT>" << endl;
		output << "\t</NODE>" << endl;
	}
}

void EndFile() {
	output << "</CONFIG>";
}

void RetrieveValues() {
	//ifstream file("Transvac Basementcsv.csv");
	ifstream file("Tristar Layout-test.csv");
	string value;
	vector<string> values;
	while (file.good()) {

		for (int i = 0; i < 10; i++) {
			getline(file, value, ',');
			values.push_back(value);
		}
		getline(file, value, '\n');
		values.push_back(value);
		AddToLists(values);
		values.clear();
	}
}

void PrintToFile() {
	for (int i = 0; i < master_node_list.size(); i++) {
		output << master_node_list[i]->PrintEverything();
	}
}

void AddToLists(vector<string> values) {
	if (values[0].find("Pipe") != string::npos) {
		AddToPipes(values);
	}
	else {
		AddToNodes(values);
	}
}

void FindChildren() {
	for (int i = 0; i < master_pipe_list.size(); i++) {
		for (int j = 0; j < master_node_list.size(); j++) {
			if (master_pipe_list[i]->ReturnSource().compare(master_node_list[j]->ReturnNodeNum()) == 0 && master_node_list[j]->ReturnType().compare("STATION") != 0) {
				master_node_list[j]->SetChildren(master_pipe_list[i]->ReturnDestination());
			}
		}
	}
}

void FindParents() {
	for (int i = 0; i < master_pipe_list.size(); i++) {
		for (int j = 0; j < master_node_list.size(); j++) {
			if (master_pipe_list[i]->ReturnDestination().compare(master_node_list[j]->ReturnNodeNum()) == 0 && master_node_list[j]->ReturnType().compare("BLOWER") != 0) {
				master_node_list[j]->SetParent(master_pipe_list[i]->ReturnSource(), master_pipe_list[i]->ReturnLength());
			}
		}
	}
}

void AddToPipes(vector<string> values) {
	Pipe * pipe = new Pipe();
	pipe->RetrieveAttributes(values);
	pipe->SetAttributes();
	master_pipe_list.push_back(pipe);
}

void AddToNodes(vector<string> values) {
	if (values[0].find("Name") != string::npos) {

	}
	else if (values[0].find("Blower") != string::npos) {
		Blower * node = new Blower();
		node->RetrieveAttributes(values);
		node->SetAttributes();
		node->SetEverything();
		node->SetLocation(default_location);
		node->SetDefault(input_default);
		node->SetZone(number_of_zones);
		master_node_list.push_back(node);
	}
	else if (values[0].find("Device") != string::npos) {
		Device * node = new Device();
		node->RetrieveAttributes(values);
		node->SetAttributes();
		node->SetEverything();
		node->SetDefault(input_default);
		node->SetZone(number_of_zones);
		master_node_list.push_back(node);
	}
	else if (values[0].find("Diverter") != string::npos) {
		Diverter * node = new Diverter();
		node->RetrieveAttributes(values);
		node->SetAttributes();
		node->SetEverything();
		node->SetLocation(default_location);
		node->SetDefault(input_default);
		node->SetZone(number_of_zones);
		master_node_list.push_back(node);
	}
	else {
		Node * node = new Node();
		node->RetrieveAttributes(values);
		node->SetAttributes();
		node->SetEverything();
		node->SetDefault(input_default);
		node->SetLocation(default_location);
		node->SetZone(number_of_zones);
		master_node_list.push_back(node);
	}

}