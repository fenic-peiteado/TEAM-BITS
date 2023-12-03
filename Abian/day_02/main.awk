BEGIN {
  FS = "[:;]+";
  result = 0;
  tmp_number = 0;
  
  red_number = 12;
  green_number = 13;
  blue_number = 14;
  
  flag_color = 0;
}

func get_number(string) {
  match(string, /[0-9]+/);
  return strtonum(substr(string, RSTART, RLENGTH));
}

func correct_color(string) {
    split(string, tmp_array, ",");

    for (j = 1; j <= length(tmp_array); j++) {
      
      if (tmp_array[j] ~ /red/ && get_number(tmp_array[j]) > red_number) {
        tmp_number = 0;
        flag_color = 1;

        break;
      
      } else if (tmp_array[j] ~ /green/ && get_number(tmp_array[j]) > green_number) {
        tmp_number = 0;
        flag_color = 1;

        break;
      
      } else if (tmp_array[j] ~ /blue/ && get_number(tmp_array[j]) > blue_number) {
        tmp_number = 0;
        flag_color = 1;
        
        break;
      }
    }
}

{
  for (i = 1; i <= NF; i++) {
    if ($i ~ /Game [0-9]+/) {
      result += tmp_number; 
      tmp_number = get_number($i);
      flag_color = 0;
      continue;
    }
    
    if (flag_color) {
      continue
    }
    
    correct_color($i);
  }
}

END {
  result += tmp_number;
  print result;
}
