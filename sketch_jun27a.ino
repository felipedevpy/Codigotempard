#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Adafruit_GFX.h>
#include "Nanoshield_Termopar.h"
#include <SPI.h>
#include "Nanoshield_LCD.h"

Nanoshield_Termopar termopar(52, TC_TYPE_K, TC_AVG_OFF);
Nanoshield_Termopar termopar2(50, TC_TYPE_K, TC_AVG_OFF);

Nanoshield_LCD lcd;
#define XM A2
#define YP A3
#define YM 9
#define XP 8

#define TS_MINX 90
#define TS_MINY 92
#define TS_MAXX 906
#define TS_MAXY 951

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_RESET A4
#define LCD_CS A3
#define LCD_CD A2 
#define LCD_WR A1
#define LCD_RD A0

MCUFRIEND_kbv tft;

#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define PRETO   0x0000
#define BRANCO  0xFFFF
#define AMARELO 0xFFE0

bool error = false;
bool valor_botao1 = false;
bool valor_botao2 = false;

int px = 150; //
int py = 128; //Direita
int largura = 150;
int altura = 205;
int tolerancia = 0                     ; 

void telaInicial();
void setup() {
  Serial.begin(9600);
  termopar.begin();
  termopar2.begin();
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);

  telaInicial();
}

void loop() {
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    digitalWrite(XM, LOW);
    pinMode(YP, OUTPUT);
    digitalWrite(YP, HIGH);
    pinMode(YM, OUTPUT);
    digitalWrite(YM, LOW);
    pinMode(XP, OUTPUT);
    digitalWrite(XP, HIGH);

    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
        p.x = tft.width() - (map(p.x, TS_MINX, TS_MAXX, tft.width(), 0));
        p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));

        
        if (p.x > px - tolerancia && p.x < px + largura + tolerancia &&
            p.y > py - tolerancia && p.y < py + altura + tolerancia) {
          
            tft.fillRect(186, 30, 85, 30, PRETO);
            tft.fillRect(186, 170, 85, 30, PRETO);

            termopar.read();
            tft.setTextColor(BRANCO);
            tft.setCursor(200, 179);
            tft.print(termopar.getExternal());
  
            termopar2.read();
            tft.setTextColor(BRANCO);
            tft.setCursor(200, 40);
            tft.print(termopar2.getExternal());
        }  
    }

    delay(300);
}

void telaInicial() {
  tft.setRotation(3);
  criarBotao(186, 145 , 90, 85, "", PRETO);
  criarBotao(186, 10, 90, 85, "", PRETO);
  criarBotao(20, 100, 120, 50, "", PRETO); 

  escreveEstado(92, 42, "Temp_1", AMARELO);
  escreveEstado(92, 176, "Temp_2", AMARELO);
  escreveEstado(42, 115, "REFRESH", AMARELO);
}

void escreveEstado(int posx, int posy, String texto, int cor) {
  tft.setCursor(posx, posy);
  tft.setTextColor(cor); 
  tft.setTextSize(2);
  tft.print(texto);
}

void criarBotao(int posx, int posy, int largura, int altura, String texto, int cor) {
  tft.fillRect(posx, posy, largura, altura, cor);
  tft.drawRect(posx, posy, largura, altura, PRETO);
  tft.setCursor(posx + 12, posy + 1000);
  tft.setTextColor(BRANCO);
  tft.setTextSize(3);
  tft.print(texto);
}
