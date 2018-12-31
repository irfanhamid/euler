#include <iostream>
#include <unordered_map>
#include <utility>

#include "../shared/list.hpp"

using namespace std;

/**
 * Assume an efficient copy ctor and assignment operator on types T and V
 */
template<typename K, typename V>
class LruCache
{
public:
    typedef euler::LinkNode_T<pair<K, V>> LinkNode;
    typedef std::unordered_map<K, LinkNode*> Tlb;

    LruCache(size_t capacity) : capacity_(capacity)
                              , head(nullptr)
    {}

    void Put(K key, V value)
    {
        if (cache_.size() == capacity_)
            EvictOldest();

        LinkNode* ln = new LinkNode(make_pair(key, value));
        if (cache_.find(key) == cache_.end())
            cache_[key] = ln;

        Refer(ln);
    }

    void EvictOldest()
    {
        if (head) {
            auto delNode = head->prev;
            auto kvp = delNode->data;
            head->prev = delNode->prev;
            head->prev->next = head;
            cache_.erase(kvp.first);
            delete delNode;
        }
    }

    bool Get(K key, V& value)
    {
        if (cache_.find(key) == cache_.end())
            return false;

        LinkNode* ln = cache_[key];
        Refer(ln);

        value = ln->data.second;
        return true;
    }

    void Refer(LinkNode* ln)
    {
        if (!head) {
            head = ln;
            head->prev = head;
        }

        ln->next = head;
        ln->prev = head->prev;
        head->prev = ln;
        head = ln;
        head->prev->next = head;
    }

private:
    size_t capacity_;
    Tlb cache_;
    LinkNode *head;
};

int main()
{
    LruCache<int, int> cache(5);

    for (int i = 0; i < 10; ++i)
        cache.Put(i, i);

    int v;
    for (int i = 9; i >= 0; --i)
        cout << "i: " << i << "\t" << cache.Get(i, v) << endl;

    return 0;
}