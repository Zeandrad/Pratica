class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            return None

    def is_empty(self):
        return len(self.stack) == 0

    def display_stack(self):
        if not self.is_empty():
            print("Pilha:")
            for item in reversed(self.stack):
                print(item)
        else:
            print("A pilha está vazia.")


def display_menu():
    print("\nMenu:")
    print("1. Inserir elemento")
    print("2. Remover elemento")
    print("3. Exibir pilha")
    print("4. Verificar se a pilha está vazia")
    print("5. Sair")


stack = Stack()

while True:
    display_menu()
    choice = input("Escolha uma opção: ")

    if choice == "1":
        item = float(input("Digite o número a ser inserido: "))
        stack.push(item)
        stack.display_stack()

    elif choice == "2":
        removed_item = stack.pop()
        if removed_item is not None:
            print(f"Item removido: {removed_item}")
        else:
            print("A pilha está vazia.")
        stack.display_stack()

    elif choice == "3":
        stack.display_stack()

    elif choice == "4":
        if stack.is_empty():
            print("A pilha está vazia.")
        else:
            print("A pilha não está vazia.")

    elif choice == "5":
        print("Encerrando o programa...")
        break

    else:
        print("Opção inválida. Por favor, escolha uma opção válida.")
