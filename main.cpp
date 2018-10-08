#include <iostream>

using namespace std;

template<typename T> class List {
    struct Elem {
        T data;
        Elem* next = nullptr;
        Elem(const T& data) :data(data) {}
    };

    Elem* head = nullptr;
    Elem* tail = nullptr;

public:

    void push_back(const T& data) {
        Elem* e = new Elem(data);
        if (head == nullptr) tail=head=e;
        else tail = tail->next = e;
    }





    class iterator{
        Elem* cur;
    public:
        explicit iterator(Elem* curvalue):cur(curvalue){}
        iterator& operator++(){
            cur=cur->next;
            return *this;
        }

        const iterator operator++(int){
            iterator old = *this;
            cur=cur->next;
            return old;
        }
        T&operator*() const{
            return cur->data;
        }
        T*operator->() const{
            return &(cur->data);
        }
        bool operator==(const iterator& iter)const {
            return this->cur == iter.cur;
        }
        bool operator!=(const iterator& iter)const {
            return this->cur != iter.cur;
        }
    };

    iterator begin() const{
        return iterator(head);
    }
    iterator end() const{
        return iterator(nullptr);
    }

};





int main() {

    List<int> lst;

    lst.push_back(2);
    lst.push_back(8);
    lst.push_back(10);

//   for(List<int>::iterator it = lst.begin();it!=lst.end();++it){
//       cout<<*it<<endl;
//   }

    int a[]={1,2,3};


    for(int elem:a){
        cout<<elem<<endl;
    }



    getchar();

    return 0;
}