#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define file "annuaire5000.csv"
#define MAX_LENGTH 300
#include <windows.h>

void Color(int ColTxt,int ColFont) // fonction d'affichage de couleurs
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,ColFont*16+ColTxt);
}

typedef struct {    /* structure */
    int id_client;
    char *last_name;
    char *name;
    char *city;
    char *postal;
    char *phone;
    char *mail;
    char *job;
} ints;

char * strsep (char **stringp, const char *delim)
{
    /* Code source de la fonction strsep extrait du site https://c-for-dummies.com/blog/?p=1769 */
  char *begin, *end;
  begin = *stringp;
  if (begin == NULL)
    return NULL;
  end = begin + strcspn (begin, delim);
  if (*end)
    {
      *end++ = '\0';
      *stringp = end;
    }
  else
    *stringp = NULL;
  return begin;
}

int nbr_ligne ()
{
    FILE* fichier;
    fichier = fopen(file,"r");
    int i = 0;
    int l;
    while((l=fgetc(fichier)) != EOF)
    {
        if(l=='\n')
            i++;
    }
    return i;
}

void change (ints *s)   /* function taking pointer to struct */
{
    FILE* fichier;
    fichier = fopen(file,"r");
    int i = 0;
    char ligne[MAX_LENGTH];
    char *ligne2,*token;
    int y = 0;
    while(!feof(fichier))
    {
        fgets(ligne,MAX_LENGTH,fichier);
        ligne2 = strdup(ligne);
        token = strsep(&ligne2, ",");
        s[y].id_client = y;
        for (i=0;i<=6;i++)
        {
            if (i==0){
                 s[y].last_name = token;
            }else if (i==1){
                s[y].name = token;
            }else if (i==2){
                s[y].city = token;
            }else if (i==3){
                s[y].postal = token;
            }else if (i==4){
                s[y].phone = token;
            }else if (i==5){
                s[y].mail = token;
            }else if (i==6){
                s[y].job = token;
            }
            token = strsep(&ligne2,",");
        }
        y++;
    }
    fclose(fichier);
}

void filter(ints *s,int NS)
{

    int ChoixMenu;
        printf("Filtrer par : \n");
        printf(" 1/ Nom de famille \n");
        printf(" 2/ Prenom  \n");
        printf(" 3/ Ville \n");
        printf(" 4/ Code Postal  \n");
        printf(" 5/ Numero de Telephone \n");
        printf(" 6/ Email  \n");
        printf(" 7/ Travail \n");

        printf("\nEntrez une valeur : ");
        scanf("%d", &ChoixMenu);

        char *val;
        printf("\nEntrez une valeur : ");
        scanf("%s", &val);
   switch(ChoixMenu){
   case 1:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].last_name,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 2:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].name,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 3:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].city,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 4:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].postal,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 5:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].phone,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 6:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].mail,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
   case 7:
        for (int i = 0; i<NS; i++){
            if (strstr(s[i].job,&val))
            {
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
        break;
       }

    }

void add_client(ints *s, int NS)
{
    ints user;
    printf(" 1/ Nom de famille\n -> ");
    scanf("%s",&user.last_name);
    printf(" 2/ Prenom\n -> ");
    scanf("%s",&user.name);
    printf(" 3/ Ville\n -> ");
    scanf("%s",&user.city);
    printf(" 4/ Code Postal\n -> ");
    scanf("%s",&user.postal);
    printf(" 5/ Numero de Telephone\n -> ");
    scanf("%s",&user.phone);
    printf(" 6/ Email\n -> ");
    scanf("%s",&user.mail);
    printf(" 7/ Travail\n -> ");
    scanf("%s",&user.job);
    save(s,NS);
    FILE* fichier;
    fichier = fopen(file,"a");
    fprintf (fichier,"%s,%s,%s,%s,%s,%s,%s\n",&user.last_name,&user.name,&user.city,&user.postal,&user.phone,&user.mail,&user.job);
    fclose(fichier);
}

void empty(ints *s, int NS)
{
    for (int i = 0;i<NS-1;i++)
        {
            if (strlen(s[i].last_name) == 0){
                printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
            }}
}

void affichage(ints *s, int NS)
{
    printf ("%5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s",s[NS].id_client,s[NS].last_name,s[NS].name,s[NS].city,s[NS].postal,s[NS].phone,s[NS].mail,s[NS].job);
    printf("%d\n",NS);
    for (int i = 0; i <NS; i++)
    {
        printf ("%5d ||| %5d || %21s | %26s | %22s | %5s | %14s | %47s | %17s", i,s[i].id_client,s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
    }
}

void save(ints *s, int NS)
{
    FILE* fichier;
    fichier = fopen(file,"w+");
    for (int i = 0; i < NS; i++)
    {
        fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s",s[i].last_name,s[i].name,s[i].city,s[i].postal,s[i].phone,s[i].mail,s[i].job);
    }
    fclose(fichier);
}

void suppr(ints *s, int NS)
{
    int i,j;
    j = 0;
    ints tmp[NS];
    printf("Entrez l'indice du client à supprimer :");
    scanf("%d",&i);
    for (int x=i;x<NS-1;x++){
            s[x].last_name == s[x+1].last_name;
            s[x].name == s[x+1].name;
            s[x].city == s[x+1].city;
            s[x].postal == s[x+1].postal;
            s[x].phone == s[x+1].phone;
            s[x].mail == s[x+1].mail;
            s[x].job == s[x+1].job;
        }

}
/*
void tri_fusion(int i, int j, ints *s,int param,ints tmp[])
{
    if (j<=i){
        return;
    }
    int m = (i+j) / 2;
    printf("\n %d %d %d Etape 1",m,i,j);
    tri_fusion(i, m, s,param,tmp);
    tri_fusion(m+1, j, s,param,tmp);

    int g = i;
    int d = m +i;
    int x;

    for (x=i;x<=j;x++)
    {
        if (g == m + 1)
        {
            tmp[x] = s[d];
            d++;
        }
        else if (d == j + 1)
        {
            tmp[x] = s[g];
            g++;
        }
        else if (compare(s[d].name,s[g].name) == 1){
            tmp[x] = s[g];
            g++;
        }
        else
        {
            tmp[x] = s[d];
            d++;
        }

    }
    for (x=i;x<=j;x++)
    {
        s[x] = tmp[x];
    }
}

int compare(char *ch1, char *ch2)
{
    int i;
    int l;
    if (strlen(*ch1) > strlen(*ch2)){int l=strlen(*ch1);}
    else {int l = strlen(*ch2);}
        for (i=0;i<l;i++){
            if (ch1[i] < ch2[i]){
                return 1;
            }else if (ch1[i] > ch2[i]){
                return 0;
            }
        }
    }

void search(ints *s)
{



    ints user;
    int SubChoixMenu;
    printf("\n Entrez le nom : ");
    scanf("%s", &user.last_name);
    printf("\n Entrez le prenom : ");
    scanf("%s", &user.name);
    printf("\n Choix d'option :\n");
    printf("\n 1/ Mail");
    printf("\n 2/ Telephone");
    printf("\nEntrez une valeur : ");
    scanf("%d", &SubChoixMenu);
    printf("%d", SubChoixMenu);
    switch(SubChoixMenu){
    case 1:
        printf("\n Entrez le mail :");
        scanf("%s",&user.mail);
        break;
    case 2:
        printf("\n Entrez le telephone :");
        scanf("%s",&user.phone);
        break;
    default:
        printf("Erreur, vous devez entrez un nombre valide entre 1 et 2 \n");
    }
    printf("%s %s %s %s",&user.last_name,&user.name,&user.mail,&user.phone);
}
*/
int main() {
    void Color(int ColTxt,int ColFont);
    Color(15,0);
    int NS;
    NS = nbr_ligne();
    ints arr[NS+1];   /* array of struct initialized zero */
    change (arr);
    while(1) //Pour faire tourner le menu en boucle tant que l'on quitte pas
    {
        NS = nbr_ligne();
        ints arr[NS+1];   /* array of struct initialized zero */
        change (arr);
        printf("\nFICHIER : %d",NS);
        printf("\nTABLEAU : %d",sizeof(arr)/sizeof(arr[0]));
        int ChoixMenu;
        printf("\n -------------------- Menu --------------------  \n");
        Color(10,0);printf(" 1/ Ajout de nouveau client \n");
        Color(12,0);printf(" 2/ Modification des donnees sur un client  \n");
        Color(12,0);printf(" 3/ Supression d'un client \n");
        Color(10,0);printf(" 4/ Affichage de la liste de tout les clients \n");
        Color(10,0);printf(" 5/ Filtrage \n");
        Color(12,0);printf(" 6/ Recherche \n");
        Color(10,0);printf(" 7/ Affichage client donnees manquante \n");
        Color(10,0);printf(" 8/ Sauvegarde de donnees \n");
        Color(10,0);printf(" 9/ Quitter \n");
        printf("----------------------------------------------\n");
        Color(15,0);printf("Entrez une valeur : ");
        scanf("%d", &ChoixMenu);
        printf("----------------------------------------------\n");
        switch(ChoixMenu)
        {
        case 1 :
            printf(" Ajout de nouveau client : \n");
            add_client(arr,NS);
            printf("\nClient Ajoute !");
        case 2 :
            printf(" Modification des donnees sur un client : \n");
            //fonction......
            break;
        case 3 :
            printf(" Supression d'un client : \n");
            suppr(arr,NS);
            break;
        case 4 :
            printf(" Affichage de la liste de tout les clients : \n");
            affichage (arr,NS);
            break;
        case 5 :
            printf(" Filtrage : \n");
            filter(arr,NS);
            break;
        case 6 :
            printf(" Recherche : \n");
            //fonction......
            break;
        case 7 :
            printf(" Affichage client donnees manquante : \n");
            empty(arr,NS);
            break;
        case 8 :
            printf(" Sauvegarde de donnees ...");
            save(arr,NS);
            printf("... Donnees sauvegardees ");
            break;
        case 9 :
            printf(" Vous avez quittez ... \n");
            return EXIT_SUCCESS;
            break;
        default:
            printf("Erreur, vous devez entrez un nombre valide entre 1 et 9 \n");
        }
    }
}
