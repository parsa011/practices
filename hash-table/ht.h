#ifndef _HASH_TABLE_H
# define _HASH_TABLE_H
/*
*	ngc programming language
*	Copyright
*		(C) 2022 Parsa Mahmoudy Sahebi
*
*	This file is part of ngc languge (new generation c)
*
*	Implement Hash Table
*/


#define TABLE_MAX_LOAD 0.75


typedef struct ht_entry_t ht_entry;
typedef struct ht_entry_key_t ht_entry_key;
typedef struct ht_table_t ht_table;

struct ht_entry_key_t {
	const char *key;
	const uint32_t hash;
}

/*
 * Hash table entry
 */
struct ht_entry_t{
	ht_entry_key key;
	Value value;
	ht_entry *next;
	/* Do not use this fields Directly
	 */
	ht_table *_table;
};

/*
 *	Hash Table struct that hold entries
 */
struct ht_table_t {
	int capacity;
	int count;
	ht_entry *entries;
};

/*
 *	@brief : Give pointer of a table then initialize it
 *	Every table that wanted to be used should be initialized first with this funtion
 */
void ht_init_table(ht_table *table);

/*
 *	@brief : Free Given table with it entries (All entries)
 */
void ht_free_table(ht_table *tablbe);

/*
 *	@brief : Increase given table size and transfer its entries to new entries that allocated
 *  But do not transer 'tombstones'
 */
void ht_adjust_table_capacity(ht_table *table, int capacity);

/*
 *	@brief : Insert given value to Hash table , return true new entry inserted int
 *  Empty bucket , false if bucker was tombstone
 */
bool ht_entry_insert(ht_table *table, Value value, ht_entry_key *key);

/*
 *	@brief : Return entry that has same key as given key , in given table
 *	Or Return NULL
 */
ht_entry *ht_entry_find(ht_table *table, int capacity, const char *key);

#endif
