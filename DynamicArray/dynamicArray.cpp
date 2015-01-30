#include "dynamicArray.h"


unsigned int DynamicArray::getCapacite() const{
	return capacite;
}

int DynamicArray::getElement(const unsigned int _index) const{
	return tabElements[_index];
}

void DynamicArray::setCapacite(const unsigned int _capacite){
	if (_capacite < 1) throw std::runtime_error("Le tableau doit avoir une capacité d'au moins 1.");
	int *ancienTableau = tabElements;
	int ancienneCapacite = capacite;
	capacite = _capacite;
	tabElements = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++){
		if (i < capacite){
			tabElements[i] = ancienTableau[i];
		}
		else{
			tabElements[i] = 0;
		}
	}
	delete ancienTableau;
}

void DynamicArray::setElement(const unsigned int _index, const int _valeur){
	if (_index + 1 > capacite) throw std::runtime_error("La pile est trop petite; l'index recherché n'éxiste pas.");
	tabElements[_index] = _valeur;
}