#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
struct BusesForStopResponse;

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse;

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse;

ostream& operator << (ostream& os, const AllBusesResponse& r);
