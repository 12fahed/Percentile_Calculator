#include<stdio.h>
#include<string.h>

//for calculating percentage
float percentage(float a, float b){
    float per= (a/b)*100;
    return per;
}

//for counting
int count_digit(long long EN){

   int count=0;
   while(EN>0){
   EN/=10;
   count++;
   }

    return count;

}

//to store ssc details
struct ssc{
    float eng;
    float maths;
    float science;
    float ss;
    float hindi;
    float marathi;
    float total;
};

//to store hsc details
struct hsc{
    float eng;
    float physics;
    float chemistry;
    float maths;
    float vocational;
    float total;
};

//to store mhtcet details
struct mhtcet{

    float physics;
    float chemistry;
    float maths;
    float total;
};

//to store DOB
struct dob{
    int day;
    int month;
    int year;
};

//to store percentile
struct mhtcet_percentile{

    double physics;
    double chemistry;
    double maths;
    double total;
};

//to store details of student
struct detail{

    long long EN;
    long long ph;
    char name[50];
    char email[50];
    char category[3];
    char gender[6];
    char pwd_def[2];
    char ews[2];
    char tfws[2];
    char orphan[2];
    char minority[50];
    struct ssc ssc;
    int no;
    float ssc_per;
    struct hsc hsc;
    float hsc_per;
    float hsc_pcm;
    struct mhtcet mhtcet;
    struct dob dob;
    struct mhtcet_percentile per;

};

//to sort and assign Total Percentile
void sorttotal(int n, struct detail stud[]){

    //sorting according to total marks
    struct detail tempT;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.total)<(stud[j+1].mhtcet.total)){
                tempT=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempT;
            }
        }
    }

    //assigning Percentile for Total
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.total)==(stud[i+1].mhtcet.total)){
            stud[i].per.total = stud[i+1].per.total = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.total = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Maths Percentile
void sortmaths(int n, struct detail stud[]){

    //sorting according to maths marks
    struct detail tempM;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.maths)<(stud[j+1].mhtcet.maths)){
                tempM=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempM;
            }
        }
    }

    //assigning Percentile for maths
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.maths)==(stud[i+1].mhtcet.maths)){
            stud[i].per.maths = stud[i+1].per.maths = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.maths = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Physics Percentile
void sortphysics(int n, struct detail stud[]){

    //sorting according to Physics marks
    struct detail tempP;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.physics)<(stud[j+1].mhtcet.physics)){
                tempP=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempP;
            }
        }
    }

    //assigning Percentile for Physics
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.physics)==(stud[i+1].mhtcet.physics)){
            stud[i].per.physics = stud[i+1].per.physics = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.physics = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

//to sort and assign Chemistry Percentile
void sortchemistry(int n, struct detail stud[]){

    //sorting according to Chemistry marks
    struct detail tempC;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if((stud[j].mhtcet.chemistry)<(stud[j+1].mhtcet.chemistry)){
                tempC=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=tempC;
            }
        }
    }

    //assigning Percentile for Chemistry
    for(int i=0; i<n; i++){

        if((stud[i].mhtcet.chemistry)==(stud[i+1].mhtcet.chemistry)){
            stud[i].per.chemistry = stud[i+1].per.chemistry = (((double)n-(double)i)/(double)n)*100;
            i++;
        }
        else{
            stud[i].per.chemistry = (((double)n-(double)i)/(double)n)*100;
        }
    }
}

void sortpermaths(int a,int b, struct detail stud[]){

    //sorting according to Maths Percentile
    struct detail tempPerM;
    if((stud[a].per.maths)<(stud[b].per.maths)){
        tempPerM=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerM;
    }

}

void sortperphysics(int a,int b, struct detail stud[]){

    //sorting according to Physics Percentile
    struct detail tempPerP;
    if((stud[a].per.physics)<(stud[b].per.physics)){
        tempPerP=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerP;
    }

}

void sortperchemistry(int a,int b, struct detail stud[]){

    //sorting according to Physics Percentile
    struct detail tempPerC;
    if((stud[a].per.chemistry)<(stud[b].per.chemistry)){
        tempPerC=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPerC;
    }

}

//to sort according to HSC PCM
void sortPCM(int a, int b, struct detail stud[]){

    //sorting according to HSC PCM marks
    struct detail tempPCM;
    if((stud[a].hsc_pcm)<(stud[b].hsc_pcm)){
        tempPCM=stud[a];
        stud[a]=stud[b];
        stud[b]=tempPCM;
    }
}

//to sort according to HSC Maths
void sorthscmaths(int a, int b, struct detail stud[]){

    //sorting according to HSC Maths marks
    struct detail temphscmaths;
    if((stud[a].hsc.maths)<(stud[b].hsc.maths)){
        temphscmaths=stud[a];
        stud[a]=stud[b];
        stud[b]=temphscmaths;
    }
}

//to sort according to HSC Physics
void sorthscphysics(int a, int b, struct detail stud[]){

    //sorting according to HSC Physics marks
    struct detail temphscphysics;
    if((stud[a].hsc.physics)<(stud[b].hsc.physics)){
        temphscphysics=stud[a];
        stud[a]=stud[b];
        stud[b]=temphscphysics;
    }
}

//to sort according to HSC Total
void sorthsctotal(int a, int b, struct detail stud[]){

    //sorting according to HSC Total marks
    struct detail temphsctotal;
    if((stud[a].hsc.total)<(stud[b].hsc.total)){
        temphsctotal=stud[a];
        stud[a]=stud[b];
        stud[b]=temphsctotal;
    }
}

//to sort according to SSC Total
void sortssctotal(int a, int b, struct detail stud[]){

    //sorting according to SSC Total marks
    struct detail tempssctotal;
    if((stud[a].ssc.total)<(stud[b].ssc.total)){
        tempssctotal=stud[a];
        stud[a]=stud[b];
        stud[b]=tempssctotal;
    }
}

//to sort according to SSC Maths Marks
void sortsscmaths(int a, int b, struct detail stud[]){

    //sorting according to SSC Maths marks
    struct detail tempsscmaths;
    if((stud[a].ssc.maths)<(stud[b].ssc.maths)){
        tempsscmaths=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscmaths;
    }
}

//to sort according to SSC Science Marks
void sortsscscience(int a, int b, struct detail stud[]){

    //sorting according to SSC Science marks
    struct detail tempsscscience;
    if((stud[a].ssc.science)<(stud[b].ssc.science)){
        tempsscscience=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscscience;
    }
}

//to sort according to SSC English Marks
void sortsscenglish(int a, int b, struct detail stud[]){

    //sorting according to SSC English marks
    struct detail tempsscenglish;
    if((stud[a].ssc.eng)<(stud[b].ssc.eng)){
        tempsscenglish=stud[a];
        stud[a]=stud[b];
        stud[b]=tempsscenglish;
    }
}

//to sort according to Year
void sortyear(int a, int b, struct detail stud[]){

    //sorting according to year
    struct detail tempdobyear;
    if((stud[a].dob.year)<(stud[b].dob.year)){
        tempdobyear=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobyear;
    }
}

//to sort according to Month
void sortmonth(int a, int b, struct detail stud[]){

    //sorting according to month
    struct detail tempdobmonth;
    if((stud[a].dob.month)<(stud[b].dob.month)){
        tempdobmonth=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobmonth;
    }
}

//to sort according to Day
void sortday(int a, int b, struct detail stud[]){

    //sorting according to day
    struct detail tempdobday;
    if((stud[a].dob.day)<(stud[b].dob.day)){
        tempdobday=stud[a];
        stud[a]=stud[b];
        stud[b]=tempdobday;
    }
}

int main(){

    int n;
    struct detail s[1000];
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        s[i].no = i;
        printf("PHYSICS: ");
        scanf("%f",&s[i].mhtcet.physics);
        printf("CHEMISTRY: ");
        scanf("%f", &s[i].mhtcet.chemistry);
        printf("MATHS: ");
        scanf("%f", &s[i].mhtcet.maths);
        s[i].mhtcet.total = s[i].mhtcet.physics + s[i].mhtcet.chemistry + s[i].mhtcet.maths;
        printf("TOTAL: %f\n\n", s[i].mhtcet.total);
    }

    sortchemistry(n,s);
    sortphysics(n,s);
    sortmaths(n,s);
    sorttotal(n,s);

    for(int i=0; i<n-1; i++){
        if((s[i].per.total)==(s[i+1].per.total)){
            sortpermaths(i,i+1,s);
            if((s[i].per.maths)==(s[i+1].per.maths)){
                sortperphysics(i,i+1,s);
                if((s[i].per.physics)==(s[i+1].per.physics)){
                    sortperchemistry(i,i+1,s);
                }
            }
        }
    }



    for(int i=0; i<n; i++){
        printf("MHTCET %d: %llf %llf %llf %llf\n",(s[i].no+1), s[i].per.total, s[i].per.maths, s[i].per.physics, s[i].per.chemistry);
    }
}



