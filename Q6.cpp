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

}

void B_func(){

}

void C_func(){

}

int main(){

}