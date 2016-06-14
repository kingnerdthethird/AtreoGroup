#pragma once
#ifndef PROPONENT_H
#define PROPONENT_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Proponent{
protected:
	string name;
	string type;

	vector<string> attributes;

public:
	Proponent();
	~Proponent();

	void RetrieveAttributes(vector<string>);
	void SetName();
	void SetType();
	void SetEverything();

	string PrintName();
	string PrintType();
	string PrintEverything();

	string ReturnName();
	string ReturnType();

	vector<string> ReturnAttributes();
};

#endif