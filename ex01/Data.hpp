/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:15:30 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/12/17 22:21:12 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <cstddef>

struct Data {
	private:
		std::string		_data;
	
	public:
		Data();
		~Data();
		Data(const Data &);
		Data &operator=(const Data &);
		std::string	getData() const;
		void	setData(const std::string &data);
};
