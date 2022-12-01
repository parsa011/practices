use std::cmp;

fn max_sub_array(nums : Vec<i32>) -> i32
{
	let mut max : i32 = nums[0];
	let mut tot : i32 = nums[0];
	for i in 1..nums.len() {
		tot = cmp::max(nums[i], nums[i] + tot);
		max = cmp::max(max, tot);
	}
	return max;
}

fn main()
{
	println!("{}", max_sub_array(vec![-2,1,-3,4,-1,2,1,-5,4]));
}
