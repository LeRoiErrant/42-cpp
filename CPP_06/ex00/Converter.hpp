#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <sstream>

class Converter {
	private:
		enum types {
			NOTYPE = -1,
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};

		enum special {
			NOSPECIAL = -1,
			MINF,
			PINF,
			NAN
		};
		
		int		_inputType;
		char	_charType;
		int		_intType;
		float	_floatType;
		double	_doubleType;


		int		_special;

		static const bool	_verbOn = false;
		static	void		_Verbose(std::string msg);

		static const std::string	specialFloat[];
		static const std::string	specialDouble[];

		static const std::string	TypeSelected[];

		Converter( void );

		bool		findType( std::string input );
		int			SpecialCases( std::string input );
		int			NumericValue( std::string input );
		int			saveInputValue( std::string input );

		void		(Converter::*printV[4])(void);
		void		(Converter::*printSp[3])(void);
		void		PrintfromChar( void );
		void		PrintfromInt( void );
		void		PrintfromFloat( void );
		void		PrintfromDouble( void );

		void		PrintNaN( void );
		void		PrintpInf( void );
		void		PrintmInf( void );
		
		std::string	PrintDotZero( double n );
		bool		CharConversion( double n);

	public:

		Converter( std::string input );
		Converter( Converter const & src );
		~Converter( void );

		Converter	&operator=( Converter const & src );

		int			getinputType( void ) const;
		char		getcharType( void ) const;
		int			getintType( void ) const;
		float		getfloatType( void ) const;
		double		getdoubleType( void ) const;
		int			getSpecial( void ) const;

		class NotaValidTypeException: public std::exception {
			virtual const char* what() const throw();
		};

		void		PrintValues( void );
};

#endif
