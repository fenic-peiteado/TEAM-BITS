BEGIN {
  FS = "[:;]+";
  result = 0;
  
  red_number = 0;
  green_number = 0;
  blue_number = 0;  
}

func get_number(string) {
  match(string, /[0-9]+/);
  return strtonum(substr(string, RSTART, RLENGTH));
}

func heigher_color(string) {
  split(string, tmp_array, ",");

  for (j = 1; j <= length(tmp_array); j++) {
    
    if (tmp_array[j] ~ /red/ && get_number(tmp_array[j]) > red_number) {
      red_number = get_number(tmp_array[j]);
    
    } else if (tmp_array[j] ~ /green/ && get_number(tmp_array[j]) > green_number) {
      green_number = get_number(tmp_array[j]);
    
    } else if (tmp_array[j] ~ /blue/ && get_number(tmp_array[j]) > blue_number) {
      blue_number = get_number(tmp_array[j]);
    
    }
  }
}

{
  for (i = 1; i <= NF; i++) {
    if ($i ~ /Game [0-9]+/) {
      result += red_number * green_number * blue_number;
      red_number = 0;
      green_number = 0;
      blue_number = 0;

      continue;
    } 
    
    heigher_color($i);
  }
}

END {
  result += red_number * green_number * blue_number;
  print result;
}
