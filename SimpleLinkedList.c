#include <stdlib.h>
#include <stdio.h>

struct node {
  int e;
  struct node* next;
};

int size = 0;
void PrintList(struct node* list);

/**
 * appends an element to the end of the list. For example, given the list 
 * [1,2,3], when this function is invoked as:
 *
 *   append(&l, 4);
 *
 * the list needs to have [1,2,3,4].
 *
 * This function runs in O(n).
 *
 * @return 0 on success, 1 if an error occurred
 */
int append(struct node* list, int e);

/**
 * removes the element at index i. For example, given the list [1,2,3], invoking 
 * this function as:
 *
 *    remove(&l, 1);
 *
 * causes the list to have [1,3]
 *
 * This function runs in O(n)
 *
 * @return 0 on success, 1 if the list is empty, 2 if there is any other error
 */
int remove_at(struct node* list, int i);

/**
 * inserts an element at index i. For example, given the list [1,3], invoking 
 * this function as:
 *
 *    insert(&l, 10, 1);
 *
 * causes the list to have [1,10,3]
 *
 * This function runs in O(n)
 *
 * @return 0 on success, 1 if there is an error
 */
int insert_at(struct node* list, int e, int i);

/**
 * inverts the order of the list. For example, if the list is [1,2,3], this 
 * function returns the list in the order [3,2,1].
 *
 * This function runs in O(n)
 *
 * @return 0 on success, 1 if there is an error
 */
int reverse(struct node* list);


int main()
{
    int opc = 0, boolean = 0, i = 0, e;
    struct node *head = (struct node *)malloc(sizeof(struct node));

    do
    {
        printf("\n.:Bienvenido a la lista:.\n\n");
        printf("1. Agregar un elemento al final de la lista\n");
        printf("2. Remover un elemento de la lista dado un indice\n");
        printf("3. Insertar elemento en un indice de la lista (i > 0)\n");
        printf("4. Invertir orden de la lista\n");
        printf("5. Imprimir Lista\n");
        printf("0. Salir\n\n");

        printf("Dame una opcion: ");
        scanf("%d", &opc);
        if(opc < 1 && opc > 5) exit(1);

        switch(opc)
        {
            case 0:
                boolean = 1;
                printf("Adios :)\n");
                break;
            case 1:
                printf("Dame un dato de tipo entero: ");
                scanf("%d", &e);
                if (append(head, e) == 0) printf("El elemento se agrego correctamente a la lista\n");
                else printf("Error, el elemento no se pudo agregar a la lista\n");
                break;
            case 2:
                printf("Dame el indice que quieres eliminar: ");
                scanf("%d", &i);
                if(size != 0 && i > 0)
                {
                    if (remove_at(head, i) == 0) printf("El elemento se elimino correctamente a la lista\n");
                }
                else printf("Error, el elemento no se pudo eliminar a la lista\n");
                break;
            case 3:
                printf("Dame un dato de tipo entero: ");
                scanf("%d", &e);
                printf("Dame el indice que quieres insertar: ");
                scanf("%d", &i);
                if(size != 0 && i > 0)
                {
                    if (insert_at(head, e, i) == 0) printf("El elemento se inserto correctamente a la lista\n");
                }
                else printf("Error, el elemento no se pudo insertar a la lista\n");
                break;
            case 4:
                if(size > 0)
                {
                    if (reverse(head) == 0) printf("La lista se invirtio correctamente\n");
                }
                else printf("Error, no se pudo invertir la lista\n");
                break;
            case 5:
                PrintList(head);
                break;
        }
        printf("Presiona 'Enter' para continuar...\n");
        system("\nread");
        system("clear");
    }while(boolean != 1);
    return 0;
}

struct node * CreateNode(int e)
{
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    if(head != NULL)
    {
        head->e = e;
        head->next = NULL;
    }
    return head;
}


int append(struct node* list, int e)
{
    struct node *head = NULL;
    struct node *new_node = NULL;
    head = list;
    new_node = CreateNode(e);

    if (new_node != NULL)
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = new_node;
        size++;
        return 0;
    }
    return 1;
}

int remove_at(struct node* list, int i)
{
    struct node* temp = list->next;
    struct node* prev = list;

    if(temp != NULL)
    {
        for (int j = 0; j < i-2; j++)
        {
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        free(temp);
        size--;
        return 0;
    }
    return 1;
}

int insert_at(struct node* head, int e, int i)
{
    struct node *temp = NULL, *new_node = NULL;
    temp = head;
    new_node = CreateNode(e);
    i++;
    if (new_node != NULL)
    {
        i--;
        while(i != 1)
        {
            temp = temp->next;
            i--;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
        return 0;
    }
    return 1;
}

int reverse(struct node* list)
{
   struct node *prev = NULL;
   struct node *next = NULL;
   struct node *current = list;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current = prev;

    if(current == list)
        return 1;
    else
        return 0;
}

void PrintList(struct node* list)
{
    struct node* head = list;
    printf("\nLinked List: [");
    for (head = list; head != NULL; head = head->next)
    {
        printf("%d, ", head->e);
    }
    printf("\b\b]\n");
}