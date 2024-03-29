#ifndef PARATROOPERLEMMING_H
#define PARATROOPERLEMMING_H

#include "lemming.h"
#include <QObject>

class ParatrooperLemming : public Lemming{
    Q_OBJECT
public:
    ParatrooperLemming();
    void move() override;

    enum { Type = UserType + 6 };
    int type() const override { return Type; }

private:
    void resolve_collision(QList<QGraphicsItem*> colliding_items);
    void resolve_collision_with_block(QGraphicsItem *block);
    void resolve_collision_with_blocker(QGraphicsItem *blocker);
    void update_axis_speeds();
    void bounce_back();
    void open_parachute();

    bool parachute_is_open = false;
    int lemmings_height_without_parachute;
};

#endif // PARATROOPERLEMMING_H
