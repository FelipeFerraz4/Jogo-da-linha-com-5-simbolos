                           # Jogo dos 5 simbolos

    Um jogo criado para uma cadeira de introdução à programação,
    onde o vencedor é o jogador que obter 5 símbolos sequenciais.

# Imagem do projeto
![Jogo dos 5 simbolos png2](https://user-images.githubusercontent.com/115377471/205943952-773f6c3a-4387-4871-81fa-700d3aff4933.png)

# Badge

![Badge Finalizada](https://img.shields.io/badge/Status-Finalizado-green)

# Índice 
  * [Título](# Jogo dos 5 simbolos)
  * [Imagem de capa](# Imagem do projeto)
  * [Badges](# Badge)
  * [Índice](# Índice)
  * [Descrição do Projeto](# Descrição-do-projeto)
  * [Status do Projeto](# Status-do-Projeto)
  * [Funcionalidades e Demonstração da Aplicação](# Funcionalidades-e-demonstração-da-aplicação)
  * [Acesso ao Projeto](# Acesso-ao-projeto)
  * [Tecnologias utilizadas](# Tecnologias-utilizadas)
  * [Pessoas Contribuidoras e desenvolvedoras](# Pessoas-contribuidoras/desenvolvedoras)
  * [Conclusão](# Conclusão)
  
# Descrição-do-projeto
  O jogo dos 5 simbolos é um jogo feito para dois jogadores. Sendo um jogo de 
  estratégia, que irão disputar para ver quem consegue atingir 5 simbolos em 
  sequência ou impossibilitar que o outro jogar consiga mover os seus peões.
  
# Status-do-Projeto
  O jogo já está finalizado; porém, está aberto para melhorias que ainda precisa ser feitas.
    Melhorias: Fazer o programa funcionar no linux (sem retirar as cores do programa).
               Deixar as funções mais eficientes.
               Mensagem de erro personalizada para cada erro.
               
# Funcionalidades-e-demonstração-da-aplicação
  O programa se inicia mostrando opções de operações: 
    1-Iniciar jogo
    0-Fechar o programa
    2-Regras
    ![image](https://user-images.githubusercontent.com/115377471/205957258-bd3c822a-eebf-4c67-9f5d-d3a5bb2110cb.png)

  O jogo com tem um tabuleiro 9x9, com 5 peões X e 5 peões O, posicionados de forma aleatória.
    ![image](https://user-images.githubusercontent.com/115377471/205957427-933308d4-c075-4637-b5bc-ce8b0597bb2c.png)
  
  O jogo se inicia com a rodada do jogador X, onde deverá escolher a posição da peça
  a ser movida.
    OBS:. a posição é feita com a união da linha e da coluna, exemplo: 1A.
          a linha vária de 1-9 e a coluna de A-I, como demostra o tabuleiro.
    ![image](https://user-images.githubusercontent.com/115377471/205958872-75e118fa-4ee6-45f6-8eff-f8619ce96ae8.png)
  
  Após é pedido a posição para qual a peça vai ser mover.
    OBS.: a peça só pode mover-se na horizontal, vertical e diagonal; como a rainha do xadrez.
          a peça não pode pular sobre outras peça.
          a peça ao finalizar o movimento deixa um simbolo aliado na posição que estava.
          ao pular todos os simbolos pulados troca para o seu oposto.
    ![image](https://user-images.githubusercontent.com/115377471/205959419-bcbd68e9-47f8-4c9e-92bd-c5679c307238.png)

  O vencedor é aquele que alinhar 5 simbolos ou impedir que seu oponente posssa
  movimenta-se.
    OBS.: Em relação aos simbolos alinhados, os peões contam com simbolos.
    
# Acesso-ao-projeto
  O projeto só funciona em um computador de sistema operacional Windown, devido ao uso de cores.
  Os arquivos estaram disponivel no https://github.com/FelipeFerraz4/Jogo-dos-5-simbolos.
    OBS.: os arquivos que devem ser pegos são os main.c e Tabuleiro.c
  Abra os arquivos em um programa que suporte C (99 ou 11).
    Open -> selecione o arquivo e clique em OK
  Se quiser abrir o arquivo, vocês deve pegar também o arquivo projeto_jogo_5_linhas.cbp e 
  deve abrir ele.
  
# Tecnologias-utilizadas
  C 99.
  CodeBlocks
  Git
  Github
  Windows
  
# Pessoas-contribuidoras/desenvolvedoras
  Felipe Ferraz

# Conclusão
  O programa é um jogo que foi criado para uma cadeira de introdução à programação,
  onde dois jogadores disputam quem é o melhor, em um sistema que é a mistura de 
  dama,jogo da velha e xadrez.
