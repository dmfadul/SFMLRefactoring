#include "Core/stdafx.h"
#include "States/TocaDisco.h"

// _______________________________________________________________________________
som::TocaDisco::TocaDisco()
{
}

// _______________________________________________________________________________
som::TocaDisco::~TocaDisco()
{
}

// _______________________________________________________________________________
void som::TocaDisco::iniciarMusica(std::string diretorio, float volume)
{
	/* carrega a musica e toca ela em loop */
	if (!musica.openFromFile(diretorio))
		std::cout << "falha ao carregar " << diretorio <<std::endl;

	musica.setVolume(volume);
	musica.setLoop(true);
	musica.play();
}

// _______________________________________________________________________________
void som::TocaDisco::tocarMusicaInicio() { this->iniciarMusica("../assets/sons/velho_oeste.ogg", 30); }

void som::TocaDisco::tocarFallenDown() { this->iniciarMusica("../assets/sons/fallen_down.ogg", 15); }

void som::TocaDisco::tocarSpearOfJustice() { this->iniciarMusica("../assets/sons/spear_of_justice.ogg"); }

void som::TocaDisco::pararMusica() { musica.stop(); }

// _______________________________________________________________________________
void som::TocaDisco::tocarTrocaBotao()
{
	if (!buffer.loadFromFile("../assets/sons/troca_botao.wav"))
		std::cout << "falha ao carregar ../assets/sons/troca_botao.wav" << std::endl;

	som.setBuffer(buffer);
	som.setVolume(10);
	som.play();
}
