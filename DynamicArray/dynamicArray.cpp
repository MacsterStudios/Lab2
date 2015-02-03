#include "dynamicArray.h"


DynamicArray::DynamicArray(const DynamicArray &_source) :
	capacite(_source.getCapacite()),
	tabElements(new int[_source.getCapacite()])
{
	for (unsigned int i = 0; i < capacite; i++){
		tabElements[i] = _source.getElement(i);
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray &_source){
	if(&_source != this){
		delete[] tabElements;
		capacite = _source.capacite;
		tabElements = new int[_source.capacite];
		for (unsigned int i = 0; i < capacite; i++){
			tabElements[i] = _source.getElement(i);
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray &_rhs) const{
	bool returnVal = true;
	if (capacite != _rhs.getCapacite()) returnVal = false;
	for (unsigned int i = 0; i < capacite; i++){
		if (tabElements[i] != _rhs.getElement(i)) returnVal = false;
	}
	return returnVal;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray &_rhs){
	int capaciteDepart = capacite;
	setCapacite(capacite + _rhs.getCapacite());
	for (unsigned int i = 0; i < _rhs.getCapacite(); i++){
		tabElements[i + capaciteDepart] = _rhs.getElement(i);
	}

	return *this;
}

unsigned int DynamicArray::getCapacite() const{
	return capacite;
}

int DynamicArray::getElement(const unsigned int _index) const{
	if (_index >= capacite) throw std::out_of_range("Élément hors tableau");
	return tabElements[_index];
}

void DynamicArray::setCapacite(const unsigned int _capacite){
	if (_capacite < 1) throw std::invalid_argument("Le tableau doit avoir une capacité d'au moins 1.");
	int *ancienTableau = tabElements;
	unsigned int ancienneCapacite = capacite;
	capacite = _capacite;
	tabElements = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++){
		if (i < ancienneCapacite){
			tabElements[i] = ancienTableau[i];
		}
		else{
			tabElements[i] = 0;
		}
	}
	delete ancienTableau;
}

void DynamicArray::setElement(const unsigned int _index, const int _valeur){
	//if (_index + 1 > capacite) throw std::runtime_error("La pile est trop petite; l'index recherché n'éxiste pas.");
	if (_index + 1 > capacite){
		setCapacite(_index + 1);
	}
	tabElements[_index] = _valeur;
	
	
}