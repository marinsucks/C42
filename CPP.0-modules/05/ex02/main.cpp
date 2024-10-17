/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/17 13:19:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	gradeTooLow(void)
{
	std::cout << "gradeTooLow(): " << std::endl;
	{
		try
		{
			std::cout << "Creating Low1 with signGrade 151" << std::endl;
			AForm low1("Low1", 151, 10);
			std::cout << low1 << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Creating Low2 with execGrade 151" << std::endl;
			AForm low2("Low2", 10, 151);
			std::cout << low2 << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	gradeTooHigh(void)
{
	std::cout << "gradeTooHigh(): " << std::endl;
	{
		try
		{
			std::cout << "Creating High1 with signGrade 0" << std::endl;
			AForm high1("High1", -13, 10);
			std::cout << high1 << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Creating High2 with execGrade 0" << std::endl;
			AForm high2("High2", 10, 0);
			std::cout << high2 << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	authorizationsCheck(void)
{
	std::cout << "authorizationsCheck(): " << std::endl;
	Bureaucrat alice("President Alice", 1);
	std::cout << alice << std::endl;
	Bureaucrat bob("My Friend Bob", 150);
	std::cout << bob << std::endl;
	std::cout << std::endl;
	{
		try
		{
			AForm nuclear("Access Nuclear Codes", 1, 1);
			std::cout << nuclear << std::endl;
			alice.signAForm(nuclear);
			bob.signAForm(nuclear);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			AForm library("Order Library Card", 150, 150);
			std::cout << library << std::endl;
			alice.signAForm(library);
			bob.signAForm(library);
		}
		catch(const std::exception& e)
		{
			
			std::cerr << e.what() << '\n';
		}
	}
}

int main(void)
{
	//std::cout << "Creating 'Valid' AForm with grades 10 and 10" << std::endl;
	//AForm valid("Valid", 10, 10);
	//std::cout << valid << std::endl;
	//Bureaucrat validB("Valid Bureaucrat", 10);
	//std::cout << validB << std::endl;
	//validB.signAForm(valid);
	//std::cout << std::endl;

	gradeTooLow();
	std::cout << std::endl;
	gradeTooHigh();
	std::cout << std::endl;

	authorizationsCheck();
	
	return 0;
}
