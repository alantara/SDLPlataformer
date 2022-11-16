#include <iostream>
using namespace std;

namespace Lists
{
    template <class TL>
    class List
    {
    public:
        template <class TE>
        class Element
        {
        private:
            Element<TE> *next;
            TE data;

        public:
            Element(TE info) : data(info), next(nullptr) {}

            Element<TE> *getNext() { return next; }
            void setNext(Element<TE> *el) { next = el; }

            TE getData() { return data; }
        };

    private:
        Element<TL> *first;
        Element<TL> *last;

    public:
        List() : first(nullptr), last(nullptr) {}
        ~List()
        {
            
        }

        Element<TL> *begin() { return first; }

        void insert(TL element)
        {
            Element<TL> *el = nullptr;
            el = new Element<TL>(element);
            if (first == nullptr)
            {
                first = el;
                last = el;
            }
            else
            {
                last->setNext(el);
                last = el;
            }
        }
    };
}