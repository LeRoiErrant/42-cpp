#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <deque>
# include <vector>
# include <sstream>
# include <iomanip>
# include <limits>

class Span {
	private:
		unsigned int		_MaxStorage;
		unsigned int		_StorageLeft;
		std::vector<int>	_Storage;
		Span( void );

		static const bool	displayVerbose = true;
		static void			Verbose( std::string msg );
	public:
		Span( unsigned int N );
		Span( Span const & src );
		~Span( void );

		Span	&operator=( Span const & src );
		int		&operator[]( unsigned int const & i);

		class MaxStorageReachedException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughNumbersException : public std::exception {
			virtual const char* what() const throw();
		};

		unsigned int	getMaxStorage( void ) const;
		unsigned int	getSize( void ) const;

		void			addNumber( int n );
		
		template<typename InputIterator>
		void			addNumbers( InputIterator begin, InputIterator end ) {
			
			unsigned int	d = std::distance(begin, end);

			if ( d > this->_StorageLeft )
				throw Span::MaxStorageReachedException();
			this->_Storage.insert(this->_Storage.end(), begin, end);
			this->_StorageLeft -= d;
		}


		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );


};

#endif
