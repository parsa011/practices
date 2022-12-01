// This Hash Table is for NGC project
// It need some enhancement to be used in someother project
// some pieces are missed , those pieces are needed , like :
//		GROW_CAPACITY macro and prerequistics
//		copy_value() function
#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : (capacity) * 2)

void ht_init_table(ht_table *table)
{
	table->count = 0;
	table->capacity = 0;
	table->entries = NULL;
}

void ht_free_table(ht_table *table)
{
}

bool ht_entry_insert(ht_table *table, Value value, ht_entry_key *key)
{
	if (table->count + 1 > table->capacity + TABLE_MAX_LOAD) {
		int capacity = GROW_CAPACITY(table->capacity);
		ht_adjust_table_capacity(table, capacity);
	}
	ht_entry *entry = ht_entry_find(table->entries, table->capacity, key);

	bool is_new_key = entry->key.key == NULL;
	if (is_new_key && IS_NULL_VALUE(entry->value))
		table->count++;

	entry->key = key;
	entry->value = value;
	return is_new_key;
}

ht_entry *ht_table_find(ht_table *table, int capacity, ht_entry_key *key)
{
	uint32_t index = key->hash % capacity;
	Entry *tombstone = NULL;

	for (;;) {
		Entry *entry = &entries[index]; 

		if (entry->key == NULL) {
			if (IS_NULL_VALUE(entry->value)) {
				// Empty entry.
				return tombstone != NULL ? tombstone : entry;
			} else {
				// We found a tombstone.
				if (tombstone == NULL) tombstone = entry;
			}
		} else if (entry->key == key) {
			// We found the key.
			return entry;
		}

		index = (index + 1) % capacity;
	}
}

int main(int argc, char **argv)
{
	ht_table strings;
	ht_init_table(&strings);
	printf("%d\n", strings.count);
	printf("I'm Working!\n");
	return 0;
}
