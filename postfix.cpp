#include <iostream>
#include <cctype> // Para a função isdigit
using namespace std;

class Parser {
public:
    static int lookahead;

    Parser() {
        lookahead = cin.get();
    }

    // Função para analisar expressões
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

    // Função para analisar termos (multiplicação e divisão)
    void term() {
        factor();
        while (true) {
            if (lookahead == '*') {
                match('*');
                factor();
                cout.put('*');
            } else if (lookahead == '/') {
                match('/');
                factor();
                cout.put('/');
            } else {
                return;
            }
        }
    }

    // Função para analisar fatores (números e parênteses)
    void factor() {
        if (isdigit(lookahead)) {
            cout.put(lookahead);
            match(lookahead);
        } else if (lookahead == '(') { // Trata os parênteses
            match('(');
            expr();
            match(')');
        } else {
            throw runtime_error("syntax error");
        }
    }

    // Função para casar e avançar a entrada
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

