#include <stdio.h>
/*
#define DE "Ohne Hoergeraet hoere ich nichts"
#define NL "Zonder gehoorapparaat hoor ik niets"
#define FI "Ilman kuuloleitta en kuula mitaeaen"
#define SE "Jag hoer ingentin utan hoerselapparat"
#define IT "Senza l'apparecchio d'autito non sento niente"
#define CN "mei zhu ting qi jiu tingbujian"
*/

#if defined(DE)
    #define SPRUCH "Ohne Hoergeraet hoere ich nichts"
#elif defined(NL)
    #define SPRUCH "Zonder gehoorapparaat hoor ik niets"
#elif defined(FI)
    #define SPRUCH "Ilman kuuloleitta en kuula mitaeaen"
#elif defined(SE)
    #define SPRUCH "Jag hoer ingentin utan hoerselapparat"
#elif defined(IT)
    #define SPRUCH "Senza l'apparecchio d'autito non sento niente"
#else
    #define SPRUCH "mei zhu ting qi jiu tingbujian"
#endif


int main(int argc, char *argv[]) {
    int abstand = 0, i, size;   
    /*#ifdef DE
        char spruch[] = "Ohne Hoergeraet hoere ich nichts";
    #endif
    #ifdef NL
        char spruch[] = "Zonder gehoorapparaat hoor ik niets";
    #endif
    #ifdef FI
        char spruch[] = "Ilman kuuloleitta en kuula mitaeaen";
    #endif
    #ifdef SE
        char spruch[] = "Jag hoer ingentin utan hoerselapparat";
    #endif
    #ifdef IT
        char spruch[] = "Senza l'apparecchio d'autito non sento niente";
    #endif
    #ifndef CN
        char spruch[] = "mei zhu ting qi jiu tingbujian";
    #endif*/

    printf("%s\n", SPRUCH);

    #if SIZE > 0
        for(i= 0; i < argc; i++) {
            #if SIZE > 1
                printf("argv[%d]=", i);
            #endif
            printf("%s\n", argv[i]);
        }
    #endif
    return 0;
}