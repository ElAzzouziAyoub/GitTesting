#include "Container.hpp"
#include <iostream>
#include <string>

Container::Container(std::string id, std::string image, double cpu, double memory) : Resource(id,cpu,memory) , image_(image) {};
void Container::start() {
    active_ = true;
};

void Container::stop() {
    active_ = false;

};
std::string Container::getMetrics() const {
    std::string metrics = "[ Container : ";
    for (auto i : id_) {
        metrics += i; 
    }
    metrics += " " + std::to_string(cpu_) + " CPU , "+ std::to_string(memory_) + " Memory , " + image_;
    metrics += "] \n";
    return metrics; 
}

std::ostream& operator<<(std::ostream& os, const Container& c){
    os << "Container: ";
    for ( auto i : c.id_){
        os<<i;
    };
    os<<" id : "<<c.cpu_<<" , " <<c.memory_<<" , "<<c.image_<<" ]\n";
    return os;

};