#pragma once

#include <iostream>

namespace ft
{
    template <class T, T v>
    class integral_constant
    {
    public:
        const static T value = v;
        typedef T value_type;
        typedef integral_constant<T, v> type;
        const value_type operator()() const { return value; }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>
    struct is_integral : public false_type
    {
    };

    template <class T>
    struct is_integral<const T> : public is_integral<T>
    {
    };
    template <class T>
    struct is_integral<volatile const T> : public is_integral<T>
    {
    };
    template <class T>
    struct is_integral<volatile T> : public is_integral<T>
    {
    };

    template <>
    struct is_integral<unsigned char> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned short> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long> : public true_type
    {
    };
    template <>
    struct is_integral<signed char> : public true_type
    {
    };
    template <>
    struct is_integral<short> : public true_type
    {
    };
    template <>
    struct is_integral<int> : public true_type
    {
    };
    template <>
    struct is_integral<long int> : public true_type
    {
    };
    template <>
    struct is_integral<long long int> : public true_type
    {
    };
    template <>
    struct is_integral<unsigned long long int> : public true_type
    {
    };
    template <>
    struct is_integral<char> : public true_type
    {
    };
    template <>
    struct is_integral<bool> : public true_type
    {
    };

    template <class Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    class iterator_traits<T *>
    {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T *>
    {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    //If B is true, std::enable_if has a public member typedef type,
    //equal to T; otherwise, there is no member typedef.
    template <bool B, typename T = void>
    struct enable_if
    {
    };

    template <typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    //https://www.geeksforgeeks.org/stdequal-in-cpp/
    //std::equal() helps to compare the elements wihin the range (first, last) with those within the range beginning at first_2
    template <typename InputIterator1, typename InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
}

//Lexicographical compare
namespace ft
{
    //Implementation inspiree de la documentation officielle
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2)
    {

        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (*first1 < *first2)
                return true;
            //On retourne true si la premiere range est lexicographiquement inferieure a la seconde 
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    // Implementation inspiree de la documentation officielle
    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2,
                                 Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (comp(*first1, *first2))
            {
                return true;
            }
            if (comp(*first2, *first1))
            {
                return false;
            }
        }
        return (first1 == last1) && (first2 != last2);
    }
}