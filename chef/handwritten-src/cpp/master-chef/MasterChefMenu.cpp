/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefMenu.cpp
 * Author: izehi
 * 
 * Created on October 25, 2016, 2:02 PM
 */

#include "include/chef/MasterChefMenu.hpp"

MasterChefMenu::MasterChefMenu(const shared_ptr<MasterChefHandler> & handler, const shared_ptr<MasterChefService> & service) 
: m_handler {handler}, m_service {service} {
}

MasterChefMenu::~MasterChefMenu() {
}

map<naomi_gen::module, shared_ptr<MasterChefDish>> MasterChefMenu::getMasterChefs() {
    return m_mapper;
}

void MasterChefMenu::addDish(const shared_ptr<MasterChefDish> & module_obj, naomi_gen::module module) {
    module_obj->set_handler(m_handler);
    module_obj->set_service(m_service);
    m_mapper.insert( pair<naomi_gen::module, shared_ptr<MasterChefDish>>(module, module_obj) );
}

