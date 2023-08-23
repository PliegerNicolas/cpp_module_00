/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:29 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/25 13:39:03 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_HPP
# define UTILS_HPP

# include "Contact.hpp"
# include "utils.hpp"
# include <string>
# include <iostream>

/* Text treatment */

std::string	capitalizeString(std::string str);

std::string	parseColumn(std::string str);

std::string	getlineNotEmpty(std::string prompt);

Contact		generateContact(void);

int			askToOverrightContact(const Contact contacts[], int index);

/* Display */

void		displayIntro(void);

void		displayContacts(const Contact contacts[8], int entries);

void		displayFullContact(Contact contact);

#endif
