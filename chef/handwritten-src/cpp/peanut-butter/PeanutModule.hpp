/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutModule.hpp
 * Author: izehi
 *
 * Created on October 25, 2016, 7:02 PM
 */

#ifndef PEANUTMODULE_HPP
#define PEANUTMODULE_HPP

#include "map"
#include "stl.hpp"
#include "dish.hpp"
#include "response.hpp"
#include "intention.hpp"
#include "PeanutHandler.hpp"
#include "PeanutService.hpp"

class PeanutDish : public naomi_gen::Dish
{
public:

    virtual ~PeanutDish()
    {
    }

    virtual void serve(naomi_gen::intention intent, const std::shared_ptr<naomi_gen::Response> & callback) = 0;

private:
    shared_ptr<PeanutHandler> m_handler;
    shared_ptr<PeanutService> m_service;

public:
    shared_ptr<PeanutHandler> get_handler()
    {
        return m_handler;
    }
    shared_ptr<PeanutService> get_service()
    {
        return m_service;
    }

public:
    void set_handler(const shared_ptr<PeanutHandler>& handler)
    {
        m_handler = handler;
    }
    void set_service(const shared_ptr<PeanutService>& service)
    {
        m_service = service;
    }
};

template<class T>
class PeanutModule : public PeanutDish
{
public:
    using action = naomi_gen::intention;
    using intent_map = void (T::*) (const shared_ptr<naomi_gen::Response>& callback);

public:

    virtual ~PeanutModule()
    {
    }

public:
    virtual void serve(naomi_gen::intention intent, const shared_ptr<naomi_gen::Response>& callback) = 0;

public:
    virtual void set_intentions(map<naomi_gen::intention, intent_map> * mapper) = 0;

public:

    map<naomi_gen::intention, intent_map> get_mapper()
    {
        return m_mapper;
    }

private:
    map<naomi_gen::intention, intent_map> m_mapper;
};

#endif /* PEANUTMODULE_HPP */

