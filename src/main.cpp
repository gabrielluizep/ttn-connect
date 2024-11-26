// #if !defined(ARDUINO_ESP32_DEV) // ESP32
// #error Use this example with the ESP32
// #endif

// // Inclusao da biblioteca
// #include <RoboCore_SMW_SX1276M0.h>
// #include <HardwareSerial.h>
// HardwareSerial LoRaSerial(2);
// #define RXD2 16
// #define TXD2 17
// unsigned long reconecta = 1000; // 10 segundos

// // Criacao do objeto lorawan para a biblioteca SMW_SX1276M0
// SMW_SX1276M0 lorawan(LoRaSerial);

// void setup()
// {

//   // Inicia o monitor serial e imprime o cabecalho
//   Serial.begin(115200);
//   Serial.println(F("--- SMW_SX1276M0 Bridge ---"));

//   // Definicao do pino de reset do modulo
//   lorawan.setPinReset(5);
//   lorawan.reset(); // Realiza um reset no modulo

//   // Inicia a comunicacao serial com o modulo
//   LoRaSerial.begin(115200, SERIAL_8N1, RXD2, TXD2);
// }
// int i = 0;
// void loop()
// {

//   // //Recebe as informacoes do modulo e exibe no monitor serial
//   if (LoRaSerial.available())
//   {
//     Serial.write(LoRaSerial.read());
//   }

//   // //Recebe as informacoes do monitor serial e envia para o modulo
//   // if(Serial.available()){
//   //   LoRaSerial.write(Serial.read());
//   // }

//   char comandoSend[] = "AT+CH 0 status=0    ";
//   char quebraLinha[] = "\n";
//   if (reconecta < millis())
//   {
//     if (15 < i || i<8 )
//     {
//       sprintf(comandoSend, "AT+CH %d status=0", i);
//       Serial.write(comandoSend);
//       LoRaSerial.print(comandoSend);
//       LoRaSerial.print(quebraLinha);
//       reconecta = millis() + 1000;
//     }
//     i++;
//   }
// }

/*******************************************************************************
 * IoT DevKit - Primeiro contato com o modulo LoRaWAN Bee (v1.0)
 *
 * Codigo usado para enviar comandos "AT" para o modulo e imprimir
 * suas respostas.
 *
 * Copyright 2020 RoboCore.
 * Escrito por Giovanni de Castro (21/08/2020).
 * Creditos: @francois - RoboCore
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version (<https://www.gnu.org/licenses/>).
 *******************************************************************************/

// Verifica se o modelo de placa selecionado esta correto
#if !defined(ARDUINO_ESP32_DEV) // ESP32
#error Use this example with the ESP32
#endif

// Inclusao da biblioteca
#include "RoboCore_SMW_SX1276M0.h"

// Declaracao dos pinos de comunicacao serial do Kit
#include <HardwareSerial.h>
HardwareSerial LoRaSerial(2);
#define RXD2 16
#define TXD2 17

// Criacao do objeto lorawan para a biblioteca SMW_SX1276M0
SMW_SX1276M0 lorawan(LoRaSerial);

void setup()
{

  // Inicia o monitor serial e imprime o cabecalho
  Serial.begin(115200);
  Serial.println(F("--- SMW_SX1276M0 Bridge ---"));

  // Definicao do pino de reset do modulo
  lorawan.setPinReset(5);
  lorawan.reset(); // Realiza um reset no modulo

  // Inicia a comunicacao serial com o modulo
  LoRaSerial.begin(115200, SERIAL_8N1, RXD2, TXD2);

  // char reset_channel_command[] = "AT+CH 0 status=0\n";
  // for (int i = 0; i <= 71; i++)
  // {
  //   if (8 <= i && i <= 15)
  //     continue;

  //   sprintf(reset_channel_command, "AT+CH %d status=0\n", i);
  //   Serial.write(reset_channel_command);
  //   LoRaSerial.print(reset_channel_command);
  //   delay(1000);
  // }

  // char deveui[] = "50F8A500300101AD\n";
  // Serial.write(deveui);
  // LoRaSerial.print(deveui);
  // delay(1000);

  // char appeui[] = "0000000000000000\n";
  // Serial.write(appeui);
  // LoRaSerial.print(appeui);
  // delay(1000);

  // char appkey[] = "CC4E93A7750B18AC902250ACC7075525\n";
  // Serial.write(appkey);
  // LoRaSerial.print(appkey);
  // delay(1000);

  lorawan.join();
}

char data[64] = "CSF rocks! balada do conhecimento!";
void loop()
{
  // // Recebe as informacoes do modulo e exibe no monitor serial
  // if (LoRaSerial.available())
  // {
  //   Serial.write(LoRaSerial.read());
  // }

  // // Recebe as informacoes do monitor serial e envia para o modulo
  // if (Serial.available())
  // {
  //   LoRaSerial.write(Serial.read());
  // }

  lorawan.sendT(2, "balada do conhecimento");
  delay(10000);

  // if (lorawan.isConnected())
  // {
  //   lorawan.sendT(2, data);
  //   delay(10000);
  // }
}