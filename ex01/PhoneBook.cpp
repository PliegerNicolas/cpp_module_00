/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:28:48 by nicolas           #+#    #+#             */
/*   Updated: 2023/07/18 15:19:30 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

/* Constructor */

PhoneBook::PhoneBook(void)
{
	setEntries(0);
	displayIntro();
}

/* Destructor */

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[37m" << "Bye-bye !" << "\033[0m" << std::endl;
}

/* Member functions */

void	PhoneBook::add(void)
{
	Contact		new_contact;
	int			index;
	std::string	str;

	index = getEntries();
	if (!askToOverrightContact(getContacts(), index))
		return ;
	new_contact = generateContact();
	setContact(new_contact, index);
	setEntries(++index);
}

void	PhoneBook::search(void)
{
	std::string	str;
	int			index;

	displayContacts(getContacts(), getEntries());
	std::cout << std::endl;
	str = getlineNotEmpty("Inspect contact nº");
	if (str.length() == 1)
		index = (str[0] - '0') - 1;
	else
	{
		std::cout << "\033[31m" << "Error. Index invalid." << "\033[0m" << std::endl;
		return ;
	}
	if (index < 0 || index >= getEntries())
	{
		std::cout << "\033[31m" << "Error. Index invalid." << "\033[0m" << std::endl;
		return ;
	}
	std::cout << std::endl;
	displayFullContact(getContact(index));
}

/* Getters */

int	PhoneBook::getEntries(void) const
{
	return(_entries);
}

Contact	PhoneBook::getContact(int index) const
{
	return (_contacts[index % 8]);
}

const Contact	*PhoneBook::getContacts(void) const
{
	return (_contacts);
}

/* Setters */

void	PhoneBook::setEntries(int index)
{
	_entries = index;
}

void	PhoneBook::setContact(Contact contact, int index)
{
	_contacts[index % 8] = contact;
}
