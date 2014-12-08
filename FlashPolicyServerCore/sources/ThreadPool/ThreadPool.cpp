#include <Kolyunya/FPS/ThreadPool>

using namespace Kolyunya::FPS;

ThreadPool::ThreadPool ( QObject* parent ) :
    QThreadPool(parent)
{

}

ThreadPool::~ThreadPool ( void ) noexcept(true)
{

}

void ThreadPool::initialize ( void )
{

    int maxThreadCount = this->getParameter("MaxThreadCount").toInt();
    if ( maxThreadCount > 0 )
    {
        this->setMaxThreadCount(maxThreadCount);
    }

    int threadExpiryTimeout = this->getParameter("ThreadExpiryTimeout").toInt();
    if ( threadExpiryTimeout > 0 )
    {
        this->setExpiryTimeout(threadExpiryTimeout);
    }

}

QString ThreadPool::getSettingsName ( void ) const
{
    QString settingsName = "ThreadPool";
    return settingsName;
}
