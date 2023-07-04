class Processo:
    def __init__(self, identificador, descricao):
        self.identificador = identificador
        self.descricao = descricao


class PilhaProcessos:
    def __init__(self):
        self.pilha = []

    def incluir_processo(self, processo):
        self.pilha.append(processo)
        print("Novo processo adicionado à pilha.")

    def retirar_processo(self):
        if not self.pilha:
            print("Pilha vazia.")
        else:
            processo_removido = self.pilha.pop()
            print(f"Removido o processo #{processo_removido.identificador} - {processo_removido.descricao}")

    def imprimir_pilha(self):
        if not self.pilha:
            print("Pilha vazia.")
        else:
            for processo in reversed(self.pilha):
                print(f"#{processo.identificador} - {processo.descricao}")

    def esvaziar_pilha(self):
        self.pilha = []

pilha = PilhaProcessos()

while True:
    print("\nEscolha uma opção:")
    print("1 - Incluir processo")
    print("2 - Retirar processo")
    print("3 - Imprimir pilha")
    print("4 - Encerrar programa")

    opcao = input("Opção: ")

    if opcao == "1":
        identificador = int(input("Digite o identificador do processo: "))
        descricao = input("Digite a descrição do processo: ")
        processo = Processo(identificador, descricao)
        pilha.incluir_processo(processo)

    elif opcao == "2":
        pilha.retirar_processo()

    elif opcao == "3":
        pilha.imprimir_pilha()

    elif opcao == "4":
        pilha.esvaziar_pilha()
        break

    else:
        print("Opção inválida. Tente novamente.")
      
    print("Programa encerrado.")

    