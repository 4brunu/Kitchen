/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutService.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 3:14 PM
 */

#ifndef PEANUTSERVICE_HPP
#define PEANUTSERVICE_HPP

#include <queue> 
#include <mutex>
#include <condition_variable>

#include "stl.hpp"
#include "service.hpp"

class PeanutService final : public naomi::TaskHandler
{
public:
    PeanutService(const shared_ptr<naomi_gen::Service> & service);
    virtual ~PeanutService();

public:
    virtual void handle(const Task & task) override;

private:
    bool m_done;
    bool m_start;

private:
    queue<Task> m_task_queue;

private:
    mutex m_task_mutex;
    mutex m_done_mutex;

private:
    condition_variable m_done_cv;
    condition_variable m_task_cv;

private:
    shared_ptr<naomi_gen::Service> m_service;

private:
    void start();
};

#endif /* PEANUTSERVICE_HPP */
