#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include<QHBoxLayout>
#include<QPushButton>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    void setBackgroundColor(const QString &color);
private:
      QHBoxLayout *layout;
      QPushButton *optionButton;
      QPushButton *minimizeButton;
      QPushButton *closeButton;

      QString bgColor;
protected:
      void paintEvent(QPaintEvent *event);
signals:
        void MinimizeButtonClicked();
        void CloseButtonClicked();

public slots:
};

#endif // TITLEBAR_H
