#ifndef KUBERNETESCLUSTER_HPP
#define KUBERNETESCLUSTER_HPP

#include <vector>
#include "Pod.hpp"
#include "Server.hpp"
#include <string>

class KubernetesCluster{
    private : 
        std::vector<std::shared_ptr<Server>> nodes_;
        std::vector<std::shared_ptr<Pod>> pods_;
    public : 
        void addNode(std::shared_ptr<Server> node);
        bool removePod(const std::string& name);
        void deployPod(std::unique_ptr<Pod> pod);
        bool schedulePod(Pod& pod);
        Pod* getPod(const std::string& name);
        std::string getMetrics() const;
        friend void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);
        friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);

};


#endif