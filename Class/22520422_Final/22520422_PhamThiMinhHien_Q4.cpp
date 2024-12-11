#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ZodiacNode structure
struct ZodiacNode {
    string name;
    vector<string> compatibleSigns;
    ZodiacNode* left;
    ZodiacNode* right;

    ZodiacNode(string name, vector<string> compatibleSigns)
        : name(name), compatibleSigns(compatibleSigns), left(nullptr), right(nullptr) {}
};

// ZodiacBST class
class ZodiacBST {
private:
    ZodiacNode* root;

    // Helper function to insert a new node into the BST
    ZodiacNode* insert(ZodiacNode* node, string name, vector<string> compatibleSigns) {
        if (node == nullptr) {
            return new ZodiacNode(name, compatibleSigns);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, compatibleSigns);
        } else if (name > node->name) {
            node->right = insert(node->right, name, compatibleSigns);
        }
        return node;
    }

    // Helper function to find a zodiac node by name
    ZodiacNode* find(ZodiacNode* node, const string& name) {
        if (node == nullptr || node->name == name) {
            return node;
        }
        if (name < node->name) {
            return find(node->left, name);
        }
        return find(node->right, name);
    }

    // Helper function to check compatibility
    bool isCompatible(ZodiacNode* node, const string& sign1, const string& sign2) {
        ZodiacNode* signNode = find(node, sign1);
        if (signNode != nullptr) {
            for (const string& compatible : signNode->compatibleSigns) {
                if (compatible == sign2) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    ZodiacBST() : root(nullptr) {}

    // Function to insert a new zodiac sign into the BST
    void insertZodiac(string name, vector<string> compatibleSigns) {
        root = insert(root, name, compatibleSigns);
    }

    // Function to check if two zodiac signs are compatible
    bool checkCompatibility(const string& sign1, const string& sign2) {
        return isCompatible(root, sign1, sign2);
    }

    // Function to calculate compatibility score based on elemental associations
    string getCompatibilityScore(const string& sign1, const string& sign2) {
        // Define elemental groups
        vector<string> fire = {"Aries", "Leo", "Sagittarius"};
        vector<string> earth = {"Taurus", "Virgo", "Capricorn", "Ophiuchus"};
        vector<string> air = {"Gemini", "Libra", "Aquarius"};
        vector<string> water = {"Cancer", "Scorpio", "Pisces"};

        auto getElement = [&](const string& sign) {
        if (std::find(fire.begin(), fire.end(), sign) != fire.end()) return "Fire";
        if (std::find(earth.begin(), earth.end(), sign) != earth.end()) return "Earth";
        if (std::find(air.begin(), air.end(), sign) != air.end()) return "Air";
        if (std::find(water.begin(), water.end(), sign) != water.end()) return "Water";
        return "Unknown";
};

        string element1 = getElement(sign1);
        string element2 = getElement(sign2);

        if (element1 == "Unknown" || element2 == "Unknown") {
            return "One or both signs are invalid.";
        }

        if (element1 == element2) {
            return "Compatibility Score: High (Same Element)";
        }

        if ((element1 == "Fire" && element2 == "Air") || (element1 == "Air" && element2 == "Fire") ||
            (element1 == "Earth" && element2 == "Water") || (element1 == "Water" && element2 == "Earth")) {
            return "Compatibility Score: High (Complementary Elements)";
        }

        return "Compatibility Score: Low (Different Elements)";
    }
};

int main() {
    ZodiacBST bst;

    // Insert zodiac signs
    bst.insertZodiac("Aries", {"Leo", "Sagittarius", "Gemini", "Libra", "Aquarius"});
    bst.insertZodiac("Taurus", {"Virgo", "Capricorn", "Cancer", "Scorpio", "Pisces"});
    bst.insertZodiac("Gemini", {"Libra", "Aquarius", "Aries", "Leo", "Sagittarius"});
    bst.insertZodiac("Cancer", {"Scorpio", "Pisces", "Taurus", "Virgo", "Capricorn"});
    bst.insertZodiac("Ophiuchus", {"Cancer", "Scorpio", "Pisces", "Taurus", "Virgo"}); // Ophiuchus added

    // Compatibility check
    string sign1 = "Aries";
    string sign2 = "Leo";
    cout << sign1 << " and " << sign2 << " compatibility: "
         << (bst.checkCompatibility(sign1, sign2) ? "Compatible" : "Not Compatible") << endl;

    // Compatibility score
    cout << bst.getCompatibilityScore(sign1, sign2) << endl;

    // Compatibility score involving Ophiuchus
    cout << "Ophiuchus and Cancer compatibility: "
         << bst.getCompatibilityScore("Ophiuchus", "Cancer") << endl;

    return 0;
}