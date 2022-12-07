#include <vector>
#include <string>
#include <set>

struct Token {
    explicit(false) Token(std::string source) : val(std::move(source)) {}

    std::string const val;

    friend auto operator<=>(const Token& lhs, const Token& rhs) = default;
};

std::vector<std::string> const tokens {
        "const", "mutable", "volatile", "if", "for", "while", "switch", "do",
        "bool", "char", "short", "int", "long", "unsigned", "float", "double",
        "<", ">", "<=", ">=", "==", "!=", "||", "&&", "!",
        "+", "-", "*", "/", "%", "=", "+=", "-=", "*=", "/=", "%=",
        // much more
};

void use_tokens() {
    const std::string to_find = "non-existent";

    std::set<Token> non_heterogeneous( tokens.begin(), tokens.end() );
    std::set<Token, std::less<>> heterogeneous( tokens.begin(), tokens.end() );

    // Which of the following is more efficient, and why?

    /* ... */ (void)non_heterogeneous.find( to_find ); // a
    /* ... */ (void)heterogeneous.find( to_find ); // b
}
