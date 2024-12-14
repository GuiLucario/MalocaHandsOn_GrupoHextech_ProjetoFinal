# MalocaHandsOn_GrupoHextech_ProjetoFinal

## Equipe 06  
- *Daniel Silva*  
- *Gilberto Alexsandro*  
- *Guilherme Miranda*  

---

# Projeto: Cartão SUS RFID com ESP32  

Este projeto, desenvolvido no contexto do *Projeto Maloca das iCoisas*, tem como objetivo criar um sistema de gerenciamento de informações médicas utilizando a tecnologia RFID e o microcontrolador ESP32. O sistema permite o registro e a leitura de dados armazenados em cartões RFID, como histórico de consultas, vacinas e alergias, além de sincronizar essas informações com servidores na nuvem via Wi-Fi.  

---

## Esquema de Conexão  
O circuito integra o microcontrolador ESP32, o módulo RFID PN532 e os cartões RFID. O diagrama esquemático foi desenvolvido para facilitar a compreensão da conexão entre os componentes.  

![Esquema de Conexão](EsquemadeConexão.png)  

Link do projeto feito no Wokwi

![LInk](https://wokwi.com/projects/417202551334105089)  

---

## Big Picture  
A *Big Picture* do projeto apresenta os objetivos principais, destacando:  
- Registro e leitura de informações médicas em cartões RFID.  
- A funcionalidade do cartão.  
- E uma das qualdiades que é o atendimento rápido e eficiente.  

![Big Picture](Big%20Picture.jpg)  

---

## Melhorias Implementadas  
- *Integração do RFID PN532 com o ESP32:*  
  - Leitura e gravação de dados médicos nos cartões RFID.  
  - Conexão Wi-Fi configurável para sincronização remota.  
  
- *Exibição de mensagens no monitor serial:*  
  - "Cartão detectado" quando o RFID identifica um cartão.  
  - "Sincronização bem-sucedida" após o envio de dados ao servidor.  
  - "Erro de conexão" em caso de falha na rede.  


---

## Tecnologias Utilizadas  
- *ESP32* - Microcontrolador principal.  
- *RFID PN532* - Módulo para leitura e gravação de cartões RFID.  
- *Arduino IDE* - Para desenvolvimento e validação do código.  

---

## Estrutura do Repositório  
- *Esquema de Conexão.png*: Imagem do diagrama esquemático.  
- *Big Picture.jpg*: Representação visual dos objetivos do projeto.  
- *Documento de Requisitos Funcionais.pdf*: Documento do projeto.  
