/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Advanced Object Oriented Programming
 * Date: June 3, 2020
 * Program Description:
 * 	Program prompts a user to input two positive floating-point numbers 
 * 	and prints their arithmetic, geometric, and harmonic mean.
*/

package test;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class ThreeMeans {
	public static void main(String[] args) {
	       
		// Variable Declarations
		double firstNum, secondNum, arithMean, geoMean, harmMean;

		// Initializing Scanner Object
		Scanner numbers = new Scanner(System.in);
		
		// Collecting User Input
		System.out.print("Enter two positive floating-point numbers: ");
		firstNum = numbers.nextDouble();
		secondNum = numbers.nextDouble();
		
		// Calculations
		arithMean = (firstNum + secondNum) / 2.0;
		geoMean = Math.sqrt(firstNum*secondNum);
		harmMean = (2.0 * firstNum * secondNum) / (firstNum + secondNum);
		
		// Rounding
		BigDecimal bd = new BigDecimal(arithMean).setScale(2, RoundingMode.HALF_UP);
		BigDecimal bd2 = new BigDecimal(geoMean).setScale(2, RoundingMode.HALF_UP);
		BigDecimal bd3 = new BigDecimal(harmMean).setScale(2, RoundingMode.HALF_UP);
		arithMean = bd.doubleValue();
		geoMean = bd2.doubleValue();
		harmMean = bd3.doubleValue();
		
		// Program Output
		System.out.println("The arithmetic mean is "  + arithMean + ".");
		System.out.println("The geometric mean is " + geoMean + ".");
		System.out.println("The harmonic mean is " + harmMean + ".");
	}
}
