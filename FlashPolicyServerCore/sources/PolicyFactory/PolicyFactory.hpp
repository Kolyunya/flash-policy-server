#ifndef POLICY_FACTORY_HPP
#define POLICY_FACTORY_HPP

#include <QObject>
#include <Kolyunya/FPS/Configurable>

namespace Kolyunya
{

    namespace FPS
    {

        class PolicyFactory :
            public QObject,
            public Configurable
        {
            Q_OBJECT
            public:
                explicit PolicyFactory ( QObject* parent );
                ~PolicyFactory ( void ) noexcept(true);
                QByteArray getPolicy ( void ) const;
                void initialize ( void );
            protected:
                QString getSettingsName ( void ) const override;
            private:
                void initializePolicy ( void );
                void getAllowedHosts ( void );
                void getPolicyBlank ( void );
                void preparePolicy ( void );
                QString allowedHosts;
                QString allowedPorts;
                QString policyBlank;
                QByteArray policy;
        };

    }

}

#endif // POLICY_FACTORY_HPP
