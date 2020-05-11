#pragma once

#include <assert.h>

#include "Service.h"
#include "Exception.h"
#include"Exception2.h"
#include"Exception3.h"
#include"Exception4.h"

using namespace std;

//Service tests

void test_service_constr();
void test_add();
void test_up();
void test_del();
void test_all();

void test_login();
void test_register();

void test_search_by_prod();
void test_search_by_cart_num();
void test_update_thingys();


//Exceptions tests

void test_constr1();
void test_msg1();

void test_constr2();
void test_msg2();

void test_constr3();
void test_msg3();

void test_constr4();
void test_msg4();

void live_tests();

//All tests

void all_tests();