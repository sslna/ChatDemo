#ifndef CLICKEDLABLE_H
#define CLICKEDLABLE_H
#include <QLabel>
#include "global.h"


class ClickedLable:public QLabel
{
    Q_OBJECT
public:
    ClickedLable(QWidget *parent=nullptr);
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    void SetState(QString normal="",QString hover="",QString press="",
                  QString select="",QString select_hover="",QString select_press="");
    ClickLbState GetCurState();

private:
    QString _normal;
    QString _normal_hover;
    QString _normal_press;

    QString _selected;
    QString _selected_hover;
    QString _selected_press;
    ClickLbState _curstate;
signals:
    void clicked(void);
};

#endif // CLICKEDLABLE_H
