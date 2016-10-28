/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.cpp
 * Author: izehi
 * 
 * Created on October 27, 2016, 11:59 PM
 */

#include "Application.hpp"

Application::Application() {
}

Application::~Application() {
}

shared_ptr<naomi_gen::Sandwich> naomi_gen::Sandwich::get_instance() {
    return make_shared<Application>();
}

shared_ptr<naomi_gen::Recipe> Application::get_recipe() {
    return make_shared<MasterChefRecipe>(make_shared<ConfigModule>(), naomi_gen::module::CHECKOUT);
}