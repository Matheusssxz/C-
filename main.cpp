#include <iostream>
#include <string.h>

using namespace std;
typedef struct tarefa
{
  char nome[100];
  int prioridade;
  int tempo;
} Ttarefa;

typedef struct No
{
  Ttarefa tarefa;
  struct No *proximo;
} TNo;

typedef struct lista
{
  No *inicio, *fim;
  int tam;
} TLista;

void inicializar(TLista *lista)
{
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

void removerTarefa(TLista *lista)
{
  if (lista->inicio == NULL)
  {
    std::cout << "Nenhuma tarefa para ser removida\n";
    return;
  }

  No *remover;

  if (lista->inicio == lista->fim)
  {
    remover = lista->inicio;
    lista->inicio = NULL;
    lista->fim = NULL;
  }
  else
  {

    No *atual = lista->inicio;
    while (atual->proximo != lista->fim)
    {
      atual = atual->proximo;
    }

    remover = lista->fim;
    atual->proximo = NULL;
    lista->fim = atual;
  }

  free(remover);
  lista->tam--;
  std::cout << "Tarefa removida com sucesso\n";
}

void InserirTarefa(TLista *lista, Ttarefa *tarefa)
{
  No *novo = (No *)malloc(sizeof(No));
  strcpy(novo->tarefa.nome, tarefa->nome);
  novo->tarefa.tempo = tarefa->tempo;
  novo->tarefa.prioridade = tarefa->prioridade;
  novo->proximo = NULL;

  if (lista->inicio == NULL)
  {
    lista->inicio = novo;
    lista->fim = novo;
  }
  else
  {
    lista->fim->proximo = novo;
    lista->fim = novo;
  }
  lista->tam++;
}
void exibirTarefaFila(TLista *lista)
{
  No *iterador = lista->inicio;
  if (lista->inicio == NULL)
  {
    std::cout << "Nenhuma tarefa a ser executada.\n";
    return;
  }
  else
  {
    while (iterador != NULL)
    {
      std::cout << "Nome: " << iterador->tarefa.nome << "\n";
      iterador = iterador->proximo;
    }
  }
}

void bubbleSortLista(TLista *lista)
{
  if (lista->inicio == NULL || lista->inicio->proximo == NULL)
    return;

  bool trocou;
  TNo *ptr1;
  TNo *lptr = NULL;

  do
  {
    trocou = false;
    ptr1 = lista->inicio;

    while (ptr1->proximo != lptr)
    {
      if (ptr1->tarefa.prioridade > ptr1->proximo->tarefa.prioridade)
      {
        Ttarefa temp = ptr1->tarefa;
        ptr1->tarefa = ptr1->proximo->tarefa;
        ptr1->proximo->tarefa = temp;

        trocou = true;
      }
      ptr1 = ptr1->proximo;
    }
    lptr = ptr1;
  } while (trocou);
}
void insertionSort(TLista *lista)
{
  if (lista->inicio == NULL || lista->inicio->proximo == NULL)
    return;
    
}

void mostrarMenu()
{
  int input;
  TLista lista;
  Ttarefa tarefa;
  TNo no;
  inicializar(&lista);

  do
  {
    std::cout << "\nEscolha as opcoes\n";
    std::cout << "1- Adicionar tarefas\n";
    std::cout << "2- Remover tarefas\n";
    std::cout << "3- Listar tarefas\n";
    std::cout << "4- Sair\n";
    std::cin >> input;
    std::cin.ignore();
    switch (input)
    {
    case 1:
      std::cout << "Adicione uma tarefa:\n";
      std::cout << "Tarefa:\n";
      std::cin.getline(tarefa.nome, 100);

      std::cout << "Tempo (min):\n";
      std::cin >> tarefa.tempo;
      std::cin.ignore();

      std::cout << "Prioridade(1 a 5 || enquanto menor o valor maior prioridade || enquanto maior o valor menor prioridade):\n";
      std::cin >> tarefa.prioridade;
      std::cin.ignore();
      if (tarefa.prioridade > 5)
      {
        cout << "Prioridades vao ate 5, favor, adicionar uma prioridade valida";
      }
      else
      {
        InserirTarefa(&lista, &tarefa);
      }
      break;
    case 2:
      removerTarefa(&lista);
      break;
    case 3:

      if (lista.tam == 0)
      {
        std::cout << "Não há tarefas no momento\n";
      }
      else
      {
        std::cout << "1 - Exibir por chegada\n";
        std::cout << "2 - Exibir por prioridade\n";
        std::cout << "3 - Exibir por tempo\n";
        std::cout << "4 - Exibir por nome\n";
        std::cin >> input;
        std::cin.ignore();
        if (input == 1)
        {
          exibirTarefaFila(&lista);
        }
        else if (input == 2)
        {

          bubbleSortLista(&lista);
          exibirTarefaFila(&lista);
        }
      }

      break;
    case 4:
      std::cout << "Saindo...";
      break;
    default:
      std::cout << "Opção não válida";
      break;
    }
  } while (input != 4);
}

int main()
{
  mostrarMenu();
  return 0;
}