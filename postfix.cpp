#include <iostream>
#include <cctype> // Para a função isdigit
using namespace std;

class Parser {
public:
    static int lookahead;

    Parser() {
        lookahead = cin.get();
    }

    void expr() {
        term();
        while (true) {
            if (lookahead == '+') {
                match('+'); 
                term(); 
                cout.put('+');
            } else if (lookahead == '-') {
                match('-'); 
                term(); 
                cout.put('-');
            } else {
                return;
            }
        }
    }

    void term() {
        if (isdigit(lookahead)) {
            cout.put(lookahead);
            match(lookahead);
        } else {
            throw runtime_error("syntax error");
        }
    }

    void match(int t) {
        if (lookahead == t) {
            lookahead = cin.get();
        } else {
            throw runtime_error("syntax error");
        }
    }
};

// Inicializa o lookahead
int Parser::lookahead = 0;

int main() {
    try {
        Parser parser;
        parser.expr();
        cout.put('\n');
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
