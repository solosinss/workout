#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

template <typename T>
inline int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;

    if (v2 < v1) return 1;

    return 0;
}

template <class T> class Queue;
template <class T> class QueueItem;
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T> class Queue {
    public:
        template <class It>
            Queue(It beg, It end):
                head(0), tail(0) {copy_elems(beg, end); }
        template <class Iter> void assign(Iter, Iter);

        Queue(): head(0), tail(0) {
            cout << "Queue default constructor" << endl;
        }
        Queue(const Queue &Q): head(0), tail(0) {
            cout << "Queue copy ctrl" << endl;
            copy_elems(Q);
        }
        Queue& operator=(const Queue &);
        ~Queue() { 
            cout << "Queue destructor" << endl;
            destroy(); }
        T &front() { 
            cout << "Queue return front" << endl;
            return head->item; }
        const T &front() const { 
            cout << "Queue return front" << endl;
            return head->item; }
        void push (const T &);
        void pop();
        bool empty() const { 
            cout << "Queue check empty" << endl;
            return head == 0; }
        friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);
    private:
        QueueItem<T> *head;
        QueueItem<T> *tail;
        void destroy();
        void copy_elems(const Queue&);
        template <class Iter> void copy_elems(Iter, Iter);
};

template <class T> template <class Iter>
void Queue<T>::assign(Iter beg, Iter end)
{
    destroy();
    copy_elems(beg, end);
}

template <class T> template <class It>
void Queue<T>::copy_elems(It beg, It end)
{
    while (beg != end)
    {
        push(*beg);
        ++beg;
    }
}

template <class T> Queue<T>& Queue<T>::operator=(const Queue &q)
{
    cout << "Queue operator=" << endl;
    if (&q != this)
    {
        copy_elems(q);
    }
    
    return *this;
}   

template <class T> void Queue<T>::destroy()
{
    cout << "Queue destroy" << endl;
    while(!empty())
        pop();
}

template <class T> void Queue<T>::pop()
{
    cout << "Queue pop" << endl;
    QueueItem<T> *p = head;
    if(head != NULL)
    {
        head = head->next;
        delete p;
    }
    else
        cout << "Empty queue" << endl;
}

template <class T> void Queue<T>::push(const T &val)
{
    cout << "Queue push" << endl; 
    QueueItem<T> *pt = new QueueItem<T>(val);

    if(empty())
        head = tail = pt;
    else
    {
        tail->next = pt;
        tail = pt;
    }
}

template <class T> void Queue<T>::copy_elems(const Queue &orig)
{
    cout << "Queue copy elems" << endl;
    for (QueueItem<T> *pt = orig.head; pt != NULL; pt = pt->next)
        push(pt->item);
}

template <class T> class QueueItem {
    QueueItem(const T &t): item(t), next(0) { cout << "QueueItem copy ctrl" << endl; }
    T item;
    QueueItem *next;
    friend class Queue<T>;
    friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);
};

template <class T>
ostream& operator<<(ostream &os, const Queue<T> &q)
{
    os << "< ";
    QueueItem<T> *p;
    for (p = q.head; p; p = p->next)
        os << p->item << " ";

    os << ">";

    return os;
}

int main()
{
    string s1 = "hi";
    string s2 = "hello";
    cout << compare(1, 0) << endl;
    cout << compare(s1, s2) << endl;
    cout << compare(2.13, 5.15) << endl;

    Queue<int> qi;
    Queue<int> qii;    
    short s = 42;
    int i = 55;

    qi.push(s);
    qi.push(i);
    qi.push(11);
    qi.push(13);

    qii = qi;
    qi.pop();

    cout << qi << endl;
    cout << qii << endl << endl;

    short a[4] = {0,3,6,9};
    Queue<int> qi2(a, a+4);
    cout << qi2 << endl;
    vector<int> vi(a, a+4);

    qi2.assign(vi.begin(), vi.end());
    cout << qi2 << endl;
    
    while (1)
    {
        usleep(1000);
    }
    return 0;
}
