
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;

const int TABLE_SIZE = 10;

class HashEntry
{
	public:
		int key;
		int value;
		HashEntry(int key, int value)
		{
			this->key = key;
			this->value = value;
		}
};

class HashMap
{
	private:
		HashEntry **table;
	public:
		HashMap()
		{
			 table = new HashEntry * [TABLE_SIZE];
			 for ( int i = 0; i < TABLE_SIZE; i++)
			 {
				 table[i] = NULL;
			 }
		}
		int HashFunc(int key)
		{
			return key % TABLE_SIZE;
		}
		void Insert(int key, int value)
		{
			int hash = HashFunc(key);
			while(table[hash] != NULL && table[hash]->key != key)
			{
				hash = HashFunc(hash + 1);
			}
			if(table[hash] != NULL)
			{
				delete table[hash];
			}
			table[hash] = new HashEntry(key, value);
		}
		int Search(int key)
		{
			int hash = HashFunc(key);
			while(table[hash] != NULL && table[hash]->key != key)
			{
				hash = HashFunc(hash + 1);
			}
			if(table[hash]==NULL)
				return -1;
			else
				return table[hash]->value;
		}
		void Remove(int key)
		{
			int hash = HashFunc(key);
			while(table[hash] != NULL)
			{
				if (table[hash]->key == key)
					break;
				hash = HashFunc(hash + 1);
			}
			if(table[hash] ==NULL)
			{
				cout << "No Element" << key << endl;
			}
			else{
				delete table[hash];
			}
			cout << "Element Deleted" << endl;
		}
		void print()
		{
			for ( int i = 0; i < TABLE_SIZE; i++)
			{
				if(table[i] != false)
				{
					cout << i << endl;
				}
			}
		}
		~HashMap()
		{
			for(int i = 0 ; i <  TABLE_SIZE; i++)
			{
				if(table[i] != NULL)
					delete table[i];
				delete[] table;
			}
		}
};

int main()
{
	HashMap hash;
	hash.Insert(5,2);
	hash.Insert(4,10);
	hash.Insert(3,10);

	hash.print();
}

