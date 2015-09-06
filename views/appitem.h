#ifndef APPITEM_H
#define APPITEM_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class BorderButton;
class ElidedLabel;


class AppItem : public QFrame
{
    Q_OBJECT
public:

    explicit AppItem(bool isAutoStart=false, QWidget *parent = 0);
    ~AppItem();

    void initUI();
    void initConnect();

    QPixmap getAppIcon();
    QString getAppName();
    QString getUrl();
    QString getAppKey();
    BorderButton* getBorderButton();

signals:

public slots:
    void setAppIcon(QString icon);
    void setAppIcon(QPixmap icon);
    void setAppName(QString name);
    void setAppKey(QString key);
    void setUrl(QString url);
    void showMenu(QPoint pos);
    void showAutoStartLabel();
    void hideAutoStartLabel();

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QLabel* m_iconLabel;
    QLabel* m_autoStartLabel;
    BorderButton* m_borderButton;
    ElidedLabel* m_nameLabel;
    QPixmap m_appIcon = QPixmap();
    QString m_appName = "";
    QString m_url = "";
    QString m_appKey = "";
    bool m_isAutoStart = false;
};

#endif // APPITEM_H
