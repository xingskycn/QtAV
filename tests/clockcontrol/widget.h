/******************************************************************************
    Clock control:  external clock controlling test
    Copyright (C) 2012-2013 Wang Bin <wbsecg1@gmail.com>

*   This file is part of QtAV

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>

namespace QtAV {
class WidgetRenderer;
class AVPlayer;
class AVClock;
}
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
public slots:
    void chooseVideo();

    void sendClock();
    void seekVideo(int);
protected slots:
    void slotStarted();
protected:
    virtual void timerEvent(QTimerEvent *);

private:
    class
    QtAV::WidgetRenderer *renderer;
    QtAV::AVPlayer *player;
    QtAV::AVClock *clock;
    QPushButton *send_btn, *file_btn, *play_btn, *pause_btn, *stop_btn;
    QSlider *slider;
    QSpinBox *time_box;
    QString vfile;
};

#endif // WIDGET_H
