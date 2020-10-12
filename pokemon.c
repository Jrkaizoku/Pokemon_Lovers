// Kodigo - Jennifer Granados
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
struct node{
  char name[25];
  struct node* left;
  struct node* right;
};

void preorderTraversal(struct node* root);
struct node* createNode(char value[]);
struct node* insertLeft(struct node* root, char value[]);
struct node* insertRight(struct node* root, char value[]);
bool yes(char quest[],char poke[]);
bool yes(char quest[],char poke[]);
void rules();
void startGame();
void gotoxy( short x, short y );
int main() {
  SetConsoleOutputCP(CP_UTF8);
  int y;
  char contin;	
	do{ 
		system("cls");	
		y=16;
		int menu=0;
		printf("\n	 -♫- JUEGO POKEMON LOVERS -♫-\n\n");
		printf("	   	_\\|/_\n         	(o o)\n");
		printf("	+----oOO-{_}-OOo----------------------+\n");
		printf("	|                                     |	\n");
		printf("	|             Menu Opciones           |\n");
		printf("	|                                     |\n");
		printf("	|    Iniciar  ------------------ 1    |\n");
		printf("	|    Descripcion del juego ----- 2    |\n");
		printf("	|    Salir --------------------- 3    |\n");
		printf("	|                                     |\n");
		printf("	|                                     |\n");
		printf("	+------------------------------------*/\n");
		gotoxy(8, y);
		scanf("%d",&menu);
		while(menu<0||menu>3){		
			gotoxy(8, y);	
			printf("Debe ingresar valores validos \n");			
			gotoxy(8, y+1);	
			printf("     ");	
			gotoxy(8, y+1);	
			scanf("%d",&menu);
		}
		switch(menu){
			case 1:	startGame();
			break;
			case 2: rules();	
			break;			
			case 3: contin='N';
			break;
		}
		fflush( stdin );		
		if(contin!='N'){;	
				printf("\n\nDesea Volver al menu? (Y/N) \n");
				contin=getchar();
			}
		
	}while(contin=='Y'||contin=='y');
	return 0;
}
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%s ->", root->name);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
struct node* createNode(char value[]) {
  struct node* newNode = malloc(sizeof(struct node));
  strcpy(newNode->name, value);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
struct node* insertLeft(struct node* root, char value[]) {
  root->left = createNode(value);
  return root->left;
}
struct node* insertRight(struct node* root, char value[]) {
  root->right = createNode(value);
  return root->right;
}
bool yes(char quest[],char poke[]){
	char res;
	printf("%s%s?\n",quest,poke);
	fflush( stdin );
	res=getchar();
	return(res=='Y'|| res=='y');
}
void startGame(){
  bool bucle = true;
  char order;
  char newPoke[25],oldPoke[25];
  char info[25];
  struct node* root = createNode("Pikachu"); 
 
	while (bucle){
		system("cls");
		printf("\n	 -♫- JUEGO POKEMON LOVERS -♫- (Y/N) \n\n");
        if (yes("Estas pensando en un Pokemon","")){	
			struct node* pokemon =root;
		while (pokemon->left != NULL){
			if(yes("",pokemon->name)) pokemon=pokemon->left;
			else pokemon=pokemon->right;
		}
		if( yes("El pokemon es ",pokemon->name)){
			printf("\nGenial, he adivinado!!\n\n");
		}
		else{
			printf("Que pokemon era?\n");
			scanf("%s",newPoke);
			printf("Que pregunta diferenciaria a %s de %s?\n",pokemon->name,newPoke);
			fflush( stdin );
			scanf("%24[0-9a-zA-Z ]",info);			
			printf("si el pokemon fuera %s, cual seria la respuesta a \"%s?\"?\n",pokemon->name,info);	
			fflush( stdin );
			order=getchar();
			strcpy(oldPoke,pokemon->name);
			strcpy(pokemon->name,info);
			if(order=='Y' || order=='y'){
				insertLeft(pokemon, oldPoke);
				insertRight(pokemon, newPoke);
			}
			else{	
				insertRight(pokemon, oldPoke);
				insertLeft(pokemon, newPoke);					
			}
		}
		system("PAUSE");
		system("cls");
		}		
		else break;	
	}
	 system("PAUSE");
	 system("cls");
	 printf("\n	 -♫- JUEGO POKEMON LOVERS -♫- (Y/N) \n\n");
	 printf("\nArbol pre orden \n\n");
     preorderTraversal(root);
}
void rules(){
	system("cls");	
	printf("	 _____________________________________________________________________________________________\n");
	printf("	/\\                     									      \\\n");
	printf("	\\_|			\e[32m-♫- JUEGO POKEMON LOVERS -♫- DESCRIPCION\e[0m 			      |\n");
	printf("	  |											      |\n");
	printf("	  | \e[36m Los Pokémon son una clase de criaturas inspiradas en animales reales, insectos, objetos,\e[0m |\n");
	printf("	  | \e[36m plantas o criaturas mitológicas, cada una de estas criaturas se pueden clasificar en \e[0m    |\n");
	printf("	  | \e[36m diferentes tipos y tienen características diferentes.\e[0m				      |\n");
	printf("	  |											      |\n");
	printf("	  |  Se requiere crear una base de datos por medio de interrogantes que se hacen al usuario,  |\n");
	printf("	  |  se van quitando alternativas hasta que queda una. El objetivo es “instruir” a la base de |\n");
	printf("	  |  datos, en un inicio la base de datos solo sabe un pokemon y cuestionará si ese pokemon   |\n");
	printf("	  |  es el que el usuario está pensando, de lo contrario preguntará en que pokemon pensaba    |\n");
	printf("	  |  el usuario y en qué lo diferencia del que nos “predice”, se debe hacer uno de arbol      |\n");
	printf("	  |  binario que despues de introducir cualquier dato podrá predecir cualquier pokemon.	      |\n");
	printf("	  |											      |\n");	
	printf("	  |   ________________________________________________________________________________________|_\n");
	printf("	   \\_/_________________________________________________________________________________________/");
}
void gotoxy( short x, short y ) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition( hStdout, position );
}
