#include <QtNetwork/QTcpSocket>
#include <Kolyunya/FPS/ClientRoutine>

#ifdef QT_DEBUG
    #include <QtCore/QDebug>
    #include <QtNetwork/QHostAddress>
#endif

using namespace Kolyunya::FPS;

ClientRoutine::ClientRoutine ( QObject* parent ) :
    QObject(parent)
{

}

void ClientRoutine::setSocketDescriptor ( qintptr socketDescriptor )
{
    this->socketDescriptor = socketDescriptor;
}

void ClientRoutine::setPolicy ( const QByteArray& policy )
{
    this->policy = policy;
}

void ClientRoutine::run ( void )
{

    // Send policy
    QTcpSocket* socket = new QTcpSocket();
    socket->setSocketDescriptor(this->socketDescriptor);
    socket->write(this->policy);
    socket->flush();

    // Print debug message
    #ifdef QT_DEBUG
        qDebug()
            << "Policy sent to"
            << socket->peerAddress().toString()
            << socket->peerPort();
    #endif

    socket->close();
    delete socket;

}
