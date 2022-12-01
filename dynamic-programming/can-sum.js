const canSum = (nums, target, memo = {}) => {
	if (target in memo)
		return meom[target];
	if (target === 0) {
		return true;
	}
	if (target < 0)
		return false;
	
	for (let num of nums) {
		const reminder = target - num;
		if (canSum(nums, reminder, memo) === true) {
			memo[target] = true;
			return true;
		}
	}
	memo[target] = false;
	return false;
};

const canSum2 = (nums, target) => {
	if (target === 0)
		return 1;
	if (target < 0)
		return 0;
	let res = 0;
	for (let num in nums) {
		const reminder = target - num;
		res += canSum2(nums, reminder);
	}
	return res;
};

console.log(canSum([5, 3, 4, 7], 13));
console.log(canSum2([5, 3, 4, 7], 7));
