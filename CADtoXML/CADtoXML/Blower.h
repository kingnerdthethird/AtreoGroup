#pragma once
#ifndef BLOWER_H
#define BLOWER_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Blower : public Node {
protected:
	string blower_id;

public:
	Blower();
	~Blower();

	void SetAttributes();
	void SetNodeNum();
	void SetName();
	void SetEverything();

	string ReturnBlowerID();
};

#endif