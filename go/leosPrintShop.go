/*
	Name: Taylor Moore
	Program Type: Course Assignment - Programming Languages
	Date: 18 January 2021
	Program Description:
		This program was written to see how much a cutomer owes for copies given the
		prices at Leo's Print Shoppe. The customer must input their name and how 
		many copies they need. Then, the program provides the customer's name and total 
		cost. Prices are dependent on the total number of copies ordered.
*/

package main

import(
	"fmt"
	"bufio"
	"log"
	"os"
	"strconv"
	"strings"
)

func main(){
	// Variable Declarations
	var name string=""
	var copyCost float64=0.0

	// User Input for Name 
	fmt.Println("Welcome to Leo's Print Shoppe!")
	fmt.Println()
	fmt.Print("Enter your name: ")
	reader:=bufio.NewReader(os.Stdin)
	name,err:=reader.ReadString('\n')
	
	// Checking for errors, terminates the program if any are found. 
	if err!=nil{
		log.Fatal(err)
	}

	// User Input for Copies Needed
	fmt.Print("How many copies do you need today? ")
	reader2:=bufio.NewReader(os.Stdin)
	input,err:=reader2.ReadString('\n')
	
	// Checking for errors, terminates the program if any are found. 
	if err!=nil{
		log.Fatal(err)
	}
	input = strings.TrimSpace(input)
	copies,err:=strconv.ParseFloat(input,64)

	// Checking for errors, terminates the program if any are found.
	if err != nil{
		log.Fatal(err)
	}

	// Price Calculations
	if (copies<=200){
		copyCost = 0.10 * copies
	}else{
		copies = copies - 200
		copyCost =(0.05 * copies) + 20.0
	}

	roundedCopyCost := fmt.Sprintf("%.2f",copyCost)

	fmt.Println()
	fmt.Print("Customer Name: ", name)
	fmt.Println("Balance Due: $", roundedCopyCost)
}
