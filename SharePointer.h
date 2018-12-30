//
// Created by cfrenkel on 12/8/18.
//

#ifndef SHAREPOINTER_SHAREPOINTER_H
#define SHAREPOINTER_SHAREPOINTER_H

#include <stddef.h>
#include <iostream>



template<typename T>
class SharePointer
{
    public:
        template<class U>
        friend class SharePointer;

        explicit SharePointer(T* = NULL);
        SharePointer(const SharePointer &);

        template<class U>
        SharePointer(const SharePointer<U> &);

        ~SharePointer();

        T* operator->() const;
        T& operator*()  const;

        SharePointer& operator= (const SharePointer&);
        SharePointer& operator= (T*);

        bool operator!=(const SharePointer&) const;
        bool operator==(const SharePointer&) const;

        operator bool() const;

        T* get() const;
        size_t getRefCount();


    private:
        void release();
        void init();

        T * m_ptr;
        size_t * refCount;
};


template<typename T>
SharePointer<T>::SharePointer(T * ptr)
{
    try
    {
        m_ptr = ptr;
        init();
    }
    catch (std::bad_alloc&e)
    {
        delete ptr;
        throw;
    }

}

template<typename T>
void SharePointer<T>::init()
{
    refCount = new size_t;
    (*refCount) = 1;
}

template<typename T>
SharePointer<T>::SharePointer(const SharePointer & pointer)
{
    m_ptr = pointer.m_ptr;
    refCount = pointer.refCount;
    ++(*refCount);
}

template<typename T>
template<class U>
SharePointer<T>::SharePointer(const SharePointer<U> & pointer)
{
    m_ptr = pointer.m_ptr;
    refCount = pointer.refCount;
    ++(*refCount);
}

template<typename T>
SharePointer<T>::~SharePointer()
{
    release();
}

template<typename T>
void SharePointer<T>::release()
{
    --(*refCount);

    if (*refCount == 0)
    {
        delete m_ptr;
        delete refCount;
    }

}

template<typename T>
T* SharePointer<T>::get() const
{
    return m_ptr;
}

template<typename T>
size_t SharePointer<T>::getRefCount()
{
    return *refCount;
}

template<typename T>
SharePointer<T>& SharePointer<T>::operator=(const SharePointer&other)
{
    if (this != &other)
    {
        release();
        m_ptr = other.m_ptr;
        refCount = other.refCount;
        ++(*refCount);

    }

    return *this;
}

template<typename T>
SharePointer<T>& SharePointer<T>::operator=(T * other)
{
    release();
    try
    {
        m_ptr = other;
        init();
    }
    catch (std::bad_alloc&e)
    {
        delete other;
        throw;
    }
    return *this;
}

template<typename T>
T& SharePointer<T>::operator*() const
{
    return *m_ptr;
}

template<typename T>
T* SharePointer<T>::operator->() const
{
    return m_ptr;
}

template<typename T>
bool SharePointer<T>::operator!=(const SharePointer & ptr) const
{
    return ptr.m_ptr != m_ptr && ptr.refCount != refCount;
}

template<typename T>
bool SharePointer<T>::operator==(const SharePointer & ptr) const
{
    return ptr.m_ptr == m_ptr && ptr.refCount == refCount;
}

template<typename T>
SharePointer<T>::operator bool() const
{
    return m_ptr!=NULL;
}


#endif //SHAREPOINTER_SHAREPOINTER_H
