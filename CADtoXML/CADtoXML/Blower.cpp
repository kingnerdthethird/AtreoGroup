#include "stdafx.h"
#include "Blower.h"

Blower::Blower(){

}

Blower::~Blower(){

}

void Blower::SetAttributes() {
	blower_id = attributes[1];
	layer = attributes[2];
}

void Blower::SetNodeNum() {
	nodenum = blower_id;
}

void Blower::SetName() {
	name = "Blower " + blower_id;
}

void Blower::SetEverything() {
	SetName();
	SetType();
	SetNodeNum();
	SetIPAddress();
	SetStateChangeTime();
}

string Blower::ReturnBlowerID() {
	return blower_id;
}