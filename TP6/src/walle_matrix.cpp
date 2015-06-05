#include "walle_matrix.hpp"

WallE_Matrix::WallE_Matrix(int size) :
	boost::numeric::ublas::matrix<int>(size, size) {
}

WallE_Matrix::iterator WallE_Matrix::begin() {
	return iterator(this);
}

WallE_Matrix::iterator WallE_Matrix::end() {
	return iterator(this, 0, 0);
}

WallE_Matrix::iterator::iterator() :
	matrix(nullptr), xIndex(0), yIndex(0) {
}

WallE_Matrix::iterator::iterator(WallE_Matrix* matrix) :
	matrix(matrix), xIndex(matrix->size1() - 1), yIndex(matrix->size2() - 1) {
}

WallE_Matrix::iterator::iterator(WallE_Matrix* matrix, int xIndex, int yIndex) :
	matrix(matrix), xIndex(xIndex), yIndex(yIndex){
}

WallE_Matrix::iterator::iterator(const iterator& it) :
	matrix(it.getContainer()), xIndex(it.getXIndex()), yIndex(it.getYIndex()) {
}

WallE_Matrix::iterator::iterator(iterator&& it) :
	matrix(it.getContainer()), xIndex(it.getXIndex()), yIndex(it.getYIndex()) {
}

WallE_Matrix::iterator& WallE_Matrix::iterator::operator=(const iterator& other) {
	if(&other != this) {
		matrix = other.getContainer();
		xIndex = other.getXIndex();
		yIndex = other.getYIndex();
	}
	return *this;
}

WallE_Matrix::iterator& WallE_Matrix::iterator::operator=(iterator&& other) {
	if(&other != this) {
		matrix = other.getContainer();
		xIndex = other.getXIndex();
		yIndex = other.getYIndex();
	}
	return *this;
}

WallE_Matrix::iterator::~iterator() {
}

WallE_Matrix::iterator& WallE_Matrix::iterator::operator++() {
	int value = (*matrix)(xIndex, yIndex);
	if(value == EAST) {
		yIndex--;
	} else if(value == NORTH) {
		xIndex--;
	} else {
		xIndex--;
		yIndex--;
	}

	return *this;
}

WallE_Matrix::iterator WallE_Matrix::iterator::operator++(int) {
	int value = (*matrix)(xIndex, yIndex),
	    xIndex = this->xIndex,
		yIndex = this->yIndex;

	if(value == EAST) {
		yIndex--;
	} else if(value == NORTH) {
		xIndex--;
	} else {
		xIndex--;
		yIndex--;
	}

	return iterator(matrix, xIndex, yIndex);
}

int& WallE_Matrix::iterator::operator*() const {
	return (*matrix)(xIndex, yIndex);
}

int* WallE_Matrix::iterator::operator->() const {
	return &( (*matrix)(xIndex, yIndex) );
}

bool operator==(const WallE_Matrix::iterator& lit, const WallE_Matrix::iterator& rit) {
	return (lit.getContainer() == rit.getContainer())
		&& (lit.getXIndex()    == rit.getXIndex())
		&& (lit.getYIndex()    == rit.getYIndex());
}

bool operator!=(const WallE_Matrix::iterator& lit, const WallE_Matrix::iterator& rit) {
	return !(lit == rit);
}

int WallE_Matrix::iterator::getXIndex() const {
	return xIndex;
}

int WallE_Matrix::iterator::getYIndex() const {
	return yIndex;
}

WallE_Matrix* WallE_Matrix::iterator::getContainer() const {
	return matrix;
}
