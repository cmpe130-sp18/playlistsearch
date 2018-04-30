

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 2000;

struct Product
{
	char title[100];
	char artist[100];

	Product(const char* a = "", const char* b = "")
	{
		strcpy(title, a);
		strcpy(artist, b);
	}

};
//the hash table class

class HashTable
{
	public:
		HashTable()
		{
			for(int i = 0; i < MAX_SIZE; i++)
			{
				store[i] = NULL;
			}
		}
		void insert(Product p)
		{
			int index = hash(p.title);

			Node* node = new Node;
			node->product = p;
			node->next = store[index];
			store[index] = node;

			cout << "inserted " << p.title << " at " << index <<endl;
		}

		void lookup(const char* title)
		{
			int index = hash(title);

			Node* current = store[index];
			int num = 0;
			while(strcmp(current->product.title, title) != 0 )
			{
				num++;
				current = current -> next;
			}

			cout << "Found " << title << " in slot " << index << ", node " << num << endl;
		}
		int hash(const char* code)
		{
			int value = 0;
			for (unsigned int i = 0; i < strlen(code); i++)
			{
				value = value + (code[i]*code[i]);
			}
			return value % MAX_SIZE;
		}
		void report()
		{
			int max = 0;
			int total = 0;
			int num_filled = 0;

			for(int i = 0; i < MAX_SIZE; i++)
			{
				int size = 0;
				Node* current = store[i];
				while(current)
				{
					size++;
					current = current -> next;
				}
				if(size > 0)
				{
					num_filled++;
					total += size;
				}
				if(size > max)
				{
					max = size;
				}
			}
			cout << "The table has " << total << " elements." << endl;
			cout << num_filled << " lists have data out of " << MAX_SIZE << " total." << endl;
			cout << "The average filled list has " << ((float)total / num_filled) << "elements." << endl;
			cout << "Largest list has " << max << " elements." << endl;
		}
	private:
		struct Node
		{
			Product product;
			Node* next;
		};

		Node* store[MAX_SIZE];

};
int main()
{
	HashTable table;

	table.insert(Product("Brizy", "YG"));
	// (song, artist)
	table.report();

	return 0;
}
