#include "myfunctions.h"
#include <iostream>
#include <string>
#include <stdexcept>


std::string getUserMoney()
{
	std::string currencyToConvert{};

	do
	{
		std::cout << "\x10 What's the currency to convert ? ";
		std::getline(std::cin, currencyToConvert);

		int length = currencyToConvert.length();

		for (int i = 1; i < length; i++)
		{
			//initially, there was only written [length - 1] but vs suggested me that (types signed or unsigned)
			if (length > 0 && currencyToConvert[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - i] == ' ')		//allows us to verify if there are whitespaces at the end of the user's answer and to remove that
			{
				currencyToConvert.erase(static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - i, 1);
			}
			else
			{
				break;
			}
		}

	} while (currencyToConvert != "euro" && currencyToConvert != "dollar americain" && currencyToConvert != "rouble");
	
	return currencyToConvert;
}


std::string getUserConversionMoney()
{
	std::string currencyConverted{};

	do
	{
		std::cout << "\x10 What's the converted currency ? ";
		std::getline(std::cin, currencyConverted);

		int length = currencyConverted.length();

		for (int i = 1; i < length; i++)
		{
			//initially, there was only written [length - 1] but vs suggested me that (types signed or unsigned)
			if (length > 0 && currencyConverted[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - i] == ' ')	  //allows us to verify if there are whitespaces at the end of the user's answer and to remove that
			{
				currencyConverted.erase(static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - i, 1);
			}
			else
			{
				break;
			}
		}

	} while (currencyConverted != "euro" && currencyConverted != "dollar americain" && currencyConverted != "rouble");

	return currencyConverted;
}


float getUserAmount()
{
	std::string input;
	float userAmountCurrency = -1;

	do
	{
		std::cout << "What's the amount ? " << std::endl;
		std::cin >> userAmountCurrency;

		if (userAmountCurrency <= 0)
		{
			std::cout << "Error ! The amount is negative ! " << std::endl;
		}
		
	} while (userAmountCurrency <= 0);
	
	return userAmountCurrency;
}


float convertedAmount(std::string getUserMoney, std::string getUserConversionMoney, float getUserAmount)
{
	float finalAmount{};

	if (getUserMoney == "euro")
	{
		if (getUserConversionMoney == "dollar americain")
		{
			finalAmount = getUserAmount * 1.07;
			std::cout << "euro dollar" << '\n';
		}
		else if (getUserConversionMoney == "rouble")
		{
			finalAmount = getUserAmount * 78.21;
			std::cout << "euro rouble" << '\n';
		}
		else
		{
			std::cout << "ERROR DETECTED" << '\n';
		}
	}

	else if (getUserMoney == "dollar americain")
	{
		if (getUserConversionMoney == "euro")
		{
			finalAmount = getUserAmount * 0.93;
			std::cout << "dollar euro" << '\n';
		}
		else if (getUserConversionMoney == "rouble")
		{
			finalAmount = getUserAmount * 73.11;
			std::cout << "dollar americain rouble" << '\n';
		}
		else
		{
			std::cout << "ERROR DETECTED" << '\n';
		}
	}

	else if (getUserMoney == "rouble")
	{
		if (getUserConversionMoney == "euro")
		{
			finalAmount = getUserAmount * 0.013;
			std::cout << "rouble euro" << '\n';
		}
		else if (getUserConversionMoney == "dollar americain")
		{
			finalAmount = getUserAmount * 0.014;
			std::cout << "rouble dollar americain" << '\n';
		}
		else
		{
			std::cout << "ERROR DETECTED" << '\n';
		}
	}

	else
	{
		std::cout << "ERROR DETECTED" << '\n';
	}

	return finalAmount;
}


char retry()
{
	char run;

	std::cout << "Convert another amount - y " << std::endl;
	std::cout << "Quit - n" << std::endl;
	std::cin >> run;

	return run;
}