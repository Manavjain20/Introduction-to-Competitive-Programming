#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (const string& s : strs) {
        // Create a key by sorting the characters of the string
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        
        // Add the string to the corresponding group in the map
        anagramGroups[sorted_s].push_back(s);
    }
    
    // Convert map values to vector of vectors (list of anagram groups)
    vector<vector<string>> result;
    for (auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    
    // Print the grouped anagrams
    for (const auto& group : groupedAnagrams) {
        cout << "[";
        for (const string& s : group) {
            cout << "\"" << s << "\", ";
        }
        cout << "], ";
    }
    cout << endl;
    
    return 0;
}
