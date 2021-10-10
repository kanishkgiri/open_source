#include <stdio.h>                             //header file

void hex_dec(int length, char str[length]);               //declaring function hex_dec()

int main()
{
   char str[20];
   printf("Unsigned Hexadecimal value: ");          //taking hexadecimal no. as string input
   scanf("%s",str);
   int length=0;

   while(str[length] != '\0')        //loop to calculate length of str
   {
      length++;
   }

   hex_dec(length, str);
   return 0;
}  
void hex_dec(int length, char str[length])        //defining function hex_dec
{   
   int point;double sum=0.0;
   point=length;
   
   for(int i=0; i<length; i++)                //loop to find out index of point '.' if any
   {
       if(str[i]=='.')
       point=i;
   }
  
   int base=1;                                  //loop to calculate decimal form of no. left of point
   for( int i=point; i>=0 ;i--)
   {
         if (str[i]>='0' && str[i]<='9')
         {
            sum += (str[i] - 48)*base;
            base = base * 16;
         }

         if (str[i]>='A' && str[i]<='F' )
         {
            sum += (str[i] - 55)*base;
            base = base*16;
         }
         
         if (str[i]>='a' && str[i]<='f' )
         {
            sum += (str[i] - 87)*base;
            base = base*16;
         }
         
   }

  double base1=16.0;                         //loop to calculate decimal form of no. right of point
   for( int i=point+1; i<length ;i++)
   {
         if (str[i]>='0' && str[i]<='9')
         {
            sum += (str[i] - 48)/base1;
            base1= base1 * 16;
         }
        
         if (str[i]>='A' && str[i]<='F' )
         {
            sum += (str[i] - 55)/base1;
            base1 = base1*16;
         }
         if (str[i]>='a' && str[i]<='f' )
         {
            sum += (str[i] - 87)/base1;
            base1 = base1*16;
         }
   }
   printf("Equivalent Decimal value: %.8f\n",sum);             //prints decimal form rounding off to 8 decimal places
}
