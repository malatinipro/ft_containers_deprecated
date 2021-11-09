#pragma once

#include <iostream>
//Set of standard exceptions 
#include <stdexcept>
//Header providing string stream classes
#include <sstream>

//Allocator
#include <memory>
#include <iterator>
#include <vector>
#include <iterator>
//#include "../srcs/utils.hpp"
//#include "../srcs/vector_iterator.hpp"
//#include "../srcs/reverse_iterator.hpp"

# define DEBUG 1

namespace ft
{
	//https://docs.microsoft.com/fr-fr/cpp/standard-library/allocator-class?view=msvc-170
    template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
	
		//Mettre ft au lieux de std
		//typedef std::vector_iterator<value_type>		iterator;
		//typedef std::vector<value_type>::iterator<value_type>				iterator;

		//typedef std::vector_iterator<const value_type>	const_iterator;
		typedef std::vector<value_type>::iterator<const value_type>			const_iterator;

		typedef std::vector<value_type>::reverse_iterator< iterator >		reverse_iterator;
		typedef std::vector<value_type>::reverse_iterator< const_iterator >	const_reverse_iterator;
		typedef std::vector<value_type>::ptrdiff_t							difference_type;
		typedef size_t														size_type;

		typedef ft::iterator												iterator; 

	private:
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;
		pointer			_data;

		/* Fonctions utiles perso */
		void	setCapacity(size_type capacity)
		{
			_capacity = capacity;
		}
	
	public:
	/*
	** Constructeurs 
	*/
		vector(const allocator_type &alloc = allocator_type()): _size(0), _capacity(0), _allocator(alloc), _data(_allocator.allocate(_capacity))
		{
			if (DEBUG == 1)
			{
				std::cout << "First constructor called" << std::endl;
			}
		}

	/*
	** allocator, it provides a layer of abstraction for the user. 
	** allocator can return constructed object, non-initialized memory space, 
	** destroy an object or release the space. 
	** STL containers use allocator to get memory space and create object.
	*/

	};
}