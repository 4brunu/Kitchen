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

MasterChef::MasterChef(const shared_ptr<MasterChefHandler> & handler,
        const shared_ptr<MasterChefService> & service)
: m_handler{handler}, m_service{service}
{
    m_version = naomi::version;
    m_store = make_shared<MasterChefMenu>(m_handler, m_service);
}

MasterChef::~MasterChef() {

}

string MasterChef::get_version() {
    return m_version;
}

shared_ptr<naomi_gen::Dish> MasterChef::grab(naomi_gen::module module) {
    return m_store->getMasterChefs().at(module);
}

void MasterChef::add_recipe(const shared_ptr<naomi_gen::Recipe>& recipe) {
    shared_ptr<MasterChefDish> dish(dynamic_cast<MasterChefDish*> (recipe->get_dish().get()));
    m_store->addDish(dish, recipe->get_module());
}


