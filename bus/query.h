#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  int stopc;
  string bus;
  string stop;
  vector<string> stops;
};
istream& operator >> (istream& is, Query& q);

