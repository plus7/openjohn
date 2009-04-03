#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class ConfigDialog;
}

class ConfigDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ConfigDialog)
public:
    explicit ConfigDialog(QWidget *parent = 0);
    virtual ~ConfigDialog();

    void createListItems();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ConfigDialog *m_ui;
};

#endif // CONFIGDIALOG_H
