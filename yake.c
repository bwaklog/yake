#include <stdio.h>

int opr(char *v);
void ex(int *p, char *syn);

int main(int ac, char *av[]) {
    int p = 0;
    return (ac < 2) ? (printf("synerr\n"),1) : (ex(&p, av[1]), 0);
}

void ex(int *v, char *syn){
    while ((int)*syn!='\0'){
        switch ((int)*syn) {
            case 46: printf("%d\n", *v); break;
            case 43: ++*v; break;
            case 45: --*v; break;
            case 60: *v = *v<<1; break;
            case 62: *v = *v>>1; break;
            default: printf("synerr\n"); return;
        }
        syn++;
    }
    return;
}
