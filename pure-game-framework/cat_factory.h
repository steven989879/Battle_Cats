#pragma once
#ifndef CAT_FACTORY_H
#define CAT_FACTORY_H

#include"cat_one.h"
#include"monster.h"
#include <list>
#include <vector>
#include <map>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include".\Source\.\Library\gameutil.h"

template<class T>
class cat_factory
{
	static T* create_cat(int cat_size);

	~cat_factory();
};

template <class T>
cat_factory<T>::~cat_factory<T>()
{

}

template <class T>
T* cat_factory<T>::create_cat(int cat_size){
	T *temp1 = new T();
	return(temp1);
}

#endif // !CAT_FACTORY_H
