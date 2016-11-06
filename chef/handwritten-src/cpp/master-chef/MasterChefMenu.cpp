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

map<naomi_gen::menu, shared_ptr<MasterChefDish>> MasterChefMenu::getMasterChefs() {
    return m_mapper;
}

void MasterChefMenu::addDish(const shared_ptr<MasterChefDish> & menu_obj, naomi_gen::menu menu) {
    m_mapper.insert( pair<naomi_gen::menu, shared_ptr<MasterChefDish>>(menu, menu_obj) );
}

