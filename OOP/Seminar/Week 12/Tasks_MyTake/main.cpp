#include <iostream>
#include "CompositeTask.h"

int main(){
    CompositeTask ctask1("Create my contacts app");
    CompositeTask ctask2("Writecode");
    ctask2.AddTask(new SimpleTask(3, "login page"));
    ctask2.AddTask(new SimpleTask(2, "contact page"));
    ctask2.AddTask(new SimpleTask(4, "contacts list page"));
    ctask1.AddTask(&ctask2);
    ctask1.AddTask(new SimpleTask(2,"test app"));
    CompositeTask ctask3("deploy");
    ctask3.AddTask(new SimpleTask(1, "create AWS acc"));
    ctask3.AddTask(new SimpleTask(1, "run deployment"));
    ctask1.AddTask(&ctask3);

    ctask1.Print();
    std::cout << '\n' << ctask1.GetTime();
}