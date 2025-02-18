#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "defs.h"
#include "RGB.h"

#include <string>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

class TextArea {
	private:
		Rectangle dimensions;
		std::string text;
		std::string id;
		RGB fill, border;
		
	public:
		TextArea(int x, int y, int width, int height, std::string id, std::string text, RGB fill, RGB border);
		TextArea(Rectangle rectangle, std::string id, std::string text, RGB fill, RGB border);
		TextArea(int x, int y, int width, int height, std::string id, std::string text);
		TextArea(Rectangle rectangle, std::string id, std::string text);
		TextArea();
		TextArea(const TextArea& textarea);

		Rectangle getDimensions() const {return this->dimensions;}
		std::string getText() const {return this->text;}
		std::string getId() const {return this->id;}
		RGB getFill() const {return this->fill;}
		RGB getBorder() const {return this->border;}
		
		void setDimensions(Rectangle dimensions){this->dimensions = dimensions;}
		void setText(std::string text){this->text = text;}
		void setId(std::string id){this->id = id;}
		void setFill(RGB fill){this->fill = fill;}
		void setBorder(RGB border){this->border = border;}
		
		void draw(Display *display, Window win, GC gc, int x, int y){}
		bool overlaps(const TextArea& ta) const;
		
		void print() const;
		
};

#endif
