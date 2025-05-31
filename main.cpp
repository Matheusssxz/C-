#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;
typedef struct tarefa
{
  std::string nome;
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
  No *iterador = lista->inicio;
  No *noARemover = NULL;
  if (lista->inicio->tarefa.nome == tarefa->nome && lista->inicio->tarefa.prioridade == tarefa->prioridade && lista->inicio->tarefa.tempo == tarefa->tempo)
  {
    noARemover = lista->inicio;
    lista->inicio = noARemover->proximo;
  }
  if (lista->inicio == NULL)
  {
    lista->fim = NULL;
  }
  else
  {
    while (iterador->proximo != NULL && iterador->proximo->tarefa.nome != tarefa->nome && iterador->proximo->tarefa.prioridade != tarefa->prioridade && iterador->proximo->tarefa.tempo == tarefa->tempo)
    {
      iterador = iterador->proximo;
    }
  }
  if (iterador->proximo != NULL)
  {
    noARemover = iterador->proximo;
    iterador->proximo = noARemover->proximo;
    if (iterador->proximo == NULL)
    {
      lista->fim = iterador;
    }
  }
  if (noARemover)
  {
    free(noARemover);
    lista->tam--;
  }
}
void InserirTarefa(TLista *lista, Ttarefa *tarefa)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->tarefa.prioridade = tarefa->prioridade;
  novo->tarefa.nome = tarefa->nome;
  novo->tarefa.tempo = tarefa->tempo;

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

// mostrar item add na pilha
std::stack<Ttarefa> pilha;
void mostrarTopoDaPilha(Ttarefa *tarefa)
{
  pilha.push({tarefa->nome, tarefa->prioridade, tarefa->tempo});
  std::cout << "Nome: (pilha) " << pilha.top().nome << "\n";
  std::cout << "priori (pilha) " << pilha.top().prioridade << "\n";
  std::cout << "tempo (pilha) " << pilha.top().tempo << "\n";
}

bool retirarTarefaDaPilha(Ttarefa *tarefa)
{
  pilha;
  if (pilha.empty())
  {
    return false;
  }
  else
  {
    std::cout << "Tirando elemento...\n";
    std::cout << "Nome: (pilha) " << pilha.top().nome << "\n";
    std::cout << "priori (pilha) " << pilha.top().prioridade << "\n";
    std::cout << "tempo (pilha) " << pilha.top().tempo << "\n";
    pilha.pop();
    return true;
  }
}

void mostrarMenu()
{
  int input;
  TLista lista;
  Ttarefa tarefa;
  TNo no;
  bool istrue;
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
      std::getline(std::cin, tarefa.nome);

      std::cout << "Tempo (min):\n";
      std::cin >> tarefa.tempo;
      std::cin.ignore();

      std::cout << "Prioridade:\n";
      std::cin >> tarefa.prioridade;
      std::cin.ignore();

      InserirTarefa(&lista, &tarefa);
      mostrarTopoDaPilha(&tarefa);
      break;

    case 2:
      istrue = retirarTarefaDaPilha(&tarefa);
      if (istrue)
      {
        removerTarefa(&lista, &tarefa);
      }
      else
      {
        std::cout << "Nenhuma tarefa adicionada\n";
      }
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