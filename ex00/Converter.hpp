/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:01:53 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 11:52:23 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>

class Converter
{
	private:
		std::string _literal;
		int ft_atoi(const char *literal);
		char ft_atos(const char *literal);
		float ft_atof(const char *literal);
		double ft_atod(const char *literal);

	public:
		Converter(std::string literal);
		~Converter();
		Converter(const Converter &other);
		Converter &operator=(const Converter &other);

		class InvalidLiteralException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class OutofRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NonConvertibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void convert();
};
