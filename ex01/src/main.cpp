/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:33:42 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/09 11:27:38 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

void    constructorTest(void)
{
    std::cout << "[ CONSTRUCTOR TEST ]" << std::endl;
    Span    s1;
    std::cout << s1 << std::endl;
    Span    s2(5);
    std::cout << s2 << std::endl;
    Span    s3(s2);
    std::cout << s3 << std::endl;
    Span    s4;
    std::cout << s4 << std::endl;
    s4 = s3;
    std::cout << s4 << std::endl;

}

void    subjectTest()
{
    std::cout << "[ SUBJECT TEST ]" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void    exceptionTest()
{
    std::cout << "[ EXCEPTION TEST ]" << std::endl;
    try
    {
        Span s(5);
        s.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span s(5);
        s.addNumber(42);
        s.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


void    rangeTest(void)
{
    std::cout << "[ RANGE TEST ]" << std::endl;
    std::cout << "100 Numbers ->" << std::endl;
    try
    {
        Span s(100);
        s.fillNumbers(100, -10000, 10000);
        s.printValueVector(s);
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "10000 Numbers ->" << std::endl;
    try
    {
        Span s2(10000);
        s2.fillNumbers(10000, -10000, 10000);
        s2.printValueVector(s2);
        std::cout << s2.shortestSpan() << std::endl;
        std::cout << s2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "20000 Numbers ->" << std::endl;
    try
    {
        Span s3(20000);
        s3.fillNumbers(20000, -20000, 20000);
        s3.printValueVector(s3);
        std::cout << s3.shortestSpan() << std::endl;
        std::cout << s3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span s(100);
        s.fillNumbers(99, -10000, 10000);
        s.printValueVector(s);
        std::cout << "Try to add 42 in an array of 99, full with 100 numbers" << std::endl;
        s.addNumber(42);
        s.printValueVector(s);
        std::cout << "Try to add a number in a full array" << std::endl;
        s.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    constructorTest();
    subjectTest();
    rangeTest();
    exceptionTest();

    return (0);
}