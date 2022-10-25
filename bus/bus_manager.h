#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "responses.cpp"
using namespace std;
class BusManager {
private:
    map<string,vector<string>> busfst,stopfb;
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const ;

  StopsForBusResponse GetStopsForBus(const string& bus) const ;

  AllBusesResponse GetAllBuses() const ;
};
