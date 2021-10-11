#include "TextChannel.h"

TextChannel::TextChannel()
{
	font.loadFromFile("Fonts/TYPEWR__.TTF");
	text.setFont(font);
	text.setCharacterSize(22);
	text.setFillColor(Color::Cyan);
	text.setStyle(Text::Bold);
}

TextChannel::~TextChannel()
{

}

void TextChannel::updateText(string text)
{
	this->text.setString(text);
}

void TextChannel::draw(RenderTarget & target, Vector2f pos, float x, float y)
{
	this->text.setPosition(pos.x + x, pos.y + y);
	target.draw(this->text);
}
