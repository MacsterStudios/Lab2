#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:

	DynamicArray(unsigned int _capacite = 100) :
		capacite(_capacite)
		{
		tabElements = new int[capacite];
		}

	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int _index) const;
	unsigned int getCapacite() const;
	void setCapacite(unsigned int _capacite);

private:

	int *tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_