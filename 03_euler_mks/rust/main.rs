fn multiples_15() -> u32 {
    let mut x = 2;
    let mut result = 0;
    while x < 1000 {
        if x % 5 == 0 || x % 3 == 0 {
            result += x;
        }
        x += 1;
    }
    return result;
}

fn smallest_multiple() -> u32 {
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

fn sum_square_difference() -> i32 {
    let mut result: i32 = 0;
    let mut num: i32 = 1;
    while num < 101 {
       result += num.pow(3) - num.pow(2);
       num += 1;
    }
    return result;
}

pub fn main() {
    println!("{}", multiples_15());
    println!("{}", smallest_multiple());
    println!("{}", sum_square_difference());
}
