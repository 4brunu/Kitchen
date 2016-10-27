/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configuration.hpp
 * Author: izehi
 *
 * Created on October 25, 2016, 2:03 PM
 */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "stl.hpp"
#include "../MasterChefMenu.hpp"

#include "../../../test.cpp"

auto application = [] (shared_ptr<MasterChefMenu> peansut) 
{
    peansut->addDish(make_shared<test>(), naomi_gen::module::CATALOG);
};

#endif /* CONFIGURATION_HPP */

