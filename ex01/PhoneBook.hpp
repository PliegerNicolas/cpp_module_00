/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:00 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/30 09:51:11 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"
# include <string>
# include <iostream>

class PhoneBook
{
	private:
		Contact			_contacts[8];
		int				_entries;
	public:
		/* Constructor */
		PhoneBook(void);

		/* Destructor */
		~PhoneBook(void);

		/* Member functions */
		void			add(void);
		void			search(void);

		/* Getters */
		int				getEntries(void) const;
		Contact			getContact(int index) const;
		const Contact	*getContacts(void) const;

		/* Setters */
		void			setEntries(int index);
		void			setContact(Contact contact, int index);
};

#endif
