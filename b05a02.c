#include <stdio.h>

/* Manuelle Berechnung des absoluten Werts */
double my_fabs(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

/* Definition der Funktion regula() zur Bestimmung der Nullstelle einer Funktion f(x) */
double regula(double x1, double x2, double (*f)(double)) {
    double xs, fx1, fx2, fx3;
    
    /* Sicherstellen, dass f(x1) * f(x2) < 0 ist (Vorzeichenwechsel) */
    if (f(x1) * f(x2) >= 0) {
        fprintf(stderr, "Fehler: Vorzeichenwechsel zwischen f(x1) und f(x2) ist nicht gegeben.\n");
        return -1.0 / 0.0;  /* Gibt -∞ zurück, um anzuzeigen, dass keine Lösung gefunden wurde */
    }
    
    /* Iteration bis die Genauigkeit erreicht ist */
    do {
        fx1 = f(x1);
        fx2 = f(x2);
        
        /* Berechnung der neuen Schätzung xs */
        xs = x1 - fx1 * (x2 - x1) / (fx2 - fx1);
        fx3 = f(xs);

        /* Wenn das Vorzeichen von f(xs) mit f(x1) übereinstimmt, setze x1 auf xs */
        if (fx3 * fx1 < 0) {
            x2 = xs;
        } else {  /* Andernfalls setze x2 auf xs */
            x1 = xs;
        }
        
        /* Wiederhole die Berechnung, solange der Fehler nicht klein genug ist */
    } while (my_fabs(f(xs)) >= 1E-6);  /* Genauigkeit: |f(xs)| < 1E-6 */
    
    /* Gibt die Nullstelle zurück */
    return xs;
}

/* Beispielhafte Funktion f(x) = x^2 - 9, deren Nullstellen bekannt sind */
double f1(double x) {
    return x * x - 9;  /* f(x) = x^2 - 9 */
}

int main() {
    /* Testen der regula() Funktion mit der Funktion f1(x) */
    double x1 = 0;   /* Startwert 1 */
    double x2 = 5;   /* Startwert 2 */

    double result = regula(x1, x2, f1);
    
    /* NaN-Prüfung: Wenn das Ergebnis -∞ ist, gab es einen Fehler */
    if (result != result) {  /* Prüft, ob der Wert NaN ist */
        fprintf(stderr, "Fehler: Keine gültige Nullstelle gefunden.\n");
    } else {
        printf("Die Nullstellen: (+/-)%f\n", result);
    }
    
    return 0;
}
