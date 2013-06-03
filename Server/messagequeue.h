#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include "message.h"

#include <queue>
#include <QSharedPointer>
#include <QMutex>

class MessageQueue
{
    std::queue< QSharedPointer<Message> > queue;
    QMutex mutex;
    void mainLoop();
    virtual void processOperation(QSharedPointer<Message> msg);
  protected:
    MessageQueue();
  public:
    ~MessageQueue();
    void addMessage(QSharedPointer<Message> msg);
  signals:
    messageReady();
};


#endif // MESSAGEQUEUE_H
