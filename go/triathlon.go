/*
	Name: Taylor Moore
	Program Type: Course Assignment - Programming Languages
	Date: 18 January 2021
	Program Description:
		This Go program calculates the number of calories burned and pounds lost based 
		on the user's response to questions about activities performed during a triathlon.
		After taking the user input, the calculations are displayed. 
*/


package main

import(
	"fmt"
	"bufio"
	"os"
	"log"
	"strconv"
	"strings"
)

func main(){
	// Variable Declarations
	var totalCalories float64
	var cyclingCals float64
	var runningCals float64
	var swimmingCals float64
	var hourCalsCyc float64=225.0
	var hourCalsRun float64=450.0
	var hourCalsSwim float64=275.0

	// User Input Using Readers
	fmt.Print("How many hours have you spent cycling this week? ")
	reader1 := bufio.NewReader(os.Stdin)
	input1,err := reader1.ReadString('\n')
	fmt.Print("How many hours have you spent running this week? ")
	reader2 := bufio.NewReader(os.Stdin)
	input2,err := reader2.ReadString('\n')
	fmt.Print("How many hours have you spent swimming this week? ")
	reader3 := bufio.NewReader(os.Stdin)
	input3,err := reader3.ReadString('\n')

	// Checks for errors and terminates the program if any are found. 
	if err!=nil{
		log.Fatal(err)
	}

	/*
	Trimming space to avoid ParseFloat syntax errors and converting the
	user inputs to the 'float64' variable type rather than the default
	'string' variable type. 
	*/

	input1 = strings.TrimSpace(input1)
	cyclingHours,err:=strconv.ParseFloat(input1,64)
	input2 = strings.TrimSpace(input2)
	runningHours,err:=strconv.ParseFloat(input2,64)
	input3 = strings.TrimSpace(input3)
	swimmingHours,err:=strconv.ParseFloat(input3,64)

	// Checking for errors again.
	if err!=nil{
		log.Fatal(err)
	}

	// Calculations
	cyclingCals = cyclingHours*hourCalsCyc
	runningCals = runningHours* hourCalsRun
	swimmingCals =swimmingHours*hourCalsSwim
	totalCalories = cyclingCals + runningCals + swimmingCals

	
	// Rounding the value for weight loss to 2 decimal points. 
	roundedWeightLoss:=fmt.Sprintf("%.2f",(totalCalories/3800))

	// Output
	fmt.Println()
	fmt.Println("Calories burned this week: ", totalCalories)
	fmt.Println("Total pounds lost this week: ",roundedWeightLoss)
}

