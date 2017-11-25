#ifndef INVERTPROGRESSBAR_H
#define INVERTPROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>
#include <QPaintEvent>

class InvertProgressBar : public QProgressBar {
    Q_OBJECT
   public:
    explicit InvertProgressBar(QWidget *parent = nullptr);
    ~InvertProgressBar();

   protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

   signals:

   public slots:
};

#endif  // INVERTPROGRESSBAR_H
