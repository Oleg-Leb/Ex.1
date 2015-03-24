#pragma once
#include <string>
using namespace std;


typedef unsigned int uint;

string to_hex(uint value);
uint F(uint X, uint Y, uint Z);
uint G(uint X, uint Y, uint Z);
uint H(uint X, uint Y, uint Z);
uint I(uint X, uint Y, uint Z);
uint rotate_left(uint value, int shift);
string get_md5(string in);
