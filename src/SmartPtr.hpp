/***********************************************************************************************
*C++11 or boost shared_ptr is a better choice
**************************************************************************************************/
#ifndef _SMARTPTR_HPP_ 
#define _SMARTPTR_HPP_

#include <pthread.h>

template<class T>
class SmartPtr{
public:
    SmartPtr(T *p);
    ~SmartPtr();
    T* acquire();
    void release();
    SmartPtr(const SmartPtr<T> &orig);
    SmartPtr<T>& operator=(const SmartPtr<T> &rhs);
private:
    void decAndFree(void);
private:
    pthread_spinlock_t* spin; 
    T *ptr;
    volatile int* use_count;
};

template<class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p){
    use_count = new int(1);
    spin = new pthread_spinlock_t();
    pthread_spin_init(spin, PTHREAD_PROCESS_PRIVATE);
}

template<class T>
SmartPtr<T>::~SmartPtr(){
    decAndFree();
}

template<class T>
void SmartPtr<T>::decAndFree(void){
    T * freePtr = NULL;
    bool destroy = false;
    pthread_spin_lock(spin);
    (*use_count) --;
    if (0 == (*use_count)){
        freePtr = ptr;
        ptr = NULL;
        destroy = true;
    }
    pthread_spin_unlock(spin);  
    if (NULL != freePtr){
        delete freePtr;
    }
    if (destroy){
        delete use_count;
        pthread_spin_destroy(spin);
        delete spin;
    }
}

template<class T>
T* SmartPtr<T>::acquire(){
    pthread_spin_lock(spin);
    if((*use_count) > 0){
    	(*use_count)++;
    }
    pthread_spin_unlock(spin);
    return ptr;	
}

template<class T>
void SmartPtr<T>::release(){
    decAndFree();	
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig){
    pthread_spin_lock(orig.spin);
    spin = orig.spin;
    ptr = orig.ptr;
    use_count = orig.use_count;
    (*use_count)++;
    pthread_spin_unlock(orig.spin);
}

template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs){
    SmartPtr tmpPtr(*this); 

    pthread_spin_lock(rhs.spin);
    (*rhs.use_count) ++;
    ptr = rhs.ptr;
    use_count = rhs.use_count;
    spin = rhs.spin;
    pthread_spin_unlock(rhs.spin);

    tmpPtr.decAndFree();
    return *this;
}

#endif 
