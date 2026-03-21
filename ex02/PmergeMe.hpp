/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:19:22 by lenakach          #+#    #+#             */
/*   Updated: 2026/03/21 15:05:31 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

//safeatoi
#include <sstream>
#include <limits>

class PmergeMe
{
  public:
	PmergeMe &operator=(const PmergeMe & other);
	PmergeMe(const PmergeMe & other);
	PmergeMe(void);
	~PmergeMe(void);

	void sorter(void);
	void parsing(char **av);

  private:
	std::vector<int> _vector;
	std::deque<int> _deque;

};