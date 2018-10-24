#ifndef IPINPUTBOX_HPP
#define IPINPUTBOX_HPP

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QSpinBox;

class IpInputBox : public QWidget
{
    Q_OBJECT

public:
    explicit IpInputBox(QWidget *parent = nullptr);

    QString getIp() const;
    int getPort() const;

private:
    QHBoxLayout *m_layout;

    QLabel *m_separatorLabel;
    QLineEdit *m_ipLineEdit;
    QSpinBox *m_portSpinBox;

};

#endif // IPINPUTBOX_HPP
