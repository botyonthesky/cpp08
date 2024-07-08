/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:33:06 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/08 08:24:01 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class notFoundException : public std::exception
{
    public :
        virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
void    printValueVector(T& container);

template <typename T>
void    printValueList(T& container);