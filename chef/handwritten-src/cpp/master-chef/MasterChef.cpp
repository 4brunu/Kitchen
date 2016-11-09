/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChef.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 11:07 AM
 */

#include "include/chef/MasterChef.hpp"

MasterChef::MasterChef(const string & root,
        const shared_ptr<Handler> & handler,
        const shared_ptr<Service> & service)
: m_root{ move(root) }
{
    m_handler = make_shared<MasterChefHandler>(handler);
    m_service = make_shared<MasterChefService>(service);
    
    m_version = naomi::version;
    m_store = make_shared<MasterChefMenu>();
}

string MasterChef::get_version() {
    return m_version;
}

shared_ptr<naomi_gen::Dish> MasterChef::grab(naomi_gen::menu menu) {
    return m_store->getMasterChefs().at(menu);
}

void MasterChef::add_recipe(const shared_ptr<naomi_gen::Recipe>& recipe) {
    shared_ptr<MasterChefDish> chef = dynamic_pointer_cast<MasterChefDish> (recipe->get_dish());
    if (chef == nullptr) {
        return;
    }
    chef->on_create(m_root, m_handler, m_service);
    m_store->addDish(chef, recipe->get_menu());
}


