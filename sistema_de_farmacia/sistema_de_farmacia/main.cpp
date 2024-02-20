#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class vendedor {
	int identificador;
	string nome;
public:
	vendedor(int id, const string& n) : identificador(id), nome(n){
	}
	~vendedor() {
		cout << "Vendedor " << get_identificador() << " destruido!" << endl;
	}
	void set_identificador(int id) {
		identificador = id;
	}
	int get_identificador() {
		return identificador;
	}
	void set_nome(const string& n) {
		nome = n;
	}
	string get_nome() {
		return nome;
	}
	void print_info() {
		cout << "### VENDEDOR ###" << endl;
		cout << "Identificador: " << identificador << endl;
		cout << "Nome: " << nome << endl << endl;
	}
};

class cliente {
	string nome;
	int cpf;
public:
	cliente(const string& n, int c) : nome(n), cpf(c) {
	}
	~cliente() {
		cout << "Cliente " << get_cpf() << " destruido!" << endl;
	}
	void set_nome(const string& n) {
		nome = n;
	}
	string get_nome() {
		return nome;
	}
	void set_cpf(int c) {
		cpf = c;
	}
	int get_cpf() {
		return cpf;
	}
	void print_info() {
		cout << "### CLIENTE ###" << endl;
		cout << "Nome: " << nome << endl;
		cout << "CPF:" << cpf << endl << endl;
	}
};

class produto {
	int preco;
	int codigo;
	string nomenclatura;
	string descricao;
public:
	produto(int p, int cod, const string& n, const string& d) : preco(p), codigo(cod), nomenclatura(n), descricao(d) {
	}
	~produto() {
		cout << "Produto " << get_codigo() << " destruido!" << endl;
	}
	void set_preco(int p) {
		preco = p;
	}
	int get_preco() {
		return preco;
	}
	void set_codigo(int cod) {
		codigo = cod;
	}
	int get_codigo() {
		return codigo;
	}
	void set_nomenclatura(const string& n) {
		nomenclatura = n;
	}
	string get_nomenclatura() {
		return nomenclatura;
	}
	void set_descricao(const string& d) {
		descricao = d;
	}
	string get_decricao() {
		return descricao;
	}
	void print_info() {
		cout << "### PRODUTO ###" << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Nomenclatura: " << nomenclatura << endl;
		cout << "Descricao: " << descricao << endl;
		cout << "Preco: " << preco << " reais" << endl << endl;
	}
};

class venda {
	produto* item;
	int quantidade;
	cliente* comprador;
	vendedor* atendente;
	string datahora;

	// os vetores foram passados como ponteiros para evitar cópia

public:
	venda(produto* p, int qtd, cliente* c, vendedor* v, const string& dt) : item(p), quantidade(qtd), comprador(c), atendente(v), datahora(dt) {
	}
	~venda() {
		cout << "Venda " << get_datahora() << " destruido!" << endl;
	}
	void set_item(produto* p) {
		item = p;
	}
	produto get_item() {
		return *item;
	}
	void set_quantidade(int qtd) {
		quantidade = qtd;
	}
	int get_quantidade() {
		return quantidade;
	}
	void set_comprador(cliente* c) {
		comprador = c;
	}
	cliente get_comprador() {
		return *comprador;
	}
	void set_atendente(vendedor* v) {
		atendente = v;
	}
	vendedor get_atendente() {
		return *atendente;
	}
	void set_datahora(const string& dt) {
		datahora = dt;
	}
	string get_datahora() {
		return datahora;
	}
	void print_info() {
		cout << "### VENDA ###" << endl;
		cout << "Data/hora: " << datahora << endl;
		cout << "Cliente: " << comprador->get_nome() << "(" << comprador->get_cpf() << ")" << endl;
		cout << "Produto: " << item->get_nomenclatura() << endl;
		cout << "Preco unitario: " << item->get_preco() << endl;
		cout << "Quantidade:" << quantidade << endl;
		cout << "Valor da venda:" << item->get_preco() * quantidade << endl;
		cout << "Atendente: " << atendente->get_nome() << "(" << atendente->get_identificador() << ")" << endl << endl;
	}
};

int main(void) {
	cout << "### SISTEMA DE FARMACIA ###" << endl << endl;

	// cadastro de medicamentos
	vector<produto> produtos;
	produtos.push_back(produto(7, 10001, "Paracetamol", "Caixa com 20 comprimidos de 500mg"));
	produtos.push_back(produto(5, 10002, "Acido Acetilsalicilico", "Caixa com 30 comprimidos de 100mg"));
	produtos.push_back(produto(15, 10003, "Omeprazol", "Caixa com 14 capsulas de 20mg"));
	produtos.push_back(produto(10, 10004, "Ibuprofeno", "Caixa com 20 comprimidos de 400mg"));
	produtos.push_back(produto(20, 10005, "Amoxilina", "Caixa com 15 capsulas de 500mg"));
	for (int a = 0; a < produtos.size(); a++) {
		produtos[a].print_info();
	}	

	// cadastro de vendedores
	vector<vendedor> vendedores;
	vendedores.push_back(vendedor(11, "Davi Lopes"));
	vendedores.push_back(vendedor(12, "Maria Clara"));
	for (int a = 0; a < vendedores.size(); a++) {
		vendedores[a].print_info();
	}

	// cadastro de clientes
	vector<cliente> clientes;
	clientes.push_back(cliente("Carlos Eduardo", 123456789));
	clientes.push_back(cliente("Ana Catarina", 987654321));
	clientes.push_back(cliente("Maria Gomes", 112358132));
	for (int a = 0; a < clientes.size(); a++) {
		clientes[a].print_info();
	}

	// cadastro de vendas
	vector<venda> vendas;
	vendas.push_back(venda(&produtos[0], 2, &clientes[0], &vendedores[0], "01-01-2024 15:35"));
	vendas.push_back(venda(&produtos[1], 3, &clientes[1], &vendedores[1], "02-01-2024 10:09"));
	vendas.push_back(venda(&produtos[2], 2, &clientes[2], &vendedores[0], "03-01-2024 16:22"));
	vendas.push_back(venda(&produtos[3], 1, &clientes[0], &vendedores[1], "04-01-2024 08:58"));
	vendas.push_back(venda(&produtos[4], 3, &clientes[1], &vendedores[0], "05-01-2024 12:15"));
	for (int a = 0; a < vendas.size(); a++) {
		vendas[a].print_info();
	}

	return 0;
}