#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <list>
#include <iterator>
#include <iostream>
#include <cstddef>

using std::list;
using std::cout;
using std::endl;

class Digrafo{
	private:
		int vertices;
		int aristas;
		list<int> *adyacentes;
public:
	Digrafo();
	Digrafo(const Digrafo &otro);
	~Digrafo();
	int getVertices() const;
	void setVertices( int vertices);
	int getAristas() const;
	list<int> getAdyacentes(int v) const;
	void agregarArista(int v, int w);
	void imprimir();
};

Digrafo::Digrafo() : vertices(0), aristas(0), adyacentes(nullptr){
	
	}

Digrafo::Digrafo(const Digrafo &otro){
	vertices = otro.vertices;
	aristas = otro.aristas;
	if (vertices == 0) {
		adyacentes = nullptr;
	}
	else {
		adyacentes = new list<int>[vertices];
		for (int i = 0; i < vertices; i++){
			list<int>::iterator it;
			for (it = otro.adyacentes[i].begin(); it != otro.adyacentes[i].end(); it++)
				adyacentes[i].push_back(*it);
		}
	}
}

Digrafo::~Digrafo(){
	if (adyacentes != nullptr) {
		delete[] adyacentes;
	}
}

int Digrafo::getVertices() const{
	return vertices;
}

void Digrafo::setVertices(int vertices) {
	if (this->vertices == 0){
		this->vertices = vertices;
		adyacentes = new list<int>[vertices];
	}
}

int Digrafo::getAristas() const{
	return aristas;
}

void Digrafo::agregarArista(int v, int w){
	adyacentes[v].push_front(w);
	aristas++;
}

list<int> Digrafo::getAdyacentes(int v) const{
	return adyacentes[v];
}

void Digrafo::imprimir(){
	for (int i = 0; i < vertices; i++){
	cout << i << ": ";
	list<int>::iterator it;
	for (it = adyacentes [i].begin(); it != adyacentes[i].end(); it++)
		cout << *it << ' ';
	cout << endl;
}
}

#endif 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

