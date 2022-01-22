#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_lcs(char *s1,char *s2)
{
	int res = 0;
	int s1_bigger = strlen(s1) > strlen(s2);
	char *longer = s1_bigger ? s1 : s2,*less = !s1_bigger ? s1 : s2;
	int temp = 0;
	while (*longer) {
		if (tolower(*longer++) == tolower(*less++))
			temp++;
		else {
			res += temp;
			temp = 0;
		}
	}
	if (temp > 0)
    	res += temp;
	return res;
}

float calc(char *s1,char *s2)
{
	int lcs = get_lcs(s1,s2);
	return lcs * 2.0f / (strlen(s1) + strlen(s2));
}

int main()
{
	char* names1[] = {"Johnson", "Adams", "Davis", "Simons", "Richards", "Taylor", "Carter", "Stevenson", "Taylor", 
		"Smith", "McDonald", "Harris", "Sim", "Williams", "Baker", "Wells", "Fraser", "Jones", "Wilks", "Hunt", "Sanders", "Parsons", "Robson", "Harker"};

	char* names2[] = {"Jonson", "Addams", "Davies", "Simmons", "Richardson", "Tailor", "Chater", "Stephenson", 
		"Naylor", "Smythe", "MacDonald", "Harrys", "Sym", "Wilson", "Barker", "Wills", "Frazer", "Johns", "Wilkinson", "Hunter", "Saunders", "Pearson", "Robertson", "Parker"};

	int namecount = sizeof(names1) / sizeof(names1[0]);

	for (int i = 0; i < namecount; i++) {
		int matched = -1;
		float last_precent = 0;
		for (int j = 0; j < namecount; j++) {
			float temp = calc(names1[i],names2[j]);
			if (temp > last_precent) {
				matched = j;
				last_precent = temp;
			}	
			
		}
		if (matched >= 0) {
			printf("%s with %s\n",names1[i],names2[matched]);
			matched = -1;
		}
	}
	return 0;
}
