use std::io;

fn main() {
    let mut left= Vec::new();
    let mut right= Vec::new();

    for _ in 0..1000{
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let parts: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        left.push(parts[0]);
        right.push(parts[1]);
    }
    let mut simscore=0;
    for &leftnum in &left {
        let mut count=0;
        for &rightnum in &right{
            if leftnum==rightnum {
                count+=1;
            }
        }
        simscore+=leftnum*count;
    }

    println!("{}", simscore);
}
