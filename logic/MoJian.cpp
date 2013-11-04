﻿#include "MoJian.h"

MoJian::MoJian()
{
    makeConnection();
    setMyRole(this);

    Button *anYingLiuXing;
    anYingLiuXing=new Button(3,QStringLiteral("暗影流星"));
    buttonArea->addButton(anYingLiuXing);
    connect(anYingLiuXing,SIGNAL(buttonSelected(int)),this,SLOT(AnYingLiuXing()));
}

void MoJian::normal()
{
    Role::normal();
    Player* myself=dataInterface->getMyself();
    int count=0;
    handArea->disableMagic();
    if(myself->getTap())
        foreach(Card*ptr,dataInterface->getHandCards())
        {
            if(ptr->getType()=="magic")
                count++;
            if(count>=2){
                buttonArea->enable(3);
                break;
            }
        }
    unactionalCheck();
}

void MoJian::AnYingNingJu()
{
    state=903;
    gui->reset();
    tipArea->setMsg(QStringLiteral("是否发动暗影凝聚？"));
    decisionArea->enable(0);
    decisionArea->enable(1);
}

void MoJian::XiuLuoLianZhan()
{
    //先借用基类的额外攻击行动状态
    state=10;
    onceUsed=true;
    gui->reset();
    handArea->setQuota(1);
    handArea->enableElement("fire");
    handArea->disableMagic();
    playerArea->setQuota(1);
    decisionArea->enable(3);
}

void MoJian::AnYingLiuXing()
{
    state=902;
    handArea->reset();
    playerArea->reset();
    tipArea->reset();

    handArea->setQuota(2);
    handArea->enableMagic();
    playerArea->setQuota(1);
    decisionArea->enable(1);
}

void MoJian::HeiAnZhenChan()
{
    state=36;
    tipArea->setMsg(QStringLiteral("是否发动黑暗震颤？"));
    decisionArea->enable(0);
    decisionArea->enable(1);
}

void MoJian::cardAnalyse()
{
    Role::cardAnalyse();

    switch (state)
    {
    case 902:
        playerArea->enableAll();
        break;
    }
}

void MoJian::onOkClicked()
{
    Role::onOkClicked();
    QList<Card*>selectedCards;
    QList<Player*>selectedPlayers;

    QString command;
    QString cardID,cardID2;
    QString sourceID;
    QString targetID;
    QString text;

    selectedCards=handArea->getSelectedCards();
    selectedPlayers=playerArea->getSelectedPlayers();

    network::Action* action;
    network::Respond* respond;

    switch(state)
    {
//额外行动询问
    case 42:
        text=tipArea->getBoxCurrentText();
        if(text[0]=='1'){
            respond = newRespond(901);
            respond->add_args(1);
            emit sendCommand(network::MSG_RESPOND, respond);
            XiuLuoLianZhan();
        }
        break;
//暗影流星
    case 902:
        action = newAction(902);
        action->add_args(selectedCards[0]->getID());
        action->add_args(selectedCards[1]->getID());
        action->add_dst_ids(selectedPlayers[0]->getID());

        dataInterface->removeHandCard(selectedCards[0]);
        dataInterface->removeHandCard(selectedCards[1]);
        emit sendCommand(network::MSG_ACTION, action);
        gui->reset();
        break;
//暗影凝聚
    case 903:
        respond = newRespond(903);
        respond->add_args(1);

        start=true;
        emit sendCommand(network::MSG_RESPOND, respond);
        gui->reset();
        break;
    }
}

void MoJian::onCancelClicked()
{
    Role::onCancelClicked();
    QString command;

    network::Respond* respond;
    switch(state)
    {
//暗影流星
    case 902:
        normal();
        break;
//暗影凝聚
    case 903:
        respond = newRespond(903);

        start=false;
        emit sendCommand(network::MSG_RESPOND, respond);
        gui->reset();
        break;
    }
}
void MoJian::askForSkill(QString skill)
{
    //Role::askForSkill(skill);
    if(skill==QStringLiteral("暗影凝聚"))
        AnYingNingJu();
    else if(skill==QStringLiteral("黑暗震颤"))
        HeiAnZhenChan();
}

void MoJian::additionalAction()
{
    //Role::additionalAction();
    if(usedAttack&&!onceUsed)
        tipArea->addBoxItem(QStringLiteral("1.修罗连斩"));
}

void MoJian::attacked(QString element, int hitRate)
{
    Role::attacked(element,hitRate);
    if(isMyTurn)
        handArea->disableMagic();
}
