#include <stdio.h>
#include <string.h>
typedef struct{
    int id;
    char name[30];
    char surname[30];
}student_t;

typedef struct{
    char degree[30];
    int id;
    char name[30];
    char surname[30];
}lecturer_t;

typedef struct{
    int code;
    char name[30];
    int lecturerId;
}lecture_t;

typedef struct{
    char className[30];
    char day[30];
    int sTimeOflecture;
    int durOflecture;
    int code;
}schedule_t;

typedef struct{
    int studentId;
    int lectureCode;
}course_t;

void getFromInputFile(student_t *student,lecturer_t *lecturer,lecture_t *lecture
,schedule_t *schedule,course_t *course,int *countSt,int *countLtr,int *countLe,
int *countSch,int *countCour,char *inputFileName);

void createOutputFile(student_t *student,lecturer_t *lecturer,lecture_t *lecture
,schedule_t *schedule,course_t *course,int countSt,int countLtr,int countLe,
int countSch,int countCour,char *outputFileName);

int main(void)
{
    char inputFileName[30]="input.dat",outputFileName[30]="output.txt";
    int countSt=0,countLtr=0,countLe=0,countSch=0,countCour=0;
    student_t student[30];
    lecturer_t lecturer[30];
    lecture_t lecture[30];
    schedule_t schedule[30];
    course_t course[30];
    getFromInputFile(student,lecturer,lecture,schedule,course,
                &countSt,&countLtr,&countLe,&countSch,&countCour,inputFileName);
    createOutputFile(student,lecturer,lecture,schedule,course,
                    countSt,countLtr,countLe,countSch,countCour,outputFileName);
    return 0;
}

void getFromInputFile(student_t *student,lecturer_t *lecturer,lecture_t *lecture
,schedule_t *schedule,course_t *course,int *countSt,int *countLtr,int *countLe,
int *countSch,int *countCour,char *inputFileName)
{
    FILE *inp;
    inp=fopen(inputFileName,"rb");
    if(!inp){
        printf("Failed!Input file is invalid.\n");
    }    
    else{    
        fread(countSt,sizeof(int),1,inp);                                            
        fread(student,sizeof(student_t),*countSt,inp);
        
        fread(countLtr,sizeof(int),1,inp);                                            
        fread(lecturer,sizeof(lecturer_t),*countLtr,inp);                   
                    
        fread(countLe,sizeof(int),1,inp);                                            
        fread(lecture,sizeof(lecture_t),*countLe,inp);
        
        fread(countSch,sizeof(int),1,inp);                                            
        fread(schedule,sizeof(schedule_t),*countSch,inp);  
        
        fread(countCour,sizeof(int),1,inp);                                            
        fread(course,sizeof(course_t),*countCour,inp);                                                          
        
        fclose(inp);
    }     
}

void createOutputFile(student_t *student,lecturer_t *lecturer,lecture_t *lecture
,schedule_t *schedule,course_t *course,int countSt,int countLtr,int countLe,
int countSch,int countCour,char *outputFileName)
{
    int i,j,k,l,dayInd=0,check=0,currCour=0,currStCour=0;
    char days[5][30];
    FILE *out;
    out=fopen(outputFileName,"w");
    fprintf(out,"Lecture-Lecturer\n");                                          printf("Lecture-Lecturer\n");
    for(i=0;i<countLe;i++)
    {
        for(j=0;j<countLtr;j++)
        {

            if(lecture[i].lecturerId==lecturer[j].id)
            { 
                currCour=0;
                for(k=0;k<countCour;k++){
                    if(course[k].lectureCode==lecture[i].code){
                        currCour++;
                    }
                }                                                               printf("%s %s %s %d\n",lecture[i].name,lecturer[j].name,lecturer[j].surname,currCour);        
                fprintf(out,"%s %s %s %d\n",lecture[i].name,lecturer[j].name,   
                                                lecturer[j].surname,currCour);                                                                
            }
        }
    }
    fprintf(out,"\n");                                                          printf("\n");    
    fprintf(out,"Student-Lecture\n");                                           printf("Student-Lecture\n");
    
    for(i=0;i<countSt;i++)
    {
        currStCour=0;
        for(k=0;k<countCour;k++){
            if(student[i].id==course[k].studentId){
                currStCour++;
            }
        }                                                                       printf("%d %s %s %d\n",student[i].id,student[i].name,student[i].surname,currStCour);
        fprintf(out,"%d %s %s %d\n",student[i].id,student[i].name,              
                                    student[i].surname,currStCour);
    }
    fprintf(out,"\n");                                                          printf("\n");    
    fprintf(out,"Student-Day\n");                                               printf("Student-Day\n");
    
    for(i=0;i<countSt;i++)
    {
        dayInd=0;
        check=0;                                                                printf("%d %s %s ",student[i].id,student[i].name,student[i].surname);
        fprintf(out,"%d %s %s ",student[i].id,
                student[i].name,student[i].surname);                                                                         
        for(j=0;j<countCour;j++)
        {
            if(student[i].id==course[j].studentId){
                for(k=0;k<countSch && course[j].lectureCode!=schedule[k].code;
                                                                           k++);
                for(l=0;l<5;l++){
                    if(strcmp(days[l],schedule[k].day)==1)
                        check=1;
                }
                if(check==0){
                    strcpy(days[dayInd],schedule[k].day);
                    dayInd++;
                }    
            }
            
        }  
        for(l=0;l<dayInd;l++){
                fprintf(out,"%s",days[l]);                                      printf("%s",days[l]);
                if(l!=dayInd-1){
                    fprintf(out,",");                                           printf(",");
                }
        }
        fprintf(out,"\n");                                                      printf("\n");                                                                                                  
    }
    fprintf(out,"\n");                                                          printf("\n");
    fclose(out);
}
