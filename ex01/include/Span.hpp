/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:56:15 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/09 10:05:27 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <cassert>
#include <functional>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <climits>
    
#include <iterator>

class Span
{
    private:
        
        unsigned int        _N;
        std::vector<int>    _arr;
        
    public:
    
        Span();
        Span(const unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

    class isFull : public std::exception
    {
        virtual const char* what() const throw();
    };

    class tooShort : public std::exception
    {
        virtual const char* what() const throw();
    };
    
    class isEmpty : public std::exception
    {
        virtual const char* what() const throw();
    };
    
    
    void                addNumber(const int value);
    int                 shortestSpan(void);
    int                 longestSpan(void);
    void                fillNumbers(int count, int min, int max);

    unsigned int        getNum(void);
    std::vector<int>    getArr(void);
    void                printValueVector(Span &src);

};

std::ostream& operator<<(std::ostream &out, Span& src);




#endif
