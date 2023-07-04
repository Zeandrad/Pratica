#include <stdio.h>
#include <stdlib.h>

struct dataDeNascimento{
    int dia;
    int mes;
    int ano;
};
struct perfilSaude{
    char nomeCompleto [81];
    char sexo;
    struct dataDeNascimento data;
    float altura;
    float peso;
};
struct dataAtual{
    int dia;
    int mes;
    int ano;
};
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void preencherDataAtual(struct dataAtual *dataAtual){
    printf("Por favor digite o dia atual: \n");
    scanf("%d", &dataAtual->dia);
    printf("Por favor digite o mes atual: \n");
    scanf("%d", &dataAtual->mes);
    printf("Por favor digite o ano atual: \n");
    scanf("%d", &dataAtual->ano);
};
void preencherInformacoes(struct perfilSaude *perfil){
    printf("Por favor digite seu nome completo: \n");
    fgets(perfil->nomeCompleto, 81, stdin);
    //comando para substituir a quebra de linha("\n") no final do nome por um caractere nulo("\0")
    perfil->nomeCompleto[strcspn(perfil->nomeCompleto, "\n")] = '\0';;

    printf("Digite o seu sexo(M e F): \n");
    scanf(" %c", &perfil->sexo);
    limparBuffer();

    printf("Digite a data de nascimento (dia mes ano): \n");
    scanf("%d %d %d", &perfil->data.dia, &perfil->data.mes, &perfil->data.ano);
    limparBuffer();

    printf("Digite a altura: \n");
    scanf("%f", &perfil->altura);
    limparBuffer();

    printf("Digite o peso: \n");
    scanf("%f", &perfil->peso);
    limparBuffer();

};

int calcularIdade(struct perfilSaude *perfil, struct dataAtual *dataAtual) {
    // Cálculo da idade atual em anos
    int idade = dataAtual->ano - perfil->data.ano;
    if (perfil->data.mes > dataAtual->mes || (perfil->data.mes == dataAtual->mes && perfil->data.dia > dataAtual->dia)) {
        idade--;
    }
    return idade;
};

float calcularIMC(struct perfilSaude *perfil){
    float alturaMetros = perfil->altura;
    return perfil->peso/(alturaMetros * alturaMetros);
};

int calcularFrequenciaCardiacaMaxima(struct perfilSaude *perfil, struct dataAtual *dataAtual){
    int idade = calcularIdade(perfil, dataAtual);
    if(perfil->sexo == 'M'){
        return 220 - idade;
    }else if(perfil->sexo == 'F'){
        return 226 - idade;
    }else{
        return -1;
    }
};

int calcularFrequenciaCardiacaIdeal(struct perfilSaude *perfil, struct dataAtual *dataAtual){
    int frequenciaCardiacaMaxima = calcularFrequenciaCardiacaMaxima(perfil,dataAtual);
    return frequenciaCardiacaMaxima * 0.5; // Valor 50% da frequência cardiaca máxima
};

void exibirPerfilSaude(struct perfilSaude *perfil){
    printf("\nPerfil de Saude: \n");
    printf("Nome: %s", perfil->nomeCompleto);
    printf("Sexo: %c\n", perfil->sexo);
    printf("Data de Nascimento: %02d/%02d/%04d\n", perfil->data.dia, perfil->data.mes, perfil->data.ano);
    printf("Altura: %.2f m\n", perfil->altura);
    printf("Peso: %.2f kg\n", perfil->peso);
};

void exibirTabelaIMC(){
    printf("\nTabela de Valores do IMC: \n");
    printf("Abaixo do peso: Abaixo de 18.5\n");
    printf("Peso Normal: 18.5 - 24.9\n");
    printf("Sobrepeso: 25.0 - 29.9\n");
    printf("Obesidade Grau I: 30.0 - 34.9\n");
    printf("Obesidade Grau II: 35.0 - 39.9\n");
    printf("Obesidade Grau III: Acima de 40.0\n");
}

int main(){
    int n;
    struct dataAtual *data = malloc(sizeof(struct dataAtual));
    preencherDataAtual(data);
    printf("Digite o numero de perfis de saude: ");
    scanf("%d", &n);
    limparBuffer();

    struct perfilSaude *perfis = malloc(n * sizeof(struct perfilSaude));

    for (int i = 0; i< n; i++){
        printf("\n--- Informacoes do Perfil de Saude %d ---\n", i + 1);
        preencherInformacoes(&perfis[i]);
        exibirPerfilSaude(&perfis[i]);

        int idade = calcularIdade(&perfis[i],data);
        float imc = calcularIMC(&perfis[i]);
        int frequenciaCardiacaMaxima = calcularFrequenciaCardiacaMaxima(&perfis[i], data);
        int frequenciaCardiacaIdeal = calcularFrequenciaCardiacaIdeal(&perfis[i], data);

        printf("Idade: %d anos\n", idade);
        printf("IMC: %.2f\n", imc);
        printf("Frequencia Cardiaca Maxima: %d bpm\n", frequenciaCardiacaMaxima);
        printf("Frequencia Cardiaca Ideal: %d bpm\n", frequenciaCardiacaIdeal);

        exibirTabelaIMC();
    }

    free(perfis);

    return 0;
}