#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>
/**
* Array - base class for methods that allocate memory on a heap. Array's may be able to dynamically resize themselves, the can be either copied from
* (new allocation) or mapped from (no new allocation just use pointer from other array) an existing array. 
*/
namespace Core
{
	template<typename TYPE>
	class Array 
	{

	public:

		explicit Array(const size_t numElements, const size_t bufferSize  = 0);
		Array(const Array &toCopy);

		virtual ~Array();

		//Accesors
		virtual const TYPE & get(const unsigned int index) const;
		virtual void set(const unsigned int index, const TYPE &value);
		virtual TYPE & set(const unsigned int index);

		//operators
		virtual TYPE & operator[](unsigned int index);

		//Create mapped array
		static Array<TYPE> * map(const Array &toCopy); 

	protected:

		bool m_mapped; //true if array is mapped from another array, false otherwise
		bool m_resizable; //true if array is dynamically resizable, false otherwise

		size_t m_numElements;
		size_t m_bufferSize;

	private:
		
		TYPE failure;
	};

}


//Implementation 
namespace Core 
{
	template<typename TYPE>
	Array<TYPE>::Array(const size_t numElements, const size_t bufferSize  = 0)
	{
		//by default arrays are not resizable and not mapped
		m_mapped = false;
		m_resizable = false;

		if(bufferSize < numElements) {
			std::cout<<"bufferSize < numElements: Setting bufferSize = numElements \n";
			m_bufferSize = numElements;
		} else {
			m_bufferSize = bufferSize;
		}

		m_numElements = numElements;
	}

	template<typename TYPE>
	Array<TYPE>::Array(const Array &toCopy)
	{
		std::cout<<"Array base class copy constructor \n";
	}

	template<typename TYPE>
	Array<TYPE>::~Array()
	{
		//Default destructor does nothing
	}

	//Accesors
	template<typename TYPE>
	const TYPE & Array<TYPE>::get(const unsigned int index) const
	{
		std::cout<<"Array base class get method \n";
		return failure; //This does nothing, just gets around the compiler complaining that I need to return something
	}

	template<typename TYPE>
	void Array<TYPE>::set(const unsigned int index, const TYPE &value)
	{
		std::cout<<"Array base class set method \n";
	}

	template<typename TYPE>
	TYPE & Array<TYPE>::set(const unsigned int index)
	{

		std::cout<<"Array base class set method \n";
		return failure;
	}

	//operators
	template<typename TYPE>
	TYPE & Array<TYPE>::operator[](unsigned int index)
	{
		std::cout<<"Array base class [] operator \n";
		return failure;
	}

	//Create mapped array
	template<typename TYPE>
	Array<TYPE> * Array<TYPE>::map(const Array &toCopy)
	{
		std::cout<<"Array base class Map \n";
		return new Array(0, 0);
	}
}

#endif