# 🚢 Batalha Naval – TP1 PDS I

Implementação do clássico jogo **Batalha Naval**, desenvolvida como **Trabalho Prático 1** da disciplina *Programação e Desenvolvimento de Software I* (DCC/UFMG, 1º período).

---

## 📖 Descrição

O objetivo do projeto é implementar, em linguagem **C**, uma versão simplificada do jogo **Batalha Naval**, utilizando **vetores, matrizes e funções**.  
O programa deve permitir ao jogador interagir com um tabuleiro, registrar disparos e acompanhar o progresso da partida até o fim.

---

## 🎮 Regras do Jogo

- O jogo é disputado em um **tabuleiro 10x10**.  
- Cada jogador (usuário e computador) possui uma frota de embarcações de tamanhos variados (definidos pelo enunciado).  
- O jogador faz disparos tentando acertar as embarcações inimigas.  
- O jogo termina quando **todas as embarcações de um dos lados forem afundadas**.  

---

## 🛠️ Funcionalidades

- Representação do tabuleiro em matriz `10x10`.  
- Posicionamento válido das embarcações (sem sobreposição).  
- Registro de disparos, com marcação de **acerto** e **erro**.  
- Impressão do tabuleiro atualizado a cada jogada.  
- Verificação de fim de jogo.  
- Possibilidade de jogar contra o **computador**.  

---

## 📂 Estrutura Esperada do Código

O projeto deve conter:

- **Funções de manipulação do tabuleiro**:
  - Inicializar o tabuleiro.  
  - Posicionar embarcações.  
  - Verificar posições válidas.  
- **Funções de jogo**:
  - Realizar disparo.  
  - Atualizar estado do tabuleiro.  
  - Verificar condições de vitória.  
- **Função principal `main`**:
  - Controla o fluxo do jogo.  
  - Alterna turnos entre jogador e computador.  

---

## ▶️ Como Compilar e Executar

No Linux:

```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
