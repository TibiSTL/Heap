#pragma once
#include <vector>
using namespace std;
template <
    class Type,
    class Container = vector<Type>,
    class Compare = less<typename Container::value_type>
>
class heap {
private:
    vector<Type> tmp;
public:
    void insert(Type x) {
        tmp.insert(upper_bound(tmp.begin(), tmp.end(), x), x);
    }
    Type max() {
        return tmp[tmp.size() - 1];
    }
    Type min() {
        return tmp[0];
    }
    int find(Type x) {
        int st = 0, dr = tmp.size() - 1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (tmp[mid] == x) {
                return mid;
            }
            if (tmp[mid] < x) {
                st = mid + 1;
            }
            else {
                dr = mid - 1;
            }
        }
        return -1;
    }
    int uppr_bound(Type x) {
        return upper_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
    int lwr_bound(Type x) {
        return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
    vector<Type> make_vector() {
        return tmp;
    }
    heap<Type> merge(heap<Type> a) {
        vector<Type> b = a.make_vector();
        vector<Type> c;
        int p1, p2;
        p1 = p2 = 0;
        while (p1 < b.size() && p2 < tmp.size()) {
            if (b[p1] < tmp[p2])
                c.push_back(b[p1++]);
            else
                c.push_back(tmp[p2++]);
        }
        while (p1 < b.size())
            c.push_back(b[p1++]);
        while (p2 < tmp.size())
            c.push_back(tmp[p2++]);
        heap<Type> aux;
        aux.tmp = c;
        return aux;
    }
    void modify(int index, Type val) {
        tmp[index] = val;
    }
    Type get(int index) {
        return tmp[index];
    }
    void init(vector<Type> a) {
        for (auto i : a)
            tmp.insert(upper_bound(tmp.begin(), tmp.end(), i), i);
    }
};