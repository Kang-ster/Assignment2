#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <vector>
#include <stdexcept>

//new Vector that encapsulates std::vector
using std::vector;

//VECTOR SHOULD HAVE 'CRUD' CAPABILITIES
template <class T>
class Vector
{
	public:
	    Vector() {}; //STL Vector does not require custom constructor,
        Vector(int n);
        ~Vector() {}; //nor destructor

		//CRUD
        /** @brief Adds T object to the last position in the vector; calls Insert() with index as Size() <p>
        * See Insert() comments for further details
		* @param const T& item - T object to insert into the vector
		* @return bool
		*/
		bool Add(const T& item);

		/** @brief Adds T object to the vector in position index. <p>
        * Inserts the item through std::vector's insert <p>
        * If the index is equal to the current Size() of the vector, it uses push_back() to insert at the end of the vector instead <p>
        * Returns false if the index is out of range
		* @param const T& item - T object to insert into the vector
		* @return bool
		*/
		bool Insert(int index, const T & item); //C
//		bool Delete(int index); //D
		const T& operator[] (int index) const;  //R eg. cout << vec[1]
		T& operator[] (const int & index);      //U eg. vec[100] = 99
		int Size() const; //returns size as an int
		void Clear(); //reset the Vector ; <Vector> has its own Clear()
		void Resize();
		//deep copy not required in <Vector>

	private:
        vector<T> m_vector; //can be m_vector(size), but without so that you can use default constructor
};  // end of interface/declaration of the template class

template <class T>
Vector<T>::Vector(int n)
{
    //validate number
    if (n <= 0)
    {
        n=5; //don't crash the system; set size to 5 instead
    }
    m_vector.resize(n); //simple method to change the size :)
}

template <class T>
bool Vector<T>::Add(const T& item)
{
    //should be ADD method
    return Insert(Size(), item); //shows code reuse
    //<Vector> is from 0 to size-1; valid values are from 0 - size (insert at position size)
}

template <class T>
bool Vector<T>::Insert(int index, const T& item)
{
    if (index < 0 || index > Size())
    {
        return false; //out of range
    }
    else
    {
        if (index == Size())
        {
            m_vector.push_back(item); //insert at the end
        }
        else
        {
            m_vector.insert(m_vector.begin() + index, item); //insert() only takes in an iterator
        }
    }
    return true;
}

//template <class T> //**std::vector has clear(), pop_back() and erase()
//bool Vector<T>::Delete(int index) //no implicit need for Delete()
//{
//    //validate index
//    if (index<0 || IsIndexNull(index))
//        return false;
//    //remove item at index and pop array
//    for (int i=(m_size-1); i>index; i--) //decrement through vector
//        m_vector[i-1] = m_vector[i]; //pop through vector
//    m_size--; //decrement size
//    return true; //successful
//}

template <class T>
T& Vector<T>::operator[] (const int& index) //U
{
    //handle invalid index thru exception handling (0-n)
    if (index<0 || index>=m_vector.size())
       throw std::runtime_error("Index is out of range. ");
    return m_vector[index]; //pass by reference***
}

template <class T>
const T& Vector<T>::operator[] (int index) const //R
{
    //handle invalid index thru exception handling (0-n)
    if (index<0 || index>=m_vector.size())
       throw std::runtime_error("Index is out of range. ");
    return m_vector[index];
}


template <class T>
int Vector<T>::Size() const
{
    return m_vector.size();
}

//template <class T>
//void Vector<T>::Resize()
//a Resize() function is no longer needed
//as std::vector would automatically resize for us

template <class T>
void Vector<T>::Clear()
{
    m_vector.clear();
}

#endif // VECTOR_H_INCLUDED
