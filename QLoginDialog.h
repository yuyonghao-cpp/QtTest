#ifndef _QLOGINDIALOG_H_
#define _QLOGINDIALOG_H_

#include <QtGui/QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class QLoginDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel UserLable;
    QLabel PwdLable;
    QLineEdit UserEdit;
    QLineEdit PwdEdit;
    QPushButton LoginBtn;
    QPushButton CancelBtn;
    QString m_user;
    QString m_pwd;
private slots:
    void LoginBtn_Clicked();
    void CancelBtn_Clicked();

public:
    QLoginDialog(QWidget *parent = 0);
    QString getUser();
    QString getPwd();
    ~QLoginDialog();
};

#endif // _QLOGINDIALOG_H_
