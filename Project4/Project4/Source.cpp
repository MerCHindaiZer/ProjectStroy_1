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

// Функция возврата через метод

void back() {
    iforcase = casebefore;
}

int main() {

    // для третьего кейса
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
    Text1[0] = L"Буквально за один день до начала учебного года в “Терморострое” я находился целый день дома и собирал сумку в лицей, до этого купленную на остаток мелочи.  ";
    Text1[1] = L"Мне в дверь громко постучали и в тот же момент я открыл, ведь редкость, чтобы я и кому-то был нужен, обычно все обходили мой дом стороной, так как думали , что он заброшен. ";
    Text1[2] = L"Под дверью на пороге лежала небольшая картонная коробочка с этикеткой, а перед дверью словно никого и не было, лишь одна посылка в ногах и всё. ";
    Text1[3] = L"Положив эту коробку на стол кухни я сразу взял нож и приступил к ее открытию, мне всем сердцем верилось, что это весть от отца и было не важно будь там деньги или письмо. ";
    Text1[4] = L"Письмо же там было, но к сожалению не от отца , а от имени лицея с подписью и печатью директора. Под письмом лежала ромбообразная нашивка синего цвета с римской цифрой I, не сразу до меня дошло, что к чему пока не прочёл само письмо. ";
    Text1[5] = L"Как позже выяснилось, абсолютно все студенты вне зависимости от их курса носят на специальной форме, от которой одно название, эти нашивки. Дресс код из себя представлял обычный бомбер темно-зеленого цвета. ";
    Text1[6] = L"Через 3 часа у меня уже была собрана сумка и нашитый на рукав бомбера ранг, я был готов ко сну, но почему-то именно этой ночью мне плохо спалось, сначала кололо в боку, после этого морозило и дико сушило во рту. ";
    Text1[7] = L"Нифига не выспавшись, примерно в 6 утра я поднялся и пошёл до колодца умыться и , вернувшись в дом, позавтракать чёрствым затвердевшим куском хлеба, который остался единственный после ужина. ";
    Text1[8] = L"Я нацепил на себя бомбер, надел старое легкое пальто дедушки , повесил на плечо сумку и направился на вступительную речь от директора для первокурсников в актовый зал лицея. ";
    Text1[9] = L"Я иду туда уже второй раз, а мне уже не нравится этот маршрут и вообще надоел он мне. Повезло же, теперь каждый день буду ходить 20 минут на морозе через лесную тропинку, самый короткий путь называется ёптель… ";

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

    //Создание и настройка окна
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

    // звук кнопки

    SoundBuffer buttonBuffer;
    buttonBuffer.loadFromFile("SFML OGG M&S\\Button.ogg");
    Sound button(buttonBuffer);
    button.setVolume(30);


    // Шрифт
    Font font;
    font.loadFromFile("SFML FONTS\\Minotaur-Jugendstil.ttf");
    Font font2;
    font2.loadFromFile("SFML FONTS\\CyrilicOld.ttf");

    // Super Music <3

    Music music;
    music.openFromFile("SFML OGG M&S\\MusicMainMenu.ogg");

    // Имя говорящего

    Text name;
    name.setFont(font);
    name.setString(L"Лёша");
    name.setStyle(Text::Bold);
    name.setPosition(360, 870);

    // Диалоговая рамка

    ramka.loadFromFile("SFML BG\\darkram.png");
    ramka.createMaskFromColor(Color(34, 177, 76));
    sp.setPosition(10, 65);
    sp.setColor(Color(0, 0, 0, 230));

    ramtext.loadFromImage(ramka);
    sp.setTexture(ramtext);

    // Кнопки !внутри! игры
    TextDrawing button1;
    button1.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 480, 0);
    String settingsb = L"Настройки";

    RectangleShape b1(Vector2f(150, 45));
    b1.setFillColor(Color(0, 0, 0, 0));
    b1.setPosition(460, 0);

    TextDrawing button2;
    button2.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 880, 0);
    String storyb = L"История";

    RectangleShape b2(Vector2f(150, 45));
    b2.setFillColor(Color(0, 0, 0, 0));
    b2.setPosition(660, 0);

    TextDrawing button3;
    button3.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 680, 0);
    String saveb = L"Сохранить";

    RectangleShape b3(Vector2f(150, 45));
    b3.setFillColor(Color(0, 0, 0, 0));
    b3.setPosition(860, 0);

    TextDrawing button4;
    button4.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 1265, 0);
    String skipb = L"Пропуск";

    RectangleShape b4(Vector2f(150, 45));
    b4.setFillColor(Color(0, 0, 0, 0));
    b4.setPosition(1245, 0);

    TextDrawing button5;
    button5.newSettings("SFML FONTS\\Minotaur-Jugendstil.ttf", 1065, 0);
    String loadb = L"Загрузить";

    RectangleShape b5(Vector2f(150, 45));
    b5.setFillColor(Color(0, 0, 0, 0));
    b5.setPosition(1045, 0);

    // Создание окна игры и ограничение частоты кадров (60 фпс)


    // Задний фон !внутри! игры

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
    opetion.setString(L"Настройки");
    opetion.setStyle(Text::Bold);
    opetion.setOutlineColor(Color::White);
    opetion.setOutlineThickness(3);
    opetion.setPosition(890, 7);
    opetion.setFillColor(Color::Black);

    Text Regmuz;
    Regmuz.setFont(font);
    Regmuz.setString(L"1) Настройка звука:\nНастраивайте мощность музыки/звуков\n с помощью стрелок вверх и вниз \n\nПриятного погружения в игру\n и здоровья вашим ушкам :)");
    Regmuz.setStyle(Text::Bold);
    Regmuz.setOutlineColor(Color::White);
    Regmuz.setOutlineThickness(3);
    Regmuz.setPosition(690, 138);
    Regmuz.setFillColor(Color::Blue);

    Text Desctop;
    Desctop.setFont(font);
    Desctop.setString(L"2) Нажмите (P) для выхода\n на рабочий стол");
    Desctop.setStyle(Text::Bold);
    Desctop.setOutlineColor(Color::White);
    Desctop.setOutlineThickness(3);
    Desctop.setPosition(127, 640);
    Desctop.setFillColor(Color::Blue);

    Text MainMenuk;
    MainMenuk.setFont(font);
    MainMenuk.setString(L"3) Нажмите (Esc) для выхода\n в главное меню");
    MainMenuk.setStyle(Text::Bold);
    MainMenuk.setOutlineColor(Color::White);
    MainMenuk.setOutlineThickness(3);
    MainMenuk.setPosition(1450, 600);
    MainMenuk.setFillColor(Color::Blue);

    Text Brain;
    Brain.setFont(font);
    Brain.setString(L"15.10.2000\nПомним");
    Brain.setStyle(Text::Bold);
    Brain.setOutlineColor(Color::White);
    Brain.setOutlineThickness(3);
    Brain.setPosition(1500, 250);
    Brain.setFillColor(Color::Red);

    Text Surp;
    Surp.setFont(font);
    Surp.setString(L"Также, вы можете \n попробовать нажать кнопку (I)");
    Surp.setStyle(Text::Bold);
    Surp.setOutlineColor(Color::White);
    Surp.setOutlineThickness(3);
    Surp.setPosition(1390, 815);
    Surp.setFillColor(Color::Blue);

    Text Opps;
    Opps.setFont(font);
    Opps.setString(L"3) Просим прощения, но разработчики\n настолько ахуенны, что сделали\n способ открытия снова главного меню\n\n BRUH ;)))");
    Opps.setStyle(Text::Bold);
    Opps.setOutlineColor(Color::White);
    Opps.setOutlineThickness(3);
    Opps.setPosition(1385, 600);
    Opps.setFillColor(Color::Blue);

    Text opetioz;
    opetioz.setFont(font2);
    opetioz.setString(L"О проекте");
    opetioz.setStyle(Text::Bold);
    opetioz.setOutlineColor(Color::White);
    opetioz.setOutlineThickness(3);
    opetioz.setPosition(890, 20);
    opetioz.setFillColor(Color::Black);

    Text opetioz1;
    opetioz1.setFont(font);
    opetioz1.setString(L"Загрузка сохранения");
    opetioz1.setStyle(Text::Bold);
    opetioz1.setPosition(890, 20);
    opetioz1.setFillColor(Color::Black);

    Text opetioz2;
    opetioz2.setFont(font);
    opetioz2.setString(L"Новое сохранение");
    opetioz2.setStyle(Text::Bold);
    opetioz2.setPosition(890, 20);
    opetioz2.setFillColor(Color::Black);

    Text StoryTale;
    StoryTale.setFont(font);
    StoryTale.setString(L"История");
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
    //                          Поля кнопок
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
        case 1:               // ИНТРО
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

                    cout << "Смена сценария" << endl;
                    iForIntro = 0;
                    break;

                }



            }
        }
        case 2:               // ГЛАВНОЕ МЕНЮ
        {
            cout << "Переход в главное меню" << endl;
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
                //                          Кнопка играть
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "Играть / Работает" << endl;
                            button.play();
                            bm1.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 10;

                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                          Кнопка Загрузить
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "Загрузить / Работает" << endl;
                            button.play();
                            bm2.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 6;
                            break;

                        }
                ///////////////////////////////////////////////////////////////////
                //                      Кнопка Настройки
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "Настройки / Работает" << endl;
                            button.play();
                            bm3.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 4;
                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                      Кнопка О проекте
                ///////////////////////////////////////////////////////////////////
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm4.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "О проекте / Работает" << endl;
                            button.play();
                            bm4.setFillColor(Color(0, 0, 0, 70));
                            casebefore = iforcase;
                            iforcase = 8;
                            break;
                            window.clear();

                        }
                ///////////////////////////////////////////////////////////////////
                //                      Кнопка Выход
                ///////////////////////////////////////////////////////////////////

                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (bm5.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {

                            cout << "Выход / Работает" << endl;
                            button.play();
                            bm5.setFillColor(Color(0, 0, 0, 70));

                            window.close();
                            WinOpened = false;
                        }

                ///////////////////////////////////////////////////////////////////
                //                      Анимация клика на кнопку
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
        case 3:               //ЗАТЫЧКА
            break;
        case 4:               //НАСТРОЙКИ
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
        case 5:               // ЗАТЫЧКА
            break;
        case 6:               // ЗАГРУЗКА СОХРАНЕНИЯ
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
        case 7:               // ЗАТЫЧКА
            break;
        case 8:               // О ПРОЕКТЕ
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
        case 9:               // ЗАТЫЧКА
            break;
        case 10:              // ИГРА
        {
            cout << "Переход на кейс с игрой " << endl;
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

                    // Подключение кнопок !внутри! игры после их создания

                    if (event.type == Event::Closed)
                        window.close();
                }
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left)
                        if (b1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                            event.type = Event::MouseButtonReleased;
                            cout << "Кнопка (1)(НАСТРОЙКИ) работает" << endl;
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

                            cout << "Кнопка (3)(ИСТОРИЯ) работает" << endl;
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

                            cout << "Кнопка (2)(СОХРАНЕНИЕ) работает" << endl;
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

                            cout << "Кнопка (5)(ПРОПУСК) работает" << endl;
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

                            cout << "Кнопка (4)(ЗАГРУЗИТЬ) работает" << endl;
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
                /// ///////////////////////////////////////////////////// ПЕРЕЛИСТЫВАВНИЕ

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

                /// ///////////////////////////////////////////////////// ПЕРЕЛИСТЫВАНИЕ


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
        case 11:              // ЗАТЫЧКА
            break;
        case 12:              // ИСТОРИЯ (внутри игры)
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
        case 13:              // ЗАТЫЧКА
            break;
        case 14:              // СОХРАНЕНИЕ (внутри игры)
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
        case 15:              // ЗАТЫЧКА 
            break;
        default: {

            cout << "выход за пределы кейсов, гасим игру";
            window.close();
            break;
        }
        }
    }
    return 0;
}