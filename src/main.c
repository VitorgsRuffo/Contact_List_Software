#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <stdbool.h>

#define Q_contatos 5


typedef struct{
    char nome[50];
    char numero[2][20];
    char endereco[60];
    char email[30];
    int on;
}contatos;


typedef struct{
    contatos contato[Q_contatos];
    int contactsalreadyadded;
}contact_list;


void init_contacts(contact_list *Contact_List){
    for(int i = 0; i<Q_contatos; ++i){
        (*Contact_List).contato[i].on = 0;
    }

    Contact_List -> contactsalreadyadded = 0;
}


int listar(contact_list *Contact_List){

    //VARIAVEIS USADAS NA FUNCAO 
    
    char menor[50];
    int contador = 0;
    int selecao = 0;

    // ESPACO PARA COLOCAR CONDICAO DE MOSTRAR QUE NAO HA CONTATOS CADASTRADOS

        if (Contact_List -> contactsalreadyadded > 0)
        {
        
            //LOOPING ORDENANDO OS CONTATOS POR ORDEM ALFABETICA
            while(contador <= Contact_List -> contactsalreadyadded)
            {
                for(int j = 0; j < Contact_List -> contactsalreadyadded; j++)
                {
                    if (strcmp (Contact_List -> contato[j].nome, Contact_List -> contato[j+1].nome) > 0)
                    {   
                        //ALTERANDO A POSICAO DOS NOMES 
                        strcpy(menor, Contact_List -> contato[j].nome);
                        strcpy(Contact_List -> contato[j].nome, Contact_List -> contato[j+1].nome);
                        strcpy(Contact_List -> contato[j+1].nome, menor);

                        //ALTERANDO A POSICAO DO PRIMEIRO NUMERO
                        strcpy(menor, Contact_List -> contato[j].numero[0]);
                        strcpy(Contact_List -> contato[j].numero[0], Contact_List -> contato[j+1].numero[0]);
                        strcpy(Contact_List -> contato[j+1].numero[0], menor);

                        //ALTERANDO A POSICAO DO SEGUNDO NUMERO 
                        strcpy(menor, Contact_List -> contato[j].numero[1]);
                        strcpy(Contact_List -> contato[j].numero[1], Contact_List -> contato[j+1].numero[1]);
                        strcpy(Contact_List -> contato[j+1].numero[1], menor);

                        //ALTERANDO A POSICAO DO ENDERECO
                        strcpy(menor, Contact_List -> contato[j].endereco);
                        strcpy(Contact_List -> contato[j].endereco, Contact_List -> contato[j+1].endereco);
                        strcpy(Contact_List -> contato[j+1].endereco, menor);

                        //ALTERANDO A POSICAO DO EMAIL
                        strcpy(menor, Contact_List -> contato[j].email);
                        strcpy(Contact_List -> contato[j].email, Contact_List -> contato[j+1].email);
                        strcpy(Contact_List -> contato[j+1].email, menor);    
                    }
                }

                contador++;
            }

            //PRINTANDO A LISTA DE CONTATOS
            for (int i = 0; i <= Contact_List -> contactsalreadyadded; i++)
            {
                printf("%d - ", i+1);
                printf("%s\n",Contact_List -> contato[i].nome);
            }

            printf(" -----------------------------------------------\n");
            printf("  1 - Escolher um contato    2 - Voltar ao menu \n");
            printf(" -----------------------------------------------\n");
            scanf("%d",&selecao);

            return selecao;
        }
        else    
        {
            printf("\tAinda nao ha contatos cadastrados\n\n");
            printf("Pressione uma tecla para voltar ao menu...\n");
            setbuf(stdin, NULL);
            getchar();
            return 0;
        }


}


void add(contact_list *Contact_List){
    int adding;
    int i = 0;

    while(1){
        system("cls");

        (*Contact_List).contactsalreadyadded = 0;
        
        for(int k = 0; k<Q_contatos; ++k){
            if((*Contact_List).contato[k].on == 1)
                ++(*Contact_List).contactsalreadyadded;
        }

        if((*Contact_List).contactsalreadyadded >= Q_contatos){
            system("cls");
            printf("------------------------------------------------\n");
            printf("|                 NOVO CONTATO:                |\n");
            printf("|----------------------------------------------|\n");
            printf("\nLimite de contatos atingido!\n");
            system("pause");
            break;
        }

        if((*Contact_List).contato[i].on == 0){
            system("cls");
            printf("------------------------------------------------\n");
            printf("|                 NOVO CONTATO:                |\n");
            printf("|----------------------------------------------|\n");
            printf("Nome: \n");
            setbuf(stdin, NULL);
            fgets((*Contact_List).contato[i].nome, 50, stdin);
            printf("Numero (1): \n");
            fgets((*Contact_List).contato[i].numero[0], 20, stdin);
            printf("Numero (2): \n");
            fgets((*Contact_List).contato[i].numero[1], 20, stdin);
            printf("Endereco: \n");
            fgets((*Contact_List).contato[i].endereco, 60, stdin);
            printf("Email: \n");
            fgets((*Contact_List).contato[i].email, 30, stdin);
            (*Contact_List).contato[i].on = 1;
            ++i;
                     

            printf("\n\nDeseja adicionar outro contato?\n1 - Sim.\n2 - Nao.\n");
            scanf("%d", &adding);

            if(adding == 2)
                break;
        }else
            ++i;
    }
 
}


int editar(contact_list *Contact_List){
    system("cls");
    printf("-------------------------------------------------\n");
    printf("|                    EDITAR:                    |\n");
    printf("|-----------------------------------------------|\n");

    int selecao = listar(Contact_List);
    if(selecao != 0){
        while(1){
            switch (selecao){
                case 1:
                    //SELECIONANDO CONTATO
                    printf("Digite o numero do contato: ");
                    
                    //VALIDACAO DE SELECAO 
                    do{
                        scanf("%d", &selecao);

                        if(selecao > Contact_List -> contactsalreadyadded || selecao <= 0)
                            printf("\nOpcao Invalida, por favor digite novamente: ");
                        
                    }while(selecao > Contact_List -> contactsalreadyadded || selecao <= 0);

                    while(1){
                        system("cls");
                        printf("-------------------------------------------------\n");
                        printf("|                    EDITAR:                    |\n");
                        printf("|-----------------------------------------------|\n");
                        printf(" 1 - Nome: %s\n", (*Contact_List).contato[selecao-1].nome);
                        printf(" 2 - Numero (1): %s\n", (*Contact_List).contato[selecao-1].numero[0]);
                        printf(" 3 - Numero (2): %s\n", (*Contact_List).contato[selecao-1].numero[1]);
                        printf(" 4 - Endereco: %s\n", (*Contact_List).contato[selecao-1].endereco);
                        printf(" 5 - Email: %s\n", (*Contact_List).contato[selecao-1].email);
                        printf(" 0 - Voltar ao Menu.");

                        int selecao2;

                        do{
                        
                            scanf("%d", &selecao2);

                            if(selecao2 > 5 || selecao2 < 0)
                                printf("\nOpcao Invalida, por favor digite novamente: ");
                        
                        }while(selecao2 > 5 || selecao2 < 0);
                        
                        system("cls");
                        printf("-------------------------------------------------\n");
                        printf("|                    EDITAR:                    |\n");
                        printf("|-----------------------------------------------|\n");

                        int varDcontrole = -1;

                        while(varDcontrole == -1){
                            switch(selecao2){
                                case 1:
                                    printf("Novo Nome: \n");
                                    scanf(" %s", &(*Contact_List).contato[selecao-1].nome);
                                    varDcontrole = 1;
                                    printf("\nPressione uma tecla para voltar.\n");
                                    setbuf(stdin, NULL);
                                    getchar();
                                    break;
                                case 2:
                                    printf("Novo Numero (1): \n");
                                    scanf(" %s", &(*Contact_List).contato[selecao-1].numero[0]);
                                    varDcontrole = 1;
                                    printf("\nPressione uma tecla para voltar.\n");
                                    setbuf(stdin, NULL);
                                    getchar();
                                    break;
                                case 3:
                                    printf("Novo Numero (2): \n");
                                    scanf(" %s", &(*Contact_List).contato[selecao-1].numero[1]);
                                    varDcontrole = 1;
                                    printf("\nPressione uma tecla para voltar.\n");
                                    setbuf(stdin, NULL);
                                    getchar();
                                    break;
                                case 4:
                                    printf("Novo Endereco: \n");
                                    scanf(" %s", &(*Contact_List).contato[selecao-1].endereco);
                                    varDcontrole = 1;
                                    printf("\nPressione uma tecla para voltar.\n");
                                    setbuf(stdin, NULL);
                                    getchar();
                                    break;
                                case 5:
                                    printf("Novo Email: \n");
                                    scanf(" %s", &(*Contact_List).contato[selecao-1].email);
                                    varDcontrole = 1;
                                    printf("\nPressione uma tecla para voltar.\n");
                                    setbuf(stdin, NULL);
                                    getchar();
                                    break;
                                case 0:
                                    return 0;
                                    break;
                                default:
                                    do{
                                        if(selecao2 > 5 || selecao2 < 0)
                                            printf("\nOpcao Invalida, por favor digite novamente: ");

                                        scanf("%d", &selecao2);
                        
                                    }while(selecao2 > 5 || selecao2 < 0);

                                    varDcontrole = -1;

                                    break;
                            }
                        }
                    }
                    break;
                case 2:
                    return 0;
                    break;

                default:
                    do{
                        if(selecao > 2 || selecao <= 0)
                            printf("\nOpcao Invalida, por favor digite novamente: ");

                        scanf("%d", &selecao);
                    
                    }while(selecao > 2 || selecao <= 0);
                    break;

                
            }
        }
    }
}


void excluir(contact_list *Contact_List){
    system("cls");
}


int ordenar(contact_list *Contact_List){
    system("cls");
    printf("-------------------------------------------------\n");
    printf("|                    LISTAR:                    |\n");
    printf("|-----------------------------------------------|\n");

    int selecao = listar(Contact_List);
        if(selecao != 0){
            while(1){
                switch (selecao)
                {   
                    case 1:
                        //SELECIONANDO CONTATO
                        printf("Digite o numero do contato: ");
                    
                        //VALIDACAO DE SELECAO 
                        do
                        {
                            scanf("%d", &selecao);

                            if(selecao > Contact_List -> contactsalreadyadded + 1 || selecao <= 0)
                                printf("\nOpcao Invalida, por favor digite novamente: ");
                        
                        }while(selecao > Contact_List -> contactsalreadyadded + 1 || selecao <= 0);

                        system("cls");
                        printf("-------------------------------------------------\n");
                        printf("|                    LISTAR:                    |\n");
                        printf("|-----------------------------------------------|\n");

                        char exit;

                        //PRINTANDO INFORMACOES DO CONTATO
                        while (exit != 's' || exit != 'S')
                        {
                        
                            printf("Nome: %s\n", Contact_List -> contato[selecao-1].nome);

                            for(int i = 0; i < 2; i++)
                            {
                                printf("Telefone %d: %s\n", i+1, Contact_List -> contato[selecao-1].numero[i]);
                            }
                            
                            
                            printf("Endereco: %s\n", Contact_List -> contato[selecao-1].endereco);
                            printf("Email: %s\n", Contact_List -> contato[selecao-1].email);
                        
                            printf("         ----------------------------\n");
                            printf("         | S - Sair das informacoes |\n");
                            printf("         ---------------------------\n");

                            setbuf(stdin, NULL);
                            scanf("%c", &exit);

                            //CONDICAO PARA VOLTAR AO MENU PRINCIPAL
                            if(exit == 's' || exit == 'S')
                                return 0;
                        }
                        break;

                    case 2:
                        return 0;
                        break;

                    default:
                        do
                        {

                            if(selecao > Contact_List -> contactsalreadyadded + 1 || selecao <= 0)
                                printf("\nOpcao Invalida, por favor digite novamente: ");

                            scanf("%d", &selecao);
                        
                        }while(selecao > Contact_List -> contactsalreadyadded + 1 || selecao <= 0);
                        break;

                }
            }
        }
     
}


void buscar(contact_list *Contact_List){
    system("cls");

}


void menu(contact_list *Contact_List){
    int option;

    while(1){
        system("cls");
        printf("-----------------------------------\n");
        printf("|       LISTA DE CONTATOS:        |\n");
        printf("|                                 |\n");
        printf("| 1 - Adicionar novo contato.     |\n");
        printf("| 2 - Editar.                     |\n");
        printf("| 3 - Excluir.                    |\n");
        printf("| 4 - Listar.                     |\n");
        printf("| 5 - Buscar.                     |\n");
        printf("| 0 - Sair                        |\n");
        printf("-----------------------------------\n");
        setbuf(stdin, NULL);
        scanf("%d", &option);

        if(option == 0)
            break;

        switch (option){
            case 1:
                add(Contact_List);
                break;
            case 2:
                editar(Contact_List);
                break;
            case 3:
                excluir(Contact_List);
                break;
            case 4:
                ordenar(Contact_List);
                break;
            case 5:
                buscar(Contact_List);
                break;
            default:
                printf("\nOpcao Invalida!\n");
                system("pause");
                break;
        }
    }

}


int main (void){

    contact_list Contact_List;

    init_contacts(&Contact_List);

    menu(&Contact_List);

    return 0;
}