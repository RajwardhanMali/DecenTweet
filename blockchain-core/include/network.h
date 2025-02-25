#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>

class Network {
public:
    static void broadcastBlock(std::string blockData);
    static void syncWithPeers();
};

#endif
