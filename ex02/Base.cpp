/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:54:26 by kawaharadar       #+#    #+#             */
/*   Updated: 2025/02/13 00:15:39 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base *generate(void) {
	Base *ans;

	std::srand(std::time(0));
	int num = std::rand() % 3;
	switch (num) {
		case 0:
			ans = new A();
			break;
		case 1:
			ans = new B();
			break;
		case 2:
			ans = new C();
			break;
	}
	return ans;
};

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Type error" << std::endl;
};

void identify(Base &p) {
	A a;
	B b;
	C c;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
	} catch (std::exception &e) {
		try {
			b = dynamic_cast<B&>(p);
			std::cout << "Type is B" << std::endl;
		} catch (std::exception &e) {
			try {
				c = dynamic_cast<C&>(p);
				std::cout << "Type is C" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "Type error" << std::endl;
			}
		}
	}
}