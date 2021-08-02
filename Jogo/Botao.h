#pragma once
#include "Gui.h"
namespace gui {
	/* Classe de um botão generico */
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
		Botao(float pos_x, float pos_y, std::string texto);
		~Botao();

		// Metodos de inicialização
		void iniciarBotao(float pos_x, float pos_y, std::string texto);
		void iniciarCaixa(float pos_x, float pos_y);

		// Ativar e Desativar botao
		void ativar();
		void desativar();

		// Setters e getters
		void setCorAtivado(sf::Color ca);

		// Desenha botao
		void desenharBotao(sf::RenderTarget& janela);
	};
}

