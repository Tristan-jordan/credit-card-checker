#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    long long cc_num = get_long_long("Number: ");
    long long cc_num2 = cc_num;
    long long cc_num3 = cc_num;
    long long cc_num4 = cc_num;
    
    int temp, counter, values, i, visa, first2;
    int ld, product_sum1, product_sum2, first_digit, second_digit, each_digit;
    double num_of_10s;
    
    counter = 0;
    while (cc_num4 != 0) {
        cc_num4 /= 10;
        counter += 1;
    }
    
    //every other digit after last
    product_sum1 = 0;
    while (cc_num != 0) {
        ld = cc_num % 10;
        product_sum1 += ld;
        cc_num = cc_num / 100;
    } 
    
    //2nd to last start - every other digit
   cc_num2 = cc_num2 / 10;
   product_sum2 = 0;
    while (cc_num2 != 0) {
        first_digit = 0;
        second_digit = 0;
        ld = cc_num2 % 10;
        if ((ld * 2)> 9) {
            first_digit = (ld * 2) / 10;
            second_digit = (ld * 2) % 10;
            product_sum2 += (first_digit + second_digit);
            
            }
        else {
        product_sum2 += ld * 2;
        }
        cc_num2 = cc_num2 / 100;
    } 
    
    //printf("Sum: %i\n", product_sum1 + product_sum2);
    
    num_of_10s = pow(10, (counter - 2));
    
    first2 = cc_num3 / num_of_10s;
    visa = first2 / 10;
    
    if ((product_sum1 + product_sum2) % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }
    
    else if (counter == 13 || counter == 15 || counter == 16) {
        
    if(visa == 4) {
        printf("VISA\n");
        return 0;
    }
    
    else if (first2 > 50 && first2 < 56) {
        printf("MASTERCARD\n");
        return 0;
    }          
    
    else if (first2 > 33 && first2 < 38) {
        printf("AMEX\n");
        return 0;
    }
    
    else {
        printf("INVALID\n");
    }
}
    else {
        printf("INVALID\n");
        return 0;
    }
}
