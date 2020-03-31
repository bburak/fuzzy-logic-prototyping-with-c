/*H**********************************************************************
* FILENAME :        main.c             
*
* DESCRIPTION :
*       In this sample implementation, effort are made that fuzzification, fuzzy Inferences and defuzzification processes.
*
* AUTHOR :    Burak Bilgic        DATE :    29 Nov 2016
*
*H*/

#include <stdio.h>
// macros
#define max(a,b) \
       ({ typeof (a) _a = (a); \
           typeof (b) _b = (b); \
         _a > _b ? _a : _b; })
#define min(a,b) \
       ({ typeof (a) _a = (a); \
           typeof (b) _b = (b); \
       _a > b ? _b : _a;})

// public array - input variables  
double arr [1][2];

// prototypes
void Calculate_CaCo3(int);
void Calculate_Cl(int);

int main()
{
    int CaCo3;
    int Cl;
    
    double aClass [3];
	double bClass [3];
	double cClass [3];
    
    printf("\nPlease enter the CaCo3 value as ppm unit of measurement (mg / L): ");
    scanf("%d", &CaCo3);
    printf("\nPlease enter the Cl value : ");
    scanf("%d", &Cl);
    
    // For first input variable  
    Calculate_CaCo3(CaCo3);
    printf("%f Membership value is SOFT.\n", arr[0][0]);
    printf("%f Membership value is MEDIUM-HARD.\n", arr[0][1]);
    printf("%f Membership value is HARD.\n", arr[0][2]);
    
    // For second input variable
    Calculate_Cl(Cl);
    printf("\n%f Membership value is GOOD.\n", arr[1][0]);
    printf("%f Membership value is MEDIOCRE.\n", arr[1][1]);
    printf("%f Membership value is GOOD.\n", arr[1][2]);
    
    // Rule Table
    if ((CaCo3 > 0) && (Cl > 0))
    {
        aClass [0] = min(arr[0][0],arr[1][0]);
        printf("\n%f   = A Quality   '0' ->  (yumusak, iyi)\n", aClass[0]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        aClass [1] = min(arr[0][0],arr[1][1]);
        printf("\n%f   = A Quality   '1' ->  (yumusak, orta)\n", aClass[1]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        bClass [0] = min(arr[0][0],arr[1][2]);
        printf("\n%f   = B Quality   '0' ->  (yumusak, kotu)\n", bClass[0]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        aClass [2] = min(arr[0][1],arr[1][0]);
        printf("\n%f   = A Quality   '2' ->  (ortasert, iyi)\n", aClass[2]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        bClass [1] = min(arr[0][1],arr[1][1]);
        printf("\n%f   = B Quality   '1' ->  (ortasert, orta)\n", bClass[1]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        cClass [0] = min(arr[0][1],arr[1][2]);
        printf("\n%f   = C Quality   '0' ->  (ortasert, kotu)\n", cClass[0]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        bClass [2] = min(arr[0][2],arr[1][0]);
        printf("\n%f   = B Quality   '2' ->  (sert, iyi)\n", bClass[2]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        cClass [1] = min(arr[0][2],arr[1][1]);
        printf("\n%f   = C Quality   '1' ->  (sert, orta)\n", cClass[1]);
    }
    if ((CaCo3 > 0) && (Cl > 0))
    {
        cClass [2] = min(arr[0][2],arr[1][2]);
        printf("\n%f   = C Quality   '2' ->  (sert, kotu)\n", cClass[2]);
    }
    
    // Fuzzy Inferences
    double aClassMax = max(max(aClass[0], aClass[1]), aClass[2]);
    printf("\nA Quality maximum = %f\n", aClassMax);
    double bClassMax = max(max(bClass[0], bClass[1]), bClass[2]);
    printf("\nB Quality maximum = %f\n", bClassMax);
    double cClassMax = max(max(cClass[0], cClass[1]), cClass[2]);
    printf("\nC Quality maximum = %f\n", cClassMax);
    
    // Defuzzification
    int x = 19;
    int y = 40;
    int z = 67;
    
    double clearness = ((aClassMax*x) + (bClassMax*y) + (cClassMax*z)) / (aClassMax + bClassMax + cClassMax);
    printf("defuzzification : %f", clearness);
    
    return 0;
}
void Calculate_CaCo3(int Quantity_CaCo3)
{
    if (Quantity_CaCo3 <= 75)
    {
        arr[0][0] = 1;
        arr[0][1] = 0;
        arr[0][2] = 0;
    }

    if ((Quantity_CaCo3 > 75) & (Quantity_CaCo3 < 150))
    {
        arr[0][0] = (150 - Quantity_CaCo3) / 75.d;
        arr[0][1] = (Quantity_CaCo3 - 75) / 75.d;
        arr[0][2] = 0;
    }
    
    if (Quantity_CaCo3 == 150)
    {
        arr[0][0] = 0;
        arr[0][1] = 1;
        arr[0][2] = 0;
    }

    if ((Quantity_CaCo3 > 150) & (Quantity_CaCo3 < 300))
    {
        arr[0][0] = 0;
        arr[0][1] = (300 - Quantity_CaCo3) / 150.d;
        arr[0][2] = (Quantity_CaCo3 - 150) / 150.d;
    }
    if (Quantity_CaCo3 >=300)
    {
        arr[0][0] = 0;
        arr[0][1] = 0;
        arr[0][2] = 1;
    }
}
void Calculate_Cl(int Quantity_Cl)
{
    if (Quantity_Cl <= 2)
    {
        arr[1][0] = 1;
        arr[1][1] = 0;
        arr[1][2] = 0;
    }
    
    if ((Quantity_Cl > 2) & (Quantity_Cl < 5))
    {
        arr[1][0] = (5 - Quantity_Cl) / (3.d);
        arr[1][1] = (Quantity_Cl - 2) / (3.d);
        arr[1][2] = 0;
    }
    
    if (Quantity_Cl == 5)
    {
        arr[1][0] = 0;
        arr[1][1] = 1;
        arr[1][2] = 0;
    }

    if((Quantity_Cl > 5) & (Quantity_Cl < 8))
    {
        arr[1][0] = 0;
        arr[1][1] = (8 - Quantity_Cl) / (3.d);
        arr[1][2] = (Quantity_Cl - 5) / (3.d);
    }
    
    if (Quantity_Cl >= 8)
    {
        arr[1][0] = 0;
        arr[1][1] = 0;
        arr[1][2] = 1;
    }
}