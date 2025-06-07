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
void removerTarefa(TLista *lista, Ttarefa *tarefa)
{
  if (lista->inicio == NULL)
  {
    return;
  }

  No *iterador = lista->inicio;
  No *noARemover = NULL;

  if (iterador->tarefa.nome == tarefa->nome &&
      iterador->tarefa.prioridade == tarefa->prioridade &&
      iterador->tarefa.tempo == tarefa->tempo)
  {
    noARemover = iterador;
    lista->inicio = iterador->proximo;

    if (lista->inicio == NULL)
    {
      lista->fim = NULL;
    }

    free(noARemover);
    lista->tam--;
    return;
  }

  while (iterador->proximo != NULL &&
         (iterador->proximo->tarefa.nome != tarefa->nome ||
          iterador->proximo->tarefa.prioridade != tarefa->prioridade ||
          iterador->proximo->tarefa.tempo != tarefa->tempo))
  {
    iterador = iterador->proximo;
  }

  if (iterador->proximo != NULL)
  {
    noARemover = iterador->proximo;
    iterador->proximo = noARemover->proximo;

    if (iterador->proximo == NULL)
    {
      lista->fim = iterador;
    }

    free(noARemover);
    lista->tam--;
  }
}

void removerTarefa(TLista *lista)
{
  if (lista->inicio == NULL)
  {
    std::cout << "pilha vazia\n";
    return;
  }

  No *remover = lista->inicio;
  lista->inicio = remover->proximo;

  if (lista->inicio == NULL)
  {
    lista->fim = NULL;
  }

  free(remover);
  lista->tam--;
 cout << "Tarefa removida com sucesso";
}

void InserirTarefa(TLista *lista, Ttarefa *tarefa)
{
  No *novo = (No *)malloc(sizeof(No));
  strcpy(novo->tarefa.nome, tarefa->nome);
  novo->tarefa.tempo = tarefa->tempo;
  novo->tarefa.prioridade = tarefa->prioridade;

  if (lista->inicio == NULL)
  {
    novo->proximo = NULL;
    lista->inicio = novo;
    lista->fim = novo;
  }
  else
  {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
  }
  lista->tam++;
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
    std::cout << "Escolha as opcoes\n";
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
      std::cin.getline(tarefa.nome,100);

      std::cout << "Tempo (min):\n";
      std::cin >> tarefa.tempo;
      std::cin.ignore();

      std::cout << "Prioridade:\n";
      std::cin >> tarefa.prioridade;
      std::cin.ignore();
      InserirTarefa(&lista, &tarefa);
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
        struct No *atual = lista.inicio;
        while (atual != NULL)
        {
          std::cout << "Tarefa: " << atual->tarefa.nome
                    << " | Tempo: " << atual->tarefa.tempo
                    << " | Prioridade: " << atual->tarefa.prioridade
                    << "\n";
          atual = atual->proximo;
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