#pragma once
#include <string>

enum class WeaponType
{
	Bolter = 1,
	ChainSword = 1 << 1
};

enum class BodyPartsPlayer
{
	eHeadPlayer = 0,
	eThoraxPlayer,
	eRightArmPlayer,
	eLeftArmPlayer,
	eRightLegPlayer,
	eLeftLegPlayer
};

class Player
{
public:
    void UsingMed();
	void ViewStatus();
	void SwapWeapon();
	bool IsAlive();
	void TakeDamagePlayer(int InDamage);
	int BoltGunShot(int EnemyHealth);
	int ChainSwordAttack(int EnemyHealth);
	

	

protected:
	std::string Name = "³ª»Û³ð´ÙÁ×¾î ÇØº´";	// ¸»·ë Ä«¿¡µµ
	unsigned int Med = 0;					// ¸ÞµðÄ«¿¡ ¼ÒÁö °¹¼ö
	unsigned int OaksHead = 0;				// ž±½º ¸Ó¸®Åë ¼ÒÁö °¹¼ö
	unsigned int HeadPlayer = 45;			// ¸Ó¸® Ã¼·Â
	unsigned int ThoraxPlayer = 90;			// ¸öÅë Ã¼·Â
	unsigned int RightArmPlayer = 70;		// ¿À¸¥ÆÈ Ã¼·Â
	unsigned int LeftArmPlayer = 70;		// ¿ÞÆÈ Ã¼·Â
	unsigned int RightLegPlayer = 70;		// ¿À¸¥´Ù¸® Ã¼·Â
	unsigned int LeftLegPlayer = 70;		// ¿Þ´Ù¸® Ã¼·Â
	WeaponType MyWeapon;					// ¹«±â ¹¹ ³¢°íÀÖ³Ä
};

