#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <map>
#include <iostream>

using std::map;

template <class K, class V>
using mItr = class map<K, V>::iterator;
template <class K, class V>
using cmItr = class map<K, V>::const_iterator;

template <class K, class V>
class Map{
public:
    typedef class map<K, V>::iterator mItr;
    typedef class map<K, V>::const_iterator cmItr;
    Map(){};
    bool InsertMap(const K index, const V item); //C
    V& Retrieve(const K index); //R
    V& operator[](const K& index); //U
    cmItr Begin() const;
    cmItr End() const;

    //Delete map?


private:
    map<K, V> m_map;
};

template <class K, class V>
bool Map<K,V>::InsertMap(const K index, const V item)
{
    m_map.insert({index, item});
}

template <class K, class V>
V& Map<K,V>::Retrieve(const K index)
{
    if (m_map.find(index)==m_map.end())
    {
        std::cout << "DEBUG: " << index << " does not exist" << std::endl;
    }
    return m_map.at(index);
    std::cout << "DEBUG " <<index<<" found successfully"<<std::endl;
}

template <class K, class V>
V& Map<K,V>::operator[](const K& index)
{
    return m_map[index];
}

template <class K, class V>
cmItr<K, V> Map<K, V>::Begin() const
{
    return m_map.begin();
}

template <class K, class V>
cmItr<K, V> Map<K, V>::End() const
{
    return m_map.end();
}


#endif // MAP_H_INCLUDED
