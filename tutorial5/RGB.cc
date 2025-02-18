#include "RGB.h"

RGB::RGB(int r, int g, int b){
	this->r = r;
	this->g = g;
	this->b = b;
}

RGB::RGB(CuColour colour){
	this->b = (int)(colour & 0xFF);
	this->g = (int)((colour >> 8) & 0xFF);
	this->r = (int)((colour >> 16) & 0xFF);
}

RGB::RGB(){
	this->r = 0;
	this->g = 0;
	this->b = 0;
}


CuColour RGB::getColour() const {
	return ((CuColour)r << 16) | ((CuColour)g << 8) | (CuColour)b;
}

RGB RGB::WHITE() {
	return RGB(255, 255, 255);
}

RGB RGB::BLACK() {
	return RGB(0, 0, 0);
}

RGB RGB::RED() {
	return RGB(255, 0, 0);
}

RGB RGB::GREEN() {
	return RGB(0, 255, 0);
}

RGB RGB::BLUE() {
	return RGB(0, 0, 255);
}
		
void RGB::setR(int r){this->r = r;}
void RGB::setG(int g){this->g = g;}
void RGB::setB(int b){this->b = b;}

void RGB::setColour(CuColour colour){
	this->b = (int)(colour & 0xFF);
	this->g = (int)((colour >> 8) & 0xFF);
	this->r = (int)((colour >> 16) & 0xFF);
}
