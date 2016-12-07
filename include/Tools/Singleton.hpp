//
// Created by Kraghan on 02/12/2016.
//

#ifndef COMPLOTS_SINGLETON_HPP
#define COMPLOTS_SINGLETON_HPP

template <typename T>
class Singleton
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /// Get the instance of the singleton
    static T *      Instance()
    {
        if(m_instance == nullptr)
            m_instance = new T();

        return m_instance;
    }


    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    /// Singleton instance
    static T * m_instance;

    /// Default constructor
    explicit        Singleton() {};

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:

};

// Set the instance of the singleton to null
template <typename T> T * Singleton<T>::m_instance = nullptr;


#endif //COMPLOTS_SINGLETON_HPP
