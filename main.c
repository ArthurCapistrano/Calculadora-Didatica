#include <stdio.h>
#include <stdlib.h>

// Função decimal para binário
void decimalPBinario(int num) {
    printf("\nConversão de decimal para binário:\n");
    int binario[32];
    int i = 0;

    while (num > 0) {
        binario[i] = num % 2;
        printf("%d / 2 = %d, Resto = %d\n", num, num / 2, binario[i]);
        num = num / 2;
        i++;
    }

    printf("Resultado em binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void decimalPBinarioComplementoA2(int num) {
    printf("\nConversão de decimal para binário em complemento de 2:\n");
    int binario[16];
    int i = 0;
    

    if(num < 0){
        num = abs(num);

        printf("\n- Calculando a representação binária do valor absoluto:\n");
        while (num > 0) {
            binario[i] = num % 2;
            printf("%d / 2 = %d, Resto = %d\n", num, num / 2, binario[i]);
            num = num / 2;
            i++;
        }

        for (int j = 15; j >= i; j--) {
            binario[j] = 0;
        }

        printf("\n- Representação binária do valor absoluto:\n");
        for (int j = 15; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");

        printf("\n- Invertendo os bits a partir do 1° '1' (macete):\n");
        int trocador = 0;
        for (int j = 0; j <= 15; j++) {
            if (binario[j] == 1 && trocador == 0){
                trocador = 1;
                printf("\n- Encontrado o primeiro 1, trocador ativado, pulando o próximo bit.\n");
                j++;
            }
            if(trocador == 1){
                if(binario[j] == 0){
                    binario[j] = 1;
                    printf("   Binário[%d] = 0, trocando para 1\n", j);
                }
                else if(binario[j] == 1){
                    binario[j] = 0;
                    printf("   Binário[%d] = 1, trocando para 0\n", j);

                }
            }
        }

        printf("\nResultado em binário: ");
        for (int j = 15; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");
    }else{
        while (num > 0) {
            binario[i] = num % 2;
            printf("%d / 2 = %d, Resto = %d\n", num, num / 2, binario[i]);
            num = num / 2;
            i++;
        }

        for (int j = 15; j >= i; j--) {
            binario[j] = 0;
        }
        
        printf("Resultado em binário: ");
        for (int j = 15; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");
    }
    
}

// Função decimal para octal
void decimalPOctal(int num) {
    printf("\nConversão de base 10 para base 8:\n");
    int octal[32];
    int i = 0;

    while (num > 0) {
        octal[i] = num % 8;
        printf("%d / 8 = %d, Resto = %d\n", num, num / 8, octal[i]);
        num = num / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

// Função decimal para hexadecimal
void decimalPHexadecimal(int num) {
    printf("\nConversão de base 10 para base 16:\n");
    char hexa[32];
    int i = 0;

    while (num > 0) {
        int temp = num % 16;
        printf("%d / 16 = %d, Resto = ", num, num / 16);

        if (temp < 10) {
            hexa[i] = temp + 48; 
            printf("%d\n", temp);
        } else {
            hexa[i] = temp + 55; 
            printf("%c\n", hexa[i]);
        }
        num = num / 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

// Função decimal para BCD
void decimalPBCD(int numero) {
    printf("\nConversão de base 10 para código BCD:\n");
    int bcd[32];
    int i = 0;

    // Tabela de conversão para BCD
    const char bcdTabela[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 1}, // 1
        {0, 0, 1, 0}, // 2
        {0, 0, 1, 1}, // 3
        {0, 1, 0, 0}, // 4
        {0, 1, 0, 1}, // 5
        {0, 1, 1, 0}, // 6
        {0, 1, 1, 1}, // 7
        {1, 0, 0, 0}, // 8
        {1, 0, 0, 1}  // 9
    };

    while (numero > 0) {
        int digito = numero % 10;
        printf("Dígito: %d, Conversão para BCD: ", digito);

        // Copia a conversão BCD do dígito para o array bcd
        for (int j = 0; j < 4; j++) {
            bcd[i] = bcdTabela[digito][j];
            printf("%d", bcd[i]);
            i++;
        }
        printf("\n");
        numero = numero / 10;
    }

    printf("Resultado em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bcd[j]);
    }
    printf("\n");
}

int main(void) {

  printf("***************************************************\n");
  printf("*              Calculadora Didática               *\n");
  printf("*                                                 *\n");
  printf("*  1. Conversão de Decimal para Binário           *\n");
  printf("*  2. Conversão de Decimal para Octal             *\n");
  printf("*  3. Conversão de Decimal para Hexadecimal       *\n");
  printf("*  4. Conversão de Decimal para Código BCD        *\n");
  printf("*  5. Conversão de Decimal com Complemento A2 16b *\n");
  printf("*  6. Sair                                        *\n");
  printf("*                                                 *\n");
  printf("***************************************************\n");
  int opcao = 0;
    
  while(opcao != 6){
    printf("\nEscolha uma opção (1-6): ");

    int decimal;
    scanf("%d", &opcao);

    if (opcao == 1){
        printf("\nDigite um número decimal para converter em Binário: ");
        scanf("%d", &decimal);
        decimalPBinario(decimal);
    }
    else if(opcao == 2){
        printf("\nDigite um número decimal para converter em  Octal: ");
        scanf("%d", &decimal);
            decimalPOctal(decimal);
    }
    else if (opcao == 3){
      printf("\nDigite um número Decimal para converter em  Hexadecimal: ");
      scanf("%d", &decimal);
            decimalPHexadecimal(decimal);
    }
    else if(opcao == 4){
      printf("\nDigite um número Decimal para converter em  Código BCD: ");
      scanf("%d", &decimal);
          decimalPBCD(decimal);
    }
    else if(opcao == 5){
      printf("\nDigite um número Decimal para converter em Complemento A2 com 16 bits: ");
      scanf("%d", &decimal);
        decimalPBinarioComplementoA2(decimal);
    }
    else if (opcao == 6){
      printf("\nSaindo da calculadora...\n");
      break;
    }
    else{
      printf("\nOpção inválida. Por favor, escolha uma opção válida (1-5).\n");
    }
  }
  

  
  return 0;
}