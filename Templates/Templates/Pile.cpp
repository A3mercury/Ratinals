#include "Pile.h"

template<typename T>
Pile<T>::Pile<T>(void)
{
	count = 0;
}

template<typename T>
Pile<T>::~Pile<T>(void)
{
}

template<typename T>
void Pile<T>::Toss(T newItem)
{
	list[count] = newItem;
	count++;
}

template<typename T>
T Pile<T>::Tip() const
{
	return list[count - 1];
}

template<typename T>
T Pile<T>::Burn()
{
	count--;
	return list[count];
}

template<typename T>
T Pile<T>::getCount() const
{
	return count;
}