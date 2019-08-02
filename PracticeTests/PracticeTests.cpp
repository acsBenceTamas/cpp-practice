#include "pch.h"
#include "CppUnitTest.h"
#include "../cpp-practice/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PracticeTests
{
	static LinkedList* ll;

	TEST_CLASS(LinkedListTests)
	{
	public:
		TEST_METHOD_INITIALIZE(Setup) 
		{
			ll = new LinkedList();
		}

		TEST_METHOD_CLEANUP(Cleanup)
		{
			delete ll;
		}
		
		TEST_METHOD(Add_AddingAnElement_ProperlyIncreasesLength)
		{
			ll->Add(1);
			int result = ll->GetLength();
			int expected = 1;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(AddToEnd_AddingAnElement_ProperlyPlacesElementAtTheEnd)
		{
			ll->Add(1);
			ll->AddToEnd(2);
			int result = ll->GetLast();
			int expected = 2;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(AddToStart_AddingAnElement_ProperlyPlacesElementAtTheStart)
		{
			ll->Add(1);
			ll->AddToStart(2);
			int result = ll->GetFirst();
			int expected = 2;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Insert_InsertingToIndex0_AddsToStart)
		{
			ll->Insert(1, 0);
			int result = ll->GetFirst();
			int expected = 1;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Insert_InsertingToIndexOfLength_AddsToEnd)
		{
			ll->Add(1);
			ll->Add(2);
			ll->Add(3);
			ll->Insert(5, ll->GetLength());
			int result = ll->GetLast();
			int expected = 5;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Insert_InsertingToIndexInMiddle_AddsToIndex)
		{
			ll->Add(1);
			ll->Add(2);
			ll->Add(3);
			ll->Insert(5, 1);
			int result = ll->Get(1);
			int expected = 5;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Get_GettingWithValidIndex_ReturnsValue)
		{
			ll->Add(1);
			ll->Add(2);
			ll->Add(3);

			Assert::AreEqual(1, ll->Get(0));
			Assert::AreEqual(2, ll->Get(1));
			Assert::AreEqual(3, ll->Get(2));
		}

		TEST_METHOD(Get_IndexSmallerThan0_ThrowsIndexOutOfBoundsException)
		{
			ll->Add(1);

			Assert::ExpectException<LinkedList::OutOfRangeException>([] {ll->Get(-1);});
		}

		TEST_METHOD(Remove_IfListIsNotEmpty_RemovesElement)
		{
			ll->Add(1);
			ll->Add(2);
			ll->Add(3);

			ll->Remove(1);

			int result = ll->Get(1);
			int expected = 3;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Remove_IfListIsEmpty_ThrowsListIsEmptyException)
		{
			Assert::ExpectException<LinkedList::ListIsEmptyException>([] {ll->Remove(0);});
		}

		TEST_METHOD(RemoveFirst_IfListIsEmpty_ThrowsListIsEmptyException)
		{
			Assert::ExpectException<LinkedList::ListIsEmptyException>([] {ll->RemoveFirst();});
		}

		TEST_METHOD(RemoveFirst_IfListIsNotEmpty_RemovesFirstElement)
		{
			ll->Add(1);
			ll->Add(2);

			ll->RemoveFirst();

			int result = ll->GetFirst();
			int expected = 2;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(RemoveFirst_IfListIsNotEmpty_LengthDecreasesProperly)
		{
			ll->Add(1);
			ll->Add(2);

			ll->RemoveFirst();

			int result = ll->GetLength();
			int expected = 1;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(RemoveLast_IfListIsNotEmpty_RemovesLastElement)
		{
			ll->Add(1);
			ll->Add(2);

			ll->RemoveLast();

			int result = ll->GetLast();
			int expected = 1;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(RemoveLast_IfListIsEmpty_ThrowsListIsEmptyException)
		{
			Assert::ExpectException<LinkedList::ListIsEmptyException>([] {ll->RemoveLast();});
		}

		TEST_METHOD(RemoveLast_IfListIsNotEmpty_LengthDecreasesProperly)
		{
			ll->Add(1);
			ll->Add(2);

			ll->RemoveLast();

			int result = ll->GetLength();
			int expected = 1;

			Assert::AreEqual(expected, result);
		}
		private:
	};
}
