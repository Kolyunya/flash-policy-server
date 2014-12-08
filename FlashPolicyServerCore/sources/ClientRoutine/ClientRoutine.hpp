#ifndef CLIENT_ROUTINE_HPP
#define CLIENT_ROUTINE_HPP

#include <QtCore/QObject>
#include <QtCore/QRunnable>
#include <QtNetwork/QTcpSocket>
#include <Kolyunya/FPS/Configurable>

namespace Kolyunya
{

    namespace FPS
    {

        class ClientRoutine :
            public QObject,
            public QRunnable
        {
            Q_OBJECT
            public:
                void setSocketDescriptor ( qintptr socketDescriptor );
                void setPolicy ( const QByteArray& policy );
                void run ( void ) override;
            private:
                qintptr socketDescriptor;
                QByteArray policy;
            signals:
                void finished ( void );
        };

    }

}

#endif // CLIENT_ROUTINE_HPP
