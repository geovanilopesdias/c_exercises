#include <stdio.h>
#include <string.h>


typedef struct ath{
  char cpf[12], name[51], team[51];
  int age, height, weight;
} Athlete;


Athlete newAthlete(char teamName[51]){
  Athlete ath;
  printf ("Name (up to 50 letters): ");
  scanf("%s", &ath.name);
  getchar();
  printf("CPF (without dots and hyphen): ");
  scanf("%s", &ath.cpf);
  getchar();
  printf("Age: ");
  scanf("%i", &ath.age);
  getchar();
  printf("Height (m): ");
  scanf("%i", &ath.height);
  getchar();
  printf("Weight (kg): ");
  scanf("%i", &ath.weight);
  getchar();
  strcpy(ath.team, teamName);
  return ath;
}


void registerAthletes(Athlete *record, int recLength, char teamName[51]){
  Athlete ath;
  for(int i = 0; i < recLength; i++){
    if(i==0) printf("\n=====\nFirst athlete of %s:\n", teamName);
    else if(i==recLength-1) printf("---\nLast athlete of %s:\n", teamName);
    else printf("---\nNext athlete:\n");
    
    ath = newAthlete(teamName);
    record[i] = ath;
  }
}


void showAthlete(Athlete ath){
  printf("%s (CPF: %s) from %s, is %i years old, %i m and %i kg.\n", ath.name, ath.cpf, ath.team, ath.age, ath.height, ath.weight);
}


typedef struct vbteam{
  Athlete athletes[6];
  char name[51];
} VolleyBallTeam;


VolleyBallTeam newVolleyBallTeam(){
  VolleyBallTeam vbt;
  printf ("Name (up to 50 letters): ");
  scanf("%s", &vbt.name);
  getchar();
  registerAthletes(vbt.athletes, 6, vbt.name);
  return vbt;
}
  
void showVolleyBallTeam(VolleyBallTeam vbt){
  printf("=====\nShowing recorded athletes for %s:\n=====\n", vbt.name);
  for(int i = 0; i < 6; i++){
    showAthlete(vbt.athletes[i]);
  }
}


void registerLeague(VolleyBallTeam *teams, int leagueSize, const char *leagueName){
  VolleyBallTeam vbt;
  printf("Registration for the %s", leagueName);
  for(int i = 0; i < leagueSize; i++){
    if(i==0) printf("\n=====\nFirst team:\n");
    else if(i==leagueSize-1) printf("---\nLast team:\n");
    else printf("*****\nNext team:\n");
    
    vbt = newVolleyBallTeam();
    teams[i] = vbt;
  }
}


void showVolleyBallLeague(VolleyBallTeam *teams, int leagueSize){
  for (int i = 0; i < leagueSize; i++){
    showVolleyBallTeam(teams[i]);
  }
}
