#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define TEAM_SIZE 6


// Athlete creator:
typedef struct ath{
  char cpf[12], name[51], team[51];
  int age;
  float height, weight;
} Athlete;


Athlete newAthlete(char teamName[51]){
  Athlete ath;
  printf ("Name (up to 50 letters): "); scanf("%50[^\n]", &ath.name); getchar();
  printf("CPF (without dots and hyphen): "); scanf("%11[^\n]", &ath.cpf); getchar();
  printf("Age: "); scanf("%d", &ath.age); getchar();
  printf("Height (m): ");
  scanf("%f", &ath.height); getchar();
  printf("Weight (kg): "); scanf("%f", &ath.weight); getchar();
  strcpy(ath.team, teamName);
  return ath;
}


void showAthlete(Athlete ath){
  printf("%s (CPF: %s) is %i years old, %.1f m and %.1f kg.\n", ath.name, ath.cpf, ath.age, ath.height, ath.weight);
}


//---- Linkedlist for Athletes functions
typedef struct ath_list{
  Athlete ath;
  struct ath_list *next;
} AthleteList;


void insertAthlete(AthleteList **head, Athlete ath){
  AthleteList *newAth = NULL;
  newAth = (AthleteList *) malloc (sizeof(AthleteList));
  if(newAth != NULL){
    newAth -> ath = ath;
    newAth -> next = *head;
    *head = newAth;
  }
  else printf("Allocation failed for start/left insertion in Athlete Linked List.");
}


//---- Team functions
typedef struct vb_team{
  AthleteList *athHead;
  char name[51];
} VolleyballTeam;


void registerAthletes(AthleteList *teamHead, char teamName[51]){
  Athlete ath;
  for(int i = 0; i < TEAM_SIZE; i++){
    if(i==0) printf("-----\nFirst athlete of %s:\n", teamName);
    else if(i==TEAM_SIZE-1) printf("---\nLast athlete of %s:\n", teamName);
    else printf("---\nNext athlete:\n");
    
    ath = newAthlete(teamName);
    insertAthlete(teamHead, ath);
  }
}


VolleyballTeam newVolleyballTeam(){
  VolleyballTeam vbt; vbt.athHead = NULL;
  printf ("Name (up to 50 letters): "); scanf("%s", &vbt.name); getchar();
  registerAthletes(&(vbt.athHead), vbt.name);
  
  return vbt;
}


void newLeague(VolleyballTeam *teams, int leagueSize, const char *leagueName){
  printf("\n**********\nRegistration System for the %s \n**********\n", leagueName);
  for(int i = 0; i < leagueSize; i++){
    printf("=====\nTeam %d registration: \n", i+1);
    teams[i] = newVolleyballTeam();
  }
}


void showLeague(VolleyballTeam *vbt, int leagueSize, const char *leagueName){
  printf("\n**********\nRegistered teams for the %s \n**********\n", leagueName);
  AthleteList *ath;
  for(int i = 0; i < leagueSize; i++){
    printf("---\nAthletes recorded for the %s:\n", vbt[i].name);
    if(vbt[i].athHead != NULL){
      ath = vbt[i].athHead;
      while (ath -> next != NULL) {
        showAthlete(ath -> ath);
        ath = ath -> next;
      }
      showAthlete(ath -> ath);
    }
    
    else printf("There's no athlete recorded in the team passed.\n");
  }
}


void freeAthleteList(AthleteList *head) {
  AthleteList *current = head;
  while (current != NULL) {
      AthleteList *next = current->next;
      free(current);
      current = next;
  }
}


void freeLeagueAllocation(VolleyballTeam *vbt, int leagueSize){
  for (int i = 0; i < leagueSize; i++) {
    freeAthleteList(vbt[i].athHead);
  }
}
