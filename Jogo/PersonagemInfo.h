#pragma once
/* Container com as informacoes do personagem */
class PersonagemInfo
{
private:
	int hp;
	int dano;
	int score;

public:
	// construtoras e destrutoras
	PersonagemInfo();
	~PersonagemInfo();

	// metodos
	void iniciarPersInfo(int hp, int dano);
	void incrementarScore(const int s);

	// setters e getters
	void setHP(const int h);
	void setDano(const int d);
	const int getHp();
	const int getDano();
};

