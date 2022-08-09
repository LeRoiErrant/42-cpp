#include "Converter.hpp"

const std::string Converter::specialFloat[] = { "-inff", "+inff", "nanf" };
const std::string Converter::specialDouble[] = { "-inf", "+inf", "nan" };

const std::string Converter::TypeSelected[] = { "Char Type", "Int Type", "Float Type", "Double Type" };

void	Converter::_Verbose(std::string msg) {
	if (Converter::_verbOn)
		std::cout << msg << std::endl;
}

const char* Converter::NotaValidTypeException::what() const throw()
{
	return "Converter Exception: Not a Valid Type";
}

Converter::Converter( void ) : _inputType(NOTYPE), _charType(0), _intType(0), _floatType(0), _doubleType(0), _special(NOSPECIAL) {
	Converter::_Verbose("Converter Base Constructor Called");
}

Converter::Converter( std::string input) : _inputType(NOTYPE), _charType(0), _intType(0), _floatType(0), _doubleType(0), _special(NOSPECIAL) {
	Converter::_Verbose("Converter string initialized Constructor Called");
	try {
		if (!findType(input))
			throw Converter::NotaValidTypeException();
		else {
			std::cout << Converter::TypeSelected[this->_inputType] << " Identified" << std::endl;
			this->printV[CHAR] = &Converter::PrintfromChar;
			this->printV[INT] = &Converter::PrintfromInt;
			this->printV[FLOAT] = &Converter::PrintfromFloat;
			this->printV[DOUBLE] = &Converter::PrintfromDouble;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

Converter::Converter( Converter const & src ) : _inputType(src.getinputType()), _charType(src.getcharType()), _intType(src.getintType()), _floatType(src.getfloatType()), _doubleType(src.getdoubleType()), _special(src.getSpecial()) {
	Converter::_Verbose("Converter Copy Constructor Called");
	this->printV[CHAR] = &Converter::PrintfromChar;
	this->printV[INT] = &Converter::PrintfromInt;
	this->printV[FLOAT] = &Converter::PrintfromFloat;
	this->printV[DOUBLE] = &Converter::PrintfromDouble;
	Converter::_Verbose("Copy Success");
}

Converter::~Converter( void ) {
	Converter::_Verbose("Converter Destructor called");
}

Converter	&Converter::operator=( Converter const & src ) {
	Converter::_Verbose("Converter Assignation  Operator Called");
	this->_inputType = src.getinputType();
	this->_charType = src.getcharType();
	this->_intType = src.getintType();
	this->_floatType = src.getfloatType();
	this->_doubleType = src.getdoubleType();
	this->_special = src.getSpecial();
	return (*this);
}

int	Converter::getinputType( void ) const {
	return (this->_inputType);
}

char	Converter::getcharType( void ) const {
	return (this->_charType);
}

int	Converter::getintType( void ) const {
	return (this->_intType);
}

float	Converter::getfloatType( void ) const {
	return (this->_floatType);
}

double	Converter::getdoubleType( void ) const {
	return (this->_doubleType);
}

int	Converter::getSpecial( void ) const {
	return (this->_special);
}

int	Converter::SpecialCases(std::string input ) {
	for (int i = 0 ; i < 3 ; i++) {
		if (!input.compare(Converter::specialFloat[i])) {
			this->_special = i;
			return (FLOAT);
		}
		else if (!input.compare(Converter::specialDouble[i])) {
			this->_special = i;
			return (DOUBLE);
		}
	}
	return (NOTYPE);
}

int	Converter::NumericValue( std::string input ) {
	bool				dot = false;
	bool				digit = false;
	int					i = -1;
	long				tmp;
	std::stringstream	ss;

	ss << input;
	if ((input[0] == '+' or input[0] == '-') and input[1])
		i++;
	while (std::isdigit(input[++i]) or input[i] == '.') {
		if (input[i] == '.' and !dot)
			dot = true;
		else if (input[i] == '.' and dot)
			return (NOTYPE);
		else if (!digit and std::isdigit(input[i]))
			digit = true;
	}
	if (!digit)
		return (NOTYPE);
	if (input[i] == 0) {
		if (dot) {
			ss >> this->_doubleType;
			return (DOUBLE);
		}
		ss >> tmp;
		if (std::numeric_limits<int>::min() <= tmp and tmp <= std::numeric_limits<int>::max()) {
			this->_intType = tmp;
			return (INT);
		}
	}
	else if (input[i] == 'f') {
		ss >> this->_floatType;
		return (FLOAT);
	}
	return (NOTYPE);
}

bool	Converter::findType( std::string input ) {
	Converter::_Verbose("Finding Type");
	this->_inputType = this->SpecialCases(input);
	if (this->_inputType != NOTYPE)
		return (true);
	if (std::isdigit(input[0]) or input[0] == '.' or input[0] == '-' or input[0] == '+' ) {
		this->_inputType = this->NumericValue(input);
		if (this->_inputType != NOTYPE)
			return (true);
	}
	if (input.length() != 1)
		return (false);
	this->_inputType = CHAR;
	this->_charType = input[0];
	return (true);
}

void	Converter::PrintValues( void ) {
	std::stringstream	ss;
	ss << "Type: " << Converter::TypeSelected[this->_inputType] << "\nchar: " << this->_charType << "\nint: " << this->_intType << "\nfloat: " << this->_floatType << "\ndouble: " << this->_doubleType << std::endl; 
	Converter::_Verbose("Print values...");
	Converter::_Verbose(ss.str());
	try {
		if (this->_inputType == NOTYPE)
			throw Converter::NotaValidTypeException();
		if (this->_special == NOSPECIAL) {
			Converter::_Verbose("No Special Case");
			(this->*printV[this->_inputType])();
		}
		else {
			Converter::_Verbose("Special Case");
			this->printSp[PINF] = &Converter::PrintpInf;
			this->printSp[MINF] = &Converter::PrintmInf;
			this->printSp[NAN] = &Converter::PrintNaN;
			(this->*printSp[this->_special])();
		}
	}
	catch (std::exception &e){
	std::cerr << "Print Value Failure: " << e.what() << std::endl;
	}
}

void	Converter::PrintfromChar( void ) {
	std::cout << std::setw(10) << std::left << "char: " << "'" << this->_charType << "'" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << static_cast<int>(this->_charType) << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << static_cast<float>(this->_charType) << ".0f" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << static_cast<double>(this->_charType) << ".0" << std::endl;
}

bool	Converter::CharConversion( double n ) {
	if (n < 0 or 127 < n)
		std::cout << std::setw(10) << std::left << "char: " << "impossible" << std::endl;
	else if (n < 32 or n == 127)
		std::cout << std::setw(10) << std::left << "char: " << "Non displayable" << std::endl;
	else
		return (true);
	return (false);
}

std::string	Converter::PrintDotZero( double n) {
	if ( n - static_cast<int>(n) == 0)
		return (".0");
	return ("");
}

void	Converter::PrintfromInt( void ) {
	if (this->CharConversion(this->_intType))
		std::cout << std::setw(10) << std::left << "char: " << "'" << static_cast<char>(this->_intType) << "'" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << this->_intType << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << static_cast<float>(this->_intType) << ".0f" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << static_cast<double>(this->_intType) << ".0" << std::endl;
}

void	Converter::PrintfromFloat( void ) {
	if (this->CharConversion(this->_floatType))
		std::cout << std::setw(10) << std::left << "char: " << "'" << static_cast<char>(this->_floatType) << "'" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << static_cast<int>(this->_floatType) << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << this->_floatType << this->PrintDotZero(this->_floatType) << "f" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << static_cast<double>(this->_floatType) << this->PrintDotZero(this->_floatType) << std::endl;
}

void	Converter::PrintfromDouble( void ) {
	if (this->CharConversion(this->_doubleType))
		std::cout << std::setw(10) << std::left << "char: " << "'" << static_cast<char>(this->_doubleType) << "'" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << static_cast<int>(this->_doubleType) << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << this->_doubleType << this->PrintDotZero(this->_doubleType) << "f" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << static_cast<double>(this->_doubleType) << this->PrintDotZero(this->_doubleType) << std::endl;
}

void	Converter::PrintNaN( void ) {
	std::cout << std::setw(10) << std::left << "char: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << "nanf" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << "nan" << std::endl;
}

void	Converter::PrintpInf( void ) {
	std::cout << std::setw(10) << std::left << "char: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << "+inff" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << "+inf" << std::endl;
}

void	Converter::PrintmInf( void ) {
	std::cout << std::setw(10) << std::left << "char: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "int: " << "impossible" << std::endl;
	std::cout << std::setw(10) << std::left << "float: " << "-inff" << std::endl;
	std::cout << std::setw(10) << std::left << "double: " << "-inf" << std::endl;
}