// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void BarSeparatorMultiStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

  static void NullSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('\0'), std::string(""));
  }

  static void NullSeparatorMultiStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    ASSERT_EQ(tm.Print('\0'), std::string("ABC"));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    BarSeparatorMultiStringTest();

    NullSeparatorTest();
    NullSeparatorMultiStringTest();
  }
};

class HomeEndTestSuite
{
private:
  static void HomeKeyFromEmptyStringTest() {
    TypingMachine tm;
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void HomeKeyFromSingleStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|A"));
  }

  static void HomeKeyFromMultiStringAtTailTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
  }

  static void HomeKeyFromMultiStringAtHeadTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    tm.LeftKey();
    tm.LeftKey();
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
  }

  static void HomeKeyFromMultiStringAtMidTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
  }

  static void EndKeyFromEmptyStringTest() {
    TypingMachine tm;
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void EndKeyFromSingleStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
  }

  static void EndKeyFromMultiStringAtTailTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

  static void EndKeyFromMultiStringAtHeadTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    tm.LeftKey();
    tm.LeftKey();
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

  static void EndKeyFromMultiStringAtMidTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

public:
  static void RunTest() {
    HomeKeyFromEmptyStringTest();
    HomeKeyFromSingleStringTest();
    HomeKeyFromMultiStringAtTailTest();
    HomeKeyFromMultiStringAtHeadTest();
    HomeKeyFromMultiStringAtMidTest();

    EndKeyFromEmptyStringTest();
    EndKeyFromSingleStringTest();
    EndKeyFromMultiStringAtTailTest();
    EndKeyFromMultiStringAtHeadTest();
    EndKeyFromMultiStringAtMidTest();
  }
};

class ArrowTestSuite
{
private:
  static void LeftKeyFromEmptyStringTest() {
    TypingMachine tm;
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void LeftKeyFromSingleStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|A"));
  }

  static void LeftKeyFromMultiStringAtTailTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("AB|C"));
  }

  static void LeftKeyFromMultiStringAtHeadTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.HomeKey();
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
  }

  static void LeftKeyFromMultiStringAtMidTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("A|BC"));
  }

  static void RightKeyFromEmptyStringTest() {
    TypingMachine tm;
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void RightKeyFromSingleStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
  }

  static void RightKeyFromMultiStringAtTailTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

  static void RightKeyFromMultiStringAtHeadTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.HomeKey();
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("A|BC"));
  }

  static void RightKeyFromMultiStringAtMidTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.HomeKey();
    tm.RightKey();
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("AB|C"));
  }
public:
  static void RunTest() {
    LeftKeyFromEmptyStringTest();
    LeftKeyFromSingleStringTest();
    LeftKeyFromMultiStringAtTailTest();
    LeftKeyFromMultiStringAtHeadTest();
    LeftKeyFromMultiStringAtMidTest();

    RightKeyFromEmptyStringTest();
    RightKeyFromSingleStringTest();
    RightKeyFromMultiStringAtTailTest();
    RightKeyFromMultiStringAtHeadTest();
    RightKeyFromMultiStringAtMidTest();
  }
};

class TypeKeyTestSuite
{
private:
  static void TypeKeyFromEmptyStringTest() {
    TypingMachine tm;
    ASSERT_TRUE(tm.TypeKey('A'));
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
  }

  static void TypeKeyFromStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    ASSERT_TRUE(tm.TypeKey('C'));
    ASSERT_EQ(tm.Print('|'), std::string("ABC|"));
  }

  static void TypeKeyUpperBoundTest() {
    TypingMachine tm;
    ASSERT_FALSE(tm.TypeKey(127));
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void TypeKeyLowerBoundTest() {
    TypingMachine tm;
    ASSERT_FALSE(tm.TypeKey(31));
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void TypeKey100StringTest() {
    TypingMachine tm;
    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    ASSERT_TRUE(tm.TypeKey('0'));

    ASSERT_EQ(tm.Print('|'), std::string("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890|"));
  }

  static void TypeKey101StringTest() {
    TypingMachine tm;
    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    tm.TypeKey('1');
    tm.TypeKey('2');
    tm.TypeKey('3');
    tm.TypeKey('4');
    tm.TypeKey('5');
    tm.TypeKey('6');
    tm.TypeKey('7');
    tm.TypeKey('8');
    tm.TypeKey('9');
    tm.TypeKey('0');

    ASSERT_FALSE(tm.TypeKey('E'));
    ASSERT_EQ(tm.Print('|'), std::string("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890|"));
  }

public:
  static void RunTest() {
    TypeKeyFromEmptyStringTest();
    TypeKeyFromStringTest();
    TypeKeyUpperBoundTest();
    TypeKeyLowerBoundTest();
    TypeKey100StringTest();
    TypeKey101StringTest();
  }
};

class EraseKeyTestSuite
{
private:
  static void EraseKeyFromEmptyStringTest() {
    TypingMachine tm;
    ASSERT_FALSE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }
  static void EraseKeyFromSingleStringTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_TRUE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }
  static void EraseKeyFromMultiStringAtTailTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    ASSERT_TRUE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("AB|"));
  }

  static void EraseKeyFromMultiStringAtHeadTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.HomeKey();
    ASSERT_FALSE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("|ABC"));
  }

  static void EraseKeyFromMultiStringAtMidTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    tm.TypeKey('B');
    tm.TypeKey('C');
    tm.LeftKey();
    ASSERT_TRUE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("A|C"));
  }

public:
  static void RunTest() {
    EraseKeyFromEmptyStringTest();
    EraseKeyFromSingleStringTest();
    EraseKeyFromMultiStringAtTailTest();
    EraseKeyFromMultiStringAtHeadTest();
    EraseKeyFromMultiStringAtMidTest();
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  HomeEndTestSuite::RunTest();
  ArrowTestSuite::RunTest();
  TypeKeyTestSuite::RunTest();
  EraseKeyTestSuite::RunTest();
}