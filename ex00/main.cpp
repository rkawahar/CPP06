/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:44:11 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/13 17:47:43 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "write a literal" << std::endl;
		return 1;
	}
	Converter converter(av[1]);
	converter.convert();
}