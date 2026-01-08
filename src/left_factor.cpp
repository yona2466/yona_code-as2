#include <iostream>
#include <vector>
#include <string>
#include <map>

// Production structure
struct Production {
    std::string lhs;
    std::vector<std::string> rhs;
    
    Production(const std::string& l, const std::vector<std::string>& r) 
        : lhs(l), rhs(r) {}
    
    void print() const {
        std::cout << lhs << " -> ";
        for (size_t i = 0; i < rhs.size(); i++) {
            std::cout << rhs[i];
            if (i < rhs.size() - 1) std::cout << " ";
        }
    }
};

// Grammar class
class Grammar {
private:
    std::vector<Production> productions;
    std::map<std::string, std::vector<Production>> prodMap;
    
public:
    void addProduction(const Production& prod) {
        productions.push_back(prod);
        prodMap[prod.lhs].push_back(prod);
    }
    
    // Find common prefix among productions of a non-terminal
    std::string findCommonPrefix(const std::string& nonTerminal) {
        auto it = prodMap.find(nonTerminal);
        if (it == prodMap.end() || it->second.size() < 2) {
            return "";
        }
        
        const auto& prods = it->second;
        std::string commonPrefix = "";
        
        // Compare first two productions
        if (prods.size() >= 2) {
            const auto& prod1 = prods[0];
            const auto& prod2 = prods[1];
            
            size_t minLen = std::min(prod1.rhs.size(), prod2.rhs.size());
            for (size_t i = 0; i < minLen; i++) {
                if (prod1.rhs[i] == prod2.rhs[i]) {
                    commonPrefix += prod1.rhs[i] + " ";
                } else {
                    break;
                }
            }
        }
        
        return commonPrefix;
    }
    
    void printGrammar() {
        std::cout << "Grammar Productions:\n";
        for (const auto& prod : productions) {
            prod.print();
            std::cout << "\n";
        }
    }
};

int main() {
    Grammar grammar;
    
    // Example 1: if-then-else grammar
    std::cout << "=== Example 1: If-Then-Else Grammar ===\n\n";
    
    grammar.addProduction(Production("S", {"if", "E", "then", "S"}));
    grammar.addProduction(Production("S", {"if", "E", "then", "S", "else", "S"}));
    grammar.addProduction(Production("S", {"other"}));
    
    grammar.printGrammar();
    
    std::string common = grammar.findCommonPrefix("S");
    if (!common.empty()) {
        std::cout << "\nCommon prefix found: " << common << "\n";
        std::cout << "Grammar needs left-factoring.\n";
    } else {
        std::cout << "\nNo common prefix found.\n";
    }
    
    // Example 2: Expression grammar
    std::cout << "\n=== Example 2: Expression Grammar ===\n\n";
    
    Grammar exprGrammar;
    exprGrammar.addProduction(Production("E", {"T", "+", "E"}));
    exprGrammar.addProduction(Production("E", {"T", "-", "E"}));
    exprGrammar.addProduction(Production("E", {"T"}));
    exprGrammar.addProduction(Production("T", {"F", "*", "T"}));
    exprGrammar.addProduction(Production("T", {"F", "/", "T"}));
    exprGrammar.addProduction(Production("T", {"F"}));
    exprGrammar.addProduction(Production("F", {"(", "E", ")"}));
    exprGrammar.addProduction(Production("F", {"id"}));
    
    exprGrammar.printGrammar();
    
    std::string commonE = exprGrammar.findCommonPrefix("E");
    std::string commonT = exprGrammar.findCommonPrefix("T");
    
    if (!commonE.empty()) {
        std::cout << "\nCommon prefix in E: " << commonE << "\n";
    }
    if (!commonT.empty()) {
        std::cout << "Common prefix in T: " << commonT << "\n";
    }
    
    return 0;
}
