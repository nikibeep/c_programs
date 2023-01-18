#include<stdio.h>
#include<string.h>
 int vowel_count(char str[100],int len){
  int count=0,i;
  for(i=0;i<=len;i++){
  switch(str[i]){
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
count++;
break;
}
}
  return count;
 }
 int main(){
  char str[100],word[10][20],check_word[20],ch;
  int i,j=0,k,len,n,word_count=0,flag=0,op,v_count,w_count,ar[10],l=0;
  printf("\n Enter the String: ");
  gets(str);
  for(len=1;str[len]!='\0';len++);
  str[len]=' ';
  for(i=0;i<len+1;i++){
  if(str[i]==' '){
  word_count++;
  j++;
  k=0;
}
else{
word[j][k]=str[i];
k++;
}
}
do{
	system("cls");
	printf("\n1) String Length");
	printf("\n2) Number of Words");
	printf("\n3) Check for a word");
	printf("\n4) Count of Vowels");
	printf("\n5) Count of each word");
	printf("\nEnter your option: ");
	scanf("%d",&op);
switch(op)
{
	case 1:
		printf("\nLength of th estring is %d",len);
		break;
	case 2:
 		printf("\nNumber of words is %d",word_count);
		break;
	case 3:
		printf("\nEnter the String: ");
		scanf("%s",check_word);
		flag=0;
		for(i=0;i<j;i++)
		if(strcmp(word[i],check_word)==0)
		flag=1;
		if(flag)
		printf("\nWord is present in the String");
		else
		printf("\nWord is not present in the String");
		break;
	case 4:
		v_count = vowel_count(str,len+1);
		printf("\nVowels Count is %d",v_count);
		break;
	case 5:
		for(i=0;i<j;i++)
		{
			flag=0;
			w_count=0;
			for(int x=0;x<l;x++)  
			if(i==ar[x]){
			flag=1;
			break;
		}
		if(flag)
		continue;
		for(k=i+1;k<j;k++)
		{
			if(strcmp(word[i],word[k])==0){
			w_count++;
			ar[l]=k;
			l++;
		}
		}
			printf("\n%s is repeated %d times ",word[i],w_count);
		}
			break;
			default:
			printf("\nWrong Option");
		}
			printf("\nDo you want to continue(y/n): ");
			scanf(" %c",&ch);
		}while(ch=='y' || ch=='Y');
		return 0;
		}