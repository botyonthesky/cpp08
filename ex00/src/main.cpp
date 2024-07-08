/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:32:29 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/08 08:54:49 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.tpp"

int main()
{
    {
        std::cout << "[ EASY TO FIND VECTOR TEST ]" << std::endl;
        const int arr[] = {11, 33, 42, 54, 65};
        const size_t size(sizeof(arr) / sizeof(int));
        std::vector<int> vect(arr, arr + size);
        printValueVector(vect);
        std::cout << std::endl;
        try
        {
            std::cout << "Try to find the value 42 ->" << std::endl;
            std::vector<int>::iterator it = easyfind(vect, 42);
            std::cout << "We find the value : " << *it << " in the container" << std::endl << std::endl;
            std::cout << "Try to find the value 65 ->" << std::endl;
            std::vector<int>::iterator it2 = easyfind(vect, 65);
            std::cout << "We find the value : " << *it2 << " in the container" << std::endl << std::endl;
            std::cout << "Try to find the value 84 ->" << std::endl;    
            std::vector<int>::iterator it3 = easyfind(vect, 84);
            std::cout << "We find the value : " << *it3 << " in the container" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "[ EASY TO FIND LIST TEST ]" << std::endl;
        std::list<int> lst;
        lst.push_back(84);
        lst.push_back(42);
        lst.push_back(21);
        lst.push_front(168);
        lst.push_front(336);
        printValueList(lst);
        std::cout << std::endl;
        try
        {
            std::cout << "Try to find the value 42 ->" << std::endl;
            std::list<int>::iterator it = easyfind(lst, 42);
            std::cout << "We find the value : " << *it << " in the container" << std::endl << std::endl;
            std::cout << "Try to find the value 84 ->" << std::endl;
            std::list<int>::iterator it2 = easyfind(lst, 84);
            std::cout << "We find the value : " << *it2 << " in the container" << std::endl << std::endl;
            std::cout << "Try to find the value 168 ->" << std::endl;
            std::list<int>::iterator it3 = easyfind(lst, 168);
            std::cout << "We find the value : " << *it3 << " in the container" << std::endl << std::endl;
            std::cout << "Try to find the value 20 ->" << std::endl;
            std::list<int>::iterator it4 = easyfind(lst, 20);
            std::cout << "We find the value : " << *it4 << " in the container" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}