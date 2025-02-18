#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
	private:
		int r, g, b;
	public:
		RGB(int r, int g, int b);
		RGB(CuColour colour);
		RGB();
	
		int getR() const {return this->r;};
		int getG() const {return this->g;};
		int getB() const {return this->b;};
		CuColour getColour() const;
		static RGB WHITE();
		static RGB BLACK();
		static RGB RED();
		static RGB GREEN();
		static RGB BLUE();
		
		void setR(int r);
		void setG(int g);
		void setB(int b);
		void setColour(CuColour colour);
};

#endif
