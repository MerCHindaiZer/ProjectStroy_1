#include "Classes.h"

Image MenuBg, BackGround, ramka, q, MusicStop, icon, pop;
Texture ramtext, BG, qq, MusicS, popp;
Sprite Back, sp, qqq, stop, poppp;
Event even;
TextDrawing newtext;
Timer TimerForIntro;
Timer timer;
bool KeyPressed = false;
bool ButtonPressed = false;
bool WinOpened = true;
bool MSted = false;
int e = 0;
String b;
int i = 0;
int iforcase = 1;
int casebefore = iforcase;
int Volume = 10;
int iforPreAnimation = 0;

// ������� �������� ����� �����

void back() {
    iforcase = casebefore;
}

int main() {

    // ��� �������� �����
    int End = 0;
    int TFE = 110;
    int Speed = 15;
    //
    Texture Menus;
    Sprite MMBG;
    Menus.loadFromFile("SFML BG\\MainMenu2.jpg");
    MMBG.setTexture(Menus);

    Image buttonpic;
    Texture buttontex;
    Sprite buttonspr;
    buttonpic.loadFromFile("SFML BG\\MenuDizain.png");
    buttonpic.createMaskFromColor(Color(237, 28, 36));
    buttontex.loadFromImage(buttonpic);
    buttonspr.setTexture(buttontex);

    MusicStop.loadFromFile("SFML BG\\StopMusic.png");
    MusicStop.createMaskFromColor(Color(255, 255, 255));
    MusicS.loadFromImage(MusicStop);
    stop.setTexture(MusicS);

    Texture NewBackGround[10];
    NewBackGround[0].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[1].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[2].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[3].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[4].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[5].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[6].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[7].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[8].loadFromFile("SFML BG\\Fon1.png");
    NewBackGround[9].loadFromFile("SFML BG\\Fon1.png");

    Sprite BackGroundz;
    BackGroundz.setTexture(NewBackGround[i]);
    String Text1[10];
    Text1[0] = L"��������� �� ���� ���� �� ������ �������� ���� � ������������� � ��������� ����� ���� ���� � ������� ����� � �����, �� ����� ��������� �� ������� ������.  ";
    Text1[1] = L"��� � ����� ������ ��������� � � ��� �� ������ � ������, ���� ��������, ����� � � ����-�� ��� �����, ������ ��� �������� ��� ��� ��������, ��� ��� ������ , ��� �� ��������. ";
    Text1[2] = L"��� ������ �� ������ ������ ��������� ��������� ��������� � ���������, � ����� ������ ������ ������ � �� ����, ���� ���� ������� � ����� � ��. ";
    Text1[3] = L"������� ��� ������� �� ���� ����� � ����� ���� ��� � ��������� � �� ��������, ��� ���� ������� ��������, ��� ��� ����� �� ���� � ���� �� ����� ���� ��� ������ ��� ������. ";
    Text1[4] = L"������ �� ��� ����, �� � ��������� �� �� ���� , � �� ����� ����� � �������� � ������� ���������. ��� ������� ������ ������������� ������� ������ ����� � ������� ������ I, �� ����� �� ���� �����, ��� � ���� ���� �� ������ ���� ������. ";
    Text1[5] = L"��� ����� ����������, ��������� ��� �������� ��� ����������� �� �� ����� ����� �� ����������� �����, �� ������� ���� ��������, ��� �������. ����� ��� �� ���� ����������� ������� ������ �����-�������� �����. ";
    Text1[6] = L"����� 3 ���� � ���� ��� ���� ������� ����� � ������� �� ����� ������� ����, � ��� ����� �� ���, �� ������-�� ������ ���� ����� ��� ����� �������, ������� ������ � ����, ����� ����� �������� � ���� ������ �� ���. ";
    Text1[7] = L"������ �� ����������, �������� � 6 ���� � �������� � ����� �� ������� ������� � , ���������� � ���, ������������ �������� ������������ ������ �����, ������� ������� ������������ ����� �����. ";
    Text1[8] = L"� ������� �� ���� ������, ����� ������ ������ ������ ������� , ������� �� ����� ����� � ���������� �� ������������� ���� �� ��������� ��� �������������� � ������� ��� �����. ";
    Text1[9] = L"� ��� ���� ��� ������ ���, � ��� ��� �� �������� ���� ������� � ������ ������ �� ���. ������� ��, ������ ������ ���� ���� ������ 20 ����� �� ������ ����� ������ ��������, ����� �������� ���� ���������� ������� ";

    Music backmus;
    backmus.openFromFile("SFML OGG M&S\\firstbackmusic.ogg");
    backmus.setVolume(10);
    backmus.play();
    backmus.setLoop(true);
    setlocale(LC_ALL, "ru");

    Music kuku;
    kuku.openFromFile("SFML OGG M&S\\Kukushka.ogg");
    kuku.setVolume(80);

    icon.loadFromFile("SFML BG\\icon.png");

    //�������� � ��������� ����
    RenderWindow window;
    window.create(VideoMode(1920, 1080), L"ProjectStroy", Style::Fullscreen);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);

    Music testma;
    testma.openFromFile("SFML Intro\\OnlyYou.ogg");
    testma.setVolume(10);
    int iForIntro = 0;
    Texture Frames[8];
    Frames[0].loadFromFile("SFML Intro\\Intro1.png");
    Frames[1].loadFromFile("SFML Intro\\Intro2.png");
    Frames[2].loadFromFile("SFML Intro\\Intro3.png");
    Frames[3].loadFromFile("SFML Intro\\Intro4.png");
    Frames[4].loadFromFile("SFML Intro\\Intro5.png");
    Frames[5].loadFromFile("SFML Intro\\Intro6.png");
    Frames[6].loadFromFile("SFML Intro\\Intro7.png");
    Frames[7].loadFromFile("SFML Intro\\Intro8.png");
    Sprite man;
    float TimeForIntro;

    // ���� ������

    SoundBuffer buttonBuffer;
    buttonBuffer.loadFromFile("SFML OGG M&S\\Button.ogg");
    Sound button(buttonBuffer);
    button.setVolume(30);


    // �����
    Font font;
    font.loadFromFile("SFML FONTS\\Minotaur-Jugendstil.ttf");
    Font font2;
    font2.loadFromFile("SFML FONTS\\CyrilicOld.ttf");

    // Super Music <3

    Music music;
    music.openFromFile("SFML OGG M&S\\MusicMainMenu.ogg");

    // ��� ����������

    Text name;
    name.setFont(font);
    name.setString(L"˸��");
    name.setStyle(Text::Bold);
    name.setPosition(360, 870);

    // ���������� �����

    ramka.loadFromFile("SFML BG\\darkram.png");
    ramka.createMaskFromColor(Color(34, 177, 76));
    sp.setPosition(10, 65);
    sp.setColor(Color(0, 0, 0, 230));

    ramtext.loadFromImage(ramka);
    sp.setTexture(ramtext);

    // ������ !������! ����
    TextDrawing button1;
    button1.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 480, 0);
    String settingsb = L"���������";

    RectangleShape b1(Vector2f(150, 45));
    b1.setFillColor(Color(0, 0, 0, 0));
    b1.setPosition(460, 0);

    TextDrawing button2;
    button2.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 880, 0);
    String storyb = L"�������";

    RectangleShape b2(Vector2f(150, 45));
    b2.setFillColor(Color(0, 0, 0, 0));
    b2.setPosition(660, 0);

    TextDrawing button3;
    button3.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 680, 0);
    String saveb = L"���������";

    RectangleShape b3(Vector2f(150, 45));
    b3.setFillColor(Color(0, 0, 0, 0));
    b3.setPosition(860, 0);

    TextDrawing button4;
    button4.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 1265, 0);
    String skipb = L"�������";

    RectangleShape b4(Vector2f(150, 45));
    b4.setFillColor(Color(0, 0, 0, 0));
    b4.setPosition(1245, 0);

    TextDrawing button5;
    button5.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 1065, 0);
    String loadb = L"���������";

    RectangleShape b5(Vector2f(150, 45));
    b5.setFillColor(Color(0, 0, 0, 0));
    b5.setPosition(1045, 0);

    // �������� ���� ���� � ����������� ������� ������ (60 ���)


    // ������ ��� !������! ����

    BackGround.loadFromFile("SFML BG\\images.jpg");
    BG.loadFromImage(BackGround);
    Back.setTexture(BG);

    Text Version;
    Version.setFont(font2);
    Version.setString(L"Alpha 0.15");
    Version.setStyle(Text::Bold);
    Version.setOutlineColor(Color::Black);
    Version.setOutlineThickness(3);
    Version.setPosition(50, 1040);
    Version.setFillColor(Color::White);

    Text opetion;
    opetion.setFont(font2);
    opetion.setString(L"���������");
    opetion.setStyle(Text::Bold);
    opetion.setOutlineColor(Color::White);
    opetion.setOutlineThickness(3);
    opetion.setPosition(890, 7);
    opetion.setFillColor(Color::Black);

    Text Regmuz;
    Regmuz.setFont(font);
    Regmuz.setString(L"1) ��������� �����:\n������������ �������� ������/������\n � ������� ������� ����� � ���� \n\n��������� ���������� � ����\n � �������� ����� ����� :)");
    Regmuz.setStyle(Text::Bold);
    Regmuz.setOutlineColor(Color::White);
    Regmuz.setOutlineThickness(3);
    Regmuz.setPosition(690, 138);
    Regmuz.setFillColor(Color::Blue);

    Text Desctop;
    Desctop.setFont(font);
    Desctop.setString(L"2) ������� (P) ��� ������\n �� ������� ����");
    Desctop.setStyle(Text::Bold);
    Desctop.setOutlineColor(Color::White);
    Desctop.setOutlineThickness(3);
    Desctop.setPosition(127, 640);
    Desctop.setFillColor(Color::Blue);

    Text MainMenuk;
    MainMenuk.setFont(font);
    MainMenuk.setString(L"3) ������� (Esc) ��� ������\n � ������� ����");
    MainMenuk.setStyle(Text::Bold);
    MainMenuk.setOutlineColor(Color::White);
    MainMenuk.setOutlineThickness(3);
    MainMenuk.setPosition(1450, 600);
    MainMenuk.setFillColor(Color::Blue);

    Text Brain;
    Brain.setFont(font);
    Brain.setString(L"15.10.2000\n������");
    Brain.setStyle(Text::Bold);
    Brain.setOutlineColor(Color::White);
    Brain.setOutlineThickness(3);
    Brain.setPosition(1500, 250);
    Brain.setFillColor(Color::Red);

    Text Surp;
    Surp.setFont(font);
    Surp.setString(L"�����, �� ������ \n ����������� ������ ������ (I)");
    Surp.setStyle(Text::Bold);
    Surp.setOutlineColor(Color::White);
    Surp.setOutlineThickness(3);
    Surp.setPosition(1390, 815);
    Surp.setFillColor(Color::Blue);

    Text Opps;
    Opps.setFont(font);
    Opps.setString(L"3) ������ ��������, �� ������������\n ��������� �������, ��� �������\n ������ �������� ����� �������� ����\n\n BRUH ;)))");
    Opps.setStyle(Text::Bold);
    Opps.setOutlineColor(Color::White);
    Opps.setOutlineThickness(3);
    Opps.setPosition(1385, 600);
    Opps.setFillColor(Color::Blue);

    Text opetioz;
    opetioz.setFont(font2);
    opetioz.setString(L"� �������");
    opetioz.setStyle(Text::Bold);
    opetioz.setOutlineColor(Color::White);
    opetioz.setOutlineThickness(3);
    opetioz.setPosition(890, 20);
    opetioz.setFillColor(Color::Black);

    Text opetioz1;
    opetioz1.setFont(font);
    opetioz1.setString(L"�������� ����������");
    opetioz1.setStyle(Text::Bold);
    opetioz1.setPosition(890, 20);
    opetioz1.setFillColor(Color::Black);

    Text opetioz2;
    opetioz2.setFont(font);
    opetioz2.setString(L"����� ����������");
    opetioz2.setStyle(Text::Bold);
    opetioz2.setPosition(890, 20);
    opetioz2.setFillColor(Color::Black);

    Text StoryTale;
    StoryTale.setFont(font);
    StoryTale.setString(L"�������");
    StoryTale.setStyle(Text::Bold);
    StoryTale.setPosition(890, 20);
    StoryTale.setFillColor(Color::Black);

    q.loadFromFile("SFML BG\\OptionsText.png");
    qq.loadFromImage(q);
    qqq.setTexture(qq);

    pop.loadFromFile("SFML BG\\SAFE_LOADBG.jpg");
    popp.loadFromImage(pop);
    poppp.setTexture(popp);

    ///////////////////////////////////////////////////////////////////
    //                          ���� ������
    ///////////////////////////////////////////////////////////////////
    RectangleShape bm1(Vector2f(280, 75));
    bm1.setFillColor(Color(0, 0, 0, 0));
    bm1.setPosition(70, 160);

    RectangleShape bm2(Vector2f(280, 75));
    bm2.setFillColor(Color(0, 0, 0, 0));
    bm2.setPosition(70, 280);

    RectangleShape bm3(Vector2f(280, 75));
    bm3.setFillColor(Color(0, 0, 0, 0));
    bm3.setPosition(70, 400);

    RectangleShape bm4(Vector2f(280, 75));
    bm4.setFillColor(Color(0, 0, 0, 0));
    bm4.setPosition(70, 520);

    RectangleShape bm5(Vector2f(280, 75));
    bm5.setFillColor(Color(0, 0, 0, 0));
    bm5.setPosition(70, 640);

    RectangleShape musig(Vector2f(120, 100));
    musig.setFillColor(Color(0, 0, 0, 0));
    musig.setPosition(1750, 20);


    TimerForIntro.Reset();
    Event event;
    while (window.pollEvent(event))

    {

        if (event.type == Event::Closed) {

            window.close();
            backmus.stop();
            WinOpened = false;
        }

    }
    while (WinOpened == true) {

        switch (iforcase)
        {
        case 1:               // �����
        {
            testma.play();
            while (window.isOpen())
            {

                man.setTexture(Frames[iForIntro]);
                TimeForIntro = TimerForIntro.GetElapsedMilliSeconds();
                //  cout << iForIntro << endl;
                if (TimeForIntro > 300) {

                    iForIntro++;
                    TimeForIntro = 0;
                    TimerForIntro.Reset();

                }


                window.clear(Color::Black);

                window.draw(man);
                window.display();

                if (iForIntro >= 8) {
                    testma.stop();


                    window.clear();

                    iforcase = 2;

                    cout << "����� ��������" << endl;
                    iForIntro = 0;
                    break;

                }



            }
        }
        case 2:               // ������� ����
        {
            cout << "������� � ������� ����" << endl;
            casebefore = iforcase;
            if (MSted == false) {
                music.play();
                music.setVolume(Volume);
                music.setLoop(true);
                MSted = true;
            }
            while (window.isOpen()) {


                cout << iforcase << endl;
                Vector2i mousePoz = Mouse::getPosition(window);

                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window.close();

                }
                ///////////////////////////////////////////////////////////////////
                //                          ������ ������
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "������ / ��������" << endl;
                            button.play();
                            bm1.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 10;

                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                          ������ ���������
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "��������� / ��������" << endl;
                            button.play();
                            bm2.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 6;
                            break;

                        }
                ///////////////////////////////////////////////////////////////////
                //                      ������ ���������
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "��������� / ��������" << endl;
                            button.play();
                            bm3.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 4;
                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                      ������ � �������
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm4.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "� ������� / ��������" << endl;
                            button.play();
                            bm4.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 8;
                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                      ������ �����
                ///////////////////////////////////////////////////////////////////

                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm5.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "����� / ��������" << endl;
                            button.play();
                            bm5.setFillColor(Color(0, 0, 0, 70));

                            window.close();
                            WinOpened = false;
                        }

                ///////////////////////////////////////////////////////////////////
                //                      �������� ����� �� ������
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (bm1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            bm1.setFillColor(Color(0, 0, 0, 0));
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (bm2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            bm2.setFillColor(Color(0, 0, 0, 0));
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (bm3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            bm3.setFillColor(Color(0, 0, 0, 0));
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (bm4.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            bm4.setFillColor(Color(0, 0, 0, 0));
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (bm5.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            bm5.setFillColor(Color(0, 0, 0, 00));
                        }
                ///////////////////////////////////////////////////////////////////

                window.clear();

                window.draw(MMBG);
                //  mainMenu.draw(window);
                window.draw(Version);
                window.draw(buttonspr);
                window.draw(bm1);
                window.draw(bm2);
                window.draw(bm3);
                window.draw(bm4);
                window.draw(bm5);
                window.display();
            }
        }
        case 3:               //�������
            break;
        case 4:               //���������
        {

            while (window.isOpen())
            {
                cout << iforcase << endl;
                Event event;

                while (window.pollEvent(event)) {

                    if (event.type == Event::Closed)
                        window.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    button.play();
                    music.setVolume(Volume + 10);
                    cout << Volume << endl;
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    button.play();
                    music.setVolume(Volume - 10);
                    cout << Volume << endl;
                }

                if (Keyboard::isKeyPressed(Keyboard::P)) {
                    button.play();
                    kuku.stop();
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::I)) {

                    button.play();
                    kuku.play();

                }

                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    button.play();
                    back();
                    break;
                }

                window.draw(qqq);
                window.draw(opetion);
                window.draw(Regmuz);
                window.draw(Desctop);
                window.draw(Opps);
                window.draw(Surp);
                window.draw(Brain);
                window.display();

            }

        }
        case 5:               // �������
            break;
        case 6:               // �������� ����������
        {
            while (window.isOpen())
            {


                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    button.play();
                    back();
                    break;
                }

                window.draw(poppp);
                window.draw(opetioz1);
                window.display();

            }
        }
        case 7:               // �������
            break;
        case 8:               // � �������
        {
            while (window.isOpen())
            {

                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    button.play();
                    back();
                    break;
                }

                window.draw(poppp);
                window.draw(opetioz);
                window.display();

            }
        }
        case 9:               // �������
            break;
        case 10:              // ����
        {
            cout << "������� �� ���� � ����� " << endl;
            timer.Reset();

            newtext.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 330, 945);

            while (window.isOpen())
            {   
                float TTime = timer.GetElapsedMilliSeconds();
                if (TTime > Speed) {
                    cout << Text1[i][b.getSize()] << endl;
                    b += Text1[i][b.getSize()];
                    e++;
                    if (Text1[i][b.getSize()] == End) {

                        b += Text1[i][b.getSize()];
                        TTime = 0;
                        timer.Pause();
                        e = 0;
                    }
                    else {
                        timer.Reset();
                    }

                }
                if (KeyPressed) {
                    KeyPressed = false;
                    b.clear();
                    i++;
                    cout << i << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                    timer.Reset();


                }
                if (e >= TFE) {
                    b = b + "\n";
                    e = 0;
                }

                Vector2i mousePoz = Mouse::getPosition(window);

                Event event;

                while (window.pollEvent(event))
                {

                    // ����������� ������ !������! ���� ����� �� ��������

                    if (event.type == Event::Closed)
                        window.close();
                }
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            event.type = Event::MouseButtonReleased;
                            cout << "������ (1)(���������) ��������" << endl;
                            ButtonPressed = true;
                            button.play();
                            b1.setFillColor(Color(0, 0, 0, 0));
                            casebefore = iforcase;
                            iforcase = 4;
                            break;

                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (b1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            ButtonPressed = false;
                            b1.setFillColor(Color(0, 0, 0, 70));
                        }
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "������ (3)(�������) ��������" << endl;
                            ButtonPressed = true;
                            button.play();
                            b2.setFillColor(Color(0, 0, 0, 0));
                            casebefore = iforcase;
                            iforcase = 12;
                            break;
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (b2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            ButtonPressed = false;
                            b2.setFillColor(Color(0, 0, 0, 70));
                        }
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "������ (2)(����������) ��������" << endl;
                            ButtonPressed = true;
                            button.play();
                            b3.setFillColor(Color(0, 0, 0, 0));
                            casebefore = iforcase;
                            iforcase = 14;
                            break;
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (b3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            ButtonPressed = false;
                            b3.setFillColor(Color(0, 0, 0, 70));
                        }



                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b4.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "������ (5)(�������) ��������" << endl;
                            ButtonPressed = true;
                            button.play();
                            b4.setFillColor(Color(0, 0, 0, 0));
                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (b4.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            ButtonPressed = false;
                            b4.setFillColor(Color(0, 0, 0, 70));
                        }



                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b5.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "������ (4)(���������) ��������" << endl;
                            ButtonPressed = true;
                            button.play();
                            b5.setFillColor(Color(0, 0, 0, 0));
                            casebefore = iforcase;
                            iforcase = 6;
                            break;

                        }
                if (event.type == Event::MouseButtonReleased)
                    if (event.key.code == Mouse::Left)
                        if (b5.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            ButtonPressed = false;
                            b5.setFillColor(Color(0, 0, 0, 70));
                        }
                /// ///////////////////////////////////////////////////// ���������������

                        /* if (Keyboard::isKeyPressed(Keyboard::Space)) {
                            KeyPressed = true;
                            }
                        */
                if (event.type == (Event::MouseButtonPressed)) {
                    switch (event.key.code) {
                    case (Mouse::Left): {
                        event.type = (Event::KeyReleased);
                        button.play();
                        KeyPressed = true;
                        break;
                    }
                    }
                }

                /// ///////////////////////////////////////////////////// ��������������


                window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

                window.clear();

                window.draw(BackGroundz);
                window.draw(sp);
                window.draw(newtext.setText(&b));

                window.draw(name);

                window.draw(button1.setText(&settingsb));
                window.draw(button2.setText(&saveb));
                window.draw(button3.setText(&storyb));
                window.draw(button4.setText(&skipb));
                window.draw(button5.setText(&loadb));

                window.draw(b1);
                window.draw(b2);
                window.draw(b3);
                window.draw(b4);
                window.draw(b5);

                window.display();

            }
        }
        case 11:              // �������
            break;
        case 12:              // ������� (������ ����)
        {
            while (window.isOpen())
            {


                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    button.play();
                    back();
                    break;
                }

                window.draw(poppp);
                window.draw(StoryTale);
                window.display();

            }
        }
        case 13:              // �������
            break;
        case 14:              // ���������� (������ ����)
        {
            while (window.isOpen())
            {


                while (window.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    button.play();
                    back();
                    break;
                }

                window.draw(poppp);
                window.draw(opetioz2);
                window.display();

            }
        }
        case 15:              // ������� 
            break;
        default: {

            cout << "����� �� ������� ������, ����� ����";
            window.close();
            break;
        }
        }
    }
    return 0;
}