#include<bits/stdc++.h>
using namespace std;
string message;
string sequence;
vector<int> Rand_array;
map<int, string> sequences;
vector<string> particular_sequence;
vector<int>together;
vector<int> skip_array;
string skip_1;
void input()
{
	cout << "Input message to be incrypted: ";
	getline (cin, message);
	cout << message;
}
void solve(int idx, vector<int>&Rand_array, vector<vector<int>>&result)
{
	if (idx == Rand_array.size())
	{
		result.push_back(Rand_array);
		return;
	}
	for (int i = idx; i < Rand_array.size(); i++)
	{
		swap(Rand_array[idx], Rand_array[i]);
		solve(idx + 1, Rand_array, result);
		swap(Rand_array[idx], Rand_array[i]);
	}

}
int  PM(vector<int>& Rand_array) {

	vector<vector<int>>result;
	solve(0, Rand_array, result);
	return result.size();
}

int S3()
{

	vector<int>triplet;
	vector<vector<int>>total_triplets;
	int sum = 0;
	int j = 0, k = 0;
	bool flag = false;
	sort(Rand_array.begin(), Rand_array.end());//-4,-1,-1,0,1,
	for (int i = 0; i < Rand_array.size(); i++)
	{

		j = i + 1;
		k = Rand_array.size() - 1;
		while (j < k) {
			if (Rand_array[i] + Rand_array[j] + Rand_array[k] == 0)
			{
				triplet.push_back(Rand_array[i]);
				triplet.push_back(Rand_array[j]);
				triplet.push_back(Rand_array[k]);
				total_triplets.push_back(triplet);
				triplet.pop_back();
				triplet.pop_back();
				triplet.pop_back();
				j++;
				k--;

			}
			if (Rand_array[i] + Rand_array[j] + Rand_array[k] > 0)
			{
				k--;
			}
			else
			{
				j++;
			}
		}
	}

	return total_triplets.size();
}
int maxSubArray() {
// either add or start a new array
	int max_sum = Rand_array[0];
	int current_sum = Rand_array[0];
	int current_element;
	if (Rand_array.size() == 1)
	{
		max_sum = Rand_array[0];
	}
	else {
		for (int i = 1; i < Rand_array.size(); i++)
		{
			current_sum = max(Rand_array[i], current_sum + Rand_array[i]);
			max_sum = max(current_sum, max_sum);

		}

	}
	return max_sum;
}
int LIS() {
	int max_value = 0;
	int*dp = new int[Rand_array.size()];
	for (int i = 0; i < Rand_array.size(); i++)
	{ dp[i] = 1;}




	for (int i = 1; i < Rand_array.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Rand_array[i] > Rand_array[j] && dp[i] < dp[j] + 1)
			{
				dp[i] += 1;


			}


		}
	}

	for (int i = 0; i < Rand_array.size(); i++)
	{
		max_value = max(max_value, dp[i]);


	}
	return max_value;
}
void decryption()
{
	cout<<endl;
	cout<<"Decrypted message:"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<message<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
int minSubarray(vector<int>& nums, int p) {
	int n = nums.size();
	vector<long> acc_sum(n, (long)nums.front()), acc_mod(n, nums.front() % p);
	unordered_map<int, set<int>> acc_mod_to_index;
	for (int i = 1; i < n; i++) {
		acc_sum[i] = acc_sum[i - 1] + nums[i];
		int mod = acc_sum[i] % p;
		acc_mod[i] = mod;
		if (acc_mod_to_index.count(mod) == 0) {acc_mod_to_index.insert({mod, {i}});}
		else {acc_mod_to_index[mod].insert(i);}
	}
	if (acc_sum.back() < p) {return -1;}
	int target_mod = acc_sum.back() % p;
	if (target_mod == 0) {return 0;}
	// printf("target_mod=%d\n", target_mod);
	int expect_back_acc_mod, min_remove = INT_MAX;
	for (int start = 0; start < n; start++) {

		if (nums[start] == target_mod) {return 1;}

		if (start == 0) { expect_back_acc_mod = target_mod % p;}
		else {expect_back_acc_mod = (acc_mod[start - 1] + target_mod) % p;}

		if (acc_mod_to_index.count(expect_back_acc_mod) == 1) {
			auto it = acc_mod_to_index[expect_back_acc_mod].lower_bound(start);
			if (it != acc_mod_to_index[expect_back_acc_mod].end()) {
				int remove = *it - start + 1;
				min_remove = min(min_remove, remove);
			}
		}
	}
	if (min_remove == INT_MAX || min_remove == nums.size()) {return -1;}
	return min_remove;
}
int findLengthOfShortestSubarray(vector<int>& arr) {
	int i, j, len = arr.size();
	int p = 0, q = arr.size() - 1;
	for (i = 0; i < arr.size() - 1; i++) {
		if (arr[i] <= arr[i + 1]) {
			p++;
		}
		else {
			break;
		}
	}
	for (i = arr.size() - 1; i >= 1; i--) {
		if (arr[i] >= arr[i - 1]) {
			q--;
		}
		else {
			break;
		}
	}
	if (q < p) {
		return 0;
	}

	int ans = min((int)arr.size() - p - 1, q);

	int x = q;
	while (x < arr.size() && arr[x] <= arr[p]) {
		x++;
	}
	ans = min(ans, x - p - 1);

	while (p > 0) {
		p--;
		while (x - 1 >= q && arr[x - 1] >= arr[p]) {
			x--;
		}
		ans = min(ans, x - p - 1);
	}
	return ans;
}
void skip2()
{
	
	string result = "";

	// traverse message
	for (int i = 0; i < message.length(); i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(message[i]))
			result += char(int(message[i] + 6 - 65) % 26 + 65);

		// Encrypt Lowercase letters
		else
			result += char(int(message[i] + 6 - 97) % 26 + 97);
	}
cout<<endl;
	cout<<"Skip 2 encryption: ";
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
	}
}

void skip1()
{
	
	string result = "";

	// traverse message
	for (int i = 0; i < message.length(); i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(message[i]))
			result += char(int(message[i] + 3 - 65) % 26 + 65);

		// Encrypt Lowercase letters
		else
			result += char(int(message[i] + 3 - 97) % 26 + 97);
	}
cout<<endl;
	cout<<"Skip 1 encryption: ";
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
	}
skip2();
}

void function_calls()
{

	srand((unsigned) time(0));
	int number;
	for (int i = 0; i < 4; i++)
	{
		number = (rand() % 50) + 1;
		skip_array.push_back(number);
	}
	cout << endl;
	cout << " Skip Array : [";
	for (int i = 0; i < skip_array.size(); i++)
	{
		cout << skip_array[i] << " ";
	}
	cout << "]";

	skip1();
}
















void generate()
{
	//GENERATING NUMBER OF ELEMENTS IN Rand_array
	srand((unsigned) time(0));
	int randomNumber;
	randomNumber = (rand() % 6) + 4;
	cout << "Number of elements in Rand_array : " << randomNumber << endl;

// Generating the Rand_array


	srand((unsigned) time(0));
	int number;
	for (int i = 0; i < randomNumber; i++)
	{
		number = (rand() % 50) + 1;
		Rand_array.push_back(number);
	}
	cout << "Array generated : [ ";
	for (int i = 0; i < Rand_array.size(); i++)
	{
		cout << Rand_array[i] << " ";
	}
	cout << "]";
// generating the sequence map and together array
	sequences.insert({1, "PM"});
	sequences.insert({2, "MSCS"});
	sequences.insert({3, "3S"});
	sequences.insert({4, "MS"});
	sequences.insert({5, "LIS"});
	sequences.insert({6, "KDP"});
	sequences.insert({7, "SDP"});
	sequences.insert({8, "RSB"});
	sequences.insert({9, "SRS"});

	for (int i = 0; i < 4; i++)
	{
		int trans = (rand() % 9) + 1;
		together.push_back(sequences[trans].size());
		particular_sequence.push_back(sequences[trans]);
	}
	cout << endl;
	cout << "Together sequence : [";
	for (int i = 0; i < together.size(); i++)
	{
		cout << together[i] << " ";
	}
	cout << "]" << endl;
	cout << "Operation sequence : [ ";
	for (int i = 0; i < particular_sequence.size(); i++)
	{
		cout << particular_sequence[i];
	}
	cout << "]";

	function_calls();

}


int main()
{
	// input();
	cout<<endl;
	message = "Apoorva";
	cout << " Message to be encrypted : " << message;
	cout << endl;
	generate();
	decryption();

}
