#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <list>
#include <vector>
#include <functional>

template<typename T>
class HashSet{
    std::vector<std::list<T>> table;
    int numBuckets;
    int size;

    int hashFunction(const T& key) const{
        return std::hash<T>{}(key)%numBuckets;
    }
public:
    explicit HashSet(const int buckets_num=50):numBuckets(buckets_num),size(0){table.resize(numBuckets);}
    void insert(const T& key);
    bool find(const T& key) const;
    void remove(const T& key);
    int getSize() const;
    void printTable() const;
};

template <typename T>
void HashSet<T>::insert(const T& key){
    int index=hashFunction(key);
    auto& chain= table[index];
    for (const T& element:chain){
        if (element==key) return;
    }
    chain.push_back(key);
    size++;
}

template <typename T>
bool HashSet<T>::find(const T& key) const
{
    int index=hashFunction(key);
    const auto& chain=table[index];
    for (const T& element : chain)
    {
        if (element==key) return true;
    }
    return false;
}

template <typename T>
void HashSet<T>::remove(const T& key)
{
    int index=hashFunction(key);
    auto& chain = table[index];
    chain.remove(key);
    size--;
}

template <typename T>
int HashSet<T>::getSize() const
{
    return size;
}

template <typename T>
void HashSet<T>::printTable() const
{
    for (int i = 0; i <numBuckets; ++i)
    {
        std::cout<<"Bucket "<<i<<": ";
        for (const T& element : table[i])
        {
            std::cout << element << " ";
        }
        std::cout<<std::endl;
    }
}

#endif // HASHTABLE_H
