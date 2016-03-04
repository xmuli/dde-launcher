/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef APPITEMMANAGER_H
#define APPITEMMANAGER_H

#include <QObject>
#include "fwd.h"
#include "dbusinterface/dbustype.h"


class CategoryItem;
class AppItem;

class AppItemManager : public QObject
{
    Q_OBJECT

public:
    explicit AppItemManager(QObject *parent = 0);
    ~AppItemManager();
    void init();
    void initConnect();
    QMap<QString, ItemInfo>& getItemInfos();
    QList<ItemInfo>& getAppNameItemInfos();
    QList<ItemInfo>& getInstallTimeItemInfos();
    QList<ItemInfo>& getUseFrequencyItemInfos();

    QList<qlonglong>& getHideKeys();
    CategoryInfoList& getCategoryInfoList();
    CategoryInfoList& getSortedCategoryInfoList();

    QMap<QString, AppItem *> &getAppItems();
    AppItem *getAppItemByKey(const QString& key);

    QMap<qlonglong, CategoryItem *> &getCategoryItems();
    CategoryItem *getCategoryItemByKey(const qlonglong key);

signals:

public slots:
    void addCategoryItem(const CategoryInfo& key);
    void setFirstLoadSortedMode(int mode);
    void setFirstLoadCategoryMode(int mode);
    void createFirstShowAppItems();
    void delayCreateOtherItems();
    void addItem(const ItemInfo& itemInfo);
    void addItems(const QList<ItemInfo>& itemInfos);
    void setItemInfos(const QMap<QString, ItemInfo>& infos);
    void setAppNameInfoList(const QList<ItemInfo>& infos);
    void setInstallTimeInfoList(const QList<ItemInfo>& infos);
    void setUseFrequencyInfoList(const QList<ItemInfo>& infos);
    void setCategoryInfoList(const CategoryInfoList& categoryInfoList);
    void hideNewInstallIndicator(QString appKey);
    void showNewInstallIndicator(QString appKey);
    void refreshIcon(const ItemInfo& itemInfo);


private:
    int m_sortMode;
    int m_categoryMode;
    QTimer* m_delayCreateItemsTimer;
    QMap<QString, ItemInfo> m_itemInfos;
    QList<ItemInfo> m_appNameItemInfoList;
    QList<ItemInfo> m_installtimeItemInfoList;
    QList<ItemInfo> m_useFrequencyItemInfoList;

    QList<qlonglong> m_hideKeys;
    CategoryInfoList m_categoryInfoList;
    CategoryInfoList m_sortedCategoryInfoList;
    QMap<qlonglong, CategoryItem*> m_categoryItems;
    QMap<QString, AppItem*> m_appItems;
};

#endif // APPITEMMANAGER_H