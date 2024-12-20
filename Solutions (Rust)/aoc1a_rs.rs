use std::io;

fn main(){
    let mut left= Vec::new();
    let mut right= Vec::new();

    for _ in 0..1000{
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let parts: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        left.push(parts[0]);
        right.push(parts[1]);
    }
    left.sort();
    right.sort();
    let mut distance:i32=0;
    for i in 0..1000{
        distance+=(left[i]-right[i]).abs();
    }
    println!("{}",distance);
}
