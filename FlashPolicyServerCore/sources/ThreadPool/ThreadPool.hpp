#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <QtCore/QThreadPool>
#include <Kolyunya/FPS/Configurable>

namespace Kolyunya
{

    namespace FPS
    {

        class ThreadPool :
            public QThreadPool,
            public Configurable
        {
            Q_OBJECT
            public:
                explicit ThreadPool ( QObject* parent );
                ~ThreadPool ( void ) noexcept(true);
                void initialize ( void );
            protected:
                QString getSettingsName ( void ) const override;
        };

    }

}


#endif // THREAD_POOL_HPP
