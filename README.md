# 🚗 Sistema de Gestão de Concessionária (C++ e Programação Orientada a Objetos)

## 🎯 Visão Geral do Projeto
Este é um projeto acadêmico desenvolvido em C++ com o objetivo de simular as operações essenciais de uma concessionária (gestão de veículos, clientes, e transações). O foco principal está na aplicação rigorosa dos princípios da **Programação Orientada a Objetos (POO)** e no uso de uma arquitetura de código modular e limpa.

## 🛠️ Habilidades e Conceitos Aplicados

| Área | Habilidade Demonstrada |
| :--- | :--- |
| **Linguagem** | C++ |
| **Desenvolvimento** | Programação Orientada a Objetos (POO), incluindo **Herança**, **Polimorfismo** e **Encapsulamento** para modelagem de entidades (`Veiculo`, `Cliente`, etc.). |
| **Organização** | **Modularização** do código com separação clara de responsabilidades (arquivos `.h` para definições e `.cpp` para implementações). |
| **Compilação** | Utilização de `Makefile` para automatizar e gerenciar o processo de compilação do projeto. |
| **Estruturas** | Utilização de estruturas de dados básicas para gerenciamento de coleções de objetos (estoque, cadastros). |

## 📁 Estrutura do Repositório

* **`include/`**: Contém todos os arquivos de cabeçalho (`.h`) das classes, definindo a interface das estruturas de dados e objetos.
* **`src/`**: Contém os arquivos-fonte (`.cpp`) com a implementação da lógica e dos métodos das classes.
* **`Makefile`**: Arquivo de configuração para compilar e gerar o executável do sistema.
* `avaliação.md` / `IMD_SA.txt`: Documentos de suporte do projeto.

## 🚀 Como Compilar e Executar

Para rodar este projeto, você precisa ter um compilador C++ (como g++ ou Clang) e o utilitário `make` instalados no seu sistema operacional (Linux/macOS) ou ambiente de desenvolvimento.

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/esdrasfelipe07/sistema-concessionaria-cpp.git](https://github.com/esdrasfelipe07/sistema-concessionaria-cpp.git)
    cd sistema-concessionaria-cpp
    ```
2.  **Compile o projeto usando o Makefile:**
    ```bash
    make
    ```
3.  **Execute o sistema:**
    ```bash
    ./[nome_do_executavel] 
    # O nome do executável é definido no Makefile, geralmente 'main' ou 'concessionaria'.
    ```
