#ifndef POLICY_SERVER_HPP
#define POLICY_SERVER_HPP

#include <QtCore/QCoreApplication>

class QSettings;

namespace Kolyunya
{

    namespace FPS
    {

        class ThreadPool;

        class PolicyFactory;

        class SocketServer;

        class PolicyServer :
            public QCoreApplication
        {
            Q_OBJECT
            public:
                explicit PolicyServer ( int& argc , char** argv );
            private:
                void initializeSettings ( void );
                void initializeThreadPool ( void );
                void initializePolicyFactory ( void );
                void initializeSocketServer ( void );
                QSettings* settings;
                ThreadPool* threadPool;
                PolicyFactory* policyFactory;
                SocketServer* socketServer;
        };

    }

}

#endif // POLICY_SERVER_HPP
