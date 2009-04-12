#ifndef IMGVIEWDIALOG_H
#define IMGVIEWDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class ImgViewDialog;
}

class ImgViewDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ImgViewDialog)
public:
    explicit ImgViewDialog(QWidget *parent = 0);
    virtual ~ImgViewDialog();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ImgViewDialog *m_ui;
};

#endif // IMGVIEWDIALOG_H
