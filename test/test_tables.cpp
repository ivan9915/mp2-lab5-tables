#include <gtest.h>
#include <Table.h>

TEST(Utable, can_create_sort_table)
{
	ASSERT_NO_THROW(unsortedTable<double> T);
}

TEST(Stable, can_create_unsort_table)
{
	ASSERT_NO_THROW(sortedTable<double> T);
}

TEST(Htable, can_create_hash_table)
{
	ASSERT_NO_THROW(hashTable<double> T);
}


TEST(table, can_insert_in_UTable)
{
	unsortedTable<double> T;
	List<double> L;
	L.insert(123, 12);
	ASSERT_NO_THROW(T.inseart(L));
}

TEST(table, can_insert_in_STable)
{
	sortedTable<double> T;
	List<double> L;
	L.insert(123, 12);
	ASSERT_NO_THROW(T.inseart(L));
}

TEST(table, can_insert_in_HTable)
{
	hashTable<double> T;
	List<double> L;
	L.insert(123, 12);
	ASSERT_NO_THROW(T.inseart(L));
}

TEST(table, correct_insert_in_STable_1)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	EXPECT_EQ(T.polinoms[0].head->power, 111);
}

TEST(table, correct_insert_in_STable_2)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);

	T.inseart(L1);
	T.inseart(L1);
	EXPECT_EQ(T.rightBorder, 0);
}

TEST(table, correct_insert_in_UTable)
{
	unsortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	T.inseart(L1);
	T.inseart(L1);

	EXPECT_EQ(T.rightBorder, 0);
}

TEST(table, correct_clear_UTable)
{
	unsortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	T.clrTable();
	EXPECT_EQ(T.rightBorder, -1);
}

TEST(table, correct_clear_STable)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	T.clrTable();
	EXPECT_EQ(T.rightBorder, -1);
}

TEST(table, correct_clear_HTable)
{
	hashTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	T.clrTable();
	EXPECT_EQ(T.polinoms[0].head, nullptr);
}


TEST(table, correct_search_UTable_1)
{
	unsortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	EXPECT_EQ(T.search(L1), 0);
}

TEST(table, correct_search_UTable_2)
{
	unsortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	EXPECT_EQ(T.search(L2), -1);
}

TEST(table, correct_search_STable_1)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	T.inseart(L2);
	EXPECT_EQ(T.search(L1), 1);
}
TEST(table, correct_search_STable_2)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	List<double> L2;
	L2.insert(111, 12);
	T.inseart(L1);
	EXPECT_EQ(T.search(L2), -1);
}


TEST(table, correct_search_HTable_1)
{
	hashTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	T.inseart(L1);
	EXPECT_EQ(T.search(L1),1);
}

TEST(table, correct_search_HTable_2)
{
	hashTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	
	EXPECT_EQ(T.search(L1), -1);
}

TEST(table, correct_del_UTable)
{
	unsortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	T.inseart(L1);
	T.del(L1);
	EXPECT_EQ(T.search(L1), -1);
}

TEST(table, correct_del_STable)
{
	sortedTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	T.inseart(L1);
	T.del(L1);
	EXPECT_EQ(T.search(L1), -1);
}

TEST(table, correct_del_HTable)
{
	hashTable<double> T;
	List<double> L1;
	L1.insert(123, 12);
	T.inseart(L1);
	T.del(L1);
	EXPECT_EQ(T.search(L1), -1);
}