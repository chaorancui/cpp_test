# print_array
define print_array
    set $i = 0
    while $i < $arg0
        print array[$i]
        set $i = $i + 1
    end
end

document print_array
Prints the first n elements of the global array 'array'
Usage: print_array n
end