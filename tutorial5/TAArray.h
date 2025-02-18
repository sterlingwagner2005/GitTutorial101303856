#ifndef TAARRAY_H
#define TAARRAY_H

#include "defs.h"
#include "TextArea.h"

#include <string>

class TAArray{
	private:
		TextArea **textAreas;
		int numTextAreas;
	
	public:
		TAArray();
		~TAArray();

		TextArea** getArray(){return this->textAreas;}
		TextArea* get(int index) const;
		TextArea* get(std::string id) const;
		int getSize() const {return this->numTextAreas;}
		
		bool add(TextArea* textarea);
		bool add(TextArea* textarea, int index);
		
		TextArea* remove(std::string id);
		TextArea* remove(int index);
};

#endif
