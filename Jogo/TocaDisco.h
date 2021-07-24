#pragma once

/* Classe que gerencia todos os sons do jogo */
class TocaDisco
{
private:
	// variaveis de som
	sf::Music musica;
	sf::Sound som;
	sf::SoundBuffer buffer;

public:
	// construtoras e destrutoras
	TocaDisco();
	~TocaDisco();

	// metodos para iniciar e parar sons
	void iniciarMusica(std::string diretorio, int volume = 20);
	void tocarMusicaInicio();
	void tocarFallenDown();
	void tocarSpearOfJustice();
	void tocarTrocaBotao();
	void pararMusica();
};