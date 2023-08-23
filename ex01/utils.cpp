/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:20 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/25 13:44:06 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.hpp"

/* Text treatment */

std::string	capitalizeString(std::string str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

std::string	parseColumn(std::string str)
{
	std::string	new_str;
	const int	column_width = 10;
	int			pos[2];

	if (str.length() > column_width)
		new_str = str.substr(0, column_width -1) + '.';
	else
	{
		str.resize(column_width, ' ');
		pos[0] = str.find_first_not_of(' ');
		pos[1] = str.find_last_not_of(' ');
		new_str = str.substr(pos[0], pos[1] - pos[0] + 1);
		pos[0] = 0;
		while (pos[0]++ < column_width - pos[1] - 1)
			new_str.insert(0, " ", 0, 1);
	}
	return (new_str);
}

std::string	getlineNotEmpty(std::string prompt)
{
	std::string str;

	while (!std::cin.eof() && str.empty())
	{
		std::cout << "\033[37m";
		std::cout << prompt << " > ";
		std::cout << "\033[0m";
		std::getline(std::cin, str);
	}
	return (str);
}

int	askToOverrightContact(const Contact contacts[], int index)
{
	std::string	str;

	if (index < 8)
		return (1);
	std::cout << "\033[31m" << "Warning: Overwriting contact nº" << index % 8 + 1;
	std::cout << " also called \"" << contacts[index % 8].getFirstName() << "\"." << std::endl;
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "\033[37m" <<"Are you sure ? (Yes || No) " << "\033[0m";
		if (std::getline(std::cin, str) && !str.empty())
		{
			str = capitalizeString(str);
			if (str == "NO" || str == "N")
				return (0);
			else if (str == "YES" || str == "Y")
				return (1);
			str = "";
		}
	}
	return (0);
}

Contact	generateContact(void)
{
	Contact		contact;
	std::string	str;

	contact = Contact();

	str = getlineNotEmpty("First name");
	contact.setFirstName(str);

	str = getlineNotEmpty("Last name");
	contact.setLastName(str);

	str = getlineNotEmpty("Nickname");
	contact.setNickname(str);

	str = getlineNotEmpty("Phone number");
	contact.setPhoneNumber(str);

	str = getlineNotEmpty("His darkest secret...");
	contact.setDarkestSecret(str);

	return (contact);
}

/* Display */

void	displayIntro(void)
{
	std::cout << "\033[36m";
	std::cout << "Welcome to PhoneBook ! It can contain up to 8 contacts." << std::endl;
	std::cout << "\033[37m";
	std::cout << "Available commands are :" << std::endl;
	std::cout << "- ADD" << std::endl;
	std::cout << "- SEARCH" << std::endl;
	std::cout << "- EXIT" << std::endl;
	std::cout << "\033[0m";
	std::cout << std::endl;
}

static void	displayContactsListHeader(void)
{
	std::cout << "\033[37m";
	std::cout << "o ============================================ o" << std::endl;
	std::cout << "o       ID|FIRST NAME| LAST NAME|  NICKNAME    o" << std::endl;
	std::cout << "o ============================================ o";
	std::cout << "\033[0m" << std::endl;
}

void	displayContacts(const Contact contacts[8], int entries)
{
	std::string	str;
	int			i;

	i = 0;
	if (entries >= 8)
		entries = 8;
	displayContactsListHeader();
	while (i < entries)
	{
		str = i + 1 + '0';
		str = parseColumn(str);
		std::cout << str;
		std::cout << "\033[37m" << "|" << "\033[0m";
		str = contacts[i].getFirstName();
		str = parseColumn(str);
		std::cout << str;
		std::cout << "\033[37m" << "|" << "\033[0m";
		str = contacts[i].getLastName();
		str = parseColumn(str);
		std::cout << str;
		std::cout << "\033[37m" << "|" << "\033[0m";
		str = contacts[i].getNickname();
		str = parseColumn(str);
		std::cout << str;
		std::cout << std::endl;
		i++;
	}
}

void	displayFullContact(Contact contact)
{
	std::cout << "\033[37m" << "First name: " << "\033[0m";
	std::cout << contact.getFirstName() << std::endl ;
	std::cout << "\033[37m" << "Last name: " << "\033[0m";
	std::cout << contact.getLastName() << std::endl;
	std::cout << "\033[37m" << "Nickname: " << "\033[0m";
	std::cout << contact.getNickname() << std::endl;
	std::cout << "\033[37m" << "Phone number: " << "\033[0m";
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << "\033[37m" << "Darkest secret: " << "\033[0m";
	std::cout << contact.getDarkestSecret() << std::endl;
}
