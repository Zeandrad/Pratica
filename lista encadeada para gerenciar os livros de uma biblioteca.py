class Node:
    def __init__(self, author, title, publisher, year):
        self.author = author
        self.title = title
        self.publisher = publisher
        self.year = year
        self.next = None


class Library:
    def __init__(self):
        self.head = None

    def insert_book(self, author, title, publisher, year):
        new_book = Node(author, title, publisher, year)
        if self.head is None:
            self.head = new_book
        elif self.head.title > title:
            new_book.next = self.head
            self.head = new_book
        else:
            current = self.head
            while current.next is not None and current.next.title < title:
                current = current.next
            new_book.next = current.next
            current.next = new_book

    def remove_book(self, title):
        if self.head is None:
            print("A biblioteca está vazia.")
            return

        if self.head.title == title:
            self.head = self.head.next
            print(f"O livro '{title}' foi removido da biblioteca.")
            return

        current = self.head
        while current.next is not None and current.next.title != title:
            current = current.next

        if current.next is None:
            print(f"O livro '{title}' não foi encontrado na biblioteca.")
        else:
            current.next = current.next.next
            print(f"O livro '{title}' foi removido da biblioteca.")

    def search_book_by_title(self, title):
        if self.head is None:
            print("A biblioteca está vazia.")
            return

        current = self.head
        while current is not None and current.title != title:
            current = current.next

        if current is None:
            print(f"O livro '{title}' não foi encontrado na biblioteca.")
        else:
            print("Informações do livro:")
            print(f"Autor: {current.author}")
            print(f"Título: {current.title}")
            print(f"Editora: {current.publisher}")
            print(f"Ano de Edição: {current.year}")

    def search_book_by_author(self, author):
        if self.head is None:
            print("A biblioteca está vazia.")
            return

        found = False
        current = self.head
        while current is not None:
            if current.author == author:
                if not found:
                    print(f"Livros do autor '{author}':")
                    found = True
                print(f"Título: {current.title}")
            current = current.next

        if not found:
            print(f"Nenhum livro do autor '{author}' foi encontrado na biblioteca.")


def display_menu():
    print("\nMenu:")
    print("1. Inserir um livro")
    print("2. Remover um livro")
    print("3. Alterar um livro")
    print("4. Buscar livro por título")
    print("5. Buscar livro por autor")
    print("6. Sair")


library = Library()

while True:
    display_menu()
    choice = input("Escolha uma opção: ")

    if choice == "1":
        author = input("Autor do livro: ")
        title = input("Título do livro: ")
        publisher = input("Editora do livro: ")
        year = input("Ano de edição do livro: ")
        library.insert_book(author, title, publisher, year)
        print("Livro inserido com sucesso!")

    elif choice == "2":
        title = input("Título do livro a ser removido: ")
        library.remove_book(title)
    
    elif choice == "3":
        title = input("Título do livro a ser alterado: ")
        library.update_book(title)

        
    elif choice == "4":
        title = input("Título do livro a ser buscado: ")
        library.search_book_by_title(title)

    elif choice == "5":
        author = input("Autor do livro a ser buscado: ")
        library.search_book_by_author(author)

    elif choice == "6":
        print("Encerrando o programa...")
        break

    else:
        print("Opção inválida. Por favor, escolha uma opção válida.")
