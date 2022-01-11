#ifndef SNAKE_H
#define SNAKE_H
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class snake; }
QT_END_NAMESPACE


class Snake : public QWidget {
public:
    Snake(QWidget *parent = nullptr);
//    virtual ~Snake();
    ~Snake();


protected:
      void paintEvent(QPaintEvent *);
      void timerEvent(QTimerEvent *);
      void keyPressEvent(QKeyEvent *);


private:
    Ui::snake *ui;
    QImage dot;
    QImage head;
    QImage apple;
    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 140;
    int timerId;
    int dots;
    int apple_x;
    int apple_y;
    int x[ALL_DOTS];
    int y[ALL_DOTS];
    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;
    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);
};

#endif // SNAKE_H
