#include "bbsmenufetchdialog.h"
#include "ui_bbsmenufetchdialog.h"
#include "johnapplication.h"
#include <QUrl>
#include <QHttp>
#include <QFile>
#include <QDir>
BBSMenuFetchDialog::BBSMenuFetchDialog(QWidget *parent) :
    QDialog(parent),m_http(NULL),m_file(NULL),
    m_ui(new Ui::BBSMenuFetchDialog)
{
    m_ui->setupUi(this);
}

BBSMenuFetchDialog::~BBSMenuFetchDialog()
{
    delete m_ui;
}

void BBSMenuFetchDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BBSMenuFetchDialog::on_closeButton_clicked()
{
    //ダウンロード中なら中止
    if(m_http && m_http->state()!=QHttp::Unconnected){
        m_http->abort();
    }
    if(m_file){
        m_file->close();
    }
    accept();
}

void BBSMenuFetchDialog::on_updateButton_clicked()
{
    m_ui->updateButton->setEnabled(false);

    m_file = new QFile(this);
    m_file->setFileName(JohnApplication::profileDir()+"/bbsmenu.html.part");
    if(m_file->exists()){
        m_file->remove();
    }
    if(!m_file->open(QIODevice::ReadWrite)) return;

    m_http = new QHttp(this);

    connect(m_http, SIGNAL(requestFinished(int,bool)),
            this, SLOT(httprequestFinished(int,bool)));
    connect(m_http, SIGNAL(requestStarted(int)),
            this, SLOT(httpRequestStarted(int)));
    connect(m_http, SIGNAL(stateChanged(int)),
            this, SLOT(httpStateChanged(int)));
    connect(m_http, SIGNAL(done(bool)),
            this, SLOT(httpDone(bool)));

    QUrl bbsmenuurl("http://menu.2ch.net/bbsmenu.html");
    m_http->setHost(bbsmenuurl.host());
    m_http->get(bbsmenuurl.path(), m_file);
}

void BBSMenuFetchDialog::httpStateChanged(int state)
{
    switch(state){
        case QHttp::HostLookup:
            m_ui->logWindow->appendPlainText(tr("ホストを検索中..."));
            break;
        case QHttp::Connecting:
            m_ui->logWindow->appendPlainText(tr("接続..."));
            break;
        case QHttp::Sending:
            m_ui->logWindow->appendPlainText(tr("リクエストを送信中..."));
            break;
        case QHttp::Reading:
            m_ui->logWindow->appendPlainText(tr("受信中..."));
            break;
        case QHttp::Connected:
            m_ui->logWindow->appendPlainText("");
            break;
        case QHttp::Closing:
            m_ui->logWindow->appendPlainText(tr("接続を閉じています..."));
            break;
        default:
            break;
    }
}

void BBSMenuFetchDialog::httpRequestStarted(int id)
{
    //m_ui->logWindow->appendPlainText(tr("リクエストを開始"));
}

void BBSMenuFetchDialog::httprequestFinished(int id, bool error)
{
    //m_ui->logWindow->appendPlainText(tr("リクエストが終了しました"));
}

void BBSMenuFetchDialog::httpDone(bool error)
{

    m_file->close();
    if(error){
        m_ui->logWindow->appendPlainText(tr("Error"));
    }
    else{
        m_ui->logWindow->appendPlainText(tr("完了"));
        QFile oldfile(JohnApplication::profileDir()+"/bbsmenu.html");
        if(oldfile.exists()){oldfile.remove();}
        m_file->rename(JohnApplication::profileDir()+"/bbsmenu.html");
    }

    delete m_file;
    m_file = NULL;

    delete m_http;
    m_http = NULL;

    m_ui->updateButton->setEnabled(true);
}
