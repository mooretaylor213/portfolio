/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Advanced Object Oriented Programming
 * Date: June 5, 2020
 * Program Description:
 * 	Program prompts a user to input three points of a triangle and 
 * 	displays its area.
*/



package taymoore;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class AreaOfATriangle {
	public static void main(String[] args) {
		// Initializing Scanner and Variables
		Scanner numbers = new Scanner(System.in);
		double x1, y1 , x2, y2, x3, y3, side1, side2, side3, s, area;
		
		// User Input
		System.out.println("User Entry for a Triangle Should Be Formatted as Follows: x1 y1 x2 y2 x3 y3");
		System.out.print("Enter three points for a triangle: ");
		x1 = numbers.nextDouble();
		y1 = numbers.nextDouble();
		x2 = numbers.nextDouble();
		y2 = numbers.nextDouble();
		x3 = numbers.nextDouble();
		y3 = numbers.nextDouble();

		// Calculations
		side1 = Math.sqrt((x2-x1)*(x2-x1) + (y2-y1) * (y2-y1));
		side2 = Math.sqrt((x3-x2)*(x3-x2) + (y3-y2) * (y3-y2));
		side3 = Math.sqrt((x3-x1)*(x3-x1) + (y3-y1) * (y3-y1));
		s = (side1 + side2 + side3) / 2.0;
		area = Math.sqrt(s * (s - side1) * (s-side2) * (s - side3));
		
		// Rounding
		BigDecimal bd = new BigDecimal(area).setScale(2, RoundingMode.HALF_UP);
		
		// Storing Area into Variable
		area = bd.doubleValue();

		// User Output
		System.out.print("The area of the triangle is " );
		System.out.printf("%.2f", area);
		System.out.print(".");
	}
}
