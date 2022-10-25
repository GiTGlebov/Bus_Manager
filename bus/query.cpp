#include "query.h"
using namespace std;
istream& operator >> (istream& is, Query& q) {
    string oper;
    is>>oper;
  if (oper=="NEW_BUS")
  {
   q.stops.clear();
   q.type=QueryType::NewBus;
      is>>q.bus>>q.stopc;
      for (int i=0;i<q.stopc;i++)
         {
             string st;
          is>>st;
          q.stops.push_back(st);
          }

  }
  else if(oper=="BUSES_FOR_STOP")
  {
      q.type=QueryType::BusesForStop;
      is>>q.stop;
  }
  else if(oper=="STOPS_FOR_BUS")
  {
      q.type=QueryType::StopsForBus;
      is>>q.bus;
  }
  else if(oper=="ALL_BUSES")
  {
      q.type=QueryType::AllBuses;
  }
  return is;
}
