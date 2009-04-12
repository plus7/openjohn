#include "imgviewdialog.h"
#include "ui_imgviewdialog.h"

ImgViewDialog::ImgViewDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ImgViewDialog)
{
    m_ui->setupUi(this);
}

ImgViewDialog::~ImgViewDialog()
{
    delete m_ui;
}

void ImgViewDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
