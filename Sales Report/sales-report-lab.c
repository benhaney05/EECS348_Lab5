/*
Ben Haney
EECS 348 Lab 5
Lab Section: Thursday 9am
*/


#include <stdio.h>
#include <math.h>

#define SIZE 12 //Number of months

//Generage Sales Report. Prints header, months and corresponding sales values.
void generateSalesReport(float sales[SIZE]) {
    char *months[] = {
       "January", "February", "March", "April", "May", "June", "July",
       "August", "September", "October", "November", "December" 
    };


    printf("Monthly Sales Report for 2024\n");
    printf("Month        Sales\n");

    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%-9s    %.2f\n", months[i], sales[i]);
    }

}

//Generates Sales Summary Report. Uses for loops to find minimum, maximum, and total sales. Prints report.
void generateSalesSummary(float sales[SIZE]) {
    char *months[] = {
       "January", "February", "March", "April", "May", "June", "July",
       "August", "September", "October", "November", "December" 
    };

    int min = 0;
    int max = 0;
    float minSales = sales[0];
    float maxSales = sales[0];
    float totalSales = 0;


    int i;
    for (i = 0; i < SIZE; i++) {
        totalSales += sales[i];
    if (sales[i] < minSales) {
        minSales = sales[i];
        min = i;
    }
    if (maxSales < sales[i]) {
        maxSales = sales[i];
        max = i;
    }
}

    float average = totalSales / 12;


    printf("Sales Summary Report: \n");
    printf("Minimum sales: %.2f (%s)\n", minSales, months[min]);
    printf("Maximum sales: %.2f (%s)\n", maxSales, months[max]);
    printf("Average sales: %.2f\n", average);

}

//Driver. Reads sales totals from input.txt. Calls neccessary functions to print sales report and sales summary.
int main() {
    float sales[SIZE];
    char *filename = "input.txt";

    FILE *file = fopen("input.txt", "r");

    int i;
    for (i = 0; i < SIZE; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file);

    generateSalesReport(sales);
    printf("\n");

    generateSalesSummary(sales);

    return 0;
}