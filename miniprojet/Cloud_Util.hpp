#ifndef CLOUD_UTIL_H
#define CLOUD_UTIL_H

#include "KubernetesCluster.hpp" // Inclure vos fichiers appropriés

// Affiche les métriques du cluster
void display(const KubernetesCluster& cluster);

// Déploie plusieurs pods
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

#endif // CLOUD_UTIL_H
