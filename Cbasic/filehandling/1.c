/*
 * Chương trình C để tạo một tệp có tên emp.rec và lưu trữ thông tin
 * về một người, về tên, tuổi và tiền lương.
 */
#include <stdio.h>
void main()
{
  FILE *file;
  char name[20];
  int age;
  float salary;
  /* open for writing */
  if((file = fopen("tt.txt","w")) == NULL)
    {
      printf("KHong the mo file %s","tt.txt");
      return;
    }
  printf("Enter the name \n ");
  scanf("%s",name);
  fprintf(file,"Name  : %s\n",name);
  printf("Enter the age \n ");
  scanf("%d",&age);
  fprintf(file,"age  : %d\n",age);
   printf("Enter the Salary \n ");
  scanf("%f",&salary);
  fprintf(file,"Salary  : %.2f\n",salary);
  fclose(file);
  
}
