/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stl.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 9:31 AM
 */

#ifndef STL_HPP
#define STL_HPP

#include <string>
#include <memory>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#include "handler.hpp"
#include "runnable.hpp"

using namespace std;

namespace naomi
{
    const string app = "MasterChef";
    const string version = "MasterChef:v2.1";
    
    /**
     *
     */
    class TaskHandler
    {
    public:
        
        using Task = function<void()>;
        virtual void handle(const Task & task) = 0;
    };

    /**
     *
     */
    class RunnableHandler: public naomi_gen::Runnable
    {
        function<void() > m_function;

    public:
        
        RunnableHandler(function<void() > func) : m_function{move(func)}
        {
        }

        virtual void run() override
        {
            m_function();
        }
    };
}

#endif /* STL_HPP */


