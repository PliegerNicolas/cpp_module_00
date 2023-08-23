/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:23:18 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/25 13:44:21 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	ph_bk;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "\033[36m" <<"PhoneBook > " << "\033[0m";
		std::getline(std::cin, str);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}

		str = capitalizeString(str);
		if (str == "EXIT")
			break ;
		if (str != "ADD" && str != "SEARCH")
			continue ;
		std::cout << std::endl;
		if (str == "ADD")
			ph_bk.add();
		else if (str == "SEARCH")
			ph_bk.search();
		std::cout << std::endl;
	}
	return (0);
}
