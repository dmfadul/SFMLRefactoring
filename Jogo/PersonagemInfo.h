#pragma once
/* Container com as informacoes do personagem */
class PersonagemInfo
{
private:
	int hp;
	int dano;
	static int score;

public:
	// construtoras e destrutoras
	PersonagemInfo();
	~PersonagemInfo();

	// metodos
	void iniciarPersInfo(int hp, int dano);

	// setters e getters
	void setHP(const int h);
	void setDano(const int d);
	static void setScore(const int s);
	const int getHp();
	const int getDano();
	static const int getScore();
};

