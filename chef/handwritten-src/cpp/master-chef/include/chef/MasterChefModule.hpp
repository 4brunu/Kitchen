/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefModule.hpp
 * Author: izehi
 *
 * Created on October 25, 2016, 7:02 PM
 */

#ifndef MasterChefMODULE_HPP
#define MasterChefMODULE_HPP

#include "map"
#include "lib/stl.hpp"
#include "dish.hpp"
#include "response.hpp"
#include "intention.hpp"
#include "MasterChefHandler.hpp"
#include "MasterChefService.hpp"

class MasterChefDish : public naomi_gen::Dish
{
public:

    virtual ~MasterChefDish()
    {
    }

    virtual void serve(naomi_gen::intention intent, const std::shared_ptr<naomi_gen::Response> & callback) = 0;

private:
    shared_ptr<MasterChefHandler> m_handler;
    shared_ptr<MasterChefService> m_service;

public:
    shared_ptr<MasterChefHandler> get_handler()
    {
        return m_handler;
    }
    shared_ptr<MasterChefService> get_service()
    {
        return m_service;
    }

public:
    void set_handler(const shared_ptr<MasterChefHandler>& handler)
    {
        m_handler = handler;
    }
    void set_service(const shared_ptr<MasterChefService>& service)
    {
        m_service = service;
    }
};

template<class T>
class MasterChefModule : public MasterChefDish
{
public:
    using action = naomi_gen::intention;
    using intent_map = void (T::*) (const shared_ptr<naomi_gen::Response>& callback);

public:

    virtual ~MasterChefModule()
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

#endif /* MasterChefMODULE_HPP */

