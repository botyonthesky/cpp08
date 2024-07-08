/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:33:10 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/08 08:47:08 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

const char* notFoundException::what() const throw()
{
    return ("The value hasn't been found");
}

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw notFoundException();
    }
    return (it);   
}

template <typename T>
void printValueVector(T& container)
{
    size_t size = container.size();
    std::cout << "The vector container size is : " << size 
    << " and this values are : ";
    for (size_t i = 0; i < size - 1; i++)
    {
        std::cout << container[i] << " ,";
    }
    std::cout << container[size - 1] << "." << std::endl;
}

template <typename T>
void    printValueList(T& container)
{
    size_t size = container.size();
    std::cout << "The list container size is : " << size 
    << " and this values are : ";
    if (!container.empty())
    {
        std::list<int>::iterator begin = container.begin();
        std::list<int>::iterator end = container.end();
        end--;
        while (begin != end)
        {
            std::cout << *begin << ", ";
            begin++;
        }
        std::cout << *begin << std::endl;
    }
}