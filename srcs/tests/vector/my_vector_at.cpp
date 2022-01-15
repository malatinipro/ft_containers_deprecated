#include "../../../includes.hpp"
#include "../../../vector.hpp"

#define TESTED_NAMESPACE ft

#define TESTED_TYPE int

//Les tests "at" permettent de tester la fonction "at"
//qui retourne la reference de l'element a la position n (du vecteur)
//At fait partie de la categorie des "element access"
int my_vector_at(void)
{
    //premier tests simple person
    ft::vector<int> vec(3, 3);
    int &ref = vec.at(2);
    std::cout << ref << std::endl;
    try
    {
        ref = vec.at(10);
    }
    catch (std::out_of_range)
    {
        std::cout << "Out of range error" << std::endl;
    }
    catch (...)
    {
        std::cout << "Error" << std::endl;
    }
    //Tests reference c plus plus
    ft::vector<int> myvector(10); // 10 zero-initialized ints

    // assign some values:
    for (unsigned i = 0; i < myvector.size(); i++)
        myvector.at(i) = i;

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';

    //Tests reference cpp
    ft::vector<int> data(6, 6);

    // Set element 1
    data.at(1) = 88;

    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';

    std::cout << "data size = " << data.size() << '\n';

    try
    {
        // Set element 6
        data.at(6) = 666;
    }
    catch (std::out_of_range const &exc)
    {
        std::cout << exc.what() << '\n';
    }

    std::cout << "data: " << std::endl;
    ft::vector<int>::iterator it = data.begin();
    ft::vector<int>::iterator ite = data.end();
    while (it != ite)
    {
        std::cout << (*it);
        it++;
    }
    std::cout << std::endl;
    return (0);
}