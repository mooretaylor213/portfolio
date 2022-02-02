/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Advanced Object Oriented Programming
 * Date: June 7, 2020
 * Program Description:
 * 	Program prompts a user to input the year, month, and day of the month.
 * 	The program then implements Zeller's congruence algorithm to calculate
 * 	the day of the week associated with the user-entered date.
*/


package taymoore;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class DayOfTheWeek {

	private static Scanner date;

	public static void main(String[] args) {

		// Initializing Scanner and Variables
		date = new Scanner(System.in);
		int year, month, dayOfMonth, dayOfWeek, yearCent, zeroCent;
		
		// User Input

		System.out.print("Enter the year (e.g., 2020): ");
		year = date.nextInt();
		System.out.print("Enter the month (i.e., 1-12): ");
		month = date.nextInt();
		System.out.print("Enter the day of the month (i.e., 1-31): ");
		dayOfMonth = date.nextInt();
	
		// Calculations
		if(month == 1) {
	   		month = 13;
	   		year--;
		}
		
		if(month == 2) {
	   		month = 14;
	  		year--;
		}	

		yearCent = year % 100;
		zeroCent = year / 100;
		dayOfWeek = ((dayOfMonth+26*(month+1)/10+yearCent+yearCent/4+zeroCent/4+5*zeroCent)%7);
	

		// Conditions Regarding Program Output
		if (dayOfWeek == 0) {
			System.out.print("Day of the week is Saturday.");
		}
		else if (dayOfWeek == 1) {
			System.out.print("Day of the week is Sunday.");
		}
		else if (dayOfWeek == 2) {
			System.out.print("Day of the week is Monday.");
		}	
		else if (dayOfWeek == 3) {
			System.out.print("Day of the week is Tuesday.");
		}
		else if (dayOfWeek == 4) {
			System.out.print("Day of the week is Wednesday.");
		}
		else if (dayOfWeek == 5) {
			System.out.print("Day of the week is Thursday.");
		}
		else if (dayOfWeek == 6) {
			System.out.print("Day of the week is Friday.");
		}
	}
}
