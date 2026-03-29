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
    void Insert(int index, const V item);
    V Retrieve(int index) const;
    cmItr<K, V> Begin();
    cmItr<K, V> End();

private:
    map<K, V> m_map;
};

template <class K, class V>
void Map<K,V>::Insert(int index, const V item)
{
    m_map.insert({index, item});
}

template <class K, class V>
V Map<K,V>::Retrieve(int index) const
{
    return m_map.at(index);
}

template <class K, class V>
cmItr<K, V> Map<K, V>::Begin()
{
    return m_map.begin();
}

template <class K, class V>
cmItr<K, V> Map<K, V>::End()
{
    return m_map.end();
}
#endif // MAP_H_INCLUDED
