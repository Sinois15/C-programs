#include <stdio.h>

void a(){
    printf("%-15.8u\n", 40000);
}

void b(){
    int hex;
    printf("Enter an hexadecimal value: ");
    scanf("%i", &hex);
    printf("the decimal value: %d and the hex value: %#x",hex,hex);
}

void c(){
    int x = 200;
    printf("with sign: %+d without sign: %d", x, x);
}
void d(){
    printf("%#x", 100);
}

void e(){
    char s[27];
    printf("enter a character: ");
    scanf("%[^p]", s);
    printf("the character is %s",s);
}

void f(){
    printf("%09.3f\n",1.234);
}

void g(){
    int h,m,s;
    printf("enter time(hour:minute:second)");
    scanf("%d%*c %d%*c %d",&h,&m,&s);
    printf("hours:%d minutes:%d seconds:%d\n",h,m,s);
    return 0;

}

int main(){

    e();
    return 0;
}
