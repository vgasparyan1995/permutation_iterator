#pragma once

#include <utility>

template <typename T>
void permutation_iterator<T>::advance()
{
    advance(m_indexes.size() - 1);
}

template <typename T>
void permutation_iterator<T>::advance(const int index)
{
    if (index == 0) {
        m_is_end = true;
        return;
    }
    if (m_indexes[index] != m_indexes.size() - 1 - index) {
        swap_left(m_indexes[index]);
        m_is_end = false;
    } else {
        m_is_end = true;
        advance(index - 1);
        for (int i = m_indexes[index]; i < m_indexes.size() - 1; ++i) {
            swap_right(i);
        }
    }
}

template <typename T>
void permutation_iterator<T>::swap_left(const int index)
{
    const auto tmp = m_permutation[index];
    m_permutation[index] = m_permutation[index - 1];
    m_permutation[index - 1] = tmp;
    const auto tmp_index = m_indexes[m_permutation[index].first];
    m_indexes[m_permutation[index].first] = m_indexes[m_permutation[index - 1].first];
    m_indexes[m_permutation[index - 1].first] = tmp_index;
}

template <typename T>
void permutation_iterator<T>::swap_right(const int index)
{
    const auto tmp = m_permutation[index];
    m_permutation[index] = m_permutation[index + 1];
    m_permutation[index + 1] = tmp;
    const auto tmp_index = m_indexes[m_permutation[index].first];
    m_indexes[m_permutation[index].first] = m_indexes[m_permutation[index + 1].first];
    m_indexes[m_permutation[index + 1].first] = tmp_index;
}

template <typename T>
std::vector<T> permutation_iterator<T>::get_permutation() const
{
    std::vector<T> result;
    result.reserve(m_permutation.size());
    for (const auto& item : m_permutation) {
        result.push_back(item.second);
    }
    return std::move(result);
}
