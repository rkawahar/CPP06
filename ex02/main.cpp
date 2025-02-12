/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:54:32 by kawaharadar       #+#    #+#             */
/*   Updated: 2025/02/13 00:07:56 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
	Base *p;

	p = generate();

	std::cout << "identify by *" << std::endl;
	identify(*p);
	std::cout << std::endl;

	std::cout << "identify by &" << std::endl;
	identify(p);

	delete p;
}