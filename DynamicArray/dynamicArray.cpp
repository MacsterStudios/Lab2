#include "dynamicArray.h"


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
	int ancienneCapacite = capacite;
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