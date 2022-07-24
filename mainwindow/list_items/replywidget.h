#ifndef REPLYWIDGET_H
#define REPLYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextDocument>
#include <QDebug>
#include "livedanmaku.h"
#include "listiteminterface.h"
#include "interactivebuttonbase.h"
#include "conditioneditor.h"

#define CODE_AUTO_REPLY_KEY (QApplication::applicationName() + ":AutoReply")

class ReplyWidget : public ListItemInterface
{
    Q_OBJECT
public:
    ReplyWidget(QWidget *parent = nullptr);

    virtual void fromJson(MyJson json) override;
    virtual MyJson toJson() const override;

    virtual bool isEnabled() const override;
    virtual QString title() const override;
    virtual QString body() const override;

signals:
    void signalReplyMsgs(QString msgs, LiveDanmaku danmaku, bool manual);

public slots:
    void slotNewDanmaku(LiveDanmaku danmaku);
    void autoResizeEdit() override;
    void triggerAction(LiveDanmaku danmaku);
    bool triggerIfMatch(QString msg, LiveDanmaku danmaku);

public:
    QLineEdit* keyEdit;
    ConditionEditor* replyEdit;

    bool keyEmpty = true;
    QRegularExpression keyRe;
};

#endif // REPLYWIDGET_H
