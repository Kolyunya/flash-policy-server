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
                explicit ClientRoutine ( QObject* parent = nullptr );
                void setSocketDescriptor ( qintptr socketDescriptor );
                void setPolicy ( const QByteArray& policy );
                void run ( void ) override;
            private:
                qintptr socketDescriptor;
                QByteArray policy;
        };

    }

}

#endif // CLIENT_ROUTINE_HPP
