/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
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


#ifndef SUBSCRIPTIONWINDOW_H
#define SUBSCRIPTIONWINDOW_H

#include <QWidget>
#include <QtMqtt/QMqttMessage>
#include <QtMqtt/QMqttSubscription>

#include "qcustomplot.h"

namespace Ui {
class SubscriptionWindow;
}

class SubscriptionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SubscriptionWindow(QMqttSubscription *sub, QWidget *parent = nullptr);
    ~SubscriptionWindow();

    static QString ByteArrayToHexString(QByteArray data);

public slots:
    void updateMessage(const QMqttMessage &msg);
    void updateStatus(QMqttSubscription::SubscriptionState state);

private:
    // 数据解析
    void AnalyticalData(QByteArray data);

    // 绘制背景
    void DrawBackground(QCustomPlot *CustomPlot, QString str);

    // 绘制曲线
    void Graph_Show(QCustomPlot *CustomPlot, QVector<double> port_x, QVector<double> port_y);

private:
    Ui::SubscriptionWindow *ui;
    QMqttSubscription *m_sub;   //  主题

    QVector<double> port1_x;
    QVector<double> port1_y_V;
    QVector<double> port1_y_I;
    QVector<double> port1_y_P;
    QVector<double> port1_y_Freq;

    QVector<double> port2_x;
    QVector<double> port2_y_Eq;
};

#endif // SUBSCRIPTIONWINDOW_H
