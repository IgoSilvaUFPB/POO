#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::remove;
using std::cout;
using std::cin;

class Autor {
private:
    string nome; // nome do autor privado
public:
    Autor(string nome) : nome(nome) {}
    ~Autor() {}
    void set_nome(string nome) { this->nome = nome; } // setter para nome público
    string get_nome() { return nome; } // getter para nome público
};

class Livro {
private:
    string titulo; // título do livro privado
    vector<Autor*> autores; // vetor de autores privado
    int num_paginas; // número de páginas privado
public:
    Livro(string titulo, int num_paginas) : titulo(titulo), num_paginas(num_paginas) {}
    virtual ~Livro() {
        for (auto autor : autores) {
            delete autor;
        }
    }
    void set_titulo(string titulo) { this->titulo = titulo; } // setter para titulo público
    string get_titulo() const { return titulo; } // getter para titulo público
    vector<Autor*> get_autores() { return autores; } // getter para autores público
    void set_num_paginas(int num_paginas) { this->num_paginas = num_paginas; } // setter para num_paginas público
    int get_num_paginas() const { return num_paginas; } // getter para num_paginas público
    Livro& operator+(Autor* autor) { autores.push_back(autor); return *this; } // sobrecarga do operador + para adicionar autor
    Livro& operator-(Autor* autor) { autores.erase(remove(autores.begin(), autores.end(), autor), autores.end()); return *this; } // sobrecarga do operador - para remover autor
    virtual void imprimirDetalhes() const = 0; // método virtual puro
};

class LivroFisico : public Livro {
private:
    string tipo_papel;
public:
    LivroFisico(string titulo, int num_paginas, string tipo_papel) : Livro(titulo, num_paginas), tipo_papel(tipo_papel) {}
    ~LivroFisico() {}
    string get_tipo_papel() const { return tipo_papel; } // getter para tipo_papel
    void imprimirDetalhes() const override {
        cout << "Título: " << get_titulo() << ", Número de páginas: " << get_num_paginas() << ", Tipo de papel: " << get_tipo_papel() << "\n";
    }
};

class LivroDigital : public Livro {
private:
    string formato_arquivo;
public:
    LivroDigital(string titulo, int num_paginas, string formato_arquivo) : Livro(titulo, num_paginas), formato_arquivo(formato_arquivo) {}
    ~LivroDigital() {}
    string get_formato_arquivo() const { return formato_arquivo; } // getter para formato_arquivo
    void imprimirDetalhes() const override {
        cout << "Título: " << get_titulo() << ", Número de páginas: " << get_num_paginas() << ", Formato do arquivo: " << get_formato_arquivo() << "\n";
    }
};

class Biblioteca {
private:
    vector<Livro*> livros; // vetor de livros privado
public:
    Biblioteca() {}
    ~Biblioteca() {}
    void adicionar_livro(Livro* livro) { livros.push_back(livro); } // adicionar livro à biblioteca público
    void remover_livro(Livro* livro) { livros.erase(remove(livros.begin(), livros.end(), livro), livros.end()); } // remover livro da biblioteca público
    Biblioteca& operator+(Livro* livro) { adicionar_livro(livro); return *this; } // sobrecarga do operador + para adicionar livro
    Biblioteca& operator-(Livro* livro) { remover_livro(livro); return *this; } // sobrecarga do operador - para remover livro
    vector<Livro*>& get_livros() { return livros; } // getter para livros
};

int main() {
    Biblioteca biblioteca;
    int opcao = 0;

    while (opcao != 9) {
        cout << "Menu:\n";
        cout << "1. Adicionar autor\n";
        cout << "2. Adicionar livro fisico\n";
        cout << "3. Adicionar livro digital\n";
        cout << "4. Remover livro\n";
        cout << "5. Listar livros\n";
        cout << "9. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            string nome;
            cout << "Nome do autor: ";
            cin >> nome;
            Autor* autor = new Autor(nome);
            cout << "Autor '" << nome << "' criado.\n";
            break;
        }
        case 2: {
            string titulo, tipo_papel;
            int num_paginas;
            cout << "Titulo do livro: ";
            cin >> titulo;
            cout << "Numero de paginas: ";
            cin >> num_paginas;
            cout << "Tipo de papel: ";
            cin >> tipo_papel;
            LivroFisico* livroFisico = new LivroFisico(titulo, num_paginas, tipo_papel);
            string nomeAutor;
            cout << "Nome do autor: ";
            cin >> nomeAutor;
            Autor* autor = new Autor(nomeAutor);
            *livroFisico + autor;
            biblioteca + livroFisico;
            break;
        }
        case 3: {
            string titulo, formato_arquivo;
            int num_paginas;
            cout << "Titulo do livro: ";
            cin >> titulo;
            cout << "Numero de paginas: ";
            cin >> num_paginas;
            cout << "Formato do arquivo: ";
            cin >> formato_arquivo;
            LivroDigital* livroDigital = new LivroDigital(titulo, num_paginas, formato_arquivo);
            string nomeAutor;
            cout << "Nome do autor: ";
            cin >> nomeAutor;
            Autor* autor = new Autor(nomeAutor);
            *livroDigital + autor;
            biblioteca + livroDigital;
            break;
        }
        case 4: {
            string titulo;
            cout << "Titulo do livro a ser removido: ";
            cin >> titulo;
            for (auto it = biblioteca.get_livros().begin(); it != biblioteca.get_livros().end(); ++it) {
                if ((*it)->get_titulo() == titulo) {
                    biblioteca.get_livros().erase(it);
                    cout << "Livro removido com sucesso.\n";
                    break;
                }
            }
            break;
        }
        case 5: {
            cout << "Livros na biblioteca:\n";
            for (auto& livro : biblioteca.get_livros()) {
                livro->imprimirDetalhes();
            }
            break;
        }
        case 9: {
            cout << "Saindo...\n";
            break;
        }
        default: {
            cout << "Opção invalida. Tente novamente.\n";
            break;
        }
        }
    }
    return 0;
}
