#include "Pod.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

Pod::Pod(std::string name , std::unordered_map<std::string , std::string> labels_)
    : name_(name) , labels_(labels_) {};
void Pod::addContainer(std::unique_ptr<Container> container){
    containers_.push_back(std::move(container));

} ;
bool Pod::removeContainer(const std::string& id) {
    for (size_t i = 0; i < containers_.size(); ++i) {
        if (containers_[i]->id_ == id) {
            containers_.erase(containers_.begin() + i);
            return true;
        }
    }
    return false;
}


void Pod::deploy(){
    std::cout<<"Deploiement du pod  [Pod :"<<name_<<" ] \n";
    for (size_t i = 0 ; i < containers_.size() ; i++){
        containers_[i]->start();
        std::cout<<containers_[i]->getMetrics()<<std::endl;
    }
    std::cout<<"déployé avec succès"<<std::endl;

};
std::string Pod::getMetrics() const {
    std::string metrics ="";
    for (size_t i = 0 ; i < containers_.size() ; i++){
        metrics += containers_[i]->getMetrics();
    }
    metrics += "\n";
    return metrics;

};

std::ostream& operator<<(std::ostream& os, const Pod& p){
    os << "Pod: "<<p.name_<<" ";
    os<<"containers : [";
    os<<p.getMetrics();
    return os;

};
const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;  
}
