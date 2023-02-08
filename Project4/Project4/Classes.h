#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
using namespace sf;
namespace sf {
	struct Timer {
		sf::Clock mC;
		float time;
		bool bPaused;
		Timer() {
			bPaused = false;
			time = 0;
			mC.restart();
		}

		void Reset() {
			mC.restart();
			time = 0;
			bPaused = false;
		}

		void Start() {
			if (bPaused) {
				mC.restart();
			}
			bPaused = false;
		}

		void Pause() {
			if (!bPaused) {
				time += mC.getElapsedTime().asSeconds();
			}
			bPaused = true;
		}

		float GetElapsedMilliSeconds() {
			if (!bPaused) {
				return time + mC.getElapsedTime().asMilliseconds();
			}
			return time;
		}

	};
}
struct TextDrawing {
	Font font;
	Text* text = new Text;
	void newSettings(String NameOfFont, float X, float Y) {
		font.loadFromFile(NameOfFont);
		text->setFont(font);
		text->setFillColor(Color::White);
		text->setPosition(X, Y);
		text->setStyle(Text::Bold);
		text->setFillColor(Color::White);
	}
	Text setText(String* NameOfString) {
		text->setString(*NameOfString);
		return *text;
	}

};
class ObjectPool {
private:
	struct ObjectInPool {
		bool used;
		Texture instance;
	};
	vector<ObjectInPool> pool;
public:
	void AddObject(Texture obj) {

		ObjectInPool new_Object;
		new_Object.instance = obj;
		new_Object.used = true;
		pool.push_back(new_Object);
		cout << pool.size() << endl;
	}
	Texture GetObject(int iForPool) {

		if (iForPool == -1) {
			for (auto c = pool.begin(); c != pool.end(); c++) {
				if (!c->used) {
					c->used = true;
					return c->instance;
				}
			}
		}
		else
			return pool[iForPool].instance;
	}
	void DeleteObject(int iForPool) {

		if (iForPool == -1) {
			for (auto c = pool.begin(); c != pool.end(); c++) {
				if (c->used) {
					c->used = false;
					break;
				}
			}
		}
		else {
			pool[iForPool].used = false;

		}
	}
};
/*
*
	void MainMenu::draw(RenderWindow& win) {
		for (int i = 0; i < Max_main_menu; ++i) {
			//cout << i << endl; - проверка работы команды
			win.draw(mainMenu[i]);

	}
} */
