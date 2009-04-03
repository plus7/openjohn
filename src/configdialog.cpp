#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ConfigDialog)
{
    m_ui->setupUi(this);
}

ConfigDialog::~ConfigDialog()
{
    delete m_ui;
}

void ConfigDialog::createListItems()
{
}

void ConfigDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
