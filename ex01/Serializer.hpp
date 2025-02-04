/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:13:28 by kawaharadar       #+#    #+#             */
/*   Updated: 2025/02/04 16:50:01 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
