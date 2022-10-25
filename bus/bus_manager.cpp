#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops)
{
      busfst[bus]=stops;
    for (const auto& f: stops)
    {
        stopfb[f].push_back(bus);
    }
}
BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
{
      BusesForStopResponse a;
    if (stopfb.count(stop)==0)
    {
        a.BusesStop.push_back("No stop");
    }
    else{
        a.BusesStop=stopfb.at(stop);
    }
    return a;
}
StopsForBusResponse BusManager::GetStopsForBus (const string& bus) const
{
    StopsForBusResponse a;
    if (busfst.count(bus)!=0)
    {
        for( const auto& f: busfst.at(bus))
        {
            a.StopsBus.push_back(f);
            if (stopfb.at(f).size()==1)
            a.busesp.push_back({"no interchange"});
            else{
                vector<string> b;
                for (const auto& e:stopfb.at(f))
                     {
                         if (bus!=e)
                        b.push_back(e);
                     }
                a.busesp.push_back(b);
            }
        }
    }
    return a;
}
AllBusesResponse BusManager::GetAllBuses() const
{
        AllBusesResponse c;
    if (!busfst.empty())
    {
        for (const auto& f: busfst)
        {
            for (const auto& e: f.second )
            {
                c.all[f.first].push_back(e);
            }
        }
    }
    return c;
}
