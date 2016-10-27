/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefService.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 3:14 PM
 */

#include "include/chef/MasterChefService.hpp"

MasterChefService::MasterChefService(const shared_ptr<naomi_gen::Service> & service)
: m_done{false}, m_start{false}, m_service{service}
{
    m_service->on_create();
    m_service->on_start(naomi::app, make_shared<naomi::RunnableHandler>([&] {
        start();
    }));
}

MasterChefService::~MasterChefService() {
    {
        lock_guard<mutex> locker(m_task_mutex);
        m_start = true;
    }
    m_task_cv.notify_one();

    unique_lock<mutex> unique_done_mutex(m_done_mutex);
    m_done_cv.wait(unique_done_mutex, [this] () {
        return m_done;
    });
}

void MasterChefService::start() {
    while (true) {
        unique_lock<mutex> unique_locker(m_task_mutex);
        m_task_cv.wait(unique_locker, [&] () {
            return m_start == true || !m_task_queue.empty();
        });
        if (m_start) {
            break;
        }
        auto task = move(m_task_queue.front());
        m_task_queue.pop();

        unique_locker.unlock();
        task();
    }

    {
        lock_guard<mutex> done_lock(m_done_mutex);
        m_done = true;
    }
    m_done_cv.notify_one();
}

void MasterChefService::handle(const Task& task) {
    {
        lock_guard<mutex> lock(m_task_mutex);
        m_task_queue.emplace(task);
    }
    m_task_cv.notify_one();
}



