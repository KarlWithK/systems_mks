// I actually don't this moduler approach for rust
pub fn multiples_15() -> u32 {
    let mut result = 0;
    for x in 2..1000 {
        if x % 5 == 0 || x % 3 == 0 {
           result += x; 
        }
    }
    return result;
}

pub fn smallest_multiple() -> u32 {
    let mut current_num: u8 = 11;
    let mut num: u32 = 2520;
    let mut fix: u32 = 2520;
    while current_num < 21 {
        if num % current_num as u32 == 0 {
            fix = num;
            current_num += 1;
        } else {
            num += fix;
        }
    }
    return num;
}

pub fn sum_square_difference() -> i32 {
    let mut result: i32 = 0;
    for num in 1i32..101 {
       result += num.pow(3) - num.pow(2); 
    }
    return result;
}
