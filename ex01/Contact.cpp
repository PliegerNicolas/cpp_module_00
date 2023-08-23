/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:44 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/25 13:37:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

/* Constructor */

Contact::Contact(void)
{
	return ;
}

/* Destructor */
Contact::~Contact(void)
{
	return ;
}

/* Member functions */

/* Getters */

std::string	Contact::getFirstName(void) const
{
	return (_first_name);
}

std::string	Contact::getLastName(void) const
{
	return (_last_name);
}

std::string	Contact::getNickname(void) const
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkest_secret);
}

/* Setters */

void	Contact::setFirstName(std::string str)
{
	_first_name = str;
}

void	Contact::setLastName(std::string str)
{
	_last_name = str;
}

void	Contact::setNickname(std::string str)
{
	_nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	_phone_number = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	_darkest_secret = str;
}

/* Details */

/*

	const is set on getters to promise not to
	modify non-static member variables of this class.

*/
