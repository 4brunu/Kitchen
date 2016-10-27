/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutSheaButter.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 11:07 AM
 */

#ifndef PEANUTSHEABUTTER_HPP
#define PEANUTSHEABUTTER_HPP

#include "stl.hpp"
#include "sandwich.hpp"

#include "dish.hpp"
#include "config.hpp"
#include "recipe.hpp"
#include "response.hpp"
#include "PeanutHandler.hpp"
#include "PeanutService.hpp"
#include "configuration.hpp"

using namespace naomi_gen;

class PeanutSheaButter: public Sandwich
{
public:
    PeanutSheaButter(const shared_ptr<PeanutHandler> & handler, const shared_ptr<PeanutService> & service);
    virtual ~PeanutSheaButter();
    
public:
    virtual string get_version() override;
    
public:
    virtual shared_ptr<naomi_gen::Dish> grab(naomi_gen::module module) override;
    
public:
    virtual void add_recipe(const shared_ptr<naomi_gen::Recipe> & recipe) override;
    
private:
    string m_version;
    
private:
    shared_ptr<PeanutStore> m_store;
    shared_ptr<PeanutHandler> m_handler;
    shared_ptr<PeanutService> m_service;
    
};

#endif /* PEANUTSHEABUTTER_HPP */

