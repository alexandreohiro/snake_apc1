# 🐍 Snake Game - Versão Completa em C

## 🎮 Sobre o Jogo

**Snake Game** é uma implementação completa e moderna do clássico jogo da cobrinha, desenvolvida inteiramente em linguagem C seguindo rigorosos critérios acadêmicos. Este projeto demonstra como criar um jogo complexo e funcional usando apenas a função `main()`, sem comprometer a qualidade ou funcionalidades.

### 🎯 Por que este projeto é especial?

- 🏗️ **Arquitetura Única**: Todo o código em uma única função `main()` (desafio técnico!)
- 🎨 **Interface Rica**: Arte ASCII, cores e sons para uma experiência imersiva
- 🧠 **Inteligência Artificial**: Sistema de power-ups e efeitos especiais
- 💾 **Persistência**: Sistema de ranking salvo em arquivo
- 🔧 **Otimização**: Renderização sem flickering (sem usar `cls` durante o jogo)

## 🚀 Como Executar

### 📋 Pré-requisitos

## o código foi adaptado para os seguintes sistemas:

#### Windows:
```bash
# Compilador GCC (MinGW) ou Visual Studio
# Bibliotecas: windows.h, conio.h (já incluídas no Windows)
```

#### Linux:
```bash
# Compilador GCC
sudo apt-get install gcc
# ou
sudo yum install gcc
```

### 🔨 Compilação

#### Windows (MinGW/GCC):
```bash
gcc snake3.c -lm -o a.out
```

#### Windows (Visual Studio):
```bash
cl snake3.c /Fe:snake3.exe
```

#### Linux/wsl:
```bash
gcc -o snake3 snake3.c
```

### ▶️ Execução

#### Windows:
```bash
./snake_game.exe
# ou simplesmente
snake_game
```

#### Linux:
```bash
./snake_game
```

## 🎮 Como Jogar

### 🕹️ Controles Básicos

| Tecla | Ação |
|-------|------|
| `W` | ⬆️ Mover para Cima |
| `A` | ⬅️ Mover para Esquerda |
| `S` | ⬇️ Mover para Baixo |
| `D` | ➡️ Mover para Direita |
| `P` | ⏸️ Pausar/Despausar |
| `Q` ou `ESC` | 🚪 Sair do Jogo |

### 🎯 Objetivo

🐍 **Controle a cobra** para comer itens espalhados pelo mapa e **crescer o máximo possível** sem:
- 💥 Bater nas paredes
- 🧱 Colidir com obstáculos (X)
- 🔄 Morder a própria cauda

## 🍎 Sistema de Itens

### 🟢 Itens Coletáveis

| Item | Símbolo | Cor | Efeito | Pontos |
|------|---------|-----|--------|--------|
| **Fruta** | `F` | 🟢 Verde | Cresce +1 segmento | +10 pts |
| **Bônus** | `B` | 🟡 Amarelo | Cresce +3 segmentos | +50 pts |
| **Super** | `S` | 🟣 Roxo | Ativa modo TURBO | +100 pts |
| **Veneno** | `V` | 🔴 Vermelho | Reduz -2 segmentos | 0 pts |

### ⚡ Power-ups Especiais

#### 🚀 **Modo TURBO**
- **Ativação**: Coletando item Super (`S`)
- **Efeito**: Velocidade dobrada temporariamente
- **Duração**: ~10 segundos
- **Visual**: Indicador "TURBO" no HUD

#### 🛡️ **Modo IMORTAL** (Cheat)
- **Ativação**: Tecla `I` durante o jogo
- **Efeito**: Atravessa paredes sem morrer
- **Comportamento**: Teleporta para o lado oposto
- **Visual**: Indicador "IMORTAL" no HUD

#### 🔄 **Modo INVERTIDO** (Cheat)
- **Ativação**: Tecla `R` durante o jogo
- **Efeito**: Inverte todos os controles
- **Exemplo**: `W` vira `S`, `A` vira `D`
- **Visual**: Indicador "INVERTIDO" no HUD

## 🏆 Sistema de Pontuação

### 📊 Como Pontuar

```
🍎 Fruta Normal (F)    = 10 pontos  + 1 segmento
🎁 Item Bônus (B)      = 50 pontos  + 3 segmentos  
⭐ Super Power (S)     = 100 pontos + Turbo
☠️ Veneno (V)          = 0 pontos   - 2 segmentos
```

### 📈 Sistema de Níveis

- **Nível 1**: Velocidade normal
- **Nível 2**: Desbloqueado aos 100 pontos
- **Nível 3**: Desbloqueado aos 200 pontos
- **Progressão**: A cada 100 pontos, velocidade aumenta!

### 🥇 Ranking Persistente

O jogo salva automaticamente os **Top 5** melhores scores no arquivo `snake_ranking.dat`:
- 💾 **Persistência**: Scores salvos entre sessões
- 🏅 **Top Players**: Visualize os melhores jogadores
- 📝 **Nome Personalizado**: Cada jogador pode inserir seu nome

## 🎨 Elementos Visuais

### 🖼️ Símbolos do Jogo

| Elemento | Símbolo | Descrição |
|----------|---------|-----------|
| 🐍 **Cabeça da Cobra** | `@` | Parte controlável |
| 🟢 **Corpo da Cobra** | `o` | Segmentos que seguem |
| 🧱 **Obstáculos** | `X` | Evite colidir! |
| 🔲 **Paredes** | `#` | Bordas do mapa |
| 🍎 **Itens** | `F/B/S/V` | Coletáveis diversos |

### 🎨 Sistema de Cores (Windows)

- 🔵 **Azul**: Paredes e bordas
- ⚪ **Branco**: Cabeça da cobra
- 🟢 **Verde**: Corpo da cobra e frutas
- 🟡 **Amarelo**: Itens bônus
- 🟣 **Roxo**: Super power-ups
- 🔴 **Vermelho**: Veneno e obstáculos

## 🔧 Arquitetura Técnica

### 🏗️ **Por que apenas uma função main()?**

Este projeto foi desenvolvido seguindo critérios acadêmicos específicos que exigiam:

1. **📚 Desafio Educacional**: Demonstrar domínio de estruturas de controle
2. **🧩 Organização de Código**: Usar apenas structs e arrays para organização
3. **💡 Criatividade**: Implementar funcionalidades complexas com limitações
4. **🎯 Foco**: Concentrar toda a lógica em um local controlado

### 🚀 **Otimizações Implementadas**

#### 🖥️ **Renderização Sem Flickering**
```c
// Problema: system("cls") causa flickering
// Solução: Buffer de tela + reposicionamento de cursor
char tela[ALTURA + 5][LARGURA + 10];
COORD coord = {0, 0};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
```

#### 💾 **Gerenciamento de Memória**
```c
// Arrays estáticos para evitar malloc/free
int cobraX[MAX_CAUDA], cobraY[MAX_CAUDA];
Item itens[MAX_POWERUPS];
Obstaculo obstaculos[MAX_OBSTACULOS];
```

#### 🔄 **Sistema de Estados**
```c
// Controle de estados do jogo
bool gameOver = false, pausado = false;
bool turboAtivado = false, imortal = false, inverso = false;
```

## 🎵 Sistema de Áudio (Windows)

### 🔊 Efeitos Sonoros

| Ação | Frequência | Duração | Descrição |
|------|------------|---------|-----------|
| 🍎 **Comer Fruta** | 1000Hz | 80ms | Som agudo e rápido |
| 🎁 **Bônus** | 1200Hz | 80ms | Som mais agudo |
| ⭐ **Super** | 1600Hz | 100ms | Som de power-up |
| ☠️ **Veneno** | 200Hz | 300ms | Som grave de perigo |
| 💥 **Colisão** | 150Hz | 500ms | Som de game over |
| 🆙 **Level Up** | 523Hz | 200ms | Melodia de progresso |

### 🎼 Sequência de Game Over
```c
// Melodia descendente dramática
Beep(659, 120);  // Mi
Beep(622, 120);  // Ré#
Beep(587, 120);  // Ré
Beep(554, 120);  // Dó#
Beep(523, 250);  // Dó
Beep(392, 350);  // Sol
Beep(330, 400);  // Mi grave
```

## 📁 Estrutura de Arquivos

```
snake-game/
│
├── 📄 snake_game_completo.c    # Código fonte principal
├── 📄 README.md                # Este arquivo
├── 💾 snake_ranking.dat        # Ranking salvo (gerado automaticamente)
└── 🎮 snake_game.exe          # Executável (após compilação)
```

## 🐛 Solução de Problemas

### ❌ **Problemas Comuns**

#### **Erro de Compilação - Windows**
```bash
# Problema: 'conio.h' not found
# Solução: Use MinGW ou Visual Studio
# MinGW: https://www.mingw-w64.org/
```

#### **Erro de Compilação - Linux**
```bash
# Problema: Algumas funções Windows não existem
# Solução: O código já tem compatibilidade com #ifdef
gcc snake3.c -lm -o a.out
```

#### **Jogo Muito Rápido/Lento**
```c
// Ajuste a velocidade inicial na linha:
int velocidade = 150;  // Aumente para mais lento, diminua para mais rápido
```

#### **Ranking Não Salva**
```bash
# Verifique permissões de escrita na pasta
# Windows: Execute como administrador se necessário
# Linux: chmod 755 ./
```


### 📚 **Conceitos Demonstrados**

1. **🏗️ Estruturas de Dados**:
   - Arrays multidimensionais
   - Structs aninhadas
   - Enumerações

2. **🔄 Algoritmos**:
   - Detecção de colisão
   - Geração de números aleatórios
   - Ordenação (ranking)

3. **💾 Manipulação de Arquivos**:
   - Leitura/escrita binária
   - Persistência de dados

4. **🎮 Programação de Jogos**:
   - Loop principal de jogo
   - Estados de jogo
   - Sistema de pontuação

5. **🖥️ Programação de Sistema**:
   - Manipulação de console
   - Entrada não-bloqueante
   - Compatibilidade multiplataforma

### 💡 **Ideias para Melhorias**

- 🎵 **Sistema de Música**: Adicionar trilha sonora
- 🏆 **Conquistas**: Sistema de achievements
- 🌐 **Multiplayer**: Modo para dois jogadores
- 📱 **Mobile**: Versão para dispositivos móveis
- 🎨 **Temas**: Diferentes skins para a cobra

## 📜 Licença

Este projeto é de **domínio público** e pode ser usado livremente para:
- 📚 **Fins Educacionais**
- 🎮 **Projetos Pessoais**
- 🏫 **Trabalhos Acadêmicos**
- 💼 **Portfólio Profissional**

## 👨‍💻 Autor - Alexandre Vieira Da silva

Desenvolvido com ❤️ e muito ☕ como demonstração de programação em C seguindo critérios acadêmicos.

### 🎯 **Objetivos Alcançados**

- ✅ Implementação completa em uma única função `main()`
- ✅ Menu interativo com validação robusta
- ✅ Sistema de armazenamento em memória eficiente
- ✅ Interface rica com cores, sons e arte ASCII
- ✅ Funcionalidades avançadas (power-ups, ranking, efeitos)
- ✅ Otimização visual sem flickering
- ✅ Compatibilidade multiplataforma

---

## 🎮 **Divirta-se jogando!** 🐍

*"A simplicidade é o último grau de sofisticação"* - Leonardo da Vinci

**Que a força esteja com você!** 🐍✨
