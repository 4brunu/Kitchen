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
#include "menu.hpp"
#include "MasterChefModule.hpp"
#include "MasterChefHandler.hpp"
#include "MasterChefService.hpp"

class MasterChefMenu
{
public:
    map<naomi_gen::menu, shared_ptr<MasterChefDish>> getMasterChefs();

public:
    void addDish(const shared_ptr<MasterChefDish> & menu_obj, naomi_gen::menu menu);

private:
    map<naomi_gen::menu, shared_ptr<MasterChefDish>> m_mapper;

};

#endif /* MasterChefMenu_HPP */

