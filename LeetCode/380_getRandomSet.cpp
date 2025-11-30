#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

template <typename T>
void printVector(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename K, typename V>
void printMap(const unordered_map<K, V> &m)
{
    for (auto &p : m)
        cout << p.first << " -> " << p.second << endl;
}

class RandomizedSet
{
    unordered_map<int, int> mp;
    vector<int> keys;

public:
    RandomizedSet()
    {
        // unordered_map<int, int> mp;
        // vector<int> set;
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;

        mp[val] = keys.size();
        keys.push_back(val);

        return true;
    }

    bool remove(int val){
        if (mp.find(val) == mp.end()) return false;

        int index = mp[val];
        keys[index] = keys.back();
        mp[keys[index] ] = index;

        keys.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom(){
        int randomIndex = rand() % keys.size();
        return keys[randomIndex];
    }
};

int main()
{
    srand(time(0));
    RandomizedSet *obj = new RandomizedSet();

    // Operations based on the input
    obj->insert(0);
    obj->insert(1);
    obj->remove(0);
    obj->insert(2);
    obj->remove(1);
    cout << "Random: " << obj->getRandom() << endl;

    delete obj;
    return 0;
}
