#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_
#include <stdexcept>

class DynamicArray
{

public:

	DynamicArray(unsigned int _capacite = 100) :
		capacite(_capacite)
		{
		if (_capacite < 1) throw std::runtime_error("Le tableau doit avoir une capacit� d'au moins 1.");
		tabElements = new int[capacite];
		for (unsigned int i = 0; i < capacite; i++){
			tabElements[i] = 0;
			}
		}

	void setElement(const unsigned int _index, const int _valeur);
	int getElement(const unsigned int _index) const;
	unsigned int getCapacite() const;
	void setCapacite(const unsigned int _capacite);

private:

	int *tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_