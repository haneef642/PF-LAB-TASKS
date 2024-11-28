#include <stdio.h>


struct Rectangle {
    float length;
    float width;
};


int check(struct Rectangle *rect) {
    return (rect->length > 0.0 && rect->length < 20.0) && 
           (rect->width > 0.0 && rect->width < 20.0);
}


float calculate_perimeter(struct Rectangle *rect) {
    return 2 * (rect->length + rect->width);
}


float calculate_area(struct Rectangle *rect) {
    return rect->length * rect->width;
}

int main() {
    
    struct Rectangle rect;

    
    printf("Enter the length of the rectangle: ");
    scanf("%f", &rect.length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &rect.width);

    
    if (check(&rect)) {
        
        printf("Perimeter: %.2f\n", calculate_perimeter(&rect));
        printf("Area: %.2f\n", calculate_area(&rect));
    } else {
        
        printf("Invalid dimensions! Length and width must be greater than 0 and less than 20.\n");
    }

    return 0;
}
