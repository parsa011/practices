#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * From : https://benhoyt.com/writings/hash-table-in-c
 */

// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct ht ht;

// Create hash table and return pointer to it, or NULL if out of memory.
ht *ht_create(void);

// Free memory allocated for hash table, including allocated keys.
void ht_destroy(ht *table);

// Get item with given key (NUL-terminated) from hash table. Return
// value (which was set with ht_set), or NULL if key not found.
void *ht_get(ht *table, const char *key);

// Set item with given key (NUL-terminated) to value (which must not
// be NULL). If not already present in table, key is copied to newly
// allocated memory (keys are freed automatically when ht_destroy is
// called). Return address of copied key, or NULL if out of memory.
const char *ht_set(ht *table, const char *key, void *value);

// Return number of items in hash table
size_t ht_length(ht *table);

typedef struct {
  const char *key;
  void *value;

  // Don't use these fields directly.
  ht *_table;
  size_t _index;
} hti;

// Return new hash table iterator (for use with ht_next).
hti ht_iterator(ht *table);

// Move iterator to next item in hash table, updatex iterator's key
// and value to current item, and return true. If there are no more
// items, return false. Don't call ht_set during iteration.
bool ht_next(hti* it);


// Hash table entry (slot may be filled or empty).
typedef struct {
  const char *key;
  void *value;
} ht_entry;

struct ht {
  ht_entry *entries;
  size_t capacity;
  size_t length;
};


#define INITIAL_CAPACITY 16

ht *ht_create()
{
  ht *table = malloc(sizeof(ht));
  if (table == NULL)
    return table;

  table->length = 0;
  table->capacity = INITIAL_CAPACITY;

  table->entries = calloc(table->capacity, sizeof(ht_entry));

  if (table->entries == NULL) {
    free(table);
    return NULL;
  }
  return table;
}

void ht_destroy(ht *table)
{
  for (size_t i = 0; i < table->capacity; i++) {
    free((void *) table->entries[i].key);
  }
  free(table->entries);
  free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t has_key(const char *key)
{
  utin64_t hash = FNV_OFFSET;
  for (const char *p = key; *p; p++) {
    hash ^= (uint64_t)(unsigned int)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
}

// Demo program
void exit_nomem(void)
{
    fprintf(stderr, "out of memory\n");
    exit(1);
}

int main(void)
{
    ht* counts = ht_create();
    if (counts == NULL) {
        exit_nomem();
    }

    // Read next word from stdin (at most 100 chars long).
    char word[101];
    while (scanf("%100s", word) != EOF) {
        // Look up word.
        void* value = ht_get(counts, word);
        if (value != NULL) {
            // Already exists, increment int that value points to.
            int* pcount = (int*)value;
            (*pcount)++;
            continue;
        }

        // Word not found, allocate space for new int and set to 1.
        int* pcount = malloc(sizeof(int));
        if (pcount == NULL) {
            exit_nomem();
        }
        *pcount = 1;
        if (ht_set(counts, word, pcount) == NULL) {
            exit_nomem();
        }
    }

    // Print out words and frequencies, freeing values as we go.
    hti it = ht_iterator(counts);
    while (ht_next(&it)) {
        printf("%s %d\n", it.key, *(int*)it.value);
        free(it.value);
    }

    // Show the number of unique words.
    printf("%d\n", (int)ht_length(counts));

    ht_destroy(counts);
    return 0;
}
