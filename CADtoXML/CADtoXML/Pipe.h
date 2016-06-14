#pragma once
#ifndef PIPE_H
#define PIPE_H
#include "Proponent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Pipe : public Proponent{
protected:
	string source;
	string destination;
	string length;

public:
	Pipe();
	~Pipe();

	void SetAttributes();

	string ReturnSource();
	string ReturnDestination();
	string ReturnLength();
};

#endif