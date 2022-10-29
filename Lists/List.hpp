#pragma once

namespace Lists
{
template<class TL>
class List
{
public:
    List():first(nullptr), atual(nullptr) {}
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
        Elemento(TE &i = nullptr):next(nullptr){ info = i;}
        ~Elemento(){next = nullptr; info = nullptr;}

        TE* GetInfo() const {return info;}
        void SetInfo(TE* i) {info = i;}

        Elemento<TE>* GetNext() const {return next;}
        void SetNext(Elemento<TE>* n) {next = n;}
    };

    void insert(TL &info)
    {
        Elemento<TL>* el = nullptr;
        el = new Elemento<TL>(info);
        if(first == nullptr){
            first = el;
            atual = el;
        }
        else{
            atual->SetNext(el);
            atual = atual->GetNext();
        }
    }

    Elemento<TL>* begin() const
    {
        return first;
    }

    private:
    Elemento<TL>* first;
    Elemento<TL>* atual;
};
}