#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class cliente {
    string nome;
    int idade;
    int cpf;
public:
    cliente(string n, int i, int c) : idade(i), cpf(c) {
        nome = n;
    }

    ~cliente() {
        cout << "destruindo o cliente" << endl;
    }

    string get_nome() {
        return nome;
    }

    void set_nome(string n) {
        nome = n;
    }

    int get_idade() {
        return idade;
    }

    void set_idade(int i) {
        idade = i;
    }

    int get_cpf() {
        return cpf;
    }

    void set_cpf(int c) {
        cpf = c;
    }

    void print_info() {
        cout << "Cliente " << endl;
        cout << " Nome: " << nome << endl;
        cout << " Cpf: " << cpf << endl;
        cout << " Idade: " << idade << endl;
    }
};

class operacao {
    char tipo;
    double valor;
    double imposto;
public:
    operacao(char t, double v, double i)
        : tipo(t), valor(v), imposto(i) { }

    ~operacao() {
        cout << "operacao destruida" << endl;
    }

    char get_tipo() {
        return tipo;
    }

    void set_tipo(char t) {
        tipo = t;
    }

    double get_valor() {
        return valor;
    }

    void set_valor(double v) {
        valor = v;
    }

    double get_imposto() {
        return imposto;
    }

    void set_imposto(double i) {
        imposto = i;
    }

    void print_info() {
        cout << "Operacao" << endl;
        cout << " Tipo: " << tipo << endl;
        cout << " Valor: " << valor << endl;
        cout << " Imposto: " << imposto << endl;
    }
};

class conta_corrente {
    int numero;
    double saldo;
    cliente* c;
    vector <operacao> operacoes;
    int qtd_oper;
public:
    conta_corrente(int n, double s, cliente* cc) : numero(n), saldo(s), c(cc), operacoes(), qtd_oper(0) {}

    ~conta_corrente() {
        cout << "conta corrente destruida:" << numero;
        cout << endl;
        delete c;
    }

    int get_numero() {
        return numero;
    }

    void set_numero(int n) {
        numero = n;
    }

    double get_saldo() {
        return saldo;
    }

    void set_saldo(double s) {
        saldo = s;
    }

    cliente* get_cliente() {
        return c;
    }

    void set_cliente(cliente* cc) {
        c = cc;
    }

    void add_operacao(operacao* o) {
        operacoes.push_back(*o);
        qtd_oper++;
        if (o->get_tipo() == 'C') {
            saldo += o->get_valor();
        }
        else {
            saldo -= o->get_valor();
        }
        saldo -= o->get_imposto();
    }

    operacao get_operacao(int i) {
        return operacoes[i];
    }

    void print_info() {
        cout << "Conta corrente" << endl;
        cout << " Numero: " << numero << endl;
        cout << " Saldo: " << saldo << endl;
        c->print_info();
        if (qtd_oper > 0) {
            for (int i = 0; i < qtd_oper; i++) {
                operacoes[i].print_info();
            }
        }
    }
};

int main(void) {
    cliente* c1 = new cliente("Ana Silva", 25, 1011);
    cliente* c2 = new cliente("Joao Ferreira", 33, 1012);
    cliente* c3 = new cliente("Maria Antunes", 40, 1099);

    conta_corrente cc1(1111, 0, c1);
    conta_corrente cc2(2222, 0, c2);
    conta_corrente cc3(3333, 0, c3);

    operacao* op1cc1 = new operacao('C', 500, 0);
    operacao* op2cc1 = new operacao('D', 100, 0.1);
    cc1.add_operacao(op1cc1);
    cc1.add_operacao(op2cc1);

    operacao* op1cc2 = new operacao('C', 1000, 0);
    operacao* op2cc2 = new operacao('C', 200, 0);
    cc2.add_operacao(op1cc2);
    cc2.add_operacao(op2cc2);

    operacao* op1cc3 = new operacao('C', 200, 0);
    operacao* op2cc3 = new operacao('D', 300, 0.3);
    cc3.add_operacao(op1cc3);
    cc3.add_operacao(op2cc3);

    cc1.print_info();
    cc2.print_info();
    cc3.print_info();

    return 0;
}