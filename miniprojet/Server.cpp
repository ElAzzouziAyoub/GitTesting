
#include "Server.hpp"
#include "Resource.hpp"
#include <iostream>
Server::Server(std::string id, double cpu, double memory) 
    : Resource(id , cpu , memory) {};
bool Server::allocate(double cpu , double memory){
    if ( cpu_ <= cpu && memory_ <= memory ){
        return true;
    }
    return false;
};
void Server::start() {
    active_ = true;
};
void Server::stop(){
    active_ = false;
};
std::string Server::getMetrics() const{
    std::string metrics = "[ Server : ";
    for (auto i : id_) {
        metrics += i; 
    }
    metrics +=  std::to_string(cpu_) 
    + std::to_string(memory_) 
    + std::to_string(avaialable_cpu) 
    + std::to_string(available_memory_);
    metrics += "\n";
    return metrics; 
};

std::ostream& operator<<(std::ostream& os, const Server& s){
    os << "Server ";
    for ( auto i : s.id_){
        os<<i;
    };
    os<<" id :"<<s.cpu_<<" , " <<s.memory_<<" , "<<s.avaialable_cpu<<s.available_memory_<< "\n";
    return os;
}
