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
	"math"
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

	// Asking the user how many triathletes they want to input.
	fmt.Print("How many triathletes are there? ")
	reader0 := bufio.NewReader(os.Stdin)
	input0,err := reader0.ReadString('\n')
	input0 = strings.TrimSpace(input0)
	numTriathletes,err := strconv.ParseFloat(input0,64)
	
	//Checking for errors.
	if err!=nil{
		log.Fatal(err)
	}
	
	
	fmt.Println()
	
	// Beginning of for loop. 
	for i:=1.0;  i<=numTriathletes; {
		fmt.Print("Athlete #",i,":")
		fmt.Println()
		fmt.Printf("Enter cycling hours: ")
		reader1 := bufio.NewReader(os.Stdin)
		input1,err := reader1.ReadString('\n')
		fmt.Print("Enter running hours: ")
		reader2 := bufio.NewReader(os.Stdin)
		input2,err := reader2.ReadString('\n')
		fmt.Print("Enter swimming hours: ")
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
		weightLoss = totalCalories/3800

		// Output
		fmt.Println("Total calories: ",int(math.Round(totalCalories)))
		fmt.Print("Pounds lost:  ")
		fmt.Printf("%.2f",weightLoss)
		fmt.Println()
		fmt.Println()
		
		// Incrementing
		i++;
		
		//End of for loop
}
}
}
