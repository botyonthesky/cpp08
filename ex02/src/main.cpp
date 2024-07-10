/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:43:26 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/10 10:41:30 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include "../include/MutantStack.tpp"

void        constructorOperatorTest(void)
{
    std::cout << "[ CONSTRUCTOR OPERATOR TEST ]" << std::endl;
    MutantStack<int> ms;

    ms.printMutantStackInfo();
    std::cout << std::endl;
    
    std::cout << "Push 3 element in the first Mutant Stack : 21, 42, 84" << std::endl;
    std::cout << std::endl;
    ms.push(21);
    ms.push(42);
    ms.push(84);
    ms.printMutantStackInfo();
    std::cout << std::endl;

    std::cout << "Copy of the first in the second Mustant Stack" << std::endl;
    MutantStack<int> ms2(ms);
    ms2.printMutantStackInfo();
    std::cout << std::endl;
    
    std::cout << "Copy assignment of the second in the third Mutant Stack" << std::endl;
    MutantStack<int> ms3;
    ms3 = ms2;
    ms3.printMutantStackInfo();
}
void    iteratorTest()
{
    std::cout << "[ ITERATOR INT TEST ]" << std::endl;
    MutantStack<int> ms;
    ms.push(9);
    ms.push(21);
    ms.push(42);
    ms.push(84);
    ms.printMutantStackInfo();
    MutantStack<int>::iterator itBegin = ms.begin();
    std::cout << "Iterator begin -> " << *itBegin << std::endl;
    MutantStack<int>::iterator itEnd = ms.end();
    std::cout << "Real end iterator -> " << *itEnd << std::endl;
    std::cout << "-> itEnd--" << std::endl;
    itEnd--;
    std::cout << "End iterator -> " << *itEnd << std::endl;
}

void    iteratorDoubleTest()
{
    std::cout << "[ ITERATOR DOUBLE TEST ]" << std::endl;
    MutantStack<double> ms;
    ms.push(21.42);
    ms.push(42.21);
    ms.push(19.84);
    ms.printMutantStackInfo();
    MutantStack<double>::iterator itBegin = ms.begin();
    std::cout << "Iterator begin -> " << *itBegin << std::endl;
    MutantStack<double>::iterator itEnd = ms.end();
    itEnd--;
    std::cout << "Iterator end - > " << *itEnd << std::endl;
}
void    iteratorIntTest()
{
    std::cout << "[ ITERATOR INT TEST ]" << std::endl;
    MutantStack<int> ms;
    ms.push(9);
    ms.push(21);
    ms.push(42);
    ms.push(84);
    ms.printMutantStackInfo();
    MutantStack<int>::iterator itBegin = ms.begin();
    std::cout << "Iterator begin -> " << *itBegin << std::endl;
    MutantStack<int>::iterator itEnd = ms.end();
    itEnd--;
    std::cout << "End iterator -> " << *itEnd << std::endl;
}


void    stringIteratorTest()
{
    std::cout << "[ ITERATOR STRING TEST ]" << std::endl;
    MutantStack<std::string> ms;
    ms.push("You");
    ms.push("don't");
    ms.push("talk");
    ms.push("about");
    ms.push("Fight Club");
    ms.printMutantStackInfo();
    MutantStack<std::string>::iterator itBegin = ms.begin();
    std::cout << "Begin iterator -> " << *itBegin << std::endl;
    MutantStack<std::string>::iterator itEnd = ms.end();
    itEnd--;
    std::cout << "End operator -> " << *itEnd << std::endl;
}

void    subjectTest()
{
    std::cout << "[ SUBJECT TEST ]" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void    subjectTest2()
{
    std::cout << "[ SUBJECT TEST 2 / SWITCH MUTANT STACK INTO STD::LIST]" << std::endl;
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(mstack);
}

int main()
{
    constructorOperatorTest();
    std::cout << std::endl;
    subjectTest();
    std::cout << std::endl;
    subjectTest2();
    std::cout << std::endl;
    iteratorIntTest();
    std::cout << std::endl;
    iteratorDoubleTest();
    std::cout << std::endl;
    stringIteratorTest();
    return 0;
}