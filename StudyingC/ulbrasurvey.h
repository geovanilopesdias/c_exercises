#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct stu{
  char gender;
  int age;
  float weight;
  float height;
} Student;

Student newStudent(){
  Student stu;
  int genderIsValid = (stu.gender == 'F' || stu.gender == 'M');
  do {
    printf("Insert student gender (upper F or M only): ");
    scanf("%c", &stu.gender);
    getchar();
    genderIsValid = (stu.gender == 'F' || stu.gender == 'M');
    if (!genderIsValid) printf("Invalid GENDER insertion; try again:\n");
  } while(!genderIsValid);

  do {
    printf("Insert student AGE (equal or greater than 17): ");
    scanf("%d", &stu.age);
    getchar();
    if (stu.age < 17) printf("Invalid age insertion; try again:\n");
  } while(stu.age < 17);

  int heightIsValid = (stu.height > 1 && stu.height < 2.5);
  do {
    printf("Insert student HEIGHT (meter): ");
    scanf("%f", &stu.height);
    getchar();
    heightIsValid = (stu.height > 1 && stu.height < 2.5);
    if (!heightIsValid) printf("Invalid height insertion; the measure need to be given in meter (between 1 and 2.5):\n");
  } while(!heightIsValid);
  
  int weightIsValid = (stu.weight > 30 && stu.weight < 200);
  do {
    printf("Insert student WEIGHT (kilogram): ");
    scanf("%f", &stu.weight);
    getchar();
    weightIsValid = (stu.weight > 30 && stu.weight < 200);
    if (!weightIsValid) printf("Invalid weight insertion; the measure need to be given in kilogram (between 30 and 200):\n");
  } while(!weightIsValid);
  
  return stu;
}


void printSurveyData(Student *group, int gSize){
  char gender[7];
  
  for(int i = 0; i < gSize; i++){
    if(group[i].gender == 'F') strcpy(gender, "female");
    else strcpy(gender, " male ");
    printf("Student #%d is %s, %d years old, %f m height and %f kg.\n", i, gender, group[i].age, group[i].height, group[i].weight);
  }
}


int getHighestAge(Student *group, int gSize){
  int hAge = 0;
  for(int i = 0; i < gSize; i++){
    if(group[i].age > hAge) hAge = group[i].age;
  }
  return hAge;
}


float getMenRatio(Student *group, int gSize){
  int cMale = 0, i;
  for(i = 0; i < gSize; i++){
    if(group[i].gender == 'M') cMale++;
  }
  return (float) cMale/gSize;
}


int countShortestMenIn(Student *group, int gSize, float heightLimit){
  int count = 0;
  for(int i = 0; i < gSize; i++){
    if(group[i].gender =='M' && group[i].height < heightLimit) count++;
  }
  return count;
}


float getAverageWomenWeight(Student *group, int gSize){
  float sum = 0;
  int cFemale = 0;
  for(int i = 0; i < gSize; i++){
    if(group[i].gender == 'F') {
      sum += group[i].weight;
      cFemale++;
    }
  }
  return sum/cFemale;
}


void printSurvey(Student *group, int gSize){
  // Survey registration:
  for (int i = 0; i < gSize; i++){
    printf("---\nStudent #%d:\n", i+1);
    group[i] = newStudent();
  }

  
// Data construction:
  float menRatio = getMenRatio(group, gSize);
  int highestAge = getHighestAge(group, gSize);
  int numberOfSmallMen = countShortestMenIn(group, gSize, 1.7);
  float avgWomenWeight = getAverageWomenWeight(group, gSize);

  // Output:
  printf("=====\nFrom the %d students interviewed, it is known that:\n-----\n", gSize);
  printf("%.1f%% are men and %.1f%% are women.\n", menRatio*100, (1-menRatio)*100);
  printf("The oldest student was %d years old.\n", highestAge);
  printf("There were %d male students shorter than 1.7 m.\n", numberOfSmallMen);
  printf("The average weigth bewteen the women is %f kg.\n", avgWomenWeight);
}