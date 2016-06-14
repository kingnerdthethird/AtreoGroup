#include "stdafx.h"
#include "Device.h"

Device::Device(){

}

Device::~Device(){

}

void Device::SetAttributes() {
	device_id = attributes[3];
	devicelocation_0 = attributes[4];
	devicelocation_1 = attributes[5];
	devicelocation_2 = attributes[6];
}

void Device::SetNodeNum() {
	nodenum = device_id;
}

void Device::SetName() {
	name = "Station " + device_id + " " + devicelocation_0;
}

void Device::SetLocation() {
	device_location = devicelocation_0 + " " + devicelocation_1 + " " + devicelocation_2;
	location = device_location;
	has_location = true;
}

void Device::SetType() {
	type = "STATION";
}

void Device::SetEverything() {
	SetType();
	SetName();
	SetNodeNum();
	SetIPAddress();
	SetStateChangeTime();
	SetLocation();
}

string Device::ReturnDeviceID() {
	return device_id;
}

string Device::ReturnDeviceLocation() {
	return device_location;
}