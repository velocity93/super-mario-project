#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML\Graphics.hpp>
#include <QtGui/QMainWindow>
#include "ui_Editor.h"

class Editor : public QMainWindow, public sf::RenderWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Editor();

private:
	Ui::EditorClass ui;
};

#endif // EDITOR_HPP
