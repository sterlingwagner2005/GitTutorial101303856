#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string text, RGB fill, RGB border){
	this->dimensions.x = x;
	this->dimensions.y = y;
	this->dimensions.width = width;
	this->dimensions.height = height;
	this->id = id;
	this->text = text;
	this->fill = fill;
	this->border = border;
}
TextArea::TextArea(Rectangle rectangle, std::string id, std::string text, RGB fill, RGB border){
	this->dimensions = rectangle;
	this->id = id;
	this->text = text;
	this->fill = fill;
	this->border = border;
	this->fill = RGB::WHITE();
	this->border = RGB::BLACK();
}
TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string text){
	this->dimensions.x = x;
	this->dimensions.y = y;
	this->dimensions.width = width;
	this->dimensions.height = height;
	this->id = id;
	this->text = text;
	this->fill = RGB::WHITE();
	this->border = RGB::BLACK();
}
TextArea::TextArea(Rectangle rectangle, std::string id, std::string text){
	this->dimensions = rectangle;
	this->id = id;
	this->text = text;
}
TextArea::TextArea(){
	this->dimensions.x = 0;
	this->dimensions.y = 0;
	this->dimensions.width = 0;
	this->dimensions.height = 0;
	this->id = "";
	this->text = "";
	this->fill = RGB::WHITE();
	this->border = RGB::BLACK();
}
TextArea::TextArea(const TextArea& textarea){
	this->dimensions = textarea.getDimensions();
	this->id = textarea.getId();
	this->text = "";
	this->fill = textarea.getFill();
	this->border = textarea.getBorder();
}

bool TextArea::overlaps(const TextArea& ta) const{
	return this->dimensions.overlaps(ta.getDimensions());
}

void TextArea::print() const{
	std::cout << "TextArea id:        " << this->id << std::endl;
	std::cout << "Preferred Location: " << this->dimensions.x << ", " << this->dimensions.y << std::endl;
	std::cout << "Size:               " << this->dimensions.x << ", " << this->dimensions.y << std::endl;
	std::cout << "Text:               " << this->text << std::endl;
	
}
