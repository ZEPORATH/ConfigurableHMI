#ifndef SINGLETONPROVIDER_H
#define SINGLETONPROVIDER_H
#include <iostream>
#include <thread>
#include <mutex>
#include <QObject>

template<class T> class singleton
{
public:
    static T* instance()
    {
        static cleanup cleanup;
        std::lock_guard<std::mutex>guard(sMutex);

        if (m_pInstance == nullptr)
        {
            m_pInstance = new T;
        }

        //std::cout  << Q_FUNC_INFO << " thread id: 0x" << std::hex << std::this_thread::get_id() << std::dec << std::endl;
        return m_pInstance;
    }

    static T* instance(QObject* obj)
    {
        static cleanup cleanup;
        std::lock_guard<std::mutex>guard(sMutex);

        if (m_pInstance == nullptr)
        {
            m_pInstance = new T(obj);
        }

        return m_pInstance;
    }
protected:
    static T* m_pInstance;

    friend class cleanup;
    class cleanup
    {
    public:
        ~cleanup()
        {
            std::lock_guard<std::mutex>guard(singleton::sMutex);
            if (m_pInstance != nullptr)
            {
                delete singleton::m_pInstance;
                singleton::m_pInstance = nullptr;
            }
        }
    };

private:
    singleton();
    virtual ~singleton();
    singleton(const singleton&);
    singleton& operator =(const singleton&);

    static std::mutex sMutex;
};

template<typename T> T* singleton<T>::m_pInstance = nullptr;
template<typename T> std::mutex singleton<T>::sMutex;
#endif // SINGLETONPROVIDER_H
