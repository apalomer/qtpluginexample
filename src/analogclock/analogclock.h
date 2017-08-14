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

#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>
#include <bitset>
#include <iostream>
#include <iomanip>

class QDESIGNER_WIDGET_EXPORT AnalogClock : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool Hours READ getDisplayHours WRITE setDisplayHours)
    Q_PROPERTY(bool Minutes READ getDisplayMinutes WRITE setDisplayMinutes)
    Q_PROPERTY(bool Seconds READ getDisplaySeconds WRITE setDisplaySeconds)
    Q_PROPERTY(bool Milliseconds READ getDisplayMilliseconds WRITE setDisplayMilliseconds)
public:
    enum DISPLAY
    {
        DISPLAY_MS = 0X01,
        DISPLAY_S  = 0X02,
        DISPLAY_M  = 0X04,
        DISPLAY_H  = 0X08
    };
    explicit AnalogClock(QWidget* parent = 0);
    explicit AnalogClock(uchar display, QWidget *parent = 0);
    virtual ~AnalogClock();

    uchar getDisplayType();
    bool getDisplayHours();
    bool getDisplayMinutes();
    bool getDisplaySeconds();
    bool getDisplayMilliseconds();

public slots:
    void addDisplay(uchar display);
    void removeDisplay(uchar display);
    void setDisplay(uchar display);
    void setDisplayHours(bool display);
    void setDisplayMinutes(bool display);
    void setDisplaySeconds(bool display);
    void setDisplayMilliseconds(bool display);

signals:
    void displayTypeUpdated(AnalogClock* analog_clock);
    void displayTypeUpdated(uchar display);
    void displayTypeUpdated();

protected:
    void paintEvent(QPaintEvent *event);
private:
    uchar displayType_;
};

#endif
