#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "nlohmann/json.hpp"


using json = nlohmann::json;
using namespace std;

// Structure to hold our parsed data
struct ShareData {
    int n;        // total shares
    int k;        // threshold
    map<string, pair<string, string>> shares;  // key -> {base, value}
};

// Function to read and parse JSON file
ShareData parseJsonFile(const string& filename) {
    ShareData data;
    
    try {
        // Read JSON file
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Could not open file: " + filename);
        }

        // Parse JSON
        json j;
        file >> j;
        
        // Get n and k values
        data.n = j["keys"]["n"];
        data.k = j["keys"]["k"];
        
        // Iterate through other keys (excluding "keys")
        for (auto& [key, value] : j.items()) {
            if (key != "keys") {
                // Store base and value in our map
                data.shares[key] = {
                    value["base"].get<string>(),
                    value["value"].get<string>()
                };
            }
        }
        
    } catch (const exception& e) {
        cerr << "Error parsing JSON: " << e.what() << endl;
        throw;
    }
    
    return data;
}

// Function to print parsed data (for verification)
void printShareData(const ShareData& data) {
    cout << "n: " << data.n << ", k: " << data.k << endl;
    cout << "\nShares:" << endl;
    for (const auto& [key, value] : data.shares) {
        cout << "Key " << key << ": "
             << "base=" << value.first 
             << ", value=" << value.second << endl;
    }
}

int main() {
    try {
        // Parse the JSON file
        ShareData data = parseJsonFile("input.json");
        
        // Print parsed data
        cout << "Successfully parsed JSON data:" << endl;
        printShareData(data);
        
        // Now you can use this data for the secret sharing calculation
        // ... rest of your secret sharing code ...
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}