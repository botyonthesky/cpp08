/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:58:51 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/09 10:46:43 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span() : _N(0)
{
    std::cout << "Span default constructor" << std::endl;
}

Span::Span(const unsigned int N) : _N(N)
{
    std::cout << "Span constructor" << std::endl;
}

Span::Span(const Span& other) : _N(other._N)
{
    std::cout << "Span copy" << std::endl;
    this->_arr = other._arr;
}

Span& Span::operator=(const Span& other)
{
    std::cout << "Span copy assignment" << std::endl;
    if (this != &other)
    {
        this->_N = other._N;
        this->_arr = other._arr;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Span destructor" << std::endl;    
}
const char* Span::isFull::what() const throw()
{
    return ("The array is full !");
}

const char* Span::tooShort::what() const throw()
{
    return ("The Span list is too short, only one element");
}

const char* Span::isEmpty::what() const throw()
{
    return ("The Span list is empty");
}
unsigned int Span::getNum(void)
{
    return (_N);
}

std::vector<int> Span::getArr(void)
{
    return (_arr);
}

void Span::printValueVector(Span &src)
{
    size_t size = src._arr.size();
    if (size == 0)
    {
        std::cout << "The array is empty" << std::endl;
    }
    else
    {
        std::cout << "The vector container size is : " << size 
        << " and this values are : " << std::endl;
        for (std::vector<int>::iterator i = _arr.begin(); i != _arr.end(); i++)
        {
            std::cout << *i << ", ";
        }
        std::cout << std::endl;
    }
}       
void    Span::fillNumbers(int count, int min, int max)
{
    std::srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < count; i++)
    {
        int random = min + std::rand() % (max - min + 1);
        this->addNumber(random); 
    }
}


void            Span::addNumber(const int value)
{
    unsigned int size;
    size = _arr.size();
    if (size >= _N)
        throw isFull();
    else
    {
        this->_arr.push_back(value);
    }
}

int           Span::shortestSpan(void)
{
    if (_arr.size() == 1)
        throw tooShort();
    if (_arr.size() == 0)
        throw isEmpty();
    int result = INT_MAX;
    std::vector<int> tmp = _arr;
    std::sort(tmp.begin(), tmp.end());
    for (unsigned int i= 1; i < tmp.size(); i++)
    {
        int range = tmp[i] - tmp[i - 1];
        if (range < result)
            result = range;
    }
    return (result);
}
int           Span::longestSpan(void)
{
    if (_arr.size() == 1)
        throw tooShort();
    if (_arr.size() == 0)
        throw isEmpty();
    int shortest = INT_MAX;
    int longest = INT_MIN;
    for (unsigned int i = 0; i < _arr.size(); i++)
    {
        if (_arr[i] > longest)
            longest = _arr[i];
    }
    for(unsigned int i = 0; i < _arr.size(); i++)
    {
        if (_arr[i] < shortest)
            shortest = _arr[i];
    }
    int result = longest - shortest;
    return (result);
}

std::ostream& operator<<(std::ostream &out, Span& src)
{    
    out << "An array of : " << src.getNum() << " elements have been created"
    << std::endl;
    return (out);
}