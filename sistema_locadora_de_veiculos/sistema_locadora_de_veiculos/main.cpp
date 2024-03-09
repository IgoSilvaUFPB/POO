#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

/*
Nas classes cliente, carro e funcionario
optei por preencher os atributos
durante a instanciação dos objetos
dentro do construtor.
*/

class cliente {
	string nome;
	string sobrenome;
	int cnh;
public:
	// construtor de cliente
	cliente() {
		cout << "== Cadastro de cliente ==" << endl;
		cout << "Nome do cliente: ";
		cin >> nome;
		cout << "Sobrenome do cliente: ";
		cin >> sobrenome;
		cout << "CNH do cliente: ";
		cin >> cnh;
	}
	// destrutor de clientes
	~cliente() {
	}
	// métodos gets e sets dos atributos
	void set_nome(const string& n) {
		nome = n;
	}
	string get_nome() {
		return nome;
	}
	void set_sobrenome(const string& s) {
		sobrenome = s;
	}
	string get_sobrenome() {
		return sobrenome;
	}
	void set_cnh(int c) {
		cnh = c;
	}
	int get_cnh() {
		return cnh;
	}
	// método para exibir cliente
	void exibe_cliente() {
		cout << "Cliente:" << endl;
		cout << "   Nome - " << nome << endl;
		cout << "   Sobrenome - " << sobrenome << endl;
		cout << "   CNH - " << cnh << endl << endl;
	}
};

class carro {
	string marca;
	string modelo;
	int quilometragem;
public:
	// contrutor de carro
	carro() {
		cout << "== Cadastro de veiculo ==" << endl;
		cout << "Marca do veiculo: ";
		cin >> marca;
		cout << "Modelo do veiculo: ";
		cin >> modelo;
		cout << "Quilometragem do veiculo: ";
		cin >> quilometragem;
	}
	// destrutor de carro
	~carro() {
	}
	// métodos gets e sets dos atributos
	void set_marca(const string& m) {
		marca = m;
	}
	string get_marca() {
		return marca;
	}
	void set_modelo(const string& mod) {
		modelo = mod;
	}
	string get_modelo() {
		return modelo;
	}
	void set_quilometragem(int km) {
		quilometragem = km;
	}
	int get_quilometragem() {
		return quilometragem;
	}
	// método para exibir carro
	void exibe_carro() {
		cout << "Veiculo:" << endl;
		cout << "   Marca - " << marca << endl;
		cout << "   Modelo - " << modelo << endl;
		cout << "   Quilometragem - " << quilometragem << " Km" << endl << endl;
	}
};

class funcionario {
	string nome;
	string sobrenome;
	int ctps;
public:
	// construtor de funcionario
	funcionario() {
		cout << "== Cadastro de funcionario ==" << endl;
		cout << "Nome do funcionario: ";
		cin >> nome;
		cout << "Sobrenome do funcionario: ";
		cin >> sobrenome;
		cout << "CTPS do funcionario: ";
		cin >> ctps;
	}
	// destrutor de funcionario
	~funcionario() {
	}
	// métodos gets e sets dos atributos
	void set_nome(const string& n) {
		nome = n;
	}
	string get_nome() {
		return nome;
	}
	void set_sobrenome(const string& s) {
		sobrenome = s;
	}
	string get_sobrenome() {
		return sobrenome;
	}
	void set_ctps(int c) {
		ctps = c;
	}
	int get_ctps() {
		return ctps;
	}
	// método para exibir carro
	void exibe_funcionario() {
		cout << "Funcionario:" << endl;
		cout << "   Nome - " << nome << endl;
		cout << "   Sobrenome - " << sobrenome << endl;
		cout << "   CTPS - " << ctps << endl << endl;
	}
};

class locacao {
	// exemplo de composição
	cliente* locador;
	carro* veiculo;
	funcionario* responsavel;
	int num_dias;
public:
	// construtor de locacao
	locacao(cliente* l, carro* v, funcionario* r, int n) : locador(l), veiculo(v), responsavel(r), num_dias(n) {
	}
	// destrutor de locacao
	~locacao(){
	}
	// métodos gets e sets dos atributos
	void set_locador(cliente* l) {
		locador = l;
	}
	cliente get_locador() {
		return *locador;
	}
	void set_veiculo(carro* v){
		veiculo = v;
	}
	carro get_veiculo() {
		return *veiculo;
	}
	void set_responsavel(funcionario* r) {
		responsavel = r;
	}
	funcionario get_responsavel() {
		return *responsavel;
	}
	void set_num_dias(int dias) {
		num_dias = dias;
	}
	int get_num_dias() {
		return num_dias;
	}
	// método para exibir locação
	void exibe_locacao() {
		cout << "----------- Dados da Locacao -----------" << endl;
		locador->exibe_cliente();
		veiculo->exibe_carro();
		responsavel->exibe_funcionario();
		cout << "   Numero de dias - " << num_dias << endl << endl;
	}
};

int main(void) {
	cout << "### LOCADORA DE VEICULOS ###" << endl;

	// cadastro de 3 veiculos
	cout << "Cadastro de 3 veiculos:" << endl << endl;
	carro v1;
	carro v2;
	carro v3;
	cout << endl << "----- Veiculos cadastrados ------" << endl;
	v1.exibe_carro();
	v2.exibe_carro();
	v3.exibe_carro();

	// cadastro de 3 funcionarios
	cout << "Cadastro de 3 funcionarios:" << endl << endl;
	funcionario f1;
	funcionario f2;
	funcionario f3;
	cout << endl << "------ Funcionarios cadastrados ------" << endl;
	f1.exibe_funcionario();
	f2.exibe_funcionario();
	f3.exibe_funcionario();

	// cadastro de 3 clientes
	cout << "Cadastro de 3 clientes:" << endl << endl;
	cliente c1;
	cliente c2;
	cliente c3;
	cout << endl << "------ Clientes cadastrados ------" << endl;
	c1.exibe_cliente();
	c2.exibe_cliente();
	c3.exibe_cliente();

	// duracoes das locacoes
	int d1, d2, d3;
	cout << "Quantidade de dias da primeira locacao: ";
	cin >> d1;
	cout << "Quantidade de dias da segunda locacao: ";
	cin >> d2;
	cout << "Quantidade de dias da terceira locacao: ";
	cin >> d3;

	cout << endl << "===========================================" << endl << endl;

	// criando e exibindo as locacoes
	locacao l1(&c1, &v1, &f1, d1);
	cout << c1.get_nome() << " " << c1.get_sobrenome() << " alugou o " << v1.get_modelo() << " por " << l1.get_num_dias() << " dias." << endl;
	cout << "E ele(a) foi atendido por " << f1.get_nome() << " " << f1.get_sobrenome() << "." << endl;
	l1.exibe_locacao();
	locacao l2(&c2, &v2, &f2, d2);
	cout << c2.get_nome() << " " << c2.get_sobrenome() << " alugou o " << v2.get_modelo() << " por " << l2.get_num_dias() << " dias." << endl;
	cout << "E ele(a) foi atendido por " << f2.get_nome() << " " << f2.get_sobrenome() << "." << endl;
	l2.exibe_locacao();
	locacao l3(&c3, &v3, &f3, d3);
	cout << c3.get_nome() << " " << c3.get_sobrenome() << " alugou o " << v3.get_modelo() << " por " << l3.get_num_dias() << " dias." << endl;
	cout << "E ele(a) foi atendido por " << f3.get_nome() << " " << f3.get_sobrenome() << "." << endl;
	l3.exibe_locacao();

	return 0;
}