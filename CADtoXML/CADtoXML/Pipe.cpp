#include "stdafx.h"
#include "Pipe.h"

Pipe::Pipe(){

}

Pipe::~Pipe(){

}

void Pipe::SetAttributes() {
	source = attributes[8];
	destination = attributes[9];
	length = attributes[10];
}

string Pipe::ReturnSource() {
	return source;
}

string Pipe::ReturnDestination() {
	return destination;
}

string Pipe::ReturnLength() {
	return length;
}