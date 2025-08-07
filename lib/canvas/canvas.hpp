#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>

class Canvas : public QWidget {
   public:
    explicit Canvas(QWidget* parent = nullptr) : QWidget(parent) {}
};

#endif
