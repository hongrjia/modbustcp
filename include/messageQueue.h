//
// Created by Administrator on 2023/10/29.
//

#ifndef MOBBUS_SERVER_MESSAGEQUEUE_H
#define MOBBUS_SERVER_MESSAGEQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include "misc.h"

template <typename Msg>
class messageQueue
{
private:
    std::mutex m_msg_mutex;
    std::condition_variable m_cond;
    std::queue<std::shared_ptr<Msg>> m_queue;
    bool m_is_running = true;

public:
    std::shared_ptr<Msg> receiveMsg()
    {
        std::unique_lock<std::mutex> lg(m_msg_mutex);
        m_cond.wait(lg, [this]()
        { return (!m_queue.empty() || !m_is_running); });

        if (m_queue.empty())
        {
            return nullptr;
        }
        auto msg = m_queue.front();
        m_queue.pop();
        return msg;
    }

    void sendMessage(std::shared_ptr<Msg> const &msg)
    {
//        std::cout << "send a message " << std::endl;
        std::unique_lock<std::mutex> lg(m_msg_mutex);
        m_queue.emplace(msg);
        m_cond.notify_one();
    }

    void stop()
    {
        m_is_running = false;
        m_cond.notify_one();
    }
};

#endif //MOBBUS_SERVER_MESSAGEQUEUE_H
