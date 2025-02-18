#include "TAArray.h"

TAArray::TAArray(){
	this->textAreas = new TextArea*[MAX_COMPONENTS];
	this->numTextAreas = 0;
}

TAArray::~TAArray(){
	for(int i = 0; i < this->numTextAreas; i++){
		delete textAreas[i];
	}
	delete[] textAreas;
}

TextArea* TAArray::get(std::string id) const {
    for (int i = 0; i < this->numTextAreas; i++) {
        std::string currentId = this->textAreas[i]->getId();
        if (currentId.compare(id) == 0) {
            return this->textAreas[i];
        }
    }

    return nullptr;
}


TextArea* TAArray::get(int index) const {
    if (this->numTextAreas > 0 && index >= 0 && index < this->numTextAreas) {
        return this->textAreas[index];
    }
    return nullptr;
}


bool TAArray::add(TextArea* textarea) {
    if (numTextAreas < MAX_COMPONENTS) {
        this->textAreas[this->numTextAreas] = textarea;  // Use the same pointer
        this->numTextAreas++;
        std::cout << "Added TextArea with ID: " << textarea->getId() << std::endl;
        return true;
    }
    return false;
}


bool TAArray::add(TextArea* textarea, int index) {
    if (this->numTextAreas < MAX_COMPONENTS && index <= this->numTextAreas) {
        // Shift all elements to the right to make space
        for (int i = this->numTextAreas; i > index; i--) {
            this->textAreas[i] = this->textAreas[i - 1];
        }

        // Instead of making a deep copy, directly store the original pointer
        this->textAreas[index] = textarea;

        // Increase the count of text areas
        this->numTextAreas++;

        return true;
    }
    return false;
}


TextArea* TAArray::remove(std::string id) {
    int index = -1;

    for (int i = 0; i < this->numTextAreas; i++) {
        if (id.compare(this->textAreas[i]->getId()) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return nullptr;
    }

    TextArea* temp = textAreas[index];
    delete textAreas[index];

    for (int i = index; i < this->numTextAreas - 1; i++) {
        this->textAreas[i] = this->textAreas[i + 1];
    }

    this->textAreas[this->numTextAreas - 1] = nullptr;
    this->numTextAreas--;

    return temp;
}


TextArea* TAArray::remove(int index) {
    if (index < this->numTextAreas) {
        TextArea* temp = textAreas[index];
        delete textAreas[index];

        for (int i = index; i < this->numTextAreas - 1; i++) {
            this->textAreas[i] = this->textAreas[i + 1];
        }

        this->numTextAreas--;
        return temp;
    }
    return nullptr;
}
