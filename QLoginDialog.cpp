#include "QLoginDialog.h"

#include <QDebug>

QLoginDialog::QLoginDialog(QWidget* parent) : QDialog(parent, Qt::WindowCloseButtonHint),
    UserLable(this), PwdLable(this), UserEdit(this), PwdEdit(this), LoginBtn(this), CancelBtn(this)
{
    UserLable.setText("User ID:");
    UserLable.move(20, 30);
    UserLable.resize(60, 25);

    UserEdit.move(85, 30);
    UserEdit.resize(180, 25);

    PwdLable.setText("Password");
    PwdLable.move(20, 65);
    PwdLable.resize(60, 25);

    PwdEdit.move(85, 65);
    PwdEdit.resize(180, 25);
    PwdEdit.setEchoMode(QLineEdit::Password);

    CancelBtn.setText("Cancel");
    CancelBtn.move(85, 110);
    CancelBtn.resize(85, 30);

    LoginBtn.setText("Login");
    LoginBtn.move(180, 110);
    LoginBtn.resize(85, 30);

    setWindowTitle("Login");

    setFixedSize(285, 170);

    //qDebug() << frameGeometry().width();
    //qDebug() << frameGeometry().height();



    connect(&LoginBtn, SIGNAL(clicked()), this, SLOT(LoginBtn_Clicked()));
    connect(&CancelBtn, SIGNAL(clicked()), this, SLOT(CancelBtn_Clicked()));

}

void QLoginDialog::LoginBtn_Clicked()
{
    qDebug() << "LoginBtn_Clicked() Begin";

    m_user = UserEdit.text().trimmed();

    m_pwd = PwdEdit.text();

    done(Accepted);

    qDebug() << "LoginBtn_Clicked() End";
}

void QLoginDialog::CancelBtn_Clicked()
{
    qDebug() << "CancelBtn_Clicked() Begin";

    done(Rejected);

    qDebug() << "CancelBtn_Clicked() End";
}

QString QLoginDialog::getUser()
{
    return m_user;
}

QString QLoginDialog::getPwd()
{
    return m_pwd;
}

QLoginDialog::~QLoginDialog()
{

}
