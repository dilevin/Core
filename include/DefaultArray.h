#ifndef _DEFAULTARRAY_H
#define _DEFAULTARRAY_H

#include "CoreDefines.h"
#include "Array.h"

/**
* DefaultArray - simple main-memory array that is non-resizable and non-mappable
*/
namespace Core
{
	template<typename TYPE>
	class DefaultArray : public Array<TYPE>
	{

	public:

		explicit DefaultArray(const size_t numElements, const size_t bufferSize  = 0);
		DefaultArray(const DefaultArray &toCopy);

		virtual ~DefaultArray();

		//Accessors
		inline const TYPE & get(const unsigned int index) const;
		inline void set(const unsigned int index, const TYPE &value);
		inline TYPE & set(const unsigned int index);

		//operators
		inline TYPE & operator[](unsigned int index);

		//Create mapped array
		static Array<TYPE> * map(const Array &toCopy); 

	protected:

		TYPE *m_memPtr; //ptr to memory

	private:

		
	};

}


//Implementation 
namespace Core 
{

	template<typename TYPE>
	DefaultArray<TYPE>::DefaultArray(const size_t numElements, const size_t bufferSize  = 0) : Array<TYPE>(numElements, bufferSize)
	{
		m_memPtr = new TYPE[m_bufferSize];
	}

	template<typename TYPE>
	DefaultArray<TYPE>::DefaultArray(const DefaultArray &toCopy)
	{
		if(m_bufferSize < toCopy.m_bufferSize)
		{
			delete[] m_memPtr;
			m_memPtr = new TYPE[toCopy.m_bufferSize];
		}

		m_bufferSize = toCopy.m_bufferSize;
		m_numElements = toCopy.m_numElements;

		MEMCPY(m_memPtr, m_bufferSize, toCopy.m_memPtr, toCopy.m_numElements*sizeof(TYPE));
		
	}

	template<typename TYPE>
	DefaultArray<TYPE>::~DefaultArray()
	{
		delete[] m_memPtr;
	}

	//Accesors
	template<typename TYPE>
	inline const TYPE & DefaultArray<TYPE>::get(const unsigned int index) const
	{
		assert(index < m_bufferSize);
		return m_memPtr[index];
	}

	template<typename TYPE>
	inline void DefaultArray<TYPE>::set(const unsigned int index, const TYPE &value)
	{
		assert(index < m_bufferSize);
		m_memPtr[index] = value;
	}

	template<typename TYPE>
	inline TYPE & DefaultArray<TYPE>::set(const unsigned int index)
	{
		assert(index < m_bufferSize);
		return m_memPtr[index];
	}

	//operators
	template<typename TYPE>
	inline TYPE & DefaultArray<TYPE>::operator[](unsigned int index)
	{
		assert(index < m_bufferSize);
		return m_memPtr[index];
	}

	//Create mapped array
	template<typename TYPE>
	static Array<TYPE> * DefaultArray<TYPE>::map(const Array &toCopy) 
	{
		std::cout<<"No mapping operator implemented\n";
	}

}

#endif