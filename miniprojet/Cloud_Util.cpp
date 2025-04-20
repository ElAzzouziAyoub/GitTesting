#include "Cloud_Util.hpp"
#include "KubernetesCluster.hpp"
#include <iostream>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics() << std::endl;
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {

    for (auto& pod : pods) {
        cluster.deployPod(std::move(pod));
    }
    
    pods.clear();
    for (auto& pod : pods) {
        cluster.deployPod(std::move(pod));
    }
     // Facultatif : vide le vecteur si les pods sont maintenant gérés par le cluster
}


