/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefMenu.hpp
 * Author: izehi
 *
 * Created on October 25, 2016, 2:02 PM
 */

#ifndef MasterChefMenu_HPP
#define MasterChefMenu_HPP

#include "map"
#include "lib/stl.hpp"
#include "module.hpp"
#include "MasterChefModule.hpp"
#include "MasterChefHandler.hpp"
#include "MasterChefService.hpp"

class MasterChefMenu
{
public:
    map<naomi_gen::module, shared_ptr<MasterChefDish>> getMasterChefs();

public:
    void addDish(const shared_ptr<MasterChefDish> & module_obj, naomi_gen::module module);

public:
    MasterChefMenu(const shared_ptr<MasterChefHandler> & handler, const shared_ptr<MasterChefService> & service);
    virtual ~MasterChefMenu();

private:
    shared_ptr<MasterChefHandler> m_handler;
    shared_ptr<MasterChefService> m_service;

private:
    map<naomi_gen::module, shared_ptr<MasterChefDish>> m_mapper;

};

#endif /* MasterChefMenu_HPP */

