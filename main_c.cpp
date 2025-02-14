#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// Structure to hold point data
struct Point {
    int x;
    double y;
};

// Convert number from given base to decimal
int convertToDecimal(string value, int base) {
    int result = 0;
    int power = 0;
    
    // Process from right to left
    for(int i = value.length() - 1; i >= 0; i--) {
        int digit;
        if(value[i] >= '0' && value[i] <= '9')
            digit = value[i] - '0';
        else
            digit = value[i] - 'a' + 10;
            
        result += digit * pow(base, power);
        power++;
    }
    return result;
}

// Lagrange interpolation to find constant term
double findConstantTerm(vector<Point>& points, int k) {
    double constantTerm = 0;
    
    // For each point i
    for(int i = 0; i < k; i++) {
        double term = points[i].y;
        
        // Compute the Lagrange basis polynomial
        for(int j = 0; j < k; j++) {
            if(i != j) {
                // Li(x) = product of (x - xj)/(xi - xj) for all j ≠ i
                // For constant term, we evaluate at x = 0
                term *= (-points[j].x) / (double)(points[i].x - points[j].x);
            }
        }
        constantTerm += term;
    }
    
    return round(constantTerm);  // Round to nearest integer
}

int main() {
    // Sample input JSON (parsed manually for demonstration)
    map<string, pair<string, string>> shares;
    shares["1"] = {"10", "4"};    // {base, value}
    shares["2"] = {"2", "111"};
    shares["3"] = {"10", "12"};
    shares["6"] = {"4", "213"};
    
    int n = 4;  // total shares
    int k = 3;  // threshold
    
    // Convert points to decimal and store
    vector<Point> points;
    for(const auto& share : shares) {
        Point p;
        p.x = stoi(share.first);  // x coordinate
        int base = stoi(share.second.first);
        string value = share.second.second;
        p.y = convertToDecimal(value, base);  // convert y to decimal
        points.push_back(p);
    }
    
    // Print converted points
    cout << "Converted Points:" << endl;
    for(const auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    
    // Find constant term using first k points
    double secret = findConstantTerm(points, k);
    cout << "\nThe constant term (secret) is: " << secret << endl;
    
    return 0;
}