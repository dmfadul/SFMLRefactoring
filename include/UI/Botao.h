#pragma once
#include "UI/Gui.h"
namespace gui {
	/* Classe de um bot�o generico */
	class Botao : public Gui 
	{
	private:
		// Variaveis SFML
		sf::RectangleShape caixaBotao;
		sf::Color corAtivado;
		sf::Color corDesativado;

		// flags
		bool ativado;

	public:
		// Construtoras e Destrutoras
		Botao();
		~Botao();

		// Ativar e Desativar botao
		void ativar();
		void desativar();

		// Setters e getters
		void setCorAtivado(sf::Color ca);
		void setCorDesativo(sf::Color cd);
		sf::RectangleShape* getCaixa();
		sf::Text* getTexto();

		// Desenha botao
		void desenharBotao(sf::RenderTarget& janela);
	};
}

