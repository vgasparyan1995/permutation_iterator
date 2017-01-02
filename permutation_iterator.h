#pragma once

#include <vector>
#include <algorithm>

namespace std {

template <typename T>
class permutation_iterator
{
public:
    permutation_iterator()
        : m_is_end(true)
    {}

    template <typename Iter>
    permutation_iterator(Iter first, Iter last)
        : m_is_end(first == last)
    {
        int index = 0;
        while (first != last) {
            m_permutation.push_back(std::make_pair(index, *first));
            m_indexes.push_back(index);
            ++index;
            ++first;
        }
        //std::reverse(m_indexes.begin(), m_indexes.end());
    }

    permutation_iterator(std::initializer_list<T> il)
        : m_is_end(il.size() == 0)
    {
        auto first = il.begin();
        auto last = il.end();
        int index = 0;
        while (first != last) {
            m_permutation.push_back(std::make_pair(index, *first));
            m_indexes.push_back(index);
            ++index;
            ++first;
        }
        //std::reverse(m_indexes.begin(), m_indexes.end());
    }

    permutation_iterator(const permutation_iterator&) = default;
    permutation_iterator& operator= (const permutation_iterator&) = default;
    ~permutation_iterator() = default;

    permutation_iterator& operator++ ()
    {
        advance();
        return *this;
    }

    permutation_iterator operator++ (int)
    {
        auto tmp = (*this);
        advance();
        return tmp;
    }

    std::vector<T> operator* () const
    {
        return get_permutation();
    }

    bool is_end() const
    {
        return m_is_end;
    }

private:
    void advance();
    void advance(const int index);
    void swap_left(const int index);
    void swap_right(const int index);
    std::vector<T> get_permutation() const;

private:
    std::vector< std::pair<int, T> > m_permutation;
    std::vector<int> m_indexes;
    bool m_is_end;
};

#include "permutation_iterator_impl.h"

} // namespace std
