#ifndef _WALLE_MATRIX_HPP_
#define _WALLE_MATRIX_HPP_

#define EAST       0
#define NORTH      1
#define NORTH_EAST 2

#include<boost/numeric/ublas/matrix.hpp>

class WallE_Matrix : public boost::numeric::ublas::matrix<int> {
public:
	explicit WallE_Matrix(int size);

	class iterator {
	public:
		typedef std::ptrdiff_t difference_type;
		typedef int  value_type;
		typedef int& reference;
		typedef int* pointer;
		typedef std::forward_iterator_tag  iterator_category;

		iterator();
		explicit iterator(WallE_Matrix* matrix);
		iterator(WallE_Matrix* matrix, int xIndex, int yIndex);

		// Rule of five
		iterator(const iterator& it);
		iterator(iterator&& it);
		iterator& operator=(const iterator& it);
		iterator& operator=(iterator&& it);
		~iterator() __attribute__((const));

		iterator& operator++();
		iterator operator++(int);

		int& operator*() const;
		int* operator->() const;

		friend bool operator==(const iterator& lit, const iterator& rit) __attribute__((pure));
		friend bool operator!=(const iterator& lit, const iterator& rit) __attribute__((pure));

		int getXIndex() const __attribute__((pure));
		int getYIndex() const __attribute__((pure));
		WallE_Matrix* getContainer() const __attribute__((pure));

	private:
		WallE_Matrix* matrix;
		int xIndex;
		int yIndex;
	};

	iterator begin();
	iterator end();

};

#endif
