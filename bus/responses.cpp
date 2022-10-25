#include "responses.h"


struct BusesForStopResponse {
    vector<string> BusesStop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  for (const auto& f:r.BusesStop)
  {
      os<<f<<" ";
  }
  return os;
}

struct StopsForBusResponse {
  vector<string> StopsBus;
  vector<vector<string>> busesp;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.StopsBus.empty())
  {
      os<<"No bus";
  }
  else{
    int count=0;
    for (const auto &stop:r.StopsBus)
    {
        os<<"Stop "<< stop<<": ";
        for (const auto& j: r.busesp[count]){
            os<<j<<" ";
        }
        if (count + 1!=r.StopsBus.size()) os<<endl;
        ++count;
    }
  }
  return os;
}

struct AllBusesResponse {
  map<string,vector<string>> all;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if(r.all.empty())
  {
     os<<"No buses";
  }
  else{
    int count=0;
    for (const auto& f: r.all)
    {
        os<<"Bus "<<f.first<<": ";
        for (const auto& j: f.second)
        {
            os<<j<<" ";
        }
        if (count+1!=r.all.size())
            os<<endl;
        ++count;
    }
  }
  return os;
}
