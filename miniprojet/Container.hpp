#ifndef CONTAINER_H
#define CONTAINER_H
#include "Resource.hpp"
#include <string>
#include "Pod.hpp"

class Container : public Resource {
    friend class Pod;
    private : 
        std::string image_;
    public : 
        Container(std::string id, std::string image, double cpu, double memory);
        void start() override;
        void stop() override;
        std::string getMetrics() const override;
        friend std::ostream& operator<<(std::ostream& os, const Container& c);
        
};

#endif