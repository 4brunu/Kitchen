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
#include "menu.hpp"
#include "recipe.hpp"
#include "package.hpp"
#include "service_binder.hpp"
#include "MasterChefHandler.hpp"
#include "MasterChefService.hpp"

/**
 * 
 */
class MasterChefRecipe : public naomi_gen::Recipe
{
    naomi_gen::menu m_menu;
    shared_ptr<naomi_gen::Dish> m_dish;

public:
    MasterChefRecipe(const shared_ptr<naomi_gen::Dish>& dish, naomi_gen::menu menu)
    : m_menu{move(menu)}, m_dish{move(dish)}
    {
    }

    virtual naomi_gen::menu get_menu() override
    {
        return m_menu;
    }

    virtual shared_ptr<naomi_gen::Dish> get_dish() override
    {
        return m_dish;
    }

};

/**
 * 
 */
class MasterChefDish : public naomi_gen::Dish
{
public:

    MasterChefDish & operator=(MasterChefDish & orig)
    {
        if (this != &orig)
        {

        }
        return * this;
    }

    virtual void on_create(const string & root,
            const shared_ptr<MasterChefHandler>& handler,
            const shared_ptr<MasterChefService>& service) = 0;

    virtual void serve(naomi_gen::package package,
            const unordered_map<string, string> & params,
            const shared_ptr<naomi_gen::ServiceBinder> & callback) = 0;

};

/**
 * 
 */
template<class T>
class MasterChefModule : public MasterChefDish
{
public:
    using action = naomi_gen::package;
    using package_map = void (T::*) (const shared_ptr<MasterChefHandler>& handler,
            const unordered_map<string, string>& params,
            const shared_ptr<naomi_gen::ServiceBinder>& callback);

public:
    virtual void set_packages(map<naomi_gen::package, package_map>* mapper) = 0;

public:
    
    string get_path()
    {
        return m_root;
    }

    void on_create(const string & root,
            const shared_ptr<MasterChefHandler>& handler,
            const shared_ptr<MasterChefService>& service)
    {
        m_root = move(root);
        m_handler = move(handler);
        m_service = move(service);
    }

    virtual void serve(naomi_gen::package package,
            const unordered_map<string, string> & params,
            const shared_ptr<naomi_gen::ServiceBinder>& callback) override
    {
        set_packages(&m_mapper);
        m_service->handle(get_task(m_mapper.at(package), params, callback));
    }

private:

    naomi::TaskHandler::Task get_task(package_map task,
            const unordered_map<string, string> & params,
            const shared_ptr<naomi_gen::ServiceBinder>& callback)
    {
        return [this, task, params, callback]
        {
            ((dynamic_cast<T*> (this))->*task)(m_handler, params, callback);
        };
    }

private:
    string m_root;
    shared_ptr<MasterChefHandler> m_handler;
    shared_ptr<MasterChefService> m_service;
    
    map<naomi_gen::package, package_map> m_mapper;

};

#endif /* MasterChefMODULE_HPP */




