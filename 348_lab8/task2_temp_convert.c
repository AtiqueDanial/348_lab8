#include <stdio.h>
#include <ctype.h>

static double to_celsius(double value, char scale) {
    switch (toupper((unsigned char)scale)) {
        case 'C': return value;
        case 'F': return (value - 32.0) * (5.0 / 9.0);
        case 'K': return value - 273.15;
        default:  return value; // Shouldn't happen if validated
    }
}

static double from_celsius(double c, char target) {
    switch (toupper((unsigned char)target)) {
        case 'C': return c;
        case 'F': return c * (9.0 / 5.0) + 32.0;
        case 'K': return c + 273.15;
        default:  return c; // Shouldn't happen if validated
    }
}

static const char* category_from_c(double c) {
    if (c < 0.0)                return "Freezing";
    else if (c < 10.0)          return "Cold";
    else if (c < 25.0)          return "Comfortable";
    else if (c < 35.0)          return "Hot";
    else                        return "Extreme Heat";
}

static const char* advisory_from_category(const char* cat) {
    if (cat[0] == 'F') return "Wear a warm jacket.";
    if (cat[0] == 'C') return "Light layers recommended.";
    if (cat[0] == 'H') return "Drink lots of water!";
    if (cat[0] == 'E') return "Stay indoors and keep cool.";
    return "Have a nice day!";
}

int main(void) {
    double value;
    char from, to;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &value) != 1) {
        puts("Invalid temperature.");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    if (scanf(" %c", &from) != 1 || (toupper((unsigned char)from)!='C' && toupper((unsigned char)from)!='F' && toupper((unsigned char)from)!='K')) {
        puts("Invalid scale. Use C, F, or K.");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");
    if (scanf(" %c", &to) != 1 || (toupper((unsigned char)to)!='C' && toupper((unsigned char)to)!='F' && toupper((unsigned char)to)!='K')) {
        puts("Invalid target scale. Use C, F, or K.");
        return 1;
    }

    double c = to_celsius(value, from);
    double converted = from_celsius(c, to);

    printf("Converted temperature: %.2f %c\n", converted, (char)toupper((unsigned char)to));

    // Categorize based on temperature in Celsius (per spec ranges)
    const char* cat = category_from_c(c);
    printf("Temperature category: %s\n", cat);
    printf("Weather advisory: %s\n", advisory_from_category(cat));

    return 0;
}
