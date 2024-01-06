#include <stdio.h>
#include <stdlib.h>

int opr(char *v);
void ex(int *p, char *syn);

int main(int ac, char *av[]) {
    int p = 0;
    return (ac < 2) ? (printf("synerr\n"),1) : (ex(&p, av[1]), 0);
}

void ex(int *v, char *syn){
    //int *p;
    int *p = malloc(8*sizeof(int));
    int st = 0; // 0 for value control, 1 for pointer control
    while ((int)*syn!='\0'){
        //printf("P @ %p : %d | m : %d\n", p, *p, st);
        switch ((int)*syn) {
            case 46: printf("&v : %d | %p -> %d | m = %d\n", *v, p, *p, st); break;
            case 43: if(st!=1){++*v;}else{++p;} break;
            case 45: if(st!=1){--*v;}else{--p;} break;
            case 60: if(st!=1){*v = *v<<1;}else{printf("synerr");return;} break;
            case 62: if(st!=1){*v = *v>>1;}else{printf("synerr");return;} break;
            case 64: if(st == 1){st = 0;*p=*v;}else{st=1;} break;
            case 38: if(st == 1){st = 0;*v=*p;}else{st=1;}break;// & is used to get value
            
            // operations, st == 1, for subsequent value for operation type
            case 37: if(st==1){
                syn++;
                switch((int)*syn) {
                    case 45: *v-=*p; break;
                    case 43: *v+=*p; break;
                }
                st = 0; // auto switch back to st=0
            } break;

            default: printf("synerr\n"); return;
        }
        //printf("P @ %p : %d | m : %d\n", p, *p, st);
        syn++;
    }
    return;
}
