#include "Span.hpp"

void	Span::Verbose( std::string msg ) {
	if (Span::displayVerbose)
		std::cout << msg << std::endl;
}

Span::Span( void ) : _MaxStorage(0) {
	Span::Verbose("Span Base Constructor called");
}

Span::Span( unsigned int N ) : _MaxStorage(N), _StorageLeft(N), _Storage(0) {
	std::stringstream	ss;

	Span::Verbose("Span Size Initialization Constructor called");
	ss << "Max Storage initialized at: " << this->_MaxStorage << "\nStorage Size: " << this->_Storage.size();
	Span::Verbose(ss.str());
}

Span::Span( Span const & src ) : _MaxStorage(src.getMaxStorage()), _StorageLeft(src._StorageLeft) {
	Span::Verbose("Span Copy Constructor called");
	if (!this->_Storage.empty())
		this->_Storage.clear();
	this->_Storage.assign(src._Storage.begin(), src._Storage.end());
}

Span::~Span( void ) {
	Span::Verbose("Span Destructor called");
}

Span	&Span::operator=( Span const & src ) {
	Span::Verbose("Span Assignation Operattor called");
	this->_MaxStorage = src.getMaxStorage();
	this->_StorageLeft = src._StorageLeft;
	if (!this->_Storage.empty())
		this->_Storage.clear();
	this->_Storage.assign(src._Storage.begin(), src._Storage.end());
	return (*this);
}

int	&Span::operator[]( unsigned int const & i) {
	if ( i >= this->_Storage.size())
		throw std::out_of_range("Span: error: Incorrect Index");
	return this->_Storage[i];
}

unsigned int	Span::getMaxStorage( void ) const {
	return (this->_MaxStorage);
}

unsigned int	Span::getSize( void ) const {
	return (this->_Storage.size());
}

void	Span::addNumber( int n ) {
	if (this->_Storage.size() < this->_MaxStorage) {
		this->_Storage.push_back(n);
		this->_StorageLeft--;
	}
	else
		throw Span::MaxStorageReachedException();
}

const char* Span::MaxStorageReachedException::what() const throw() {
	return "Max Storage reached, cannot add any number";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return "Not Enough Numbers";
}

unsigned int	Span::shortestSpan( void ) {
	unsigned int				range = std::numeric_limits<unsigned int>::max();
	std::vector<int>			tmp(this->_Storage);
	std::vector<int>::iterator	current;
	std::vector<int>::iterator	next;

	if (this->_Storage.size() <= 1)
		throw Span::NotEnoughNumbersException();
	std::sort(tmp.begin(), tmp.end());
	current = tmp.begin();
	next = current + 1;
	while (next != tmp.end()) {
		unsigned int	delta = std::abs(*current - *next);
		if (delta < range)
			range = delta;
		current++;
		next++;
	}
	return range;
}

unsigned int	Span::longestSpan( void ) {
	if (this->_Storage.size() <= 1)
		throw Span::NotEnoughNumbersException();
	int	min = *std::min_element(this->_Storage.begin(), this->_Storage.end());
	int	max = *std::max_element(this->_Storage.begin(), this->_Storage.end());
	return (std::abs(max - min));
}
