#include<stdio.h>
#include<string.h>


char * encrypt(char *, int);


char * decrypt(char *, int);


int main()
{
    char test[] = "BIGOTED";
    char test2[] = "M KS XS EDOEFER";
    printf("%s\n",encrypt(test,5));
    printf("%s\n",decrypt(test2,4));
    return 0;
}



char * encrypt(char *message, int shift_key)
{
    int begin=0, char s , count=0;
    char *index = message;
    while(*index != '\0')
    {
        if(*index == ' ')
        {
            index++;
            continue;
        }
        if(*index + shift_key > 'Z')
        {
            *index = *index + shift_key-26;
        } 
        else *index = *index+shift_key;
        index++;
    } 
    
   s=message;
   while (s[count] != '\0')
   count++;
   end = count - 1;
   for (begin = 0; begin < count; begin++) 
   {
      message[begin] = s[end];
      end--;
   }
   message[begin] = '\0';
   return message;
}



char * decrypt(char *message, int shift_key)
{
    int begin=0, char s , count=0;
    char *index = message;
    while(*index != '\0')
    {
        if(*index == ' ')
        {
            index++;
            continue;
        }
        if(*index - shift_key < 'A')
        {
            *index = *index - shift_key+26;
        }
        else *index = *index-shift_key;
        index++;
    }
    
   s=message;
   while (s[count] != '\0')
   count++;
   end = count - 1;
   for (begin = 0; begin < count; begin++) 
   {
      message[begin] = s[end];
       end--;
   }
  message[begin] = '\0';
  return message;    
   
}


