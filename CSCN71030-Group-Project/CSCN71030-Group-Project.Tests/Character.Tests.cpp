#include "pch.h"
#include "CppUnitTest.h"
#include "../CSCN71030-Group-Project/Character.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharacterTests
{

	TEST_CLASS(CharacterTests)
	{
	public:

		TEST_METHOD(CharacterTests001ItitializeSpoon_NameString_CharacterObjectName)
		{
			// Arrange
			std::string NameString = "name";
			// Act
			Character* UserChar = new spoon(NameString);
			// Assert
			Assert::AreEqual(NameString, UserChar->getName());
		}
		TEST_METHOD(CharacterTests002InitializaFork_NameString_CharacterObject)
		{
			// Arrange
			std::string NameString = "name";
			// Act
			Character* UserChar = new fork(NameString);
			// Assert
			Assert::AreEqual(NameString, UserChar->getName());
		}
		TEST_METHOD(CharacterTests003InitializeKnife_NameString_CharacterObject)
		{
			// Arrange
			std::string NameString = "name";
			// Act
			Character* UserChar = new knife(NameString);
			// Assert
			Assert::AreEqual(NameString, UserChar->getName());
		}
		TEST_METHOD(CharacterTests004SetSpoonHealth_2_2)
		{
			// Arrange
			int ExpectedHealth = 2;
			Character* UserChar = new spoon("name");
			// Act
			UserChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, UserChar->getHealth());	// Expected 2
		}
		TEST_METHOD(CharacterTests005SetForkHealth_4_4)
		{
			// Arrange
			int ExpectedHealth = 4;
			Character* UserChar = new fork("name");
			// Act
			UserChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, UserChar->getHealth());	// Expected 2
		}
		TEST_METHOD(CharacterTests006SetKnifeHealth_5_5)
		{
			// Arrange
			int ExpectedHealth = 5;
			Character* UserChar = new knife("name");
			// Act
			UserChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, UserChar->getHealth());	// Expected 2
		}
		TEST_METHOD(CharacterTests007SetSpoonPrepared_True_True)
		{
			// Arrange
			Character* UserChar = new spoon("name");
			// Act
			UserChar->setPrepared(true);	// Set as true
			// Assert
			Assert::AreEqual(true, UserChar->getPrepared());	// Expected: True

		}
		TEST_METHOD(CharacterTests008SetForkPrepared_True_True)
		{
			// Arrange
			Character* UserChar = new fork("name");
			// Act
			UserChar->setPrepared(true);	// Set as true
			// Assert
			Assert::AreEqual(true, UserChar->getPrepared());	// Expected: True
		}
		TEST_METHOD(CharacterTests009SetKnifePrepared_True_True)
		{
			// Arrange
			Character* UserChar = new knife("name");
			// Act
			UserChar->setPrepared(true);	// Set as true
			// Assert
			Assert::AreEqual(true, UserChar->getPrepared());	// Expected: True
		}
		TEST_METHOD(CharacterTests010GetSpoonAttack_Spoon_5)
		{
			// Arrange
			Character* UserChar = new spoon("name");
			int Expected;
			// Act
			Expected = UserChar->getAttack();
			// Assert
			Assert::AreEqual(5, Expected);						// Expected: 5

		}
		TEST_METHOD(CharacterTests011GetForkAttack_Fork_7)
		{
			// Arrange
			Character* UserChar = new fork("name");
			int Expected;
			// Act
			Expected = UserChar->getAttack();
			// Assert
			Assert::AreEqual(7, Expected);						// Expected: 7
		}
		TEST_METHOD(CharacterTests012GetKnifeAttack_Knife_10)
		{
			// Arrange
			Character* UserChar = new knife("name");
			int Expected;
			// Act
			Expected = UserChar->getAttack();
			// Assert
			Assert::AreEqual(10, Expected);						// Expected: 10

		}
		TEST_METHOD(CharacterTests013GetSpoonDefence_Spoon_10)
		{
			// Arrange
			Character* UserChar = new spoon("name");
			int Expected;
			// Act
			Expected = UserChar->getDefence();
			// Assert
			Assert::AreEqual(10, Expected);						// Expected: 10

		}
		TEST_METHOD(CharacterTests014GetForkDefence_Fork_5)
		{
			// Arrange
			Character* UserChar = new fork("name");
			int Expected;
			// Act
			Expected = UserChar->getDefence();
			// Assert
			Assert::AreEqual(5, Expected);						// Expected: 5

		}
		TEST_METHOD(CharacterTests015GetKnifeDefence_Knife_2)
		{
			// Arrange
			Character* UserChar = new knife("name");
			int Expected;
			// Act
			Expected = UserChar->getDefence();
			// Assert
			Assert::AreEqual(2, Expected);						// Expected: 2
		}
		TEST_METHOD(CharacterTests016GetSpoonSpeed_Spoon_4)
		{
			// Arrange
			Character* UserChar = new spoon("name");
			int Expected;
			// Act
			Expected = UserChar->getSpeed();
			// Assert
			Assert::AreEqual(4, Expected);						// Expected: 4
		}
		TEST_METHOD(CharacterTests017GetForkSpeed_Fork_10)
		{
			// Arrange
			Character* UserChar = new fork("name");
			int Expected;
			// Act
			Expected = UserChar->getSpeed();
			// Assert
			Assert::AreEqual(10, Expected);						// Expected: 10

		}
		TEST_METHOD(CharacterTests018GetKnifeSpeed_Knife_8)
		{
			// Arrange
			Character* UserChar = new knife("name");
			int Expected;
			// Act
			Expected = UserChar->getSpeed();
			// Assert
			Assert::AreEqual(8, Expected);						// Expected: 8
		}
	};

	TEST_CLASS(CharacterEnemyTests)
	{
	public:
		TEST_METHOD(CharacterEnemyTests001ItitializeDrawerEnemy_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new DrawerEnemy(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());
		}
		TEST_METHOD(CharacterEnemyTests002ItitializeDrawerBoss_4_5_6_7__CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new DrawerBoss(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());
		}
		TEST_METHOD(CharacterEnemyTests003ItitializeSinkEnemy_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new SinkEnemy(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());
		}
		TEST_METHOD(CharacterEnemyTests004ItitializeSinkBoss_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new SinkBoss(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());

		}
		TEST_METHOD(CharacterEnemyTests005ItitializeOvenEnemy_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new OvenEnemy(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());

		}
		TEST_METHOD(CharacterEnemyTests006ItitializeOvenBoss_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new OvenBoss(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());
		}
		TEST_METHOD(CharacterEnemyTests007ItitializeCounterEnemy_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new CounterEnemy(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());

		}
		TEST_METHOD(CharacterEnemyTests008ItitializeCounterBoss_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new CounterBoss(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());

		}
		TEST_METHOD(CharacterEnemyTests009ItitializeFinalBoss_4_5_6_7_CharacterObject)
		{
			// Arrange
			int Health = 4;
			int Attack = 5;
			int Defence = 6;
			int Speed = 7;

			// Act
			Character* EnemyChar = new FinalBoss(Health, Attack, Defence, Speed);

			// Assert
			Assert::AreEqual(Health, EnemyChar->getHealth());
			Assert::AreEqual(Attack, EnemyChar->getAttack());
			Assert::AreEqual(Defence, EnemyChar->getDefence());
			Assert::AreEqual(Speed, EnemyChar->getSpeed());

		}
		TEST_METHOD(CharacterEnemyTests010SetDrawerEnemyHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new DrawerEnemy(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests011SetDrawerBossHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new DrawerBoss(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests012SetSinkEnemyHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new SinkEnemy(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests013SetSinkBossHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new SinkBoss(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests014SetOvenEnemyHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new OvenEnemy(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());

		}
		TEST_METHOD(CharacterEnemyTests015SetOvenBossHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new OvenBoss(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());

		}
		TEST_METHOD(CharacterEnemyTests016SetCounterEnemyHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new CounterEnemy(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests017SetCounterBossHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new CounterBoss(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests018SetFinalBossHealth_5_5)
		{
			// Arrange
			Character* EnemyChar = new FinalBoss(0, 0, 0, 0);
			int ExpectedHealth = 5;
			// Act
			EnemyChar->setHealth(ExpectedHealth);
			// Assert
			Assert::AreEqual(ExpectedHealth, EnemyChar->getHealth());
		}
		TEST_METHOD(CharacterEnemyTests019SetDrawerEnemyPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new DrawerEnemy(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());

		}
		TEST_METHOD(CharacterEnemyTests020SetDrawerBossPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new DrawerBoss(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests021SetSinkEnemyPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new SinkEnemy(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests022SetSinkBossPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new SinkBoss(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests023SetOvenEnemyPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new OvenEnemy(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests024SetOvenBossPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new OvenBoss(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests025SetCounterEnemyPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new CounterEnemy(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests026SetCounterBossPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new CounterBoss(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
		TEST_METHOD(CharacterEnemyTests027SetFinalBossPrepared_True_True)
		{
			// Arrange
			Character* EnemyChar = new FinalBoss(0, 0, 0, 0);
			// Act
			EnemyChar->setPrepared(true); // Set to prepared
			// Assert
			Assert::AreEqual(true, EnemyChar->getPrepared());
		}
	};
}
