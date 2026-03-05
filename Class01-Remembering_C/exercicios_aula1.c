#include <stdio.h>
#include <math.h>

int dentro_retangulo(int x, int y, int x0, int y0, int x1, int y1){
    int y_maximo = (y0<y1) ? y1 : y0;
    int x_maximo = (x0<x1) ? x1 : x0;
    
    int y_minimo = (y0<y1) ? y0 : y1;
    int x_minimo = (x0<x1) ? x0 : x1;
    
    if((x<=x_maximo) && (x>=x_minimo) && (y<=y_maximo) && (y>=y_minimo)){
        return 1;
    }
    return 0;
}

int fibonacci(int n){
    int a = 1;
    int b = 1;
    int temp;
    if (n==1){
        return 1;
    }
    else if(n==2){
        return 1;
    }
    else{
        for(int i=3; i<=n; i++){
            temp = b;
            b = b+a;
            a = temp;
        }
        return b;
    }
}

int primo(int n){
    
    for(int i = 2; i<(sqrt(n) + 1); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int soma_impares(int n){
    int soma = 0;
    for(int i=1; i<(n*2); i+=2){
        soma+=i;
    }
    return soma;
}

double pi(int n){
    int turn = 0;
    double denominador = 1;
    double leibniz = 0;
    for(int i=0; i<n; i++){
        if(turn%2 == 0){
            leibniz += 1/denominador;
        }
        else{
            leibniz-=1/denominador;
        }
        turn++;
        denominador+=2;
    }
    double pi = 4*leibniz;
    return pi;
}

int raizes(int a, int b, int c, float* x1, float* x2){
    float delta = b*b - (4*a*c);
    *x1 = (-b + sqrt(delta))/(2*a);
    *x2 = (-b - sqrt(delta))/(2*a);
    if (delta<0){
        return 0;
    }
    if(*x1 == *x2){
        return 1;
    }
    else{
        return 2;
    }
}

#define PI 3.141592653f

void calc_esfera(float r, float* area, float* volume){
    *area = 4*PI*(r*r);
    *volume = (4*PI*(r*r*r))/3;
}

int negativos(int n, float* vet){
    int count = 0;
    for(int i=0; i<n; i++){
        if (vet[i]<0){
            count++;
        }
    }
    return count;
}

int main(){
    int a = dentro_retangulo(1, 2, 0, 0, 2, 2);
    printf("Esta dentro do retangulo? 1=Sim, 0=Nao - %d\n", a);
    int b = primo(1000000007);
    printf("Eh primo? 1=Sim, 0=Nao - %d\n", b);
    int entrada_fib = 27;
    int c = fibonacci(entrada_fib);
    printf("FIBONACCI NUMERO %d - %d\n", entrada_fib, c);
    int entrada_odd_sum = 100;
    int odd_sum = soma_impares(entrada_odd_sum);
    printf("Soma dos %d primeiros numeros impares - %d\n", entrada_odd_sum, odd_sum);
    int entrada_pi = 10000;
    double pie = pi(entrada_pi);
    printf("Entrada: %d; Valor de Pi: %.4lf\n", entrada_pi, pie);
    int f = 2;
    int g = 5;
    int h = 2;
    float x1;
    float x2;
    int nraizes = raizes(f, g, h, &x1, &x2);
    printf("N de raizes: %d\n%dxx + %dx + %d = 0;\nx1 = %f\nx2 = %f\n", nraizes, f, g, h, x1, x2);
    float area;
    float volume;
    float r = 5;
    calc_esfera(r, &area, &volume);
    printf("Raio: %f - Area da superficie: %f - Volume: %f\n", r, area, volume);
    int len = 5;
    float array[] = {1, -1, 2, -2, 0};
    int negatives = negativos(len, array);
    printf("%d numeros negativos no array.", negatives);
    
    return 0;
}
