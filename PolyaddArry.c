#include <stdio.h>
#define max 20
float p1[max][2], p2[max][2], p3[max][2];
int d1, d2;
void readpol(float p[max][2], int d)
{
for(int i=d; i>=0; i--)
{
scanf("%f", &p[i][0]);
p[i][1] = i;
}
}
void printpol(float p[max][2], int d)
{
int i;
for(i=d; i>=0; i--)
{
if(p[i][0]!=0)
{
if(i==d)
printf("%.2fx^%.0f", p[i][0], p[i][1]);
else if(i==1)
printf("+%.2fx", p[i][0]);
else if(i==0)
printf("+%.2f", p[i][0]);
else
printf("+%.2fx^%.0f", p[i][0], p[i][1]);
}}}
void addpol(float p1[max][2], float p2[max][2], float p3[max][2], int d1, int d2)
{
int i=0,j=0,k=0;
while(i<=d1 && j<=d2)
{
if (p1[i][1] == p2[j][1]) {
p3[k][0] = p1[i][0] + p2[j][0];
p3[k][1] = p1[i][1];
i++, j++, k++;
}
else if (p1[i][1] > p2[j][1]) {
p3[k][0] = p1[i][0];
p3[k][1] = p1[i][1];
i++, k++;
}
else {
p3[k][0] = p2[j][0];
p3[k][1] = p2[j][1];
j++, k++;
}
}
while(i<=d1)
{
p3[k][0] = p1[i][0];
p3[k][1] = p1[i][1];
i++, k++;
}
while (j <= d2) {
p3[k][0] = p2[j][0];
p3[k][1] = p2[j][1];
j++, k++;
}
}
int main(){
printf("enter the degree of the first polynomial");
scanf("%d",&d1);
printf("Enter coefficients for the first polynomial (in descending order of power):\n");
readpol(p1, d1);
printf("\nEnter the degree of the second polynomial: ");
scanf("%d", &d2);
printf("Enter cofficients for the second polynomial (in descending order of power):\n");
readpol(p2, d2);
printf("\nPolynomial 1 entered:\n");
printpol(p1, d1);
printf("\nPolynomial 2 entered:\n");
printpol(p2, d2);
addpol(p1, p2, p3, d1, d2);
printf("\nResultant Polynomial after addition:\n");
printpol(p3, d1 > d2 ? d1 : d2);
return 0;
}
