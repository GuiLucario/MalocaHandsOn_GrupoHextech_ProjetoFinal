#include <Wire.h>               // Inclui a biblioteca Wire para comunicação I2C
#include <Adafruit_PN532.h>     // Inclui a biblioteca Adafruit para o PN532

// Definição dos pinos I2C no ESP32
#define SDA_PIN 21              // Define o pino 21 do ESP32 como SDA
#define SCL_PIN 22              // Define o pino 22 do ESP32 como SCL

// Inicializa o objeto para o módulo NFC PN532 usando I2C
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

// Protótipos das funções
void accessGranted();
void accessDenied();

void setup(void) {
  Serial.begin(115200);         // Inicia a comunicação serial a 115200 bps
  Serial.println("Inicializando o Leitor NFC...");

  // Inicializa a comunicação I2C com o módulo NFC
  nfc.begin();

  // Obtém a versão do firmware do PN532 para garantir que está funcionando corretamente
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    // Se não houver resposta do módulo, exibe uma mensagem de erro
    Serial.println("Não foi possível encontrar o leitor NFC.");
    while (1); // Trava o código se o leitor não for encontrado
  }

  // Exibe as informações do firmware no monitor serial
  Serial.print("Firmware do leitor NFC: 0x");
  Serial.println(versiondata, HEX); // Exibe a versão do firmware em hexadecimal

  // Configura o leitor NFC para modo passivo (para ler tags RFID/NFC)
  nfc.SAMConfig(); // Necessário para inicializar o modo de leitura passiva

  Serial.println("Esperando por uma tag NFC...");
}

void loop(void) {
  uint8_t success;               // Variável para verificar se a leitura foi bem-sucedida
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // Buffer para armazenar o UID da tag
  uint8_t uidLength;             // Variável para armazenar o comprimento do UID

  // Tenta detectar uma tag NFC próxima ao leitor
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("Tag NFC detectada!");
    Serial.print("UID da tag: ");
    String uidString = "";
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print("0x");
      Serial.print(uid[i], HEX);
      Serial.print(" ");
      uidString += String(uid[i], HEX);
      if (i < uidLength - 1) uidString += " ";
    }
    Serial.println();

    // Verifica se a UID é a esperada
    if (uidString.equalsIgnoreCase("73 3C 2A 10")) {
      accessGranted();
    } else {
      accessDenied();
    }
  }
}

// Função chamada quando o acesso é permitido
void accessGranted() {
  Serial.println("Acesso permitido!");

  // Dados fictícios do paciente
  String pacienteNome = "João da Silva";
  String pacienteIdade = "30 anos";
  String pacienteGenero = "Masculino";
  String pacienteEndereco = "Rua Exemplo, 123, Cidade X";
  String pacienteDiagnostico = "Colite ulcerativa";

  // Exibe os dados do paciente no Serial Monitor
  Serial.println("Dados do Paciente:");
  Serial.print("Nome: ");
  Serial.println(pacienteNome);
  Serial.print("Idade: ");
  Serial.println(pacienteIdade);
  Serial.print("Gênero: ");
  Serial.println(pacienteGenero);
  Serial.print("Endereço: ");
  Serial.println(pacienteEndereco);
  Serial.print("Diagnóstico: ");
  Serial.println(pacienteDiagnostico);
}

// Função chamada quando o acesso é negado
void accessDenied() {
  Serial.println("Acesso negado!");
}
