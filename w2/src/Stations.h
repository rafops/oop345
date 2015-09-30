#ifndef _STATIONS
#define _STATIONS

#include <vector>
#include "Station.h"

namespace w2
{  
  class Stations
  {
    public:
      Stations(char* fileName);
      void update() const;
      void restock() const;
      void report() const;
      ~Stations();
    private:
      std::string _fileName;
      // std::vector<Station> _stations;
      Station* _stations;
      int _count;
  };
}

#endif