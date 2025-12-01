/*
 * File Name: Route.cpp
 * Assignment: Term Project
 * Lab section: B01
 * Created by: Benjamin Anderson, Rolanted Ramos, Ayush Sreejith
 * Submission Date: Dec 1, 2025
 */

#include "route.h"
#include <string>
using namespace std;

Route::Route(string s, string d): source(s), destination(d) {}
string Route::get_source()const { return source;}
string Route::get_destination()const { return destination;}