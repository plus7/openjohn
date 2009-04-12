#ifndef BBSMENUFETCHDIALOG_H
#define BBSMENUFETCHDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class BBSMenuFetchDialog;
}
class QHttp;
class QFile;
class BBSMenuFetchDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(BBSMenuFetchDialog)
public:
    explicit BBSMenuFetchDialog(QWidget *parent = 0);
    virtual ~BBSMenuFetchDialog();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::BBSMenuFetchDialog *m_ui;
    QHttp *m_http;
    QFile *m_file;
private slots:
    void on_updateButton_clicked();
    void on_closeButton_clicked();
    void httpStateChanged(int state);
    void httpRequestStarted(int id);
    void httprequestFinished(int id, bool error);
    void httpDone(bool error);
};

#endif // BBSMENUFETCHDIALOG_H
