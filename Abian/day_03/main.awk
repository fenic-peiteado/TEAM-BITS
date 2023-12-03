BEGIN {
  FS="";

  first_line = "";
  middle_line = "";
  last_line = "";
  
  result = 0;
}

func not_has_number_or_dot(string) {
  if (string == "") {
    return 0;
  }

  detected = 0;
  
  for (j = 1; j <= length(string); j++) {
    
    char = substr(string, j, 1);

    if (char !~ /[0-9\.]/) {
      detected = 1;
      break;
    }
  }

  return detected;
}

{
  number = "";

  if (middle_line != "") {
    flag_found = 0;
    
    #print "first_line: " first_line, "middle_line: " middle_line, "last_line: " last_line;
    for (i = 1; i <= length(middle_line); i++) {
      
      char_middle = substr(middle_line, i, 1);
      string_middle = substr(middle_line, i - 1, 3);
      
      if (char_middle !~ /[0-9]/) {
        if (flag_found == 1) {
          result = result + number;
          flag_found = 0;
          
          #print "number: " number, "result: " result;
        }
        
        number = "";
        continue;
      }
      
      if (flag_found == 1) {
        number = number "" char_middle;
        continue;
      } 
      
      string_first = substr(first_line, i - 1, 3);
      string_last = substr(last_line, i - 1, 3);

      number = number "" char_middle;
      
      if (not_has_number_or_dot(string_first) || not_has_number_or_dot(string_last) || not_has_number_or_dot(string_middle)) {
        flag_found = 1;
        continue;
      }
    }

    #print "\n";
  }

  first_line = middle_line;
  middle_line = last_line;
  last_line = $0;
}

END {
  print result;
}
