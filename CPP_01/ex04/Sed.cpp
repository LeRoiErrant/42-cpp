/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:39:34 by vheran            #+#    #+#             */
/*   Updated: 2022/07/30 07:54:25 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

std::string	Sed::strReplace(std::string const &line, std::string const &search, std::string const &replace)
{
	std::string			newLine(line);
	size_t				pos;
	size_t				len;

	len = search.length();
	pos = newLine.find(search);
	while (pos != std::string::npos)
	{
		if (!std::isalnum(newLine[pos + len]))
		{
			newLine.erase(pos, len);
			newLine.insert(pos, replace);
		}
		pos = newLine.find(search, pos + len);
	}
	return (newLine);
}

/*std::string	Sed::strReplace(std::string const &line, std::string const &search, std::string const &replace)
{
	std::stringstream	result;
	std::istringstream	iss(line);
	std::string			word;
	bool				first = true;
	
	while (iss >> word)
	{
		if (first)
			first = false;
		else
			result << " ";
		if (!search.compare(word))
			result << replace;
		else
			result << word;
	}
	return (result.str());
}*/

/*std::string	Sed::strReplace(std::string const &line, std::string const &search, std::string const &replace)
{
	std::stringstream	ss;
	size_t				j;
	size_t				sl(search.length());
	
	for (size_t i = 0; i < line.length(); i++)
	{
		j = 0;
		while (std::tolower(line[i + j]) == std::tolower(search[j]) and j < sl)
			j++;
		if (j == sl && !std::isalnum(line[i + j]))
		{
			ss << replace;
			i += (j - 1);
		}
		else
			ss << line[i];
	}
	return (ss.str());
}*/

void	Sed::replace(std::string const &filename, std::string const &search, std::string const &replace)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		outfile;
	std::string		line;

	if (!filename.length() or !search.length() or !replace.length())
		throw (std::string) "bad arguments: filename/search/replace strings cannot be empty.";
	ifs.open(filename.data());
	if (!ifs.is_open())
		throw "cannot open " + filename;
	outfile = filename;
	outfile = outfile.append(".replace");
	ofs.open(outfile.data(), std::ios::trunc);
	if (!ofs.is_open())
	{
		ifs.close();
		throw "cannot open " + outfile;
	}
	while (std::getline(ifs, line))
	{
		ofs << Sed::strReplace(line, search, replace);
		if (!ifs.eof())
			ofs << '\n';
	}	
	ifs.close();
	ofs.close();
}


