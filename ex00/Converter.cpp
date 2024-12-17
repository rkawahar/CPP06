/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:51 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 21:27:16 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() {}

Converter::~Converter() {}

Converter::Converter(const Converter &other) {
	(void)other;
}

Converter &Converter::operator=(const Converter &other)
{
	(void)other;
	return *this;
}
//--------------------------------

static bool isChar(std::string literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

static bool isInt(std::string literal, bool *offlg)
{
	size_t	i = 0;
	long ans = 0;

	if (literal == "-2147483648")
		return true;
	if (literal.at(0) == '-')
		i++;
	while (i < literal.length())
	{
		if (!std::isdigit(literal.at(i)))
			return false;
		ans = ans * 10 + (literal.at(i) - '0');
		if (2147483647 < ans)
			*offlg = true;
		i++;
	}
	return true;
}

static bool isFloat(std::string literal)
{
	int dflg = 0;
	int eflg = 0;
	size_t i = 0;

	if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")
		return true;
	if (literal.at(literal.length() - 1) != 'f')
		return false;
	if (literal.at(0) == '-' || literal.at(0) == '+')
		i++;
	while (i < literal.length() - 1)
	{
		if (literal.at(i) == '.')
			dflg++;
		else if (literal.at(i) == 'e' || literal.at(i) == 'E')
			eflg++;
		else if (!std::isdigit(literal.at(i)))
			return false;
		i++;
	}
	if (dflg > 1 || eflg > 1)
		return false;
	return true;
}

static bool isDouble(std::string literal)
{
	int dflg = 0;
	int eflg = 0;
	size_t i = 0;

	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf")
		return true;
	if (literal.at(0) == '-' || literal.at(0) == '+')
		i++;
	while (i < literal.length())
	{
		if (literal.at(i) == '.')
			dflg++;
		else if (literal.at(i) == 'e' || literal.at(i) == 'E')
			eflg++;
		else if (!std::isdigit(literal.at(i)))
			return false;
		i++;
	}
	if (dflg > 1 || eflg > 1)
		return false;
	return true;
}

static int get_type(std::string literal, bool *offlg)
{
	if (isChar(literal))
		return CHAR;
	else if (isInt(literal, offlg))
		return INT;
	else if (isFloat(literal))
		return FLOAT;
	else if (isDouble(literal))
		return DOUBLE;
	return -1;
}

static void convert_int(std::string literal, bool offlg)
{
	if (offlg)
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return ;
	}
	int ans = std::atoi(literal.c_str());
	if (ans > 255 || ans < 0)
		std::cout << "char: overflow" << std::endl;
	else if (std::isprint(ans))
		std::cout << "char: " << static_cast<char>(ans) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << ans << std::endl;
	std::cout << "float: " << static_cast<float>(ans) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ans) << ".0" << std::endl;
}

static void convert_char(std::string literal)
{
	char ans = literal.at(0);
	if (std::isprint(ans))
		std::cout << "char: " << ans << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(ans) << std::endl;
	std::cout << "float: " << static_cast<float>(ans) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ans) << ".0" << std::endl;
}


static bool check_dflg(std::string literal)
{
	int dflg = 0;
	size_t i = 0;
	while (i < literal.length())
	{
		if (literal.at(i) == '.')
			dflg++;
		else if (dflg == 1 && literal.at(i) != '0')
			return true;
		i++;
	}
	return false;
}

static void convert_float(std::string literal)
{
	if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		if (literal == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (literal == "-inff")
			std::cout << "double: -inf" << std::endl;
		else if (literal == "+inff")
			std::cout << "double: +inf" << std::endl;
		return ;
	}
	float ans = strtod(literal.c_str(), NULL);
	if (ans > 255 || ans < 0)
		std::cout << "char: overflow" << std::endl;
	else if (std::isprint(static_cast<int>(ans)))
		std::cout << "char: " << static_cast<char>(ans) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if (static_cast<long>(ans) > 2147483647 || static_cast<long>(ans) < -2147483648)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(ans) << std::endl;
	
	if (ans == 0)
	{
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return ;
	}
	if (static_cast<float>(ans) > std::numeric_limits<float>::max() || static_cast<float>(ans) < std::numeric_limits<float>::lowest())
		std::cout << "float: overflow" << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(ans);
		if (check_dflg(literal))
			std::cout << "f" << std::endl;
		else
			std::cout << ".0f" << std::endl;
	}
	std::cout << "double: " << ans;
	if (check_dflg(literal))
		std::cout << std::endl;
	else
		std::cout << ".0" << std::endl;
}

static void convert_double(std::string literal)
{
	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	double ans = strtod(literal.c_str(), NULL);
	if (ans > 255 || ans < 0)
		std::cout << "char: overflow" << std::endl;
	else if (std::isprint(static_cast<int>(ans)))
		std::cout << "char: " << static_cast<char>(ans) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (static_cast<long>(ans) > 2147483647 || static_cast<long>(ans) < -2147483648)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(ans) << std::endl;
	
	if (ans == 0)
	{
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return ;
	}
	if (static_cast<float>(ans) > std::numeric_limits<float>::max() || static_cast<float>(ans) < std::numeric_limits<float>::lowest())
		std::cout << "float: overflow" << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(ans);
		if (check_dflg(literal))
			std::cout << "f" << std::endl;
		else
			std::cout << ".0f" << std::endl;
	}
	std::cout << "double: " << static_cast<double>(ans);
	if (check_dflg(literal))
		std::cout << std::endl;
	else
		std::cout << ".0" << std::endl;
}

void Converter::convert(std::string literal)
{
	bool offlg = false;
	//型判定
	switch (get_type(literal, &offlg))
	{
		case INT:
			convert_int(literal, offlg);
			break;
		case CHAR:
			convert_char(literal);
			break;
		case FLOAT:
			convert_float(literal);
			break;
		case DOUBLE:
			convert_double(literal);
			break;
		case -1:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}
