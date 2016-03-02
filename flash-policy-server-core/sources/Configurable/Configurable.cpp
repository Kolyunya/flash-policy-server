#include <QtCore/QSettings>
#include <Kolyunya/FPS/Configurable>

using namespace Kolyunya::FPS;

void Configurable::setSettings ( QSettings* settings )
{
    this->settings = settings;
}

QVariant Configurable::getParameter ( const QString& parameterName )
{
    QString parameterKey = this->getParameterKey(parameterName);
    QVariant parameter = this->settings->value(parameterKey);
    return parameter;
}

QString Configurable::getParameterKey ( const QString& parameterName )
{
    QString settingsName = this->getSettingsName();
    QString parameterKey = settingsName + "/" + parameterName;
    return parameterKey;
}
