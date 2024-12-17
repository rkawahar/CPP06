/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:51 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 12:59:02 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string literal) : _literal(literal) {}

Converter::~Converter() {}

Converter::Converter(const Converter &other) : _literal(other._literal) {}

Converter &Converter::operator=(const Converter &other)
{
	if (this != &other)
		_literal = other._literal;
	return *this;
}

const char *Converter::InvalidLiteralException::what() const throw()
{
	return "invalid literal";
}

const char *Converter::OutofRangeException::what() const throw()
{
	return "out of range";
}

const char *Converter::NonDisplayableException::what() const throw()
{
	return "non displayable";
}

const char *Converter::NonConvertibleException::what() const throw()
{
	return "nan";
}

int Converter::ft_atoi(const char *literal)
{
	int	ans = 0;
	int flg = 1;
	int	i = 0;

	while (literal[i] == ' ')
		i++;
	if (literal[i] == '-')
	{
		flg = -1;
		i++;
	}
	else if (literal[i] == '+')
		i++;
	if (!(literal[i] >= '0' && literal[i] <= '9'))
		throw InvalidLiteralException();
	while (literal[i] >= '0' && literal[i] <= '9')
	{
		if (flg == 1 && ans > (2147483647 - (literal[i] - '0')) / 10)
			throw OutofRangeException();
		if (flg == -1 && ans > (long)(2147483648 - (literal[i] - '0')) / 10)
			throw OutofRangeException();
		ans = ans * 10 + (literal[i++] - '0');
	}
	if (literal[i] != '\0' && literal[i] != '.')
		throw InvalidLiteralException();
	return ans * flg;
}

char Converter::ft_atos(const char *literal)
{
	int	ans = ft_atoi(literal);
	if (ans < 32 || ans > 126)
		throw NonDisplayableException();
	return static_cast<char>(ans);
}

double Converter::ft_atod(const char *literal)
{
	double ans = strtod(literal, NULL);
	// if (ans < std::numeric_limits<double>::min() || ans > std::numeric_limits<double>::max())
	// 	throw OutofRangeException();
	if (ans == HUGE_VAL || ans == -HUGE_VAL)
		throw OutofRangeException();
	if (std::isnan(ans))
		throw NonConvertibleException();
	return ans;
}

float Converter::ft_atof(const char *literal)
{
	float ans = static_cast<float>(ft_atod(literal));
	// if (ans < std::numeric_limits<float>::min() || ans > std::numeric_limits<float>::max())
	// 	throw OutofRangeException();
	if (ans == HUGE_VAL || ans == -HUGE_VAL)
		throw OutofRangeException();
	if (std::isnan(ans))
		throw NonConvertibleException();
	return ans;
}

void Converter::convert()
{
	std::cout << "convert" << std::endl;

	try
	{
		std::cout << "char: " << ft_atos(_literal.c_str()) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << ft_atoi(_literal.c_str()) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: " << ft_atof(_literal.c_str()) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << ft_atod(_literal.c_str()) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

