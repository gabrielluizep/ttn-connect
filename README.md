# The Things Network Connect

Dispositivo: [IoT DevKit - LoRaWAN](https://www.robocore.net/lorawan/iot-devkit-lorawan)

# Procedimento para configuração do dispositivo

Realizar reset de fábrica no módulo

```
AT+FRESET 
```

Configurar banda para australiana

```
AT+REGION 1
```

Limitar o uso do módulo apenas para sub-banda 2 (FSB2)

```
AT+CH 0 status=0
AT+CH 1 status=0
.
.
.
AT+CH 7 status=0
AT+CH 8 status=1
.
.
.
AT+CH 15 status=1
AT+CH 16 status=0
.
.
.
AT+CH 71 status=0
```

Configurar variáveis TTN

```
AT+APPKEY ${APP_KEY}
AT+DEVEUI ${DEV_EUI}
AT+APPEUI ${APP_EUI}
```

Conectar ao gateway

```
AT+JOIN
```

Enviar dados

```
AT+SENDB 2:${DADOS_BINARIOS}
AT+SEND 2:${DADOS_STRING_SEM_\n}
```
