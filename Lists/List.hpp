#pragma once

namespace Lists
{
template<class TL>
class List
{
public:
    List():first(nullptr),last(nullptr) {}
    ~List()
    {
        Elemento<TL>* aux = nullptr;
        aux = first;
        while(aux != nullptr){
            first = first->GetNext();
            delete aux;
            aux = first;
        }
    }

    template<class TE>
    class Elemento
    {
    private:
        Elemento<TE>* next;
        TE* info;
    public:
        Elemento(TE* i = nullptr):info(i), next(nullptr){}
        ~Elemento(){next = nullptr; info = nullptr;}

        TE* GetInfo() const {return info;}
        void SetInfo(TE* i) {info = i;}

        Elemento<TE>* GetNext() const {return next;}
        void SetNext(Elemento<TE>* n) {next = n;}
    };

    void insert(TL* elem)
    {
        Elemento<TL>* el = nullptr;
        el = new Elemento(elem);
        if(first == nullptr){
            first = el;
            last = el;
        }
        else{
            last->SetNext(el);
            last = last->GetNext();
        }
    }

    Elemento<TL>* begin() const
    {
        return first;
    }

    Elemento<TL>* end() const
    {
        return last;
    }

    private:
    Elemento<TL>* first;
    Elemento<TL>* last;
};
}