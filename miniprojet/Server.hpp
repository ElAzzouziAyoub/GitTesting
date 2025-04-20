#ifndef SERVER_H
#define SERVER_H

#include "Resource.hpp"
#include <string>

class Server : Resource {
    private : 
        double avaialable_cpu;
        double available_memory_ ;
    public : 
        Server(std::string id, double cpu, double memory);
        bool allocate(double cpu, double memory);
        void start() override;
        void stop() override;
        std::string getMetrics() const override;
        friend std::ostream& operator<<(std::ostream& os, const Server& s);


};




#endif