﻿#include "RoleItem.h"
#include <QPainter>
#include "GUI.h"
RoleItem::RoleItem(int roleID)
{
    this->roleID=roleID;
    pixmap.load("role/"+QString::number(roleID)+".png");
    bpFlag = -1;
    this->width=pixmap.width();
    this->height=pixmap.height();
    this->selected=false;
    setVisible(1);
}

RoleItem::~RoleItem()
{

}

QRectF RoleItem::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void RoleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,pixmap);
    painter->drawPixmap(0,-10,player);
    painter->drawPixmap(0,-10,action);
}
int RoleItem::getRoleID()
{
    return this->roleID;
}
bool RoleItem::isSelected()
{
    return this->selected;
}
void RoleItem::setSelected(bool status)
{
    if(status && !this->selected)
    {
        setY(y()-20);
    }
    else if( !status && this->selected)
    {
        setY(y()+20);
    }
    this->selected=status;
    update();
}

void RoleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!this->selected)
    {
        emit roleSelected(roleID);
    }
    else
    {
        emit roleUnselected(roleID);
    }
}

void RoleItem::setBPMsg(int step)
{
    if(step == 0)
        return;
    QStringList team;
    team << "Red";
    team << "Blue";
    int index = (step-1)/4 + 1;
    int flag = ((step-1)/2)%2;
    int color = (step-1) % 2;
    switch(flag)
    {
    case 0:
        pixmap.load("resource/bp/Ban"+QString::number(roleID)+".png");
        player.load("resource/bp/Game"+team[color]+QString::number(index)+".png");
        action.load("resource/bp/GameBan.png");
        this->setEnabled(false);
        break;
    case 1:
        player.load("resource/bp/Game"+team[color]+QString::number(index)+".png");
        action.load("resource/bp/GamePick"+team[color]+".png");
        this->setEnabled(false);
        break;
    }
}
