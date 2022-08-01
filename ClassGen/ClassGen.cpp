/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassGen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:03:06 by vheran            #+#    #+#             */
/*   Updated: 2022/07/30 16:32:49 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassGen.hpp"

ClassGen::ClassGen( void ) : _Filename(""), _NbVar(0) {	
}

ClassGen::ClassGen( std::string const filename ) : _Filename(filename), _NbVar(0) {
}

ClassGen::ClassGen( ClassGen const & src ) {
	*this = src;
}

ClassGen::~ClassGen( void ) {
}

ClassGen	&ClassGen::operator=( ClassGen const & src ) {
	if (this != &src)
		this->_Filename = src.getFilename();
	return (*this);
}

void	ClassGen::setFilename( std::string const filename ) {
	this->_Filename = filename;
}

std::string	ClassGen::getFilename( void ) const {
	return (this->_Filename);
}

bool	ClassGen::setVariables( int argc, char **argv ) {
	

	this->_NbVar = argc - 2;
	this->_VarType = new std::string[this->_NbVar];
	if (!this->_VarType)
		return (cerberror("ClassGen: error: ", "VarType allocation failed", false));
	this->_VarValue = new std::string[this->_NbVar];
	if (!this->_VarValue) {
		delete [] this->_VarType;
		return (cerberror("ClassGen: error: ", "VarType allocation failed", false));
	}
	for (int i = 0; i < this->_NbVar; i++) {
		std::istringstream	iss(argv[i + 2]);
		iss >> this->_VarType[i];
		iss >> this->_VarValue[i];
	}
	return (true);
}

bool	ClassGen::open_files( void ) {
	std::stringstream	ss;
	std::string			c_outfile(this->_Filename);
	std::string 		h_outfile(this->_Filename);
	
	ss << std::filesystem::current_path() << "/" << c_outfile << ".cpp";
	c_outfile = ss.str();
	c_outfile.erase(c_outfile.find("\""), 1);
	c_outfile.erase(c_outfile.find("\""), 1);
	ss.str(std::string());
	ss << std::filesystem::current_path() << "/" << h_outfile << ".hpp";
	h_outfile = ss.str();
	h_outfile.erase(h_outfile.find("\""), 1);
	h_outfile.erase(h_outfile.find("\""), 1);
	this->_cpp.open(c_outfile.data());
	if (!this->_cpp.is_open())
		return (cerberror("can't open: ", c_outfile, false));
	this->_hpp.open(h_outfile.data());
	if (!this->_hpp.is_open()) {
		this->_cpp.close();
		return (cerberror("can't open: ", h_outfile, false));
	}
	return (true);
}

void	ClassGen::close_files( void ) {
	this->_cpp.close();
	this->_hpp.close();
}

void	ClassGen::write_cpp( void ) {
	this->_cpp << "#include \"" << this->_Filename << ".hpp\"" << std::endl;
	this->_cpp << "\n" << this->_Filename << "::" << this->_Filename << "( void ) {\n}" << std::endl;
	this->_cpp << "\n" << this->_Filename << "::" << this->_Filename << "( " << this->_Filename << " const & src ) {\n\t*this = src;\n}" << std::endl;
	this->_cpp << "\n" << this->_Filename << "::~" << this->_Filename << "( void ) {\n}" << std::endl;
	this->_cpp << "\n" << this->_Filename << "\t&" << this->_Filename << "::" << "operator=( " << this->_Filename << " const & src ) {\n\treturn (*this);\n}\n" << std::endl;
	for (int i = 0; i < this->_NbVar; i++) {
		this->_cpp << "void\t" << this->_Filename << "::set" << this->_VarValue[i] << "( " << this->_VarType[i] << " const value ) {" << std::endl;
		this->_cpp << "\tthis->_" << this->_VarValue[i] << " = value;\n}\n" << std::endl;
		this->_cpp << this->_VarType[i] << "\t" << this->_Filename << "::get" << this->_VarValue[i] << "( void ) const {" << std::endl;
		this->_cpp << "\treturn (this->_" << this->_VarValue[i] << ");\n}\n" << std::endl;
	}
}

void	ClassGen::write_hpp( void ) {
	std::string	MAJ(this->_Filename);

	for (size_t i = 0; i < MAJ.length(); i++)
		MAJ[i] = std::toupper(MAJ[i]);

	this->_hpp << "#ifndef " << MAJ << "_HPP\n" << "# define " << MAJ << "_HPP" <<std::endl;
	this->_hpp << "\n# include <iostream>\n\nclass " << this->_Filename << " {\n\tprivate:" << std::endl;
	for (int i = 0; i < this->_NbVar; i++) {
		this->_hpp << "\t\t" << this->_VarType[i] << "\t_" << this->_VarValue[i] << ";" << std::endl;
	}
	this->_hpp << "\n\tpublic:" << std::endl;
	this->_hpp << "\t\t" << this->_Filename << "( void );" << std::endl;
	this->_hpp << "\t\t" << this->_Filename << "( " << this->_Filename << " const & src );" << std::endl;
	this->_hpp << "\t\t~" << this->_Filename << "( void );\n" << std::endl;
	this->_hpp << "\t\t" << this->_Filename << "\t&operator=( " << this->_Filename << " const & src );\n" << std::endl;
	if (this->_NbVar) {
		for (int i = 0; i < this->_NbVar; i++)
			this->_hpp << "\t\tvoid\t\tset" << this->_VarValue[i] << "( " << this->_VarType[i] << " const value );" << std::endl;
		this->_hpp << std::endl;
		for (int i = 0; i < this->_NbVar; i++)
			this->_hpp << "\t\t" << this->_VarType[i] << "\tget" << this->_VarValue[i] << "( void ) const;" << std::endl;
	}
	this->_hpp << "\n};\n" << std::endl;
	this->_hpp << "#endif" << std::endl; 
}

bool	cerberror(std::string msg, std::string arg, bool ret) {
	if (!msg.empty())
		std::cerr << msg;
	if (!arg.empty())
		std::cerr << arg;
	std::cerr << std::endl;
	return (ret);
}

int	cerberror(std::string msg, std::string arg, int errnum) {
	if (!msg.empty())
		std::cerr << msg;
	if (!arg.empty())
		std::cerr << arg;
	std::cerr << std::endl;
	return (errnum);
}