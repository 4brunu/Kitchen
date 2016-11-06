/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChef.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 11:07 AM
 */

#ifndef MasterChef_HPP
#define MasterChef_HPP

#include "lib/stl.hpp"
#include "chef.hpp"

#include "dish.hpp"
#include "recipe.hpp"
#include "MasterChefMenu.hpp"
#include "MasterChefHandler.hpp"
#include "MasterChefService.hpp"

using namespace naomi_gen;

class MasterChef: public Chef
{
public:
    MasterChef(const string & root,
            const shared_ptr<Handler> & handler, 
            const shared_ptr<Service> & service);
    
public:
    virtual string get_version() override;
    
public:
    virtual shared_ptr<naomi_gen::Dish> grab(naomi_gen::menu menu) override;
    
public:
    virtual void add_recipe(const shared_ptr<naomi_gen::Recipe> & recipe) override;
    
private:
    string m_root;
    string m_version;
    
private:
    shared_ptr<MasterChefMenu> m_store;
    shared_ptr<MasterChefHandler> m_handler;
    shared_ptr<MasterChefService> m_service;
    
};

#endif /* MasterChef_HPP */

