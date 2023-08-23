/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:09:20 by nicolas           #+#    #+#             */
/*   Updated: 2023/05/22 17:42:52 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int	main(int argc, char **argv)
{
	size_t		i;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	argv++;
	while (*argv)
	{
		i = 0;
		while (*argv && (*argv)[i])
			std::cout << (char)std::toupper((*argv)[i++]);
		argv++;
	}
	std::cout << std::endl;
	return (0);
}
