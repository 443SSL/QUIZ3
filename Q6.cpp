#include <iostream>
#include <thread>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "Semaphore.h"
using namespace std;

Semaphore A_done(0);
Semaphore B_done(0);
Semaphore C_done(1);
Semaphore mtx(1);

int b_cnt = 0;

void A_func(){
    while(true){
        C_done.P();
        cout << "Thread: A Running" << endl;

        A_done.V();
        A_done.V();
    }
}

void B_func(){
    while(true){
        A_done.P();

        usleep(500000);
        mtx.P();
        cout << "Thread: B Running" << endl;
        b_cnt++;
        if(b_cnt == 2){
            b_cnt = 0;
            B_done.V();
        }
        mtx.V();
    }
}

void C_func(){
    while(true){
        B_done.P();
        cout << "Thread: C Running" << endl;
        C_done.V();
    }
}

int main(){
    vector<thread> A_vec;
    vector<thread> B_vec;
    vector<thread> C_vec;

    for(int i = 0; i < 20; i++){
        A_vec.push_back(thread(A_func));
        B_vec.push_back(thread(B_func));
        C_vec.push_back(thread(C_func));
    }

    for(int i = 0; i < 20; i++){
        A_vec[i].join();
        B_vec[i].join();
        C_vec[i].join();
    }
}