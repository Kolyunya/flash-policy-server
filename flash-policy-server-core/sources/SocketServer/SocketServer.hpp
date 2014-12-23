#ifndef SOCKET_SERVER_HPP
#define SOCKET_SERVER_HPP

#include <QTcpServer>
#include <Kolyunya/FPS/Configurable>

class QThreadPool;

namespace Kolyunya
{

    namespace FPS
    {

        class PolicyFactory;

        class SocketServer :
            public QTcpServer,
            public Configurable
        {
            Q_OBJECT
            public:
                explicit SocketServer ( QObject* parent );
                ~SocketServer ( void ) noexcept(true);
                void setThreadPool ( QThreadPool* threadPool );
                void setPolicyFactory ( PolicyFactory* policyFactory );
                void initialize ( void );
                void launch ( void );
            protected:
                QString getSettingsName ( void ) const override;
                void incomingConnection ( qintptr socketDescriptor ) override;
            private:
                QThreadPool* threadPool;
                PolicyFactory* policyFactory;
                QHostAddress hostName;
                quint16 port;
        };

    }

}

#endif // SOCKET_SERVER_HPP
