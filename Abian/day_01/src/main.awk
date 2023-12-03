BEGIN {
  FS = "\n";
  result = 0;
  
  numbers[1] = "one";
  numbers[2] = "two";
  numbers[3] = "three";
  numbers[4] = "four";
  numbers[5] = "five";
  numbers[6] = "six";
  numbers[7] = "seven";
  numbers[8] = "eight";
  numbers[9] = "nine";
}

func is_number(string) {
  return string ~ /[0-9]+/;
}

{
  for (i = 1; i <= NF; i++) { 
    converted = "";
    
    for (k = 1; k <= length($i); k++) {
      string = substr($i, k);
      char = substr($i, k, 1);

      if (is_number(char)) {
        converted = converted "" char;
        continue;
      }

      for (j = 1; j <= 9; j++) {
        if (index(string, numbers[j]) == 1) {
          converted = converted "" j;
        }
      } 
    }
    
    result_string = substr(converted, 1, 1) "" substr(converted, length(converted));
    result += result_string;
  }
}

END {
  print(result);
}
