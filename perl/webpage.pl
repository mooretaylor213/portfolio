#!/usr/bin/perl
print "Content-Type: Text/html\n\n";
$str = $ENV{QUERY_STRING};
($s1,$s2) = split(/&/, $str);
($dummy,$amount) = split(/=/,$s1);
($dummy,$currency) = split(/=/,$s2);

  	 if ($currency eq "P")
	 {
  	 $converted = ($amount * 0.65);
	 }
  	 if ($currency eq "E")
	 {
   	 $converted = ($amount * 0.83);
         }
  	 if ($currency eq "M")
   	 {
   	 $converted = ($amount * 20.12);
   	 }
   	 if ($currency eq "C")
   	 {
   	 $converted = ($amount * 1.28);
   	 }
	 $converted = sprintf("%.2f",$converted);

print "<!DOCTYPE html>\n";
print "<html lang =\"en\">\n";
print "<head>\n";
print " <meta charset=\"UTF-8\">\n";
print " <link rel=\"stylesheet\"href=\"styles.css\" type=\"text/css\">\n";
print " <title>Currency Conversion</title>\n";
print "</head>\n";
print "<body>\n";
print "<h1>Currency Conversion</h1>\n";
print "<h2>Amount Entered: \$ $amount </h2>\n";
print "<h2>Converted Amount: \$ $converted </h2>\n";
print "</body>\n";
print "</html>\n";
