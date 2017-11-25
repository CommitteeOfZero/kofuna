#ifndef FLATCHECKBOX_H
#define FLATCHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <QPaintEvent>

/**
 * @brief QCheckBox with Win32 flat, white-on-black style
 *
 */
class FlatCheckBox : public QCheckBox {
    Q_OBJECT
   public:
    explicit FlatCheckBox(QWidget *parent = nullptr);
    ~FlatCheckBox();

   protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
   signals:

   public slots:
};

#endif  // FLATCHECKBOX_H
