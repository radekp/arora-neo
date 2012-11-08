/****************************************************************************
**
** This file was largely copied from examples/webviewer/webviewer.cpp
** in the QtMoko distribution.  But given that it has so few lines of
** code, and that that code simply implements what standard Qtopia
** documentation says for a Qtopia service, I don't think it has to
** inherit that file's copyright and license.  For the same reasons,
** we don't declare any specific copyright and license for this file.
**
****************************************************************************/

#ifndef WEBSERVICE_H
#define WEBSERVICE_H

#include <qobject.h>
#include <qtopiaabstractservice.h>
#include <qstring.h>

class WebAccessService : public QtopiaAbstractService
{
    Q_OBJECT

public:
    WebAccessService(QObject* parent) : QtopiaAbstractService("WebAccess",parent)
    {
        publishAll();
    }

signals:
    void openUrl(const QString &);

public slots:
    void openURL(QString);
    void openSecureURL(QString);
};

#endif
