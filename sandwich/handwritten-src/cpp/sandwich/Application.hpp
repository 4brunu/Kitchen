/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.hpp
 * Author: izehi
 *
 * Created on October 27, 2016, 11:59 PM
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "menu.hpp"
#include "recipe.hpp"
#include "chef/lib/stl.hpp"
#include "sandwich.hpp"
#include "ConfigModule.hpp"

class Application final : public naomi_gen::Sandwich
{
public:
    Application();
    virtual ~Application();

public:
    virtual shared_ptr<naomi_gen::Recipe> get_recipe() override;

};

#endif /* APPLICATION_HPP */

