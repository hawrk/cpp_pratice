#include<stdio.h>
struct student
{
    int num;
    char name[20];
    int score[3];
}stu[30];
void input(struct student p[])
{
    int i,j,k;
    printf("The number of students:");scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        printf("Num:");scanf("%d",&p[i].num);
        printf("Name:");scanf("%s",&p[i].name);
        for(j=0;j<3;j++)
        {
            printf("score[%d]:",j);
            scanf("%d",&p[i].score[j]);
        }
    }
}
int main()
{
    input(stu);
    return 0;
}
