#include "stdafx.h"
#include "Diverter.h"

Diverter::Diverter(){

}

Diverter::~Diverter(){

}

void Diverter::SetAttributes(){
	diverter_id = attributes[7];
}

void Diverter::SetName() {
	name = "Pevco Diverter " + diverter_id;
}

void Diverter::SetType() {
	type = "DIVERTER";
}

void Diverter::SetNodeNum() {
	nodenum = diverter_id;
}

void Diverter::SetEverything() {
	SetType();
	SetName();
	SetNodeNum();
	SetIPAddress();
	SetStateChangeTime();
}

string Diverter::ReturnDiverterID() {
	return diverter_id;
}