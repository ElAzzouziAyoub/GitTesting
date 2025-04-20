#include "KubernetesCluster.hpp"
#include <iostream>


void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(node);
}

bool KubernetesCluster::removePod(const std::string& name) {
    for (auto it = pods_.begin(); it != pods_.end(); ++it) {
        if ((*it)->name_ == name) {
            pods_.erase(it);
            return true;
        }
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    if (schedulePod(*pod)) {
        pod->deploy();
        pods_.push_back(std::move(pod));
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double total_cpu = 0;
    double total_mem = 0;
    for (const auto& c : pod.containers_) {
        total_cpu += c->cpu_;
        total_mem += c->memory_;
    }

    for (auto& server : nodes_) {
        if (server->allocate(total_cpu, total_mem)) {
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    for (auto& pod : pods_) {
        if (pod->name_ == name) {
            return pod.get();
        }
    }
    return nullptr;
}


std::string KubernetesCluster::getMetrics() const {
    std::string metrics = "=== Cluster Metrics ===\n";

    metrics += "Servers:\n";
    for (const auto& server : nodes_) {
        metrics += server->getMetrics() + "\n";
    }

    metrics += "Pods:\n";
    for (const auto& pod : pods_) {
        metrics += pod->getMetrics() + "\n";
    }

    return metrics;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c){
    os<< "=== Kubernetes Cluster ===\n";
    os<< "Nodes:\n";
    for (auto& node : c.nodes_) {
        os << *node << "\n";
    };

    os<<"Pods:\n";
    for (auto& pod : c.pods_) {
        os<<*pod<< "\n";
    }
    return os;
}


