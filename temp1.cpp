#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

std::vector<int> s(std::vector<std::string>& strings) {
    std::vector<int> result;
    int n = strings.size();

    // Initialize a map to store the dominance of each prefix
    std::unordered_map<std::string, int> prefixDominance;

    // Iterate through each string
    for (const auto& str : strings) {
        // Iterate through each prefix length
        for (int len = 1; len <= str.length(); len++) {
            std::string prefix = str.substr(0, len);
            prefixDominance[prefix]++;
        }
    }

    // Find the dominance of the most influential prefix for each length
    for (int len = 1; len <= strings[0].length(); len++) {
        int maxDominance = 0;
        for (const auto& [prefix, count] : prefixDominance) {
            if (prefix.length() == len && count > maxDominance) {
                maxDominance = count;
            }
        }
        result.push_back(maxDominance);
    }

    return result;
}

int main() {

    int n;cin>>n;
    std::vector<std::string> strings(n,"");

    for(int i=0;i<n;i++){
        cin>>strings[i];
    }
    
    std::vector<int> result = s(strings);

    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}