#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente {
    string nome;
    string cpf;
    int idade;

public:
    Cliente(string nome, string cpf, int idade) : nome(nome), cpf(cpf), idade(idade) {}

    string getNome() const { return nome; }
    string getCPF() const { return cpf; }
    int getIdade() const { return idade; }

    void setNome(string novoNome) { nome = novoNome; }
    void setCPF(string novoCPF) { cpf = novoCPF; }
    void setIdade(int novaIdade) { idade = novaIdade; }
};

class Operacao {
    string tipo;
    double valor;
    double imposto;

public:
    Operacao(string tipo, double valor, double imposto) : tipo(tipo), valor(valor), imposto(imposto) {}

    string getTipo() const { return tipo; }
    double getValor() const { return valor; }
    double getImposto() const { return imposto; }

    void setTipo(string novoTipo) { tipo = novoTipo; }
    void setValor(double novoValor) { valor = novoValor; }
    void setImposto(double novoImposto) { imposto = novoImposto; }
};

class ContaCorrente {
    int numero;
    Cliente cliente;
    double saldo;
    vector<Operacao> operacoes;

public:
    ContaCorrente(int numero, Cliente cliente, double saldo) : numero(numero), cliente(cliente), saldo(saldo) {}

    int getNumero() const { return numero; }
    Cliente getCliente() const { return cliente; }
    double getSaldo() const { return saldo; }
    vector<Operacao> getOperacoes() const { return operacoes; }

    void adicionarOperacao(const Operacao& op) {
        operacoes.push_back(op);
        if (op.getTipo() == "credito") {
            saldo += op.getValor();
        }
        else if (op.getTipo() == "debito") {
            saldo -= op.getValor() + op.getImposto();
        }
    }

    void setNumero(int novoNumero) { numero = novoNumero; }
    void setCliente(const Cliente& novoCliente) { cliente = novoCliente; }
    void setSaldo(double novoSaldo) { saldo = novoSaldo; }
};

int main() {
    Cliente cliente1("Joao", "123.456.789-00", 30);
    Cliente cliente2("Maria", "987.654.321-00", 25);
    Cliente cliente3("Pedro", "111.222.333-44", 35);

    ContaCorrente conta1(1001, cliente1, 1000.0);
    ContaCorrente conta2(1002, cliente2, 1500.0);
    ContaCorrente conta3(1003, cliente3, 2000.0);

    Operacao op1("credito", 500.0, 0.0);
    Operacao op2("debito", 200.0, 1.38);
    Operacao op3("credito", 1000.0, 0.0);
    Operacao op4("debito", 300.0, 0.07);
    Operacao op5("credito", 700.0, 0.0);
    Operacao op6("debito", 400.0, 2.14);

    conta1.adicionarOperacao(op1);
    conta1.adicionarOperacao(op2);
    conta2.adicionarOperacao(op3);
    conta2.adicionarOperacao(op4);
    conta3.adicionarOperacao(op5);
    conta3.adicionarOperacao(op6);

    cout << "Dados da Conta 1:" << endl;
    cout << "Cliente: " << conta1.getCliente().getNome() << endl;
    cout << "CPF: " << conta1.getCliente().getCPF() << endl;
    cout << "Idade: " << conta1.getCliente().getIdade() << endl;
    cout << "Saldo: " << conta1.getSaldo() << endl;

    cout << "Dados da Conta 2:" << endl;
    cout << "Cliente: " << conta2.getCliente().getNome() << endl;
    cout << "CPF: " << conta2.getCliente().getCPF() << endl;
    cout << "Idade: " << conta2.getCliente().getIdade() << endl;
    cout << "Saldo: " << conta2.getSaldo() << endl;

    cout << "Dados da Conta 3:" << endl;
    cout << "Cliente: " << conta3.getCliente().getNome() << endl;
    cout << "CPF: " << conta3.getCliente().getCPF() << endl;
    cout << "Idade: " << conta3.getCliente().getIdade() << endl;
    cout << "Saldo: " << conta3.getSaldo() << endl;

    return 0;
}
