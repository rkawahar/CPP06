/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:01:53 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 16:51:48 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cmath>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class Converter
{
	private:
		Converter();
		~Converter();
		Converter(const Converter &other);
		Converter &operator=(const Converter &other);

	public:
		static void convert(std::string literal);

};
