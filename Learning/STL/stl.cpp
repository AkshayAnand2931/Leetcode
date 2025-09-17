#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

int main() {
    return 0;
}

void explainPairs() {

    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second;
}

void explainVectors() {
    
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vecPair;
    vecPair.push_back({1, 2});
    v.emplace_back(1, 2);

    vector<int> v1(5, 100); // [100,100,100,100,100]
    vector<int> v2(v1);

    vector<int>::iterator it = v.begin();
    vector<int>::iterator it_back = v.end();
    vector<int>::reverse_iterator it_rback = v.rend();
    vector<int>::reverse_iterator it_rbegin = v.rbegin();

    cout << v[0] << " " << v.at(0);
    cout << v.back() << " ";

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for(auto it: v) {
        cout << it << " ";
    }

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2, v.begin() + 4);

    vector<int> v3(2, 100);
    v3.insert(v.begin(), 300);
    v3.insert(v.begin() + 1, 2, 10);

    vector<int> copy(2, 50);
    v3.insert(v.begin(), copy.begin(), copy.end());

    cout << v3.size();

    v3.pop_back();

    v3.swap(v2);

    v3.clear();

    cout << v.empty();
}

void explainList() {
    list<int> ls;
    
    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front(5);
}

void explainDeque() {

    deque<int> dq;

    dq.push_back(1);
    dq.emplace_back(2);

    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();
    
    dq.front();
    dq.back();
}

void explainStack() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.emplace(3);

    cout << st.top();

    st.pop();

    st.size();
    st.empty();
    
    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back() += 5;

    cout << q.back();
    cout << q.front();

    q.pop();
}

void explainPriorityQueue() {
    //Max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.emplace(10);

    pq.top();

    pq.pop();

    cout << pq.top();

    //MinHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(10);
    minHeap.emplace(2);

    cout << minHeap.top();
}

void explainSet() {
    set<int> st;

    st.insert(1);
    st.emplace(2);
    st.insert(2); 

    auto it = st.find(1);
    auto it = st.find(6); //iterator to set.end()

    st.erase(2);
}

void explainMultiSet() {
    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    // store multiple

    ms.erase(1); //erase all
    ms.erase(ms.find(1)); //erase only 1
}

void explainUnorderedSet() {
    unordered_set<int> st;
    
    //Same as set
    //No lower bound or upper bound operation
    //No order
}

void explainMap() {
    map<int, int> mp;

    map<int, pair<int,int>> mp1;

    map<pair<int,int>,int> mp2;

    mp[1] = 2;
    mp.emplace(3, 4);
    mp.insert({2, 4});

    auto it = mp.find(3);
}

void explainUnorderedMap() {
    unordered_map<int, int> ump;
}

void explainAlgorithms() {
    int a[] = {1, 5, 2};
    int n = 3;

    sort(a, a + n); //ascending
    sort(a, a + n, greater<int>()); //descending

    int maxi = *max_element(a, a + n);
    int mini = *min_element(a, a + n);
}