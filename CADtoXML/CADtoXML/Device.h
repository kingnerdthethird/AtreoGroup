#pragma once
#ifndef DEVICE_H
#define DEVICE_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Device : public Node {
protected:
	string device_id;
	string devicelocation_0;
	string devicelocation_1;
	string devicelocation_2;
	string device_location;

public:
	Device();
	~Device();

	void SetAttributes();
	void SetNodeNum();
	void SetName();
	void SetLocation();
	void SetType();
	void SetEverything();

	string ReturnDeviceID();
	string ReturnDeviceLocation();
};

#endif