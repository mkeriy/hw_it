#pragma once

#include <iostream>
#include <cassert>
namespace blr
{
	template<typename T>
	class victor
	{
		public:
		victor() :
			m_size(0), m_array(nullptr)
		{}

		victor(std::size_t size) :
			m_size(size)
		{
			assert(size >= 0);

			if (size > 0)
			{
				m_array = new T[size];
			}
			else
			{
				m_array = nullptr;
			}
		}

		victor(std::size_t size, T number) :
			m_size(size), m_number(number)
		{
			assert(size >= 0);
			if (size > 0)
			{
				m_array = new T[size];
				for (auto i = 0; i < size; ++i)
				{
					m_array[i] = number;
				}
			}
		}

		~victor()
		{
			delete[] m_array;
		}

		T& operator[](std::size_t index)
		{
			assert(index >= 0 && index < m_size);
			return m_array[index];
		}

	
		std::size_t lenth() { return m_size; }

		void erase()
		{
			delete[] m_array;

			m_array = nullptr;
			m_size = 0;
		}

		void resize(std::size_t newSize)
		{
			if (newSize = m_size)
			{
				return;
			}

			if (newSize <= 0)
			{
				erase();
			}

			T* newArray = new T[newSize];
			if (m_size > 0)
			{
				std::size_t ellemCop = (m_size > newSize) ? newSize : m_size;
				for (auto i = 0; i < ellemCop; ++i)
				{
					newArray[i] = m_array[i];
				}
			}

			delete[] m_array;
			m_array = newArray;
			m_size = newSize;
		}

		void insert(T value, std::size_t index)
		{
			assert(index >= 0 && index < m_size);

			T* newArray = new T[m_size + 1];

			for (auto i = 0; i < index; ++i)
			{
				newArray[i] = m_array[i];
			}

			newArray[index] = value;

			for (auto i = index; i < m_size + 1; ++i)
			{
				newArray[i + 1] = m_array[i];
			}
			delete[] m_array;
			m_array = newArray;
			++m_size;
		}

		void push_back(T value)
		{
			insert(value, m_size);
		}
		
		void push_forward(T value)
		{
			insert(value, 0);
		}


		void remove(std::size_t index)
		{
	
				assert(index >= 0 && index < m_size);

				if (m_size == 1)
				{
					erase();
					return;
				}

				
				T* newArray = new T[m_size - 1];

				for (auto i = 0; i < index; ++i)
				{
					newArray[i] = m_array[i];
				}

				for (auto i = index + 1; i < m_size; ++i)
				{
					newArray[i] = m_array[i];
				}
				delete[] m_array;
				m_array = newArray;
				++m_size;
			
		}

		void print()
		{
			for (auto i = 0; i < m_size; ++i)
			{
				std::cout << m_array[i] << ' ';
			}
			std::cout << std::endl;
		}

		void print(std::size_t index1, std::size_t index2)
		{
			assert(index1 >= 0 && index1 < m_size&& index2 > index1 && index2 < m_size);
			for (auto i = index1; i <= index2; ++i)
			{
				std::cout << m_array[i] << ' ';
			}
			std::cout << std::endl;
		}
		
		
		friend void swap(blr::victor<T> v1, blr::victor<T> v2)
		{
			std::swap(v1.m_size, v2.m_size);
			std::swap(v1.m_array, v2.m_array);
		}


		private:
		std::size_t m_size;
		T* m_array;
		T m_number;

	};
}