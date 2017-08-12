/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "digitalclock.h"
#include "digitalclockplugin.h"

#include <QtPlugin>

DigitalClockPlugin::DigitalClockPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void DigitalClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool DigitalClockPlugin::isInitialized() const
{
    return initialized;
}

QWidget *DigitalClockPlugin::createWidget(QWidget *parent)
{
    return new DigitalClock(parent);
}

QString DigitalClockPlugin::name() const
{
    return "DigitalClock";
}

QString DigitalClockPlugin::group() const
{
    return "Custom created widgets [Example]";
}

QIcon DigitalClockPlugin::icon() const
{
    return QIcon();
}

QString DigitalClockPlugin::toolTip() const
{
    return "";
}

QString DigitalClockPlugin::whatsThis() const
{
    return "";
}

bool DigitalClockPlugin::isContainer() const
{
    return false;
}

QString DigitalClockPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"DigitalClock\" name=\"digitalClock\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>The current time</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The Digital clock widget displays the current time.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QString DigitalClockPlugin::includeFile() const
{
    return "digitalclock.h";
}
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    Q_EXPORT_PLUGIN2(digitalclockplugin, DigitalClockPlugin)
#endif
