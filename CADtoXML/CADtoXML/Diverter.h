#pragma once
#ifndef DIVERTER_H
#define DIVERTER_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Diverter : public Node {
protected:
	string diverter_id;
public:
	Diverter();
	~Diverter();

	void SetAttributes();
	void SetName();
	void SetType();
	void SetNodeNum();
	void SetEverything();

	string ReturnDiverterID();
};

#endif