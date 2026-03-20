/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:13:05 by lenakach          #+#    #+#             */
/*   Updated: 2026/03/20 18:46:21 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{	
}

PmergeMe::~PmergeMe(void)
{
}

std::deque<int> sortDeque(std::deque<int> deq)
{
	if (deq.size() <= 1)
		return deq;
	
	std::deque<std::pair<int, int> > pairs;
	size_t i = 0;

	//Creer les paires
	for ( ; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	int reste = -1;
	bool hasReste = false;

	if (i < deq.size())
	{
		reste = deq[i];
		hasReste = true;
	}

	//Construction de la main Chain
	std::deque<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++)
	{
		mainChain.push_back(pairs[j].second);
	}

	//Tri recursif
	mainChain = sortDeque(mainChain);

	for (size_t j = 0; j < pairs.size(); j++)
	{
		int small = pairs[j].first;

		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), small);

		mainChain.insert(pos, small);
	}
	if (hasReste)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), reste);

		mainChain.insert(pos, reste);
	}

	return mainChain;
}

std::vector<int> sortVector(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return vec;
		
	std::vector<std::pair<int, int> > pairs;
	size_t i = 0;
	
	//Creer les paires
	for ( ; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));		
	}

	int reste = -1;
	bool hasReste = false;

	if (i < vec.size())
	{
		reste = vec[i];
		hasReste = true;
	}

	//construction des mains chains
	std::vector<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++)
	{
		mainChain.push_back(pairs[j].second);
	}
	
	//tri recursif
	mainChain = sortVector(mainChain);

	//insertion des b
	for (size_t j = 0; j < pairs.size(); j++)
	{
		int small = pairs[j].first;

		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), small);

		mainChain.insert(pos, small);
	}

	if (hasReste)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), reste);

		mainChain.insert(pos, reste);
	}

	return mainChain;
}

void PmergeMe::sorter(void)
{
	clock_t startVec = clock();
	_vector = sortVector(_vector);
	clock_t endVec = clock();
	
	clock_t startDeq = clock();
	_deque = sortDeque(_deque);
	clock_t endDeq = clock();

	std::cout << "After: ";
	for (size_t i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;

	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;


	std::cout << "Time to process a range of "
			  << _vector.size()
			  << " elements with std::vector: "
			  << timeVec << " us" << std::endl;

	std::cout << "Time to process a range of "
			  << _deque.size()
			  << " elements with std::deque: "
			  << timeDeq << " us" << std::endl;
}


//-------------------------PARSING-------------------------------
int safeAtoi(const std::string &str)
{
	std::istringstream	iss(str);
	long value;

	iss >> value;

	if (iss.fail() || !iss.eof())
		throw std::runtime_error("Error: invalid input");
	
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		throw std::runtime_error("Error: overflow");
	
	return static_cast<int>(value);
}

void PmergeMe::parsing(char **av)
{
	std::set<int> doublon;

	for (int i = 1; av[i]; i++)
	{
		std::string str(av[i]);

		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Error: invalid input");
		
		int value = safeAtoi(str);
		
		if (value < 0)
			throw std::runtime_error("Error: negative number");
		if (doublon.count(value))
			throw std::runtime_error("Error: no duplicata are allowed");
		
		doublon.insert(value);
		_vector.push_back(value);
		_deque.push_back(value);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}