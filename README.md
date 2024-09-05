Projeto de Leitura e Exibição de Temperatura com Touchscreen e Termopares
Este projeto utiliza um display touchscreen e sensores termopares para exibir duas leituras de temperatura em uma interface gráfica. Ele foi desenvolvido para rodar em um ambiente baseado em Arduino e faz uso de diversas bibliotecas para gerenciar tanto o display LCD quanto os termopares conectados.

Descrição
O código implementa um sistema que:

Lê temperaturas de dois sensores termopares do tipo K usando a biblioteca Nanoshield_Termopar.
Exibe as temperaturas em um display LCD com touchscreen usando as bibliotecas MCUFRIEND_kbv, Adafruit_GFX e TouchScreen.
Utiliza a tela touchscreen para detectar toques e atualizar as leituras dos sensores de temperatura em tempo real.
Componentes Utilizados
Nanoshield Termopar (x2): Sensores de temperatura do tipo K.
Nanoshield LCD: Display LCD com interface touchscreen.
Arduino (ou outro microcontrolador compatível com SPI).
Bibliotecas Necessárias
As bibliotecas abaixo são utilizadas no projeto e devem ser instaladas previamente no Arduino IDE:

MCUFRIEND_kbv
Adafruit_GFX
TouchScreen
Nanoshield_Termopar
SPI
Funcionamento
Leitura de Temperatura: O código lê a temperatura de dois sensores termopares conectados aos pinos 50 e 52.
Interface Gráfica: A interface exibe dois botões e as leituras de temperatura. Quando o usuário toca na área sensível do display, as leituras são atualizadas.
Detecção de Toques: A detecção do toque na tela é feita utilizando a biblioteca TouchScreen e os parâmetros de calibração para mapear a coordenada do toque.
Atualização das Temperaturas: As temperaturas são atualizadas e exibidas nas respectivas áreas da tela ao detectar um toque válido.
Conexões
Termopares
Termopar 1: Conectado ao pino digital 52.
Termopar 2: Conectado ao pino digital 50.
LCD Touchscreen
Pinos de Controle do LCD: A0 (RD), A1 (WR), A2 (CD), A3 (CS), A4 (RESET)
Pinos do Touchscreen: A2 (XM), A3 (YP), 8 (XP), 9 (YM)
Funções Principais
setup(): Inicializa as bibliotecas, o display e os sensores.
loop(): Responsável por detectar toques na tela, atualizar as leituras dos sensores e exibir as informações no display.
telaInicial(): Configura a interface gráfica inicial, criando os botões e exibindo as áreas onde as temperaturas serão mostradas.
criarBotao(): Desenha um botão na interface gráfica com base em coordenadas e cor.
escreveEstado(): Escreve texto em uma posição específica do display com uma cor definida.
Como Usar
Conecte os componentes ao Arduino seguindo o esquema de pinos fornecido.
Instale as bibliotecas necessárias no Arduino IDE.
Faça o upload do código ao Arduino.
Ao ligar o sistema, a interface será exibida no display. Toque na tela para atualizar as leituras de temperatura.
Observações
As leituras de temperatura são atualizadas sempre que um toque válido é detectado na área de exibição.
Certifique-se de calibrar corretamente os valores de pressão e coordenadas do touchscreen para garantir a detecção precisa dos toques.


Licença:
Thermocouples_project © 2024 por Felipe Ramos Nogueira está licenciado sob Creative Commons Atribuição-NãoComercial 4.0 Internacional
