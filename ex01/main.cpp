/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:28:04 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 22:49:31 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data	data;
	data.setData("Hello, World!");
	std::cout << "data: " << data.getData() << std::endl;
	std::cout << "data address: " << &data << std::endl;
	std::cout << std::endl;

	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;
	std::cout << std::endl;

	Data *data2 = Serializer::deserialize(raw);
	std::cout << "data2: " << data2->getData() << std::endl;
	std::cout << "data2 address: " << data2 << std::endl;
	std::cout << std::endl;

	Data *data3 = new Data();
	Data *leaks = data3;
	data3 = Serializer::deserialize(raw);
	std::cout << "data3: " << data3->getData() << std::endl;
	std::cout << "data3 address: " << data3 << std::endl;

	delete leaks;
}
