pub fn main() {
    let mut x = 42i32;
    x += 1;
    let greeting = "what is sup";
    let t = (13, false);
    let a = 13u8;
    let b = 8u32;
    let c = a as u32 + b;
    let nums: [i64; 4] = [1, 2, 3, 4];
    println!("{:?}", nums);
    println!("{1} {0}", x, greeting);
    println!("Life is {}", t.1);
    println!("{}", c);
}
