#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class calcado {
	int tamanho;
	string cor;
	float preco;
public:
	calcado(int t, string c, float p) : tamanho(t), cor(c), preco(p) {
	}
	~calcado() {
	}
	int get_tamanho() {
		return tamanho;
	}
	void set_tamanho(int t) {
		tamanho = t;
	}
	string get_cor() {
		return cor;
	}
	void set_cor(string c) {
		cor = c;
	}
	float get_preco() {
		return preco;
	}
	void set_preco(float p) {
		preco = p;
	}
	virtual void print_info() {
		cout << "calcado(" << tamanho << ", " << cor << ", " << preco << ")" << endl;
	}
};

class acessorio {
	string material;
	string estilo;
public:
	acessorio(string m, string e) : material(m), estilo(e) {
	}
	~acessorio() {
	}
	string get_material() {
		return material;
	}
	void set_material(string m) {
		material = m;
	}
	string get_estilo() {
		return estilo;
	}
	void set_estilo(string e) {
		estilo = e;
	}
	virtual void print_info() {
		cout << "acessorio(" << material << ", " << estilo << ")" << endl;
	}
};

class sapato : public calcado {
	string fecho;
public:
	sapato(int t, string c, float p, string f) : calcado(t, c, p), fecho(f) {
	}
	~sapato() {
	}
	string get_fecho() {
		return fecho;
	}
	void set_fecho(string f) {
		fecho = f;
	}
	void print_info() {
		cout << "sapato(" << get_tamanho() << ", " << get_cor() << ", " << get_preco() << ", " << fecho << ")" << endl;
	}
};

class sandalia : public calcado {
	string solado;
public:
	sandalia(int t, string c, float p, string s) : calcado(t, c, p), solado(s) {
	}
	~sandalia() {
	}
	string get_solado() {
		return solado;
	}
	void set_solado(string s) {
		solado = s;
	}
	void print_info() {
		cout << "sandalia(" << get_tamanho() << ", " << get_cor() << ", " << get_preco() << ", " << solado << ")" << endl;
	}
};

class bota : public calcado {
	string revestimento;
public:
	bota(int t, string c, float p, string r) : calcado(t, c, p), revestimento(r) {
	}
	~bota() {
	}
	string get_revestimento() {
		return revestimento;
	}
	void set_revestimento(string r) {
		revestimento = r;
	}
	void print_info() {
		cout << "bota(" << get_tamanho() << ", " << get_cor() << ", " << get_preco() << ", " << revestimento << ")" << endl;
	}
};

class palmilha : public acessorio {
	string suporte;
public:
	palmilha(string m, string e, string s) : acessorio(m, e), suporte(s) {
	}
	~palmilha() {
	}
	string get_suporte() {
		return suporte;
	}
	void set_suporte(string s) {
		suporte = s;
	}
	void print_info() {
		cout << "palmilha(" << get_material() << ", " << get_estilo() << ", " << suporte << ")" << endl;
	}
};

class cadarco : public acessorio {
	float comprimento;
public:
	cadarco(string m, string e, float c) : acessorio(m, e), comprimento(c) {
	}
	~cadarco() {
	}
	float get_comprimento() {
		return comprimento;
	}
	void set_comprimento(float c) {
		comprimento = c;
	}
	void print_info() {
		cout << "cadarco(" << get_material() << ", " << get_estilo() << ", " << comprimento << ")" << endl;
	}
};

class fivela : public acessorio {
	string formato;
public:
	fivela(string m, string e, string f) : acessorio(m, e), formato(f) {
	}
	~fivela() {
	}
	string get_formato() {
		return formato;
	}
	void set_formato(string f) {
		formato = f;
	}
	void print_info() {
		cout << "fivela(" << get_material() << ", " << get_estilo() << ", " << formato << ")" << endl;
	}
};

class estoque {
	vector<calcado*> calcados;
	vector<acessorio*> acessorios;
public:
	void add_calcado(calcado* c) {
		calcados.push_back(c);
	}
	void add_acessorio(acessorio* a) {
		acessorios.push_back(a);
	}
	void remove_calcado(int i) {
		calcados.erase(calcados.begin() + i);
	}
	void remove_acessorio(int i) {
		acessorios.erase(acessorios.begin() + i);
	}
	void listar_calcados() {
		for (int i = 0; i < calcados.size(); i++) {
			cout << "Calcado " << i << ":" << endl;
			calcados[i]->print_info();
		}
	}
	void listar_acessorios() {
		for (int i = 0; i < acessorios.size(); i++) {
			cout << "Acessorio " << i << ":" << endl;
			acessorios[i]->print_info();
		}
	}
};

int main(void) {
	cout << "Sistema de controle de estoque - sapataria" << endl;

	cout << "Criando calcados e acessorios..." << endl;

	// criar um sapato
	sapato s(40, "preto", 100.0, "cadarco");

	// criar uma sandalia
	sandalia sa(38, "marrom", 80.0, "borracha");

	// criar uma bota
	bota b(42, "bege", 120.0, "couro");

	// criar uma palmilha
	palmilha p("espuma", "esportiva", "arco");

	// criar um cadarco
	cadarco c("algodao", "fino", 1.5);

	// criar uma fivela
	fivela f("metal", "tradicional", "quadrada");

	cout << "Adicionando calcados e acessorios ao estoque..." << endl;

	// criar um estoque
	estoque e;

	// adicionar calcados ao estoque
	e.add_calcado(&s);
	e.add_calcado(&sa);
	e.add_calcado(&b);

	// adicionar acessorios ao estoque
	e.add_acessorio(&p);		
	e.add_acessorio(&c);
	e.add_acessorio(&f);

	cout << "Listando calcados e acessorios..." << endl;

	// listar calcados
	e.listar_calcados();

	// listar acessorios
	e.listar_acessorios();

	cout << "Removendo calcados e acessorios do estoque..." << endl;

	// remover calcado
	e.remove_calcado(1);

	// remover acessorio
	e.remove_acessorio(2);

	cout << "Listando calcados e acessorios..." << endl;

	// listar calcados
	e.listar_calcados();

	// listar acessorios
	e.listar_acessorios();
	
	return 0;
}