#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstring>

template< typename T >
class Array {
	private:

		int	_size;
		T*	_array;

	public:
		
		Array<T>( void ) : _size(0), _array(NULL) {
			std::cout << "Void Constructor called" << std::endl;
		}

		Array<T>( unsigned int n ) : _size(n) {
			std::cout << "Size Constructor called" << std::endl;
			this->_array = new T[this->_size];
			std::memset(this->_array, 0, _size);
		}

		Array<T>( Array const & src ) : _size(src.size()) {
			std::cout << "Copy Constructor called" << std::endl;
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++) {
				this->_array[i] = src._array[i];
			}
		}
		
		~Array<T>( void ) {
			std::cout << "Destructor called" << std::endl;
			if (this->_size > 0)
				delete [] this->_array;
		}

		Array<T>	&operator=( Array<T> const & src ) {
			std::cout << "Assignation Operator Called" << std::endl;
			if (this->_size > 0)
				delete [] this->_array;
			this->_size = src.size();
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++) {
				this->_array[i] = src[i];
			}
			return (*this);
		}

		T	&operator[]( int const & i) const {
			if (i >= this->_size || i < 0)
				throw std::out_of_range("Incorrect index");
			return this->_array[i];
		}

		int	size( void ) const {
			return (this->_size);
		}


};



#endif
