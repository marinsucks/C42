/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:37:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/05 16:18:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	displayMenu(void)
{
	//PROTOTYPE 1:
	//	"██████  ██   ██  ██████  ███    ██ ███████ ██████   ██████   ██████  ██   ██", 
	//	"██   ██ ██   ██ ██    ██ ████   ██ ██      ██   ██ ██    ██ ██    ██ ██  ██ ",
	//	"██████  ███████ ██    ██ ██ ██  ██ █████   ██████  ██    ██ ██    ██ █████  ",
	//	"██      ██   ██ ██    ██ ██  ██ ██ ██      ██   ██ ██    ██ ██    ██ ██  ██ ", 
	//	"██      ██   ██  ██████  ██   ████ ███████ ██████   ██████   ██████  ██   ██",
	//
	std::string logo[] = {
		"\033[1;35m██████  \033[1;36m██   ██ \033[1;35m ██████  \033[1;36m███    ██ \033[1;35m███████ \033[1;36m██████  \033[1;35m ██████  \033[1;36m ██████  \033[1;35m██   ██\033[0m", 
		"\033[1;35m██   ██ \033[1;36m██   ██ \033[1;35m██    ██ \033[1;36m████   ██ \033[1;35m██      \033[1;36m██   ██ \033[1;35m██    ██ \033[1;36m██    ██ \033[1;35m██  ██ \033[0m",
		"\033[1;35m██████  \033[1;36m███████ \033[1;35m██    ██ \033[1;36m██ ██  ██ \033[1;35m█████   \033[1;36m██████  \033[1;35m██    ██ \033[1;36m██    ██ \033[1;35m█████  \033[0m",
		"\033[1;35m██      \033[1;36m██   ██ \033[1;35m██    ██ \033[1;36m██  ██ ██ \033[1;35m██      \033[1;36m██   ██ \033[1;35m██    ██ \033[1;36m██    ██ \033[1;35m██  ██ \033[0m", 
		"\033[1;35m██      \033[1;36m██   ██ \033[1;35m ██████  \033[1;36m██   ████ \033[1;35m███████ \033[1;36m██████  \033[1;35m ██████  \033[1;36m ██████  \033[1;35m██   ██\033[0m",
	};

	for (int i = 0; i < 5; i++)
		std::cout << logo[i] << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	PhoneBook	pb;
	std::string	command;

	displayMenu();
	while (1)
	{
		std::cout << MAGENTA << "Please enter a command: " << NC;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (std::cout << std::endl, 0);
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
		{
			pb.exitPhoneBook();
			break;
		}
		else
			std::cout << RED <<"Invalid command." << GREY << " [ADD/SEARCH/EXIT]" << NC << std::endl;
	}
	return (0);
}
