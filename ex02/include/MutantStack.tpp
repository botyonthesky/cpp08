/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:43:20 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/10 10:20:31 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template <typename T>
void    MutantStack<T>::printMutantStackInfo(void) const
{
    MutantStack<T> tmp(*this);
    tmp = *this;
    if (tmp.size() == 0)
        std::cout << "The Mutant Stack is empty !" << std::endl;
    else
    {
        std::cout << "The Mutant Stack size is : " << tmp.size() << std::endl;
        int i = 0;
        while (!tmp.empty())
        {
            std::cout << "MS position : " << i << ", element : " << tmp.top() << std::endl;           
            i++;
            tmp.pop();
        }
    }
}