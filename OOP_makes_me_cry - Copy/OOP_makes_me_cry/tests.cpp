#include "tests.h"

#include <iostream>

using namespace std;

//void test_service_constr()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    assert(s.all_trains().size() == 3);
//    assert(s.login("admin", "admin") == true);
//}
//
//void test_add()
//{
//    RepoTrain* r = new RepoTrain();
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//    assert(s.all_trains().size() == 0);
//    Train* t = new FreightTrain("model,sid,29,coal,10,10", ',');
//    s.add_train(t);
//    assert(s.all_trains().size() == 1);
//}
//
//void test_up()
//{
//    RepoTrain* r = new RepoTrain();
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//    assert(s.all_trains().size() == 0);
//    Train* t = new FreightTrain("model,sid,29,coal,10,10", ',');
//    Train* t1 = new FreightTrain("MODEL,sid,29,coal,10,10", ',');
//    s.add_train(t);
//    int ok = s.update_train(t, t1);
//    assert(ok == 0);
//    assert(s.all_trains().front() == t1);
//}
//
//void test_del()
//{
//    RepoTrain* r = new RepoTrain();
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//    assert(s.all_trains().size() == 0);
//    Train* t = new FreightTrain("model,sid,29,coal,10,10", ',');
//    s.add_train(t);
//    assert(s.all_trains().size() == 1);
//    int ok = s.del_train(t);
//    assert(ok == 0);
//    assert(s.all_trains().size() == 0);
//}
//
//void test_all()
//{
//    RepoTrain* r = new RepoTrain();
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//    assert(s.all_trains().size() == 0);
//    Train* t = new FreightTrain("model,sid,29,coal,10,10", ',');
//    s.add_train(t);
//    assert(s.all_trains().front() == t);
//
//}
//
//void test_login()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    assert(s.login("admin", "admin") == true);
//    assert(s.login("ionut", "pass") == false);
//}
//
//void test_register()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    assert(s.reg("admin", "admin") == false);
//    assert(s.reg("ionut", "pass") == true);
//}
//
//void test_search_by_prod()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    Train* t1 = new FreightTrain("model,idk,29,coal,10,10", ',');
//    Train* t2 = new PersonalTrain("a,idk,20,200,10,10", ',');
//
//    vector <Train*> search_results = s.search_by_producer("idk");
//    assert(search_results[0] == t1);
//    assert(search_results[1] == t2);
//}
//
//void test_search_by_cart_num()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    Train* t1 = new FreightTrain("model,idk,20,coal,10,10", ',');
//    Train* t2 = new PersonalTrain("a,idk,20,200,10,10", ',');
//    Train* t3 = new FreightTrain("aa,20,20,coal,10,10", ',');
//
//    vector<Train*> s_res = s.search_by_cart_no(20);
//    assert(s_res[0] == t1);
//    assert(s_res[1] == t2);
//    assert(s_res[2] == t3);
//}
//
//void test_update_thingys()
//{
//    RepoTrain* r = new RepoFileTrainCSV("test.csv");
//    RepoUser* repo = new RepoFileUserTXT("test.txt");
//
//    Service s(r, repo);
//
//    Train* t1 = new FreightTrain("model,idk,20,coal,10,10", ',');
//
//    s.update_da_booked_thingys("model", 20);
//    
//    vector <Train*> res = s.all_trains();
//    assert(res.front()->get_res_cart_no() == 20);
//}
//
//void test_constr1()
//{
//    Exception ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_msg1()
//{
//    Exception ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_constr2()
//{
//    Exception2 ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_msg2()
//{
//    Exception2 ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_constr3()
//{
//    Exception3 ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_msg3()
//{
//    Exception3 ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_constr4()
//{
//    Exception4 ex("Error message");
//    assert(ex.what() == "Error message");
//}
//
//void test_msg4()
//{
//    Exception4 ex("Error message");
//    assert(ex.what() == "Error message");
//}

void live_tests()
{
    Train* g1 = new FreightTrain("carbuni", "104", "Fleischmann", 8, 10, 20);
    Train* g2 = new PersonalTrain(200, "749", "Neumann", 10, 4, 30);
    Train* g3 = new FreightTrain("benzina", "951", "Aron", 11, 9, 12);
    Train* g4 = new PersonalTrain(300, "104", "Alonso", 20, 2, 10);
    Train* g5 = new FreightTrain("lemn", "354", "Fierra", 12, 11, 13);

    RepoTrain* repo_t = new RepoTrain();
    RepoUser* repo_u = new RepoUser();

    Service s(repo_t, repo_u);

    s.add_train(g1);
    s.add_train(g2);
    s.add_train(g3);
    
    try
    {
        s.update_train(g4, "749");
        assert(s.size() == 3);
        assert(s.get(0) == g1);
        assert(s.get(1) == g4);
        assert(s.get(2) == g3);
    }
    catch(Exception& UpdateException1)
    {
        assert(false);
    }
    catch (Exception2& UpdateException2)
    {
        assert(false);
    }
    catch (Exception3& UpdateException3)
    {
        assert(false);
    }


    try
    {
        s.update_train(g5, "770");
        assert(false);
    }
    catch (Exception& UpdateException1)
    {
        cout << "UpdateException1 thrown";
        assert(s.size() == 3);
        assert(s.get(0) == g1);
        assert(s.get(1) == g4);
        assert(s.get(2) == g3);
    }
    catch (Exception2& UpdateException2)
    {
        assert(false);
    }
    catch (Exception3& UpdateException3)
    {
        assert(false);
    }


    try
    {
        s.update_train(g4, "104");
        assert(false);
    }
    catch (Exception& UpdateException1)
    {
        assert(false);
    }
    catch (Exception2& UpdateException2)
    {
        cout << "UpdateException2 thrown";
        assert(s.size() == 3);
        assert(s.get(0) == g1);
        assert(s.get(1) == g4);
        assert(s.get(2) == g3);
        
    }
    catch (Exception3& UpdateException3)
    {
        assert(false);

    }


   /* try
    {
        s.update_train(g5, "770");
        assert(false);
    }
    catch (Exception& UpdateException1)
    {
        assert(false);
    }
    catch (Exception2& UpdateException2)
    {
        assert(false);
    }
    catch (Exception3& UpdateException3)
    {
        cout << "UpdateException3 thrown";
    }


    try
    {
        s.update_train(g5, "104");
        assert(false);
    }
    catch (Exception& UpdateException1)
    {
        assert(false);
    }
    catch (Exception2& UpdateException2)
    {
        assert(false);
    }
    catch (Exception3& UpdateException3)
    {
        cout << "UpdateException3 thrown";
    }*/
    
}

void all_tests()
{
    //test_service_constr();
    //test_add();
    //test_up();
    //test_del();
    //test_all();
    //test_login();
    //test_register();
   // test_search_by_prod();
    //test_search_by_cart_num();
    //test_update_thingys();
    //test_constr1();
    //test_msg1();
    //test_constr2();
    //test_msg2();
    //test_constr3();
    //test_msg3();
    //test_constr4();
    //test_msg4();

}