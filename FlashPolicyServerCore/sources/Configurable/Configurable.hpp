#ifndef CONFIGURABLE_HPP
#define CONFIGURABLE_HPP

#include <QtCore/QString>
#include <QtCore/QVariant>

class QSettings;

namespace Kolyunya
{

    namespace FPS
    {

        class Configurable
        {
            public:
                virtual ~Configurable ( void ) = default;
                void setSettings ( QSettings* settings );
            protected:
                virtual QString getSettingsName ( void ) const = 0;
                QVariant getParameter ( const QString& parameterName );
                QSettings* settings;
        };

    }

}

#endif // CONFIGURABLE_HPP
