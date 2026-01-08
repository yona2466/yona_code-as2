# Compiler Design Assignment 2
## Topic: Left-Factoring in Parsing

Student: [Your Name]
Student ID: [Your ID]
Course: COMP 202
Date: [Date]

---

## 1. Introduction

Left-factoring is a grammar transformation technique used in compiler design to eliminate common prefixes in production rules. This process makes grammars suitable for top-down parsing methods like LL(k) parsing.

## 2. What is Left-Factoring?

Left-factoring rewrites grammar productions to remove ambiguity caused by common prefixes.

**Problematic Grammar:**
S → if E then S
S → if E then S else S
S → other

**Left-Factored Grammar:**
S → if E then S S'
S → other
S' → else S | ε

## 3. Why is Left-Factoring Important?

1. **Enables Predictive Parsing:** Allows LL(k) parsers to work without backtracking
2. **Removes Ambiguity:** Eliminates non-deterministic choices in parsing
3. **Improves Efficiency:** Reduces parsing time by avoiding backtracking
4. **Essential for Top-Down Parsers:** Required for recursive descent and LL parsers

## 4. Left-Factoring Algorithm

### Step-by-Step Process:

1. **Identify common prefixes** among alternative productions
2. **Extract the common prefix** into a new production
3. **Create new non-terminal** for the remaining parts
4. **Replace original productions** with factored form

**Mathematical Representation:**
If we have: A → αβ₁ | αβ₂ | ... | αβₙ | γ
After left-factoring:
A → αA' | γ
A' → β₁ | β₂ | ... | βₙ

## 5. Examples

### Example 1: Simple If-Statement

**Original:**
stmt → if expr then stmt
| if expr then stmt else stmt
| other

**After Left-Factoring:**
stmt → if expr then stmt stmt'
| other
stmt' → else stmt | ε

### Example 2: Expression Grammar

**Original:**
E → T + E
E → T - E
E → T

**After Left-Factoring:**
E → T E'
E' → + E | - E | ε

## 6. Implementation in C++

File: `src/left_factor.cpp`
#include <iostream>
#include <vector>
#include <string>

struct Production {

std::string lhs;

std::vectorstd::string rhs;
Production(std::string l, std::vector<std::string> r) 

    : lhs(l), rhs(r) {}
    };

class LeftFactorer {
private:
std::vector<Production> productions;

public:
void addProduction(Production p) {
productions.push_back(p);
}
void leftFactor() {
    // Implementation of left-factoring algorithm
    // For each non-terminal, find common prefixes
    // and factor them
}

void printProductions() {

    for (const auto& prod : productions) {
    
        std::cout << prod.lhs << " -> ";
        for (size_t i = 0; i < prod.rhs.size(); i++) {
        
            if (i > 0) std::cout << " | ";
            for (const auto& sym : prod.rhs) {
            
                std::cout << sym << " ";
            }
        }
        std::cout << std::endl;
    }
}
};

int main() {
LeftFactorer factorer;
// Example: if-then-else grammar
factorer.addProduction(Production("S", {"if", "E", "then", "S"}));

factorer.addProduction(Production("S", {"if", "E", "then", "S", "else", "S"}));

factorer.addProduction(Production("S", {"other"}));

std::cout << "Original Grammar:" << std::endl;
factorer.printProductions();

factorer.leftFactor();

std::cout << "\nAfter Left-Factoring:" << std::endl;
factorer.printProductions();

return 0;
}

## 7. Real-World Applications

1. **Compiler Construction:** Used in tools like ANTLR, Yacc, and Bison
2. **IDE Development:** Enables syntax highlighting and code completion
3. **Language Processing:** Helps parse complex programming language constructs
4. **Data Validation:** Used in parsing configuration files and data formats

## 8. Limitations

1. **Grammar Size:** May increase number of productions
2. **ε-Productions:** Can introduce empty productions
3. **Not Always Sufficient:** Some grammars require additional transformations
4. **Language Restrictions:** Only works for certain types of ambiguities

## 9. Conclusion

Left-factoring is a fundamental technique in compiler design that transforms ambiguous grammars into forms suitable for top-down parsing. By eliminating common prefixes, it enables efficient, deterministic parsing essential for modern compiler construction.

## 10. References

1. Aho, A. V., Lam, M. S., Sethi, R., & Ullman, J. D. (2006). Compilers: Principles, Techniques, and Tools.
2. Grune, D., & Jacobs, C. J. (2008). Parsing Techniques: A Practical Guide.
3. Course materials: COMP 202 - Compiler Design

