/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:15:34 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 22:27:50 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _data("") {}

Data::~Data() {}

Data::Data(const Data &other) : _data(other._data) {}

Data &Data::operator=(const Data &other) {
	_data = other.getData();
	return (*this);
}

std::string	Data::getData() const {
	return (_data);
}

void	Data::setData(const std::string &data) {
	_data = data;
}
