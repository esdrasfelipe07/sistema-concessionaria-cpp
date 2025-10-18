
# Identificação

* Nome: Esdras Felipe Chaves Pinto Nascimento e Silva

* Matrícula: 20230051975
  
# Compilação  

* Compilação: Para compilar o código, você pode usar o Makefile ou compilar diretamente no terminal. Se estiver usando o Makefile, navegue até o diretório do projeto e execute o comando make. Isso compilará todos os arquivos fonte (.cpp) e gerará o executável bin/concessionaria. Para rodar o programa, use ./bin/concessionaria ou make run. Se preferir compilar manualmente no terminal, utilize o comando g++ -Wall -o concessionaria src/main.cpp src/Automovel.cpp src/Caminhao.cpp src/Concessionaria.cpp src/Moto.cpp src/Veiculo.cpp src/listarFrotaConcessionaria.cpp src/saveConcessionaria.cpp -Iinclude. Isso criará um executável chamado concessionaria, que pode ser executado com ./concessionaria. Para interagir manualmente com o programa, insira comandos como create-concessionaria NomeDaConcessionaria CNPJ, add-car NomeDaConcessionaria Marca Preço Chassi Ano TipoMotor, list-concessionaria NomeDaConcessionaria, remove-vehicle Chassi, raise-price NomeDaConcessionaria X e quit para encerrar. Para testar o programa com entradas pré-definidas, redirecione um arquivo de texto (como teste.txt) para a entrada do programa usando ./concessionaria < teste.txt. Use make clean para remover arquivos temporários gerados durante a compilação.


# Limitações

* O código não lida com exceções, o que pode resultar em falhas silenciosas ou comportamentos inesperados em situações de erro, como entradas inválidas do usuário ou falhas ao manipular arquivos. Além disso, não há verificações robustas para as entradas do usuário, o que pode levar a problemas como valores negativos para preços ou anos de fabricação. Outra limitação é o uso de ponteiros brutos, que pode causar vazamentos de memória ou acesso a memória já liberada.
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | ** 10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | ** 10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | ** 10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | ** 10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | ** 10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | ** 15 / 15 - Bônus: 0 **
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | ** 10 / 10 - Bônus: 0 **
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | ** 10 / 10 - Bônus: 0 **
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | ** 15 / 15**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | ** 10 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | ** 5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | ** 5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | ** 15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 ** 135 / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
